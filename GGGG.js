// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

/**
 * @fileoverview Run the GGGG program using WASM so it works on the open web.
 */

import { Process, SyscallEntry, SyscallHandler, WASI } from "./wjb.js";

const FD_STDIN = 0;
const FD_STDOUT = 1;
const FD_STDERR = 2;
const FD_CWD = 3;
const FD_INPUT = 4;
const FD_OUTPUT = 5;

/**
 * Syscall handler that glues the JS/DOM world to the WASM world.
 * This isn't meant to be complete or perfect, simply enough to make GGGG work.
 */
class GgggSyscallHandler extends SyscallHandler.DirectWasiPreview1 {
  constructor(...args) {
    super(...args);
    this.log = document.getElementById("log");
    this.td = new TextDecoder();
    this.inputOffset = 0;
    this.outputOffset = 0;
  }

  // Write data to a file descriptor.
  handle_fd_write(fd, buf) {
    switch (fd) {
      case FD_STDOUT:
      case FD_STDERR:
        this.log.value += this.td.decode(buf, { stream: true });
        return { nwritten: buf.length };

      case FD_OUTPUT: {
        outputRomBuffer.set(buf, this.outputOffset);
        this.outputOffset += buf.length;
        return { nwritten: buf.length };
      }
    }

    return WASI.errno.EBADF;
  }

  // Write data to a file descriptor with specific offset.
  handle_fd_pwrite(fd, buf, offset) {
    switch (fd) {
      case FD_OUTPUT: {
        outputRomBuffer.set(buf, Number(offset));
        return { nwritten: buf.length };
      }
    }
    return WASI.errno.EBADF;
  }

  // Ignore unlink requests since we always create anew.
  handle_path_unlink_file(fd, path) {
    return WASI.errno.ESUCCESS;
  }

  // File descriptors opened before the program runs.
  // Really just fake the current working directory.
  handle_fd_prestat_get(fd) {
    switch (fd) {
      case FD_CWD:
        return { path: "." };
      default:
        return WASI.errno.EBADF;
    }
  }

  // Names for the file descriptors opened before the program runs.
  handle_fd_prestat_dir_name(fd) {
    switch (fd) {
      case FD_CWD:
        return { path: "." };
      default:
        return WASI.errno.EBADF;
    }
  }

  // The file descriptor stat details (mostly WASI perms).
  handle_fd_fdstat_get(fd) {
    const ret = {
      fs_filetype: WASI.filetype.UNKNOWN,
      fs_flags: 0,
      fs_rights_base: 0xffffffffffffffffn,
      fs_rights_inheriting: 0xffffffffffffffffn,
    };
    switch (fd) {
      case FD_CWD:
        return {
          ...ret,
          fs_filetype: WASI.filetype.DIRECTORY,
        };
      case FD_INPUT:
        return {
          ...ret,
          fs_filetype: WASI.filetype.REGULAR_FILE,
        };
      case FD_OUTPUT:
        return {
          ...ret,
          fs_filetype: WASI.filetype.REGULAR_FILE,
        };
    }
    return WASI.errno.EBADF;
  }

  // The file descriptor stat details (standard UNIX stuff).
  handle_fd_filestat_get(fd) {
    const ret = {
      dev: 0n,
      ino: 0n,
      filetype: WASI.filetype.UNKNOWN,
      nlink: 0n,
      size: 0n,
      atim: 0n,
      mtim: 0n,
      ctim: 0n,
    };
    switch (fd) {
      case FD_INPUT:
        return {
          ...ret,
          filetype: WASI.filetype.REGULAR_FILE,
          size: BigInt(inputRomBuffer.length),
        };
      case FD_OUTPUT:
        return {
          ...ret,
          filetype: WASI.filetype.REGULAR_FILE,
          size: BigInt(outputRomBuffer.length),
        };
    }
    return WASI.errno.EBADF;
  }

  // Request to open files.
  handle_path_open(
    dirfd,
    dirflags,
    path,
    o_flags,
    fs_rights_base,
    fs_rights_inheriting,
    fdflags,
  ) {
    if (dirfd === FD_CWD) {
      switch (path) {
        case inputRom.name: {
          return { fd: FD_INPUT };
        }
        case "output.rom":
          return { fd: FD_OUTPUT };
      }
    }
    return WASI.errno.ENOENT;
  }

  // Read data from a file descriptor.
  handle_fd_read(fd, length) {
    switch (fd) {
      case FD_INPUT: {
        const slice = inputRomBuffer.slice(
          this.inputOffset,
          this.inputOffset + length,
        );
        this.inputOffset += slice.length;
        return {
          nread: slice.length,
          buf: slice,
        };
      }
      case FD_OUTPUT:
        break;
    }
    return WASI.errno.EBADF;
  }

  // Read data from a file descriptor with specific offset.
  handle_fd_pread(fd, length, offset) {
    switch (fd) {
      case FD_INPUT:
      case FD_OUTPUT: {
        offset = Number(offset);
        const slice = inputRomBuffer.slice(offset, offset + length);
        return {
          nread: slice.length,
          buf: slice,
        };
      }
    }
    return WASI.errno.EBADF;
  }

  // Close a file descriptor.
  handle_fd_close(fd) {
    return WASI.errno.ESUCCESS;
  }
}

/**
 * Helper to run the WASI program using the WJB framework.
 */
async function run(prog, argv, debug = false) {
  const handler = new GgggSyscallHandler();
  const sys_handlers = [handler];
  const proc = new Process.Foreground({
    executable: prog,
    argv: ["GGGG.wasm", ...argv],
    debug: debug,
    sys_handlers: sys_handlers,
    sys_entries: [
      new SyscallEntry.WasiPreview1({ sys_handlers, debug, trace: debug }),
    ],
  });
  return await proc.run();
}

/**
 * Callback when the user wants to patch a ROM.
 */
async function runGgggMain() {
  // If a ROM hasn't been selected, force it now.
  const input = document.getElementById("input");
  if (input.files.length === 0) {
    input.click();
    return false;
  }

  // Read the ROM and initialize global vars with its data.
  globalThis.inputRom = input.files[0];
  const iblob = new Blob([inputRom], { type: "application/octet-stream" });
  const buf = await iblob.arrayBuffer();
  globalThis.inputRomBuffer = new Uint8Array(buf);
  globalThis.outputRomBuffer = new Uint8Array(buf.byteLength);

  // Get the user settings to run GGGG.
  const codes = document.getElementById("codes").value;
  const system = document.getElementById("system").value;
  const log = document.getElementById("log");
  const debug = document.getElementById("debug").checked;
  const ret = await run(
    GGGGwasm,
    [codes, system, inputRom.name, "output.rom"],
    debug,
  );
  log.value += `GGGG.wasm exited ${ret}\n\n`;

  // Save the output ROM.
  if (ret === 0) {
    const download = document.getElementById("download");
    const oblob = new Blob([outputRomBuffer]);
    download.download = inputRom.name + ".gggg";
    download.href = URL.createObjectURL(oblob);
    download.click();
    setTimeout(() => {
      URL.revokeObjectURL(download.href);
    }, 1000);
  }
}

/**
 * Callback to initialize the page when it finishes loading.
 */
async function DOMContentLoaded() {
  document.getElementById("run").onclick = runGgggMain;

  // Fetch & read the program.
  globalThis.GGGGwasm = await fetch("GGGG.wasm").then((response) =>
    response.arrayBuffer(),
  );
}

globalThis.addEventListener("DOMContentLoaded", DOMContentLoaded);
