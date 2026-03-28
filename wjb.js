// Copyright 2020 The ChromiumOS Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview WASI advice API constants from wasi/api.h.
 */

const NORMAL = 0;
const SEQUENTIAL = 1;
const RANDOM = 2;
const WILLNEED = 3;
const DONTNEED = 4;
const NOREUSE = 5;

const advice = /*#__PURE__*/Object.freeze({
__proto__: null,
NORMAL: NORMAL,
SEQUENTIAL: SEQUENTIAL,
RANDOM: RANDOM,
WILLNEED: WILLNEED,
DONTNEED: DONTNEED,
NOREUSE: NOREUSE
});

// Copyright 2019 The ChromiumOS Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview WASI clockid API constants from wasi/api.h.
 */

const REALTIME = 0;
const MONOTONIC = 1;
const PROCESS_CPUTIME_ID = 2;
const THREAD_CPUTIME_ID = 3;

const clock = /*#__PURE__*/Object.freeze({
__proto__: null,
REALTIME: REALTIME,
MONOTONIC: MONOTONIC,
PROCESS_CPUTIME_ID: PROCESS_CPUTIME_ID,
THREAD_CPUTIME_ID: THREAD_CPUTIME_ID
});

// Copyright 2019 The ChromiumOS Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview WASI errno API constants from wasi/api.h.
 */

const ESUCCESS = 0;
const E2BIG = 1;
const EACCES = 2;
const EADDRINUSE = 3;
const EADDRNOTAVAIL = 4;
const EAFNOSUPPORT = 5;
const EAGAIN = 6;
const EALREADY = 7;
const EBADF = 8;
const EBADMSG = 9;
const EBUSY = 10;
const ECANCELED = 11;
const ECHILD = 12;
const ECONNABORTED = 13;
const ECONNREFUSED = 14;
const ECONNRESET = 15;
const EDEADLK = 16;
const EDESTADDRREQ = 17;
const EDOM = 18;
const EDQUOT = 19;
const EEXIST = 20;
const EFAULT = 21;
const EFBIG = 22;
const EHOSTUNREACH = 23;
const EIDRM = 24;
const EILSEQ = 25;
const EINPROGRESS = 26;
const EINTR = 27;
const EINVAL = 28;
const EIO = 29;
const EISCONN = 30;
const EISDIR = 31;
const ELOOP = 32;
const EMFILE = 33;
const EMLINK = 34;
const EMSGSIZE = 35;
const EMULTIHOP = 36;
const ENAMETOOLONG = 37;
const ENETDOWN = 38;
const ENETRESET = 39;
const ENETUNREACH = 40;
const ENFILE = 41;
const ENOBUFS = 42;
const ENODEV = 43;
const ENOENT = 44;
const ENOEXEC = 45;
const ENOLCK = 46;
const ENOLINK = 47;
const ENOMEM = 48;
const ENOMSG = 49;
const ENOPROTOOPT = 50;
const ENOSPC = 51;
const ENOSYS = 52;
const ENOTCONN = 53;
const ENOTDIR = 54;
const ENOTEMPTY = 55;
const ENOTRECOVERABLE = 56;
const ENOTSOCK = 57;
const ENOTSUP = 58;
const ENOTTY = 59;
const ENXIO = 60;
const EOVERFLOW = 61;
const EOWNERDEAD = 62;
const EPERM = 63;
const EPIPE = 64;
const EPROTO = 65;
const EPROTONOSUPPORT = 66;
const EPROTOTYPE = 67;
const ERANGE = 68;
const EROFS = 69;
const ESPIPE = 70;
const ESRCH = 71;
const ESTALE = 72;
const ETIMEDOUT = 73;
const ETXTBSY = 74;
const EXDEV = 75;
const ENOTCAPABLE = 76;

const ERRNO = /*#__PURE__*/Object.freeze({
__proto__: null,
ESUCCESS: ESUCCESS,
E2BIG: E2BIG,
EACCES: EACCES,
EADDRINUSE: EADDRINUSE,
EADDRNOTAVAIL: EADDRNOTAVAIL,
EAFNOSUPPORT: EAFNOSUPPORT,
EAGAIN: EAGAIN,
EALREADY: EALREADY,
EBADF: EBADF,
EBADMSG: EBADMSG,
EBUSY: EBUSY,
ECANCELED: ECANCELED,
ECHILD: ECHILD,
ECONNABORTED: ECONNABORTED,
ECONNREFUSED: ECONNREFUSED,
ECONNRESET: ECONNRESET,
EDEADLK: EDEADLK,
EDESTADDRREQ: EDESTADDRREQ,
EDOM: EDOM,
EDQUOT: EDQUOT,
EEXIST: EEXIST,
EFAULT: EFAULT,
EFBIG: EFBIG,
EHOSTUNREACH: EHOSTUNREACH,
EIDRM: EIDRM,
EILSEQ: EILSEQ,
EINPROGRESS: EINPROGRESS,
EINTR: EINTR,
EINVAL: EINVAL,
EIO: EIO,
EISCONN: EISCONN,
EISDIR: EISDIR,
ELOOP: ELOOP,
EMFILE: EMFILE,
EMLINK: EMLINK,
EMSGSIZE: EMSGSIZE,
EMULTIHOP: EMULTIHOP,
ENAMETOOLONG: ENAMETOOLONG,
ENETDOWN: ENETDOWN,
ENETRESET: ENETRESET,
ENETUNREACH: ENETUNREACH,
ENFILE: ENFILE,
ENOBUFS: ENOBUFS,
ENODEV: ENODEV,
ENOENT: ENOENT,
ENOEXEC: ENOEXEC,
ENOLCK: ENOLCK,
ENOLINK: ENOLINK,
ENOMEM: ENOMEM,
ENOMSG: ENOMSG,
ENOPROTOOPT: ENOPROTOOPT,
ENOSPC: ENOSPC,
ENOSYS: ENOSYS,
ENOTCONN: ENOTCONN,
ENOTDIR: ENOTDIR,
ENOTEMPTY: ENOTEMPTY,
ENOTRECOVERABLE: ENOTRECOVERABLE,
ENOTSOCK: ENOTSOCK,
ENOTSUP: ENOTSUP,
ENOTTY: ENOTTY,
ENXIO: ENXIO,
EOVERFLOW: EOVERFLOW,
EOWNERDEAD: EOWNERDEAD,
EPERM: EPERM,
EPIPE: EPIPE,
EPROTO: EPROTO,
EPROTONOSUPPORT: EPROTONOSUPPORT,
EPROTOTYPE: EPROTOTYPE,
ERANGE: ERANGE,
EROFS: EROFS,
ESPIPE: ESPIPE,
ESRCH: ESRCH,
ESTALE: ESTALE,
ETIMEDOUT: ETIMEDOUT,
ETXTBSY: ETXTBSY,
EXDEV: EXDEV,
ENOTCAPABLE: ENOTCAPABLE
});

// Copyright 2020 The ChromiumOS Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview WASI eventtype API constants from wasi/api.h.
 */

const CLOCK = 0;
const FD_READ$1 = 1;
const FD_WRITE$1 = 2;
const ENUM_END = FD_WRITE$1;

const eventtype = /*#__PURE__*/Object.freeze({
__proto__: null,
CLOCK: CLOCK,
FD_READ: FD_READ$1,
FD_WRITE: FD_WRITE$1,
ENUM_END: ENUM_END
});

// Copyright 2020 The ChromiumOS Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview WASI file descriptor flags API constants from wasi/api.h.
 */

const APPEND = 1;
const DSYNC = 2;
const NONBLOCK = 4;
const RSYNC = 8;
const SYNC = 16;

const fdflags = /*#__PURE__*/Object.freeze({
__proto__: null,
APPEND: APPEND,
DSYNC: DSYNC,
NONBLOCK: NONBLOCK,
RSYNC: RSYNC,
SYNC: SYNC
});

// Copyright 2019 The ChromiumOS Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview WASI filetype API constants from wasi/api.h.
 */

const UNKNOWN = 0;
const BLOCK_DEVICE = 1;
const CHARACTER_DEVICE = 2;
const DIRECTORY$1 = 3;
const REGULAR_FILE = 4;
const SOCKET_DGRAM = 5;
const SOCKET_STREAM = 6;
const SYMBOLIC_LINK = 7;

const filetype = /*#__PURE__*/Object.freeze({
__proto__: null,
UNKNOWN: UNKNOWN,
BLOCK_DEVICE: BLOCK_DEVICE,
CHARACTER_DEVICE: CHARACTER_DEVICE,
DIRECTORY: DIRECTORY$1,
REGULAR_FILE: REGULAR_FILE,
SOCKET_DGRAM: SOCKET_DGRAM,
SOCKET_STREAM: SOCKET_STREAM,
SYMBOLIC_LINK: SYMBOLIC_LINK
});

// Copyright 2020 The ChromiumOS Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview WASI file stat flags API constants from wasi/api.h.
 */

const ATIM = 1;
const ATIM_NOW = 2;
const MTIM = 4;
const MTIM_NOW = 8;

const fstflags = /*#__PURE__*/Object.freeze({
__proto__: null,
ATIM: ATIM,
ATIM_NOW: ATIM_NOW,
MTIM: MTIM,
MTIM_NOW: MTIM_NOW
});

// Copyright 2020 The ChromiumOS Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview WASI path lookup flags API constants from wasi/api.h.
 */

const SYMLINK_FOLLOW = 1;

const lookupflags = /*#__PURE__*/Object.freeze({
__proto__: null,
SYMLINK_FOLLOW: SYMLINK_FOLLOW
});

// Copyright 2020 The ChromiumOS Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview WASI file open flags API constants from wasi/api.h.
 */

const CREAT = 1;
const DIRECTORY = 2;
const EXCL = 4;
const TRUNC = 8;

const oflags = /*#__PURE__*/Object.freeze({
__proto__: null,
CREAT: CREAT,
DIRECTORY: DIRECTORY,
EXCL: EXCL,
TRUNC: TRUNC
});

// Copyright 2020 The ChromiumOS Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview WASI rights API constants from wasi/api.h.
 */

const FD_DATASYNC = 1n;
const FD_READ = 2n;
const FD_SEEK = 4n;
const FD_FDSTAT_SET_FLAGS = 8n;
const FD_SYNC = 16n;
const FD_TELL = 32n;
const FD_WRITE = 64n;
const FD_ADVISE = 128n;
const FD_ALLOCATE = 256n;
const PATH_CREATE_DIRECTORY = 512n;
const PATH_CREATE_FILE = 1024n;
const PATH_LINK_SOURCE = 2048n;
const PATH_LINK_TARGET = 4096n;
const PATH_OPEN = 8192n;
const FD_READDIR = 16384n;
const PATH_READLINK = 32768n;
const PATH_RENAME_SOURCE = 65536n;
const PATH_RENAME_TARGET = 131072n;
const PATH_FILESTAT_GET = 262144n;
const PATH_FILESTAT_SET_SIZE = 524288n;
const PATH_FILESTAT_SET_TIMES = 1048576n;
const FD_FILESTAT_GET = 2097152n;
const FD_FILESTAT_SET_SIZE = 4194304n;
const FD_FILESTAT_SET_TIMES = 8388608n;
const PATH_SYMLINK = 16777216n;
const PATH_REMOVE_DIRECTORY = 33554432n;
const PATH_UNLINK_FILE = 67108864n;
const POLL_FD_READWRITE = 134217728n;
const SOCK_SHUTDOWN = 268435456n;

const rights = /*#__PURE__*/Object.freeze({
__proto__: null,
FD_DATASYNC: FD_DATASYNC,
FD_READ: FD_READ,
FD_SEEK: FD_SEEK,
FD_FDSTAT_SET_FLAGS: FD_FDSTAT_SET_FLAGS,
FD_SYNC: FD_SYNC,
FD_TELL: FD_TELL,
FD_WRITE: FD_WRITE,
FD_ADVISE: FD_ADVISE,
FD_ALLOCATE: FD_ALLOCATE,
PATH_CREATE_DIRECTORY: PATH_CREATE_DIRECTORY,
PATH_CREATE_FILE: PATH_CREATE_FILE,
PATH_LINK_SOURCE: PATH_LINK_SOURCE,
PATH_LINK_TARGET: PATH_LINK_TARGET,
PATH_OPEN: PATH_OPEN,
FD_READDIR: FD_READDIR,
PATH_READLINK: PATH_READLINK,
PATH_RENAME_SOURCE: PATH_RENAME_SOURCE,
PATH_RENAME_TARGET: PATH_RENAME_TARGET,
PATH_FILESTAT_GET: PATH_FILESTAT_GET,
PATH_FILESTAT_SET_SIZE: PATH_FILESTAT_SET_SIZE,
PATH_FILESTAT_SET_TIMES: PATH_FILESTAT_SET_TIMES,
FD_FILESTAT_GET: FD_FILESTAT_GET,
FD_FILESTAT_SET_SIZE: FD_FILESTAT_SET_SIZE,
FD_FILESTAT_SET_TIMES: FD_FILESTAT_SET_TIMES,
PATH_SYMLINK: PATH_SYMLINK,
PATH_REMOVE_DIRECTORY: PATH_REMOVE_DIRECTORY,
PATH_UNLINK_FILE: PATH_UNLINK_FILE,
POLL_FD_READWRITE: POLL_FD_READWRITE,
SOCK_SHUTDOWN: SOCK_SHUTDOWN
});

// Copyright 2020 The ChromiumOS Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview WASI signal API constants from wasi/api.h.
 */

const NONE = 0;
const HUP = 1;
const INT = 2;
const QUIT = 3;
const ILL = 4;
const TRAP = 5;
const ABRT = 6;
const BUS = 7;
const FPE = 8;
const KILL = 9;
const USR1 = 10;
const SEGV = 11;
const USR2 = 12;
const PIPE = 13;
const ALRM = 14;
const TERM = 15;
const CHLD = 16;
const CONT = 17;
const STOP = 18;
const TSTP = 19;
const TTIN = 20;
const TTOU = 21;
const URG = 22;
const XCPU = 23;
const XFSZ = 24;
const VTALRM = 25;
const PROF = 26;
const WINCH = 27;
const POLL = 28;
const PWR = 29;
const SYS = 30;

const signal = /*#__PURE__*/Object.freeze({
__proto__: null,
NONE: NONE,
HUP: HUP,
INT: INT,
QUIT: QUIT,
ILL: ILL,
TRAP: TRAP,
ABRT: ABRT,
BUS: BUS,
FPE: FPE,
KILL: KILL,
USR1: USR1,
SEGV: SEGV,
USR2: USR2,
PIPE: PIPE,
ALRM: ALRM,
TERM: TERM,
CHLD: CHLD,
CONT: CONT,
STOP: STOP,
TSTP: TSTP,
TTIN: TTIN,
TTOU: TTOU,
URG: URG,
XCPU: XCPU,
XFSZ: XFSZ,
VTALRM: VTALRM,
PROF: PROF,
WINCH: WINCH,
POLL: POLL,
PWR: PWR,
SYS: SYS
});

// Copyright 2020 The ChromiumOS Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * @fileoverview WASI whence API constants from wasi/api.h.
 */

const CUR = 0;
const END = 1;
const SET = 2;

const whence = /*#__PURE__*/Object.freeze({
__proto__: null,
CUR: CUR,
END: END,
SET: SET
});

// Copyright 2019 The ChromiumOS Authors

const wasi = /*#__PURE__*/Object.freeze({
__proto__: null,
advice: advice,
clock: clock,
errno: ERRNO,
eventtype: eventtype,
fdflags: fdflags,
filetype: filetype,
fstflags: fstflags,
lookupflags: lookupflags,
oflags: oflags,
rights: rights,
signal: signal,
whence: whence
});

// Copyright 2020 The ChromiumOS Authors

/**
 * DataView with methods for working with WASI structures.
 *
 * @implements {WasiViewInterface}
 */
class WasiView extends DataView {
  /**
   * Helper for reading out a packed structure.
   *
   * @suppress {checkTypes} Closure doesn't like the this[] lookup.
   * @param {!Object} spec A specification for the structure to process.
   * @param {number} byteOffset Byte offset into the buffer to process.
   * @param {boolean=} littleEndian The endian of this structure.
   * @return {!Object} The structure read out.
   */
  get_(spec, byteOffset, littleEndian = false) {
    const ret = {struct_size: spec.struct_size};
    for (const [name, field] of Object.entries(spec.fields)) {
      ret[name] = this[`get${field.type}`](
          byteOffset + field.offset, littleEndian);
    }
    return ret;
  }

  /**
   * Helper for writing out a packed structure.
   *
   * @suppress {checkTypes} Closure doesn't like the this[] lookup.
   * @param {!Object} spec A specification for the structure to process.
   * @param {number} byteOffset Byte offset into the buffer to process.
   * @param {!Object} value The structure to write out.
   * @param {boolean=} littleEndian The endian of this structure.
   */
  set_(spec, byteOffset, value, littleEndian = false) {
    for (const [name, field] of Object.entries(spec.fields)) {
      this[`set${field.type}`](
          byteOffset + field.offset, value[name], littleEndian);
    }
  }

  /**
   * @param {number} byteOffset
   * @param {boolean=} littleEndian
   * @return {!WASI_t.dirent}
   * @override
   */
  getDirent(byteOffset, littleEndian = false) {
    return /** @type {!WASI_t.dirent} */ (
        this.get_(WasiView.dirent_t, byteOffset, littleEndian));
  }

  /**
   * @param {number} byteOffset
   * @param {!WASI_t.dirent} value
   * @param {boolean=} littleEndian
   * @override
   */
  setDirent(byteOffset, value, littleEndian = false) {
    this.set_(WasiView.dirent_t, byteOffset, value, littleEndian);
  }

  /**
   * @param {number} byteOffset
   * @param {boolean=} littleEndian
   * @return {!WASI_t.event}
   * @override
   */
  getEvent(byteOffset, littleEndian = false) {
    return /** @type {!WASI_t.event} */ (
        this.get_(WasiView.event_t, byteOffset, littleEndian));
  }

  /**
   * @param {number} byteOffset
   * @param {!WASI_t.event} value
   * @param {boolean=} littleEndian
   * @override
   */
  setEvent(byteOffset, value, littleEndian = false) {
    this.set_(WasiView.event_t, byteOffset, value, littleEndian);
  }

  /**
   * @param {number} byteOffset
   * @param {boolean=} littleEndian
   * @return {!WASI_t.event_fd_readwrite}
   * @override
   */
  getEventFdReadWrite(byteOffset, littleEndian = false) {
    return /** @type {!WASI_t.event_fd_readwrite} */ (
        this.get_(WasiView.event_fd_readwrite_t, byteOffset, littleEndian));
  }

  /**
   * @param {number} byteOffset
   * @param {!WASI_t.event_fd_readwrite} value
   * @param {boolean=} littleEndian
   * @override
   */
  setEventFdReadWrite(byteOffset, value, littleEndian = false) {
    this.set_(WasiView.event_fd_readwrite_t, byteOffset, value, littleEndian);
  }

  /**
   * @param {number} byteOffset
   * @param {boolean=} littleEndian
   * @return {!WASI_t.fdstat}
   * @override
   */
  getFdstat(byteOffset, littleEndian = false) {
    return /** @type {!WASI_t.fdstat} */ (
        this.get_(WasiView.fdstat_t, byteOffset, littleEndian));
  }

  /**
   * @param {number} byteOffset
   * @param {!WASI_t.fdstat} value
   * @param {boolean=} littleEndian
   * @override
   */
  setFdstat(byteOffset, value, littleEndian = false) {
    this.set_(WasiView.fdstat_t, byteOffset, value, littleEndian);
  }

  /**
   * @param {number} byteOffset
   * @param {boolean=} littleEndian
   * @return {!WASI_t.filestat}
   * @override
   */
  getFilestat(byteOffset, littleEndian = false) {
    return /** @type {!WASI_t.filestat} */ (
        this.get_(WasiView.filestat_t, byteOffset, littleEndian));
  }

  /**
   * @param {number} byteOffset
   * @param {!WASI_t.filestat} value
   * @param {boolean=} littleEndian
   * @override
   */
  setFilestat(byteOffset, value, littleEndian = false) {
    this.set_(WasiView.filestat_t, byteOffset, value, littleEndian);
  }

  /**
   * @param {number} byteOffset
   * @param {boolean=} littleEndian
   * @return {!WASI_t.iovec}
   * @override
   */
  getIovec(byteOffset, littleEndian = false) {
    return /** @type {!WASI_t.iovec} */ (
        this.get_(WasiView.iovec_t, byteOffset, littleEndian));
  }

  /**
   * @param {number} byteOffset
   * @param {!WASI_t.iovec} value
   * @param {boolean=} littleEndian
   * @override
   */
  setIovec(byteOffset, value, littleEndian = false) {
    this.set_(WasiView.iovec_t, byteOffset, value, littleEndian);
  }

  /**
   * @param {number} byteOffset
   * @param {boolean=} littleEndian
   * @return {!WASI_t.subscription_clock}
   * @override
   */
  getSubscriptionClock(byteOffset, littleEndian = false) {
    return /** @type {!WASI_t.subscription_clock} */ (
        this.get_(WasiView.subscription_clock_t, byteOffset, littleEndian));
  }

  /**
   * @param {number} byteOffset
   * @param {!WASI_t.subscription_clock} value
   * @param {boolean=} littleEndian
   * @override
   */
  setSubscriptionClock(byteOffset, value, littleEndian = false) {
    this.set_(WasiView.subscription_clock_t, byteOffset, value, littleEndian);
  }

  /**
   * @param {number} byteOffset
   * @param {boolean=} littleEndian
   * @return {!WASI_t.subscription_fd_readwrite}
   * @override
   */
  getSubscriptionFdReadWrite(byteOffset, littleEndian = false) {
    return /** @type {!WASI_t.subscription_fd_readwrite} */ (
        this.get_(WasiView.subscription_fd_readwrite_t, byteOffset,
                  littleEndian));
  }

  /**
   * @param {number} byteOffset
   * @param {!WASI_t.subscription_fd_readwrite} value
   * @param {boolean=} littleEndian
   * @override
   */
  setSubscriptionFdReadWrite(byteOffset, value, littleEndian = false) {
    this.set_(WasiView.subscription_fd_readwrite_t, byteOffset, value,
              littleEndian);
  }

  /**
   * @param {number} byteOffset
   * @param {boolean=} littleEndian
   * @return {!WASI_t.subscription}
   * @override
   */
  getSubscription(byteOffset, littleEndian = false) {
    const ret = {
      userdata: this.getBigUint64(byteOffset, littleEndian),
      tag: /** @type {!WASI_t.eventtype} */ (this.getUint8(byteOffset + 8)),
      struct_size: 48,
    };
    switch (ret.tag) {
      case CLOCK:
        ret.clock = this.getSubscriptionClock(byteOffset + 16, littleEndian);
        break;
      case FD_READ$1:
        ret.fd_read = this.getSubscriptionFdReadWrite(
            byteOffset + 16, littleEndian);
        break;
      case FD_WRITE$1:
        ret.fd_write = this.getSubscriptionFdReadWrite(
            byteOffset + 16, littleEndian);
        break;
      default:
        throw new Error(`Unknown tag ${ret.tag}`);
    }
    return ret;
  }

  /**
   * These stub methods are here to keep closure-compiler happy.  We hot patch
   * the methods in below via WasiView.typedefs.  We can clean this up if/when
   * JS supports class fields.
   */
  /* eslint-disable lines-between-class-members */
  /** @override */ getAdvice() {}
  /** @override */ setAdvice() {}
  /** @override */ getClockid() {}
  /** @override */ setClockid() {}
  /** @override */ getDevice() {}
  /** @override */ setDevice() {}
  /** @override */ getDircookie() {}
  /** @override */ setDircookie() {}
  /** @override */ getDirnamlen() {}
  /** @override */ setDirnamlen() {}
  /** @override */ getErrno() {}
  /** @override */ setErrno() {}
  /** @override */ getEventrwflags() {}
  /** @override */ setEventrwflags() {}
  /** @override */ getEventtype() {}
  /** @override */ setEventtype() {}
  /** @override */ getExitcode() {}
  /** @override */ setExitcode() {}
  /** @override */ getFd() {}
  /** @override */ setFd() {}
  /** @override */ getFdflags() {}
  /** @override */ setFdflags() {}
  /** @override */ getFilesize() {}
  /** @override */ setFilesize() {}
  /** @override */ getFiletype() {}
  /** @override */ setFiletype() {}
  /** @override */ getFstflags() {}
  /** @override */ setFstflags() {}
  /** @override */ getInode() {}
  /** @override */ setInode() {}
  /** @override */ getLinkcount() {}
  /** @override */ setLinkcount() {}
  /** @override */ getLookupflags() {}
  /** @override */ setLookupflags() {}
  /** @override */ getOflags() {}
  /** @override */ setOflags() {}
  /** @override */ getPointer() {}
  /** @override */ setPointer() {}
  /** @override */ getPreopentype() {}
  /** @override */ setPreopentype() {}
  /** @override */ getRiflags() {}
  /** @override */ setRiflags() {}
  /** @override */ getRights() {}
  /** @override */ setRights() {}
  /** @override */ getRoflags() {}
  /** @override */ setRoflags() {}
  /** @override */ getSdflags() {}
  /** @override */ setSdflags() {}
  /** @override */ getSiflags() {}
  /** @override */ setSiflags() {}
  /** @override */ getSignal() {}
  /** @override */ setSignal() {}
  /** @override */ getSize() {}
  /** @override */ setSize() {}
  /** @override */ getSubclockflags() {}
  /** @override */ setSubclockflags() {}
  /** @override */ getTimestamp() {}
  /** @override */ setTimestamp() {}
  /** @override */ getUserdata() {}
  /** @override */ setUserdata() {}
  /** @override */ getWhence() {}
  /** @override */ setWhence() {}
  /* eslint-enable lines-between-class-members */
}

/*
 * Move all these structures to class fields once JS supports it:
 * https://github.com/tc39/proposal-class-fields
 */

/**
 * These match the __wasi_*_t typedefs.
 *
 * @type {!Object<string, !Array<string>>}
 */
WasiView.typedefs = {
  'Uint8': [
    'Advice', 'Eventtype', 'Filetype', 'Preopentype', 'Sdflags', 'Signal',
    'Whence',
  ],
  'Uint16': [
    'Errno', 'Eventrwflags', 'Fdflags', 'Fstflags', 'Oflags', 'Riflags',
    'Roflags', 'Siflags', 'Subclockflags',
  ],
  'Uint32': [
    'Clockid', 'Dirnamlen', 'Exitcode', 'Fd', 'Lookupflags', 'Pointer', 'Size',
  ],
  'BigUint64': [
    'Device', 'Dircookie', 'Filesize', 'Inode', 'Linkcount', 'Rights',
    'Timestamp', 'Userdata',
  ],
};
Object.entries(WasiView.typedefs).forEach(([type, wasiTypes]) => {
  wasiTypes.forEach((wasiType) => {
    WasiView.prototype[`get${wasiType}`] = DataView.prototype[`get${type}`];
    WasiView.prototype[`set${wasiType}`] = DataView.prototype[`set${type}`];
  });
});

/*
 * typedef struct __wasi_dirent_t {
 *   __wasi_dircookie_t d_next;
 *   __wasi_inode_t d_ino;
 *   __wasi_dirnamlen_t d_namlen;
 *   __wasi_filetype_t d_type;
 * } __wasi_dirent_t;
 */
WasiView.dirent_t = {
  fields: {
    d_next: {offset: 0, type: 'Dircookie'},
    d_ino: {offset: 8, type: 'Inode'},
    d_namlen: {offset: 16, type: 'Dirnamlen'},
    d_type: {offset: 20, type: 'Filetype'},
  },
  struct_size: 24,
};

/*
 * typedef struct __wasi_event_t {
 *   __wasi_userdata_t userdata;
 *   __wasi_errno_t error;
 *   __wasi_eventtype_t type;
 *   __wasi_event_fd_readwrite_t fd_readwrite;
 * } __wasi_event_t;
 */
WasiView.event_t = {
  fields: {
    userdata: {offset: 0, type: 'Userdata'},
    error: {offset: 8, type: 'Errno'},
    type: {offset: 10, type: 'Eventtype'},
    fd_readwrite: {offset: 16, type: 'EventFdReadWrite'},
  },
  struct_size: 32,
};

/*
 * typedef struct __wasi_event_fd_readwrite_t {
 *   __wasi_filesize_t nbytes;
 *   __wasi_eventrwflags_t flags;
 * } __wasi_event_fd_readwrite_t;
 */
WasiView.event_fd_readwrite_t = {
  fields: {
    nbytes: {offset: 0, type: 'Filesize'},
    flags: {offset: 8, type: 'Eventrwflags'},
  },
  struct_size: 16,
};

/*
 * typedef struct __wasi_fdstat_t {
 *   __wasi_filetype_t fs_filetype;
 *   __wasi_fdflags_t fs_flags;
 *   __wasi_rights_t fs_rights_base;
 *   __wasi_rights_t fs_rights_inheriting;
 * } __wasi_fdstat_t;
 */
WasiView.fdstat_t = {
  fields: {
    fs_filetype: {offset: 0, type: 'Filetype'},
    fs_flags: {offset: 2, type: 'Fdflags'},
    fs_rights_base: {offset: 8, type: 'Rights'},
    fs_rights_inheriting: {offset: 16, type: 'Rights'},
  },
  struct_size: 24,
};

/*
 * typedef struct __wasi_filestat_t {
 *   __wasi_device_t dev;
 *   __wasi_inode_t ino;
 *   __wasi_filetype_t filetype;
 *   __wasi_linkcount_t nlink;
 *   __wasi_filesize_t size;
 *   __wasi_timestamp_t atim;
 *   __wasi_timestamp_t mtim;
 *   __wasi_timestamp_t ctim;
 * } __wasi_filestat_t;
 */
WasiView.filestat_t = {
  fields: {
    dev: {offset: 0, type: 'Device'},
    ino: {offset: 8, type: 'Inode'},
    filetype: {offset: 16, type: 'Filetype'},
    nlink: {offset: 24, type: 'Linkcount'},
    size: {offset: 32, type: 'Filesize'},
    atim: {offset: 40, type: 'Timestamp'},
    mtim: {offset: 48, type: 'Timestamp'},
    ctim: {offset: 56, type: 'Timestamp'},
  },
  struct_size: 64,
};

/*
 * typedef struct __wasi_iovec_t {
 *   void *buf;
 *   size_t buf_len;
 * } __wasi_iovec_t;
 */
WasiView.ciovec_t =
WasiView.iovec_t = {
  fields: {
    buf: {offset: 0, type: 'Pointer'},
    buf_len: {offset: 4, type: 'Size'},
  },
  struct_size: 8,
};

/*
 * typedef struct __wasi_subscription_clock_t {
 *   __wasi_clockid_t id;
 *   __wasi_timestamp_t timeout;
 *   __wasi_timestamp_t precision;
 *   __wasi_subclockflags_t flags;
 * } __wasi_subscription_clock_t;
 */
WasiView.subscription_clock_t = {
  fields: {
    id: {offset: 0, type: 'Clockid'},
    timeout: {offset: 8, type: 'Timestamp'},
    precision: {offset: 16, type: 'Timestamp'},
    flags: {offset: 24, type: 'Subclockflags'},
  },
  struct_size: 32,
};

/*
 * typedef struct __wasi_subscription_fd_readwrite_t {
 *   __wasi_fd_t file_descriptor;
 * } __wasi_subscription_fd_readwrite_t;
 */
WasiView.subscription_fd_readwrite_t = {
  fields: {
    file_descriptor: {offset: 0, type: 'Fd'},
  },
  struct_size: 4,
};

// Copyright 2020 The ChromiumOS Authors

// eslint-disable-next-line jsdoc/require-returns-check
/**
 * Generator to return all properties on an object.
 *
 * @param {?Object} obj The object whose names to enumerate.
 * @return {!Generator<string>} The property names.
 */
function* getAllPropertyNames(obj) {
  while (obj) {
    const keys = Object.getOwnPropertyNames(obj);
    for (let i = 0; i < keys.length; ++i) {
      yield keys[i];
    }
    obj = Object.getPrototypeOf(obj);
  }
}

/**
 * Status of an exited process.
 */
class CompletedProcessError extends Error {
  /**
   * @param {{
   *   status: (number|undefined),
   *   signal: (number|undefined),
   *   message: (string|undefined),
   * }} param1
   */
  constructor({status, signal, message}) {
    super();
    this.status = status;
    this.signal = signal;
    this.message_ = message;
    this.message = this.toString();
  }

  /**
   * Convert object to a human readable string.
   *
   * @override
   * @return {string}
   */
  toString() {
    let ret;
    if (this.status !== undefined) {
      ret = `Process called exit(${this.status})`;
    } else if (this.signal !== undefined) {
      ret = `Process exited due to signal ${this.signal}`;
    } else {
      ret = 'Process exited for unknown reasons';
    }
    if (this.message_) {
      ret += `: ${this.message_}`;
    }
    return ret;
  }
}

/**
 * Exception when a documented API is used incorrectly.
 */
class ApiViolation extends Error {}

/**
 * Turn error number into symbolic constant.
 *
 * @param {number} errno The error number.
 * @return {string} The symbolic constant (e.g. EINVAL).
 */
function strerror(errno) {
  for (const [key, val] of Object.entries(ERRNO)) {
    if (key[0] == 'E' && val == errno) {
      return key;
    }
  }
  return `E???[${errno}]`;
}

/**
 * Helper to encodeInto shared array buffers.
 *
 * TODO(crbug.com/1012656): Workaround Chrome's limitation :(.
 *
 * @param {!TextEncoder} encoder The text encoder to use.
 * @param {string} str The string to encode.
 * @param {!Uint8Array} buf The buffer to write to.
 * @return {number} The number of bytes written to the buffer.
 */
function encodeIntoSab(encoder, str, buf) {
  try {
    return encoder.encodeInto(str, buf).written;
  } catch (e) {
    if (e instanceof TypeError) {
      const bytes = encoder.encode(str);
      buf.set(bytes);
      return bytes.length;
    }

    throw e;
  }
}

const util = /*#__PURE__*/Object.freeze({
__proto__: null,
getAllPropertyNames: getAllPropertyNames,
CompletedProcessError: CompletedProcessError,
ApiViolation: ApiViolation,
strerror: strerror,
encodeIntoSab: encodeIntoSab
});

// Copyright 2019 The ChromiumOS Authors

/**
 * A program API encapsulating a WASM program.
 */
class Program {
  /**
   * @param {string|!Promise<!Response>|!Response|!ArrayBuffer} source The WASM
   *     program to run.  Strings will automatically be fetched, responses will
   *     be processed, and ArrayBuffers used directly.
   * @param {boolean=} stream Whether to use WebAssembly.instantiateStreaming.
   */
  constructor(source, stream = false) {
    this.source = source;
    /** @type {?WebAssembly.Instance} */
    this.instance = null;
    // Hack for webservers that don't return .wasm with right mime type.
    // https://www.w3.org/TR/wasm-web-api-1/#streaming-modules
    // https://github.com/http-party/http-server/issues/35#issuecomment-455666015
    this.stream_ = stream;
  }

  /**
   * Instantiate the program (but don't run it).
   *
   * @param {!Object} imports Set of function imports for the WASM program.
   * @return {!Promise<!WebAssembly.Instance>} The WASM instance.
   */
  async instantiate(imports) {
    let result;

    let stream = this.stream_;
    if (this.source instanceof ArrayBuffer) {
      stream = false;
    }

    let source;
    if (typeof this.source === 'string') {
      source = fetch(this.source);
    } else {
      source = this.source;
    }

    if (stream) {
      if (source instanceof ArrayBuffer) {
        throw new ApiViolation(
            'source cannot be an ArrayBuffer when streaming');
      }
      /** @suppress {checkTypes} Closure externs are missing Response. */
      result = await WebAssembly.instantiateStreaming(source, imports);
    } else {
      let buffer;
      if (this.source instanceof ArrayBuffer) {
        buffer = this.source;
      } else {
        if (source instanceof Promise) {
          source = await source;
        }
        buffer = await source.arrayBuffer();
      }

      result = await WebAssembly.instantiate(buffer, imports);
    }
    this.instance = result.instance;
    return /** @type {!WebAssembly.Instance} */ (this.instance);
  }

  /**
   * Run the program.
   *
   * This won't normally resolve until the program itself exits.
   *
   * @return {!Promise<number>} The program exit code.
   */
  async run() {
    // WASI libc will return here only if the program *returns* 0 from its main
    // function.  If it *returns* non-zero, WASI libc will call exit() with that
    // value which triggers the exit syscall, and this point never returns.  If
    // the program calls exit() itself, then it too runs the exit syscall.  If
    // the program aborts, WASM will throw an exception which our Program class
    // will catch & process.  This seems more complicated than it should be.
    let entry = this.instance.exports['_start'];
    if (WebAssembly.promising !== undefined) {
      entry = WebAssembly.promising(entry);
    }
    return await entry() ?? 0;
  }
}

// Copyright 2020 The ChromiumOS Authors

/**
 * A magic string to mark bigints serialized in JSON as a string.
 */
const BIGINT_MAGIC = '_WASI\x00BigInt\x01';
const ARRAY_BUFFER_MAGIC = '_WASI\x00ArrayBuffer\x01';

/**
 * Locking type that's more analagous to a Win32-style signal. This class
 * creates locking semantics and a return code around a piece of shared memory
 * supplied at construction time. This lets two threads share a communications
 * channel, as one thread can lock() and wait() while another thread performs
 * the unlock() when execution in the original thread should continue.
 */
class SyscallLock {
  /**
   * Creates an instance of SyscallLock.
   *
   * @param {!SharedArrayBuffer} buffer Shared memory for this lock.
   * @param {number=} offset
   */
  constructor(buffer, offset = 0) {
    // Constants for keeping track of the locked state.
    this.UNLOCKED = 0;
    this.LOCKED = 1;

    // NB: We don't verify offset, or buffer length, of offset alignment as
    // Int32Array does it for us.
    if (!(buffer instanceof SharedArrayBuffer)) {
      throw new Error('buffer must be a SharedArrayBuffer');
    }

    // Space for integers shared memory.
    this.sabArr = new Int32Array(buffer, offset, 4);
    // Offset of the lock itself.
    this.lockIndex = 0;
    // Offset of the return value.
    this.retcodeIndex = 1;
    // Offset of the data object.
    this.dataLengthIndex = 2;
    // Offset of the array buffer.
    this.arrLengthIndex = 3;

    // The space for passing shared objects around.
    this.sabDataArr = new Uint8Array(
        buffer, offset + this.sabArr.byteLength,
        buffer.byteLength - offset - this.sabArr.byteLength);
  }

  /**
   * Sets |lockIndex| to LOCKED, the caller must *not* already hold the lock
   * when making this call.
   *
   * @return {boolean} True if the lock was acquired, False otherwise.
   */
  lock() {
    // TODO(ajws@): Check if the lock is already held.
    return Atomics.compareExchange(
        this.sabArr, this.lockIndex, this.UNLOCKED, this.LOCKED) ===
        this.UNLOCKED;
  }

  /**
   * Blocks execution of the caller while lockIndex remains in the LOCKED
   * state.
   */
  wait() {
    Atomics.wait(this.sabArr, this.lockIndex, this.LOCKED);
  }

  /**
   * Unlock lockIndex, this does not check to see if the lock is currenly held
   * by anyone.
   */
  unlock() {
    Atomics.store(this.sabArr, this.lockIndex, this.UNLOCKED);
    Atomics.notify(this.sabArr, this.lockIndex);
  }

  /**
   * Set the return code for a syscall.
   *
   * @param {number} retcode Must be be able to fit into an Int32, should be one
   *     of the values of ./wasi/errno.js.
   */
  setRetcode(retcode) {
    Atomics.store(this.sabArr, this.retcodeIndex, retcode);
  }

  /**
   * Get the returncode of the last syscall made using this lock.
   *
   * @return {number} A syscall result from ./wasi/errno.js.
   */
  getRetcode() {
    const ret = Atomics.load(this.sabArr, this.retcodeIndex);
    return ret;
  }

  /**
   * Serialize complicated objects for passing via shared memory.
   *
   * This uses JSON internally, so objects should not be complicated, and they
   * need to fit within 64KiB.
   *
   * @param {!Object} obj The object to serialize.
   */
  setData(obj) {
    const te = new TextEncoder();
    /** @type {?ArrayBufferView} */
    let ab = null;
    const str = JSON.stringify(obj, (key, value) => {
      switch (typeof value) {
        case 'bigint':
          return BIGINT_MAGIC + value.toString();
        case 'object':
          if (ArrayBuffer.isView(value)) {
            // closure-compiler misses the ArrayBuffer.isView check above, so we
            // have to cast it when using it below.
            if (ab !== null) {
              console.warn('Can only handle one array buffer at a time.');
              return Array.from(
                  /** @type {!IArrayLike<!ArrayBufferView>} */ (value));
            }
            ab = /** @type {!ArrayBufferView} */ (value);
            return ARRAY_BUFFER_MAGIC;
          }
        default:
          return value;
      }
    });
    const written = encodeIntoSab(te, str, this.sabDataArr);
    this.sabArr[this.dataLengthIndex] = written;
    if (ab !== null) {
      // closure-compiler is missing the null check here for some reason.
      this.sabDataArr.set(/** @type {!ArrayBufferView} */ (ab), written);
      this.sabArr[this.arrLengthIndex] = ab.length;
    }
  }

  /**
   * Deserialize complicated objects.
   *
   * @return {?Object} The object returned by the syscall handler, or null if
   *    there is no object passed back.
   */
  getData() {
    const length = this.sabArr[this.dataLengthIndex];
    if (!length) {
      return null;
    }

    const td = new TextDecoder();
    // We have to use slice to get a copy as decode doesn't support shared array
    // buffers yet.
    const bytes = this.sabDataArr.slice(0, length);
    const ret = JSON.parse(td.decode(bytes), (key, value) => {
      if (typeof value === 'string') {
        if (value.startsWith(BIGINT_MAGIC)) {
          return BigInt(value.substr(BIGINT_MAGIC.length));
        } else if (value.startsWith(ARRAY_BUFFER_MAGIC)) {
          const arrLength = this.sabArr[this.arrLengthIndex];
          return Array.from(this.sabDataArr.slice(length, length + arrLength));
        }
      }
      return value;
    });
    if (!(ret instanceof Object)) {
      throw new Error(`Invalid serialized object`);
    }
    return ret;
  }
}

// Copyright 2020 The ChromiumOS Authors

/**
 * Shared logic between different process types.
 *
 * @extends {Process}
 */
class Base$3 {
  /**
   * @param {{
   *   executable: (string|!Promise<!Response>|!Response|!ArrayBuffer),
   *   argv: (!Array<string>|undefined),
   *   environ: (!Object<string, string>|undefined),
   *   debug: (boolean|undefined)
   * }} options
   */
  constructor({executable, argv, environ, debug}) {
    this.executable = executable;
    if (argv === undefined) {
      if (typeof executable === 'string') {
        this.argv = [executable];
      } else {
        this.argv = ['wasi-program'];
      }
    } else {
      if (!Array.isArray(argv)) {
        throw new ApiViolation('argv must be an Array');
      }
      for (let i = 0; i < argv.length; ++i) {
        if (typeof argv[i] !== 'string') {
          throw new ApiViolation(
              `argv must be an Array of strings; argv[${i}] is a ` +
              `"${typeof argv[i]}" instead!`);
        }
      }

      this.argv = argv;
    }
    this.environ = environ || {};
    /** @type {?number} The program exit code. */
    this.exit_status = null;
    /** @type {boolean} Whether the program was aborted. */
    this.aborted = false;
    this.enableDebug_ = debug;
  }

  /**
   * @param {...*} args
   * @override
   */
  debug(...args) {
    if (!this.enableDebug_) {
      return;
    }

    console.log(...args);
  }

  /**
   * @param {...*} args
   * @override
   */
  logGroup(...args) {
    console.group(...args);
  }

  /**
   * @param {...*} args
   * @override
   */
  logError(...args) {
    console.error(...args);
  }

  /**
   * @param {number} status
   * @override
   */
  exit(status) {
    this.exit_status = status;
    this.onExit(status);
  }

  /**
   * Callback event for when the program exits.
   *
   * @param {number} status The program's exit code.
   */
  onExit(status) {}

  /** @override */
  abort() {
    this.aborted = true;
    this.onAbort();
  }

  /**
   * Callback event for when the program is aborted.
   */
  onAbort() {}
}

/**
 * A process that runs in the current thread synchronously.
 *
 * This will not return until the program finishes running, so use it only with
 * fast/short programs, or when the thread is dedicated to it (e.g. a worker).
 */
class Foreground extends Base$3 {
  /**
   * @param {{
   *   executable: (string|!Promise<!Response>|!Response|!ArrayBuffer),
   *   argv: (!Array<string>|undefined),
   *   environ: (!Object<string, string>|undefined),
   *   debug: (boolean|undefined),
   *   sys_handlers: !Array<!SyscallHandler>,
   *   sys_entries: !Array<!SyscallEntry>,
   * }} param1
   */
  constructor({executable, argv, environ, debug, sys_handlers, sys_entries}) {
    super({executable, argv, environ, debug});
    this.sys_handlers = sys_handlers;
    this.sys_entries = sys_entries;
    /** @type {?WebAssembly.Instance} */
    this.instance_ = null;
    /** @type {?function(number)} Callback when the process finishes. */
    this.process_finish_ = null;

    sys_handlers.forEach((ele) => ele.setProcess(this));
    sys_entries.forEach((ele) => ele.setProcess(this));
  }

  async run() {
    const program = new Program(this.executable);
    this.instance_ = await program.instantiate(this.getImports_());
    return new Promise(async (resolve) => {
      this.process_finish_ = resolve;
      try {
        const ret = await program.run();
        resolve(ret);
      } catch (e) {
        if (e instanceof WebAssembly.RuntimeError) {
          if (e.message === 'unreachable') {
            // This shows up with abort() & exit() calls.  If this was an exit,
            // then exit status should be set (via the exit syscall).
            if (this.exit_status === null) {
              this.abort();
            }
            return;
          }

          // Not sure how else this would show up.  Fallthru.
        }
        throw e;
      }
    });
  }

  /**
   * @param {number} status
   * @override
   */
  onExit(status) {
    if (this.process_finish_) {
      this.process_finish_(status);
      this.process_finish_ = null;
    }
  }

  /** @override */
  onAbort() {
    if (this.process_finish_) {
      // Emulate common shell behavior where the exit code is 128+signum.
      // If we ever switch to more fine-grained POSIX "is signalled" values,
      // we can convert this over.
      this.process_finish_(134);
      this.process_finish_ = null;
    }
  }

  /**
   * Return an imports object suitable for a new WASM instance.
   *
   * @return {!Object}
   */
  getImports_() {
    return this.sys_entries.reduce((ret, sys_entry) => {
      return Object.assign(ret, sys_entry.getImports());
    }, {});
  }

  /**
   * @param {number} base
   * @param {number=} end
   * @return {!Uint8Array}
   * @override
   */
  getMem(base, end = undefined) {
    return new Uint8Array(this.instance_.exports.memory.buffer)
        .subarray(base, end);
  }

  /**
   * @param {number} base
   * @param {number=} length
   * @return {!WasiView}
   * @override
   * @suppress {checkTypes} WasiView$$module$js$dataview naming confusion.
   */
  getView(base, length = undefined) {
    return new WasiView(this.instance_.exports.memory.buffer, base, length);
  }
}

/**
 * A process that runs in a web worker.
 *
 * This will take care of creating the web worker, managing its communication,
 * and its lifecycle.  You need to provide the script that runs in the new
 * worker and implements the worker.js APIs.
 *
 * @unrestricted https://github.com/google/closure-compiler/issues/1737
 */
class Background extends Base$3 {
  /**
   * @param {string} workerUri
   * @param {{
   *   executable: string,
   *   argv: !Array<string>,
   *   environ: !Object<string, string>,
   *   handler: !SyscallHandler,
   *   sabSize: number,
   * }} param1
   */
  constructor(workerUri, {
    executable, argv, environ, handler,
    sabSize = 64 * 1024,
  }) {
    super({executable, argv, environ});

    this.resolve_ = null;
    this.workerUri = workerUri;
    this.worker = null;
    this.handler = handler;
    this.sab = new SharedArrayBuffer(sabSize);
    this.lock = new SyscallLock(this.sab);

    handler.setProcess(this);
  }

  onMessageError(e) {
    this.logError('>>>main onMessageError', e);
  }

  onError(e) {
    this.logError('terminating process due to runtime error:', e);
    this.terminate({message: e.toString()});
  }

  /**
   * @param {string} name
   * @param {...number|string|!Object} args Arguments that can be serialized.
   */
  postMessage(name, ...args) {
    this.debug(`main>>> postMessage ${name}`, args);
    this.worker.postMessage({name, argv: args});
  }

  /**
   * Handle an incoming messsage.
   *
   * The message must have a registered handler (see onMessage_*).
   *
   * @param {!MessageEvent} e The message sent to us.
   */
  async onMessage(e) {
    /**
     * @type {{
     *   name: string,
     *   argv: !Array<*>,
     * }}
     */
    const data = e.data;
    this.debug('>>>main onMessage', data);

    const {name, argv} = data;

    const method = `onMessage_${name}`;
    if (method in this) {
      try {
        await this[method].apply(this, argv);
      } catch (e) {
        this.onError(`Error while handling ${name}: ${e}\n${e.stack}`);
      }
    } else {
      this.onError(`Unknown message "${name}"`);
    }
  }

  /**
   * @param {string} syscall
   * @param {...!Array<*>} args
   */
  async onMessage_syscall(syscall, ...args) {
    const method = `handle_${syscall}`;
    let ret = ENOSYS;
    if (method in this.handler) {
      ret = await this.handler[method].apply(this.handler, args);
      if (typeof ret !== 'number') {
        this.lock.setData(ret);
        ret = -1;
      }
    }
    this.lock.setRetcode(ret);
    this.lock.unlock();
  }

  /**
   * @param {number} status
   */
  onMessage_exit(status) {
    this.terminate(new CompletedProcessError({status}));
  }

  /**
   * @param {number} signal
   */
  onMessage_signal(signal) {
    this.terminate(new CompletedProcessError({signal}));
  }

  onMessage_error(message) {
    this.logError('terminating process due to worker error:', message);
    this.terminate(new CompletedProcessError({message}));
  }

  terminate(reason) {
    if (this.resolve_) {
      this.resolve_(reason);
      this.resolve_ = null;
    }
    this.worker.terminate();
  }

  async run() {
    const w = new Worker(this.workerUri, {type: 'module'});
    this.worker = w;
    w.addEventListener(
        'message', /** @type {!EventListener} */ (this.onMessage.bind(this)));
    w.addEventListener('messageerror', this.onMessageError.bind(this));
    w.addEventListener('error', this.onError.bind(this));
    this.postMessage('run', this.executable, this.argv, this.environ, this.sab,
                     this.handler.getHandlers_());

    // Return a promise that resolves when we terminate.
    return new Promise((resolve) => {
      this.resolve_ = resolve;
    });
  }
}

const process = /*#__PURE__*/Object.freeze({
__proto__: null,
Foreground: Foreground,
Background: Background
});

// Copyright 2020 The ChromiumOS Authors

/**
 * While the runtime has a Function builtin, there isn't one for async.
 */
const AsyncFunction = (async () => {}).constructor;

/**
 * Base class for creating syscall entries.
 *
 * @unrestricted https://github.com/google/closure-compiler/issues/1737
 * @extends {SyscallEntry}
 * @abstract
 */
class Base$2 {
  /**
   * @param {{
   *   sys_handlers: (!Array<!Object>|undefined),
   *   process: !Process,
   *   trace: (boolean|undefined),
   *   debug: (boolean|undefined),
   * }} options
   */
  constructor({sys_handlers, process, trace, debug}) {
    this.enableTrace_ = trace;
    this.enableDebug_ = debug;
    this.process_ = process;
    this.bindHandlers_(sys_handlers);
    /** @type {string} */
    this.namespace = '';
  }

  /**
   * @param {!Process} process
   * @override
   */
  setProcess(process) {
    this.process_ = process;
  }

  /**
   * @param {!WASI_t.pointer} base
   * @param {!WASI_t.pointer=} end
   * @return {!Uint8Array}
   */
  getMem_(base, end = undefined) {
    return this.process_.getMem(base, end);
  }

  /**
   * @param {!WASI_t.pointer} base
   * @param {!WASI_t.u32=} offset
   * @return {!WasiView}
   * @suppress {checkTypes} WasiView$$module$js$dataview naming confusion.
   */
  getView_(base, offset = undefined) {
    return this.process_.getView(base, offset);
  }

  /**
   * Log a debug message.
   *
   * @param {...*} args The message to log.
   */
  debug(...args) {
    if (!this.enableDebug_) {
      return;
    }

    this.process_.debug(...args);
  }

  /**
   * Start a group of log messages.
   *
   * @param {...*} args The header message to log.
   */
  logGroup(...args) {
    this.process_.logGroup(...args);
  }

  /**
   * Log an error message.
   *
   * @param {...*} args The message to log.
   */
  logError(...args) {
    this.process_.logError(...args);
  }

  /**
   * @param {function(*): !WASI_t.errno} func
   * @param {string} prefix
   * @param {...} args
   * @return {!WASI_t.errno}
   */
  traceCall(func, prefix, ...args) {
    this.logGroup(`${prefix}(${args.join(', ')})`);
    const ret = func(...args);
    if (typeof ret === 'number') {
      let style;
      switch (ret) {
        case ESUCCESS:
          style = '';
          break;
        case ENOSYS:
          style = 'font-weight: bold; color: #fc036f';
          break;
        default:
          style = 'color: #d44';
          break;
      }
      this.debug(`${prefix} -> %c${strerror(ret)}`, style);
    } else {
      this.debug(`${prefix} ->`, ret);
    }
    console.groupEnd();
    return ret;
  }

  /**
   * @param {function(*)} func
   * @param {string} prefix
   * @return {function(*)}
   */
  createTracer_(func, prefix) {
    if (this.enableTrace_) {
      return this.traceCall.bind(this, func, prefix);
    } else {
      return func;
    }
  }

  /**
   * A stub func that always returns ENOSYS.
   *
   * @return {number} ENOSYS.
   */
  enosysStub_() {
    return ENOSYS;
  }

  /**
   * @param {!Function} func
   * @param {...*} args
   * @return {*}
   */
  unhandledExceptionWrapper_(func, ...args) {
    try {
      return func(...args);
    } catch (e) {
      if (e instanceof CompletedProcessError) {
        return e;
      }
      this.logError(`Error: ${func?.name}(${args}): ${e}\n${e.stack}`);
      return ENOTRECOVERABLE;
    }
  }

  /**
   * Bind handlers to this object.
   *
   * This will populate this instance with "handle_xxx" methods for each
   * syscall.  If the |handlers| provide a relevant implementation, we'll use
   * it, otherwise we'll fallback to a stub that returns ENOSYS.
   *
   * @param {!Array<!Object>=} handlers Array of SyscallHandler objects.
   */
  bindHandlers_(handlers = []) {
    if (!Array.isArray(handlers)) {
      handlers = [handlers];
    }

    this.getSyscalls_().forEach((key) => {
      const method = `handle_${key.slice(4)}`;
      let i;
      for (i = 0; i < handlers.length; ++i) {
        const handler = handlers[i];
        if (method in handler) {
          if (handler[method] instanceof AsyncFunction &&
              !(this[key] instanceof AsyncFunction)) {
            throw new ApiViolation(
                `async ${method} requires async ${key}`);
          }
          this[method] = this.createTracer_(
              handler[method].bind(handler), `handler: ${method}`);
          break;
        }
      }
      if (i == handlers.length) {
        this[method] = this.createTracer_(
            this.enosysStub_, `handler: enosysStub_: ${method}`);
      }
    });
  }

  /**
   * Get list of all registered syscall entries.
   *
   * @return {!Array<string>}
   */
  getSyscalls_() {
    return Array.from(getAllPropertyNames(this))
      .filter((/** @type {string} */ key) => key.startsWith('sys_'));
  }

  /**
   * @return {!Object<string, !Array<string>>}
   * @override
   */
  getImports() {
    const entries = {};
    this.getSyscalls_().forEach((key) => {
      let func = this.createTracer_(
          this.unhandledExceptionWrapper_.bind(this, this[key].bind(this)),
          `entry: ${key}`);
      if (this[key] instanceof AsyncFunction) {
        func = new WebAssembly.Suspending(func);
      }
      entries[key.slice(4)] = func;
    });
    return {[this.namespace]: entries};
  }
}

/**
 * WASI syscall entries.
 */
class WasiPreview1 extends Base$2 {
  constructor(...args) {
    super(...args);
    this.namespace = 'wasi_snapshot_preview1';
  }

  /**
   * @param {!WASI_t.pointer} ptr
   * @param {!WASI_t.u32} len
   * @return {?string|number}
   */
  get_nullable_path_(ptr, len) {
    let ret = null;
    if (ptr) {
      const td = new TextDecoder();
      const buf = this.getMem_(ptr, ptr + len);
      try {
        ret = td.decode(buf);
      } catch (e) {
        return EFAULT;
      }
    }
    return ret;
  }

  /**
   * @param {!WASI_t.pointer} argv
   * @param {!WASI_t.pointer} argv_buf
   * @return {!WASI_t.errno}
   * @override
   */
  sys_args_get(argv, argv_buf) {
    const ret = this.handle_args_get();
    if (typeof ret === 'number') {
      return ret;
    }

    const te = new TextEncoder();
    const dvArgv = this.getView_(argv, 4 * ret.argv.length);
    let ptr = argv_buf;
    for (let i = 0; i < ret.argv.length; ++i) {
      const buf = this.getMem_(ptr);
      dvArgv.setUint32(i * 4, ptr, true);
      let length;
      const arg = ret.argv[i];
      if (typeof arg === 'string') {
        length = encodeIntoSab(te, arg, buf);
      } else {
        buf.set(arg);
        length = arg.length;
      }
      buf[length] = 0;
      ptr += length + 1;
    }
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.pointer} argc
   * @param {!WASI_t.pointer} argv_size
   * @return {!WASI_t.errno}
   * @override
   */
  sys_args_sizes_get(argc, argv_size) {
    const ret = this.handle_args_sizes_get();
    if (typeof ret === 'number') {
      return ret;
    }

    const dvSize = this.getView_(argc, 4);
    const dvBuf = this.getView_(argv_size, 4);
    dvSize.setUint32(0, ret.argc, true);
    dvBuf.setUint32(0, ret.argv_size, true);
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.clockid} clockid
   * @param {!WASI_t.pointer} resolution_ptr
   * @return {!WASI_t.errno}
   * @override
   */
  sys_clock_res_get(clockid, resolution_ptr) {
    const ret = this.handle_clock_res_get(clockid);
    if (typeof ret === 'number') {
      return ret;
    }

    const dv = this.getView_(resolution_ptr, 8);
    dv.setBigUint64(0, ret.res, true);
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.clockid} clockid
   * @param {!WASI_t.timestamp} precision
   * @param {!WASI_t.pointer} time_ptr
   * @return {!WASI_t.errno}
   * @override
   */
  sys_clock_time_get(clockid, precision, time_ptr) {
    // TODO: Figure out what to do with precision.
    const ret = this.handle_clock_time_get(clockid);
    if (typeof ret === 'number') {
      return ret;
    }

    const dv = this.getView_(time_ptr, 8);
    dv.setBigUint64(0, ret.now, true);
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.pointer} envp
   * @param {!WASI_t.pointer} env_buf
   * @return {!WASI_t.errno}
   * @override
   */
  sys_environ_get(envp, env_buf) {
    const ret = this.handle_environ_get();
    if (typeof ret === 'number') {
      return ret;
    }

    const te = new TextEncoder();
    const env = ret.env;
    const dvEnvp = this.getView_(envp, 4 * (env.length + 1));
    let ptr = env_buf;
    for (let i = 0; i < env.length; ++i) {
      const buf = this.getMem_(ptr);
      dvEnvp.setUint32(i * 4, ptr, true);
      let length;
      const arg = env[i];
      if (typeof arg === 'string') {
        length = encodeIntoSab(te, arg, buf);
      } else {
        buf.set(arg);
        length = arg.length;
      }
      buf[length] = 0;
      ptr += length + 1;
    }
    // The NULL terminator.
    dvEnvp.setUint32(4 * env.length, 0, true);
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.pointer} env_size
   * @param {!WASI_t.pointer} env_buf
   * @return {!WASI_t.errno}
   * @override
   */
  sys_environ_sizes_get(env_size, env_buf) {
    const ret = this.handle_environ_sizes_get();
    if (typeof ret === 'number') {
      return ret;
    }

    const dvSize = this.getView_(env_size, 4);
    const dvBuf = this.getView_(env_buf, 4);
    // Include one extra for NULL terminator.
    // TODO(vapier): Is this necessary ?
    dvSize.setUint32(0, ret.length + 1, true);
    dvBuf.setUint32(0, ret.size, true);
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.filesize} offset
   * @param {!WASI_t.filesize} len
   * @param {!WASI_t.advice} advice
   * @return {!WASI_t.errno}
   * @override
   */
  sys_fd_advise(fd, offset, len, advice) {
    return this.handle_fd_advise(fd, offset, len, advice);
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.filesize} offset
   * @param {!WASI_t.filesize} len
   * @return {!WASI_t.errno}
   * @override
   */
  sys_fd_allocate(fd, offset, len) {
    return this.handle_fd_allocate(fd, offset, len);
  }

  /**
   * @param {!WASI_t.fd} fd
   * @return {!WASI_t.errno}
   * @override
   */
  sys_fd_close(fd) {
    return this.handle_fd_close(fd);
  }

  /**
   * @param {!WASI_t.fd} fd
   * @return {!WASI_t.errno}
   * @override
   */
  sys_fd_datasync(fd) {
    return this.handle_fd_datasync(fd);
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.pointer} buf
   * @return {!WASI_t.errno}
   * @override
   */
  sys_fd_fdstat_get(fd, buf) {
    const ret = this.handle_fd_fdstat_get(fd);
    if (typeof ret === 'number') {
      return ret;
    }

    const dv = this.getView_(buf);
    dv.setFdstat(0, ret, true);
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.fdflags} fdflags
   * @return {!WASI_t.errno}
   * @override
   */
  sys_fd_fdstat_set_flags(fd, fdflags) {
    return this.handle_fd_fdstat_set_flags(fd, fdflags);
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.rights} fs_rights_base
   * @param {!WASI_t.rights} fs_rights_inheriting
   * @return {!WASI_t.errno}
   * @override
   */
  sys_fd_fdstat_set_rights(fd, fs_rights_base, fs_rights_inheriting) {
    return this.handle_fd_fdstat_set_rights(
        fd, fs_rights_base, fs_rights_inheriting);
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.pointer} filestat_ptr
   * @return {!WASI_t.errno}
   * @override
   */
  sys_fd_filestat_get(fd, filestat_ptr) {
    const ret = this.handle_fd_filestat_get(fd);
    if (typeof ret === 'number') {
      return ret;
    }

    const dv = this.getView_(filestat_ptr);
    dv.setFilestat(0, ret, true);
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.filesize} size
   * @return {!WASI_t.errno}
   * @override
   */
  sys_fd_filestat_set_size(fd, size) {
    return this.handle_fd_filestat_set_size(fd, size);
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.timestamp} atim
   * @param {!WASI_t.timestamp} mtim
   * @param {!WASI_t.fstflags} fst_flags
   * @return {!WASI_t.errno}
   * @override
   */
  sys_fd_filestat_set_times(fd, atim, mtim, fst_flags) {
    return this.handle_fd_filestat_set_times(fd, atim, mtim, fst_flags);
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.pointer} iovs_ptr
   * @param {!WASI_t.size} iovs_len
   * @param {!WASI_t.filesize} offset
   * @param {!WASI_t.pointer} nread_ptr
   * @return {!WASI_t.errno}
   * @override
   */
  sys_fd_pread(fd, iovs_ptr, iovs_len, offset, nread_ptr) {
    const dvIovs = this.getView_(iovs_ptr);
    let nread = 0;
    let iovs_off = 0;
    for (let i = 0; i < iovs_len; ++i) {
      const iovec = dvIovs.getIovec(iovs_off, true);
      const buf = this.getMem_(iovec.buf, iovec.buf + iovec.buf_len);
      const ret = this.handle_fd_pread(fd, iovec.buf_len, offset);
      if (typeof ret === 'number') {
        if (ret === ESUCCESS) {
          nread += iovec.buf_len;
        } else {
          return ret;
        }
      } else {
        if (ret.buf !== undefined) {
          const u8 = new Uint8Array(ret.buf);
          buf.set(u8);
          if (ret.nread === undefined) {
            ret.nread = u8.length;
          }
        }
        nread += ret.nread;
      }
      offset += BigInt(nread);
      iovs_off += iovec.struct_size;
    }

    const dvNread = this.getView_(nread_ptr, 4);
    dvNread.setUint32(0, nread, true);
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.pointer} path_ptr
   * @param {!WASI_t.size} path_len
   * @return {!WASI_t.errno}
   * @override
   */
  sys_fd_prestat_dir_name(fd, path_ptr, path_len) {
    const ret = this.handle_fd_prestat_dir_name(fd);
    if (typeof ret === 'number') {
      return ret;
    }

    const buf = this.getMem_(path_ptr, path_ptr + path_len);
    const te = new TextEncoder();
    encodeIntoSab(te, ret.path, buf);
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.pointer} buf
   * @return {!WASI_t.errno}
   * @override
   */
  sys_fd_prestat_get(fd, buf) {
    const ret = this.handle_fd_prestat_get(fd);
    if (typeof ret === 'number') {
      return ret;
    }

    const dv = this.getView_(buf, 8);
    dv.setUint8(0, 0 /* __WASI_PREOPENTYPE_DIR */);

    const te = new TextEncoder();
    dv.setUint32(4, te.encode(ret.path).length, true);
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.pointer} iovs_ptr
   * @param {!WASI_t.size} iovs_len
   * @param {!WASI_t.filesize} offset
   * @param {!WASI_t.pointer} nwritten_ptr
   * @return {!WASI_t.errno}
   * @override
   */
  sys_fd_pwrite(fd, iovs_ptr, iovs_len, offset, nwritten_ptr) {
    const dvIovs = this.getView_(iovs_ptr);
    let nwritten = 0;
    let iovs_off = 0;
    for (let i = 0; i < iovs_len; ++i) {
      const iovec = dvIovs.getIovec(iovs_off, true);
      const buf = this.getMem_(iovec.buf, iovec.buf + iovec.buf_len);
      const ret = this.handle_fd_pwrite(fd, Uint8Array.from(buf), offset);
      if (typeof ret === 'number') {
        if (ret === ESUCCESS) {
          nwritten += iovec.buf_len;
        } else {
          return ret;
        }
      } else {
        nwritten += ret.nwritten;
      }
      offset += BigInt(nwritten);
      iovs_off += iovec.struct_size;
    }

    const dvWritten = this.getView_(nwritten_ptr, 4);
    dvWritten.setUint32(0, nwritten, true);
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.pointer} iovs_ptr
   * @param {!WASI_t.size} iovs_len
   * @param {!WASI_t.pointer} nread_ptr
   * @return {!WASI_t.errno}
   * @override
   */
  sys_fd_read(fd, iovs_ptr, iovs_len, nread_ptr) {
    const dvIovs = this.getView_(iovs_ptr);
    let nread = 0;
    let iovs_off = 0;
    for (let i = 0; i < iovs_len; ++i) {
      const iovec = dvIovs.getIovec(iovs_off, true);
      const buf = this.getMem_(iovec.buf, iovec.buf + iovec.buf_len);
      const ret = this.handle_fd_read(fd, iovec.buf_len);
      if (typeof ret === 'number') {
        if (ret === ESUCCESS) {
          nread += iovec.buf_len;
        } else {
          return ret;
        }
      } else {
        if (ret.buf !== undefined) {
          const u8 = new Uint8Array(ret.buf);
          if (u8.length > iovec.buf_len) {
            this.logError('handle_fd_read returned too many bytes: ' +
                          `${u8.length} > ${iovec.buf_len}`);
          }
          buf.set(u8);
          if (ret.nread === undefined) {
            ret.nread = u8.length;
          }
        }
        nread += ret.nread;
      }
      iovs_off += iovec.struct_size;
    }

    const dvNread = this.getView_(nread_ptr, 4);
    dvNread.setUint32(0, nread, true);
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.pointer} buf_ptr
   * @param {!WASI_t.size} buf_len
   * @param {!WASI_t.dircookie} cookie
   * @param {!WASI_t.pointer} size_ptr
   * @return {!WASI_t.errno}
   * @override
   */
  sys_fd_readdir(fd, buf_ptr, buf_len, cookie, size_ptr) {
    const buf = this.getMem_(buf_ptr, buf_ptr + buf_len);
    const ret = this.handle_fd_readdir(fd, buf, cookie);
    if (typeof ret === 'number') {
      return ret;
    }

    const dv = this.getView_(size_ptr);
    dv.setUint32(0, ret.length, true);
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.fd} to
   * @return {!WASI_t.errno}
   * @override
   */
  sys_fd_renumber(fd, to) {
    return this.handle_fd_renumber(fd, to);
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.filedelta} offset
   * @param {!WASI_t.whence} whence
   * @param {!WASI_t.pointer} newoffset_ptr
   * @return {!WASI_t.errno}
   * @override
   */
  sys_fd_seek(fd, offset, whence, newoffset_ptr) {
    if (whence < 0 || whence > 2) {
      return EINVAL;
    }

    const ret = this.handle_fd_seek(fd, offset, whence);
    if (typeof ret === 'number') {
      return ret;
    }

    const dv = this.getView_(newoffset_ptr, 8);
    dv.setBigUint64(0, ret.newoffset, true);
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.fd} fd
   * @return {!WASI_t.errno}
   * @override
   */
  sys_fd_sync(fd) {
    return this.handle_fd_sync(fd);
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.pointer} offset_ptr
   * @return {!WASI_t.errno}
   * @override
   */
  sys_fd_tell(fd, offset_ptr) {
    const ret = this.handle_fd_tell(fd);
    if (typeof ret === 'number') {
      return ret;
    }

    const dv = this.getView_(offset_ptr, 8);
    dv.setBigUint64(0, ret.offset, true);
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.pointer} iovs_ptr
   * @param {!WASI_t.size} iovs_len
   * @param {!WASI_t.pointer} nwritten_ptr
   * @return {!WASI_t.errno}
   * @override
   */
  sys_fd_write(fd, iovs_ptr, iovs_len, nwritten_ptr) {
    const dvIovs = this.getView_(iovs_ptr);
    let nwritten = 0;
    let iovs_off = 0;
    for (let i = 0; i < iovs_len; ++i) {
      const iovec = dvIovs.getIovec(iovs_off, true);
      const buf = this.getMem_(iovec.buf, iovec.buf + iovec.buf_len);
      const ret = this.handle_fd_write(fd, Uint8Array.from(buf));
      if (typeof ret === 'number') {
        if (ret === ESUCCESS) {
          nwritten += iovec.buf_len;
        } else {
          return ret;
        }
      } else {
        nwritten += ret.nwritten;
      }
      iovs_off += iovec.struct_size;
    }

    const dvWritten = this.getView_(nwritten_ptr, 4);
    dvWritten.setUint32(0, nwritten, true);
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.pointer} path_ptr
   * @param {!WASI_t.size} path_len
   * @return {!WASI_t.errno}
   * @override
   */
  sys_path_create_directory(fd, path_ptr, path_len) {
    const path = this.get_nullable_path_(path_ptr, path_len);
    if (typeof path === 'number') {
      return path;
    }

    return this.handle_path_create_directory(fd, path);
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.lookupflags} lookupflags
   * @param {!WASI_t.pointer} path_ptr
   * @param {!WASI_t.size} path_len
   * @param {!WASI_t.pointer} filestat_ptr
   * @return {!WASI_t.errno}
   * @override
   */
  sys_path_filestat_get(fd, lookupflags, path_ptr, path_len, filestat_ptr) {
    const path = this.get_nullable_path_(path_ptr, path_len);
    if (typeof path === 'number') {
      return path;
    }

    const ret = this.handle_path_filestat_get(fd, lookupflags, path);
    if (typeof ret === 'number') {
      return ret;
    }

    const dv = this.getView_(filestat_ptr);
    dv.setFilestat(0, ret, true);
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.lookupflags} flags
   * @param {!WASI_t.pointer} path_ptr
   * @param {!WASI_t.size} path_len
   * @param {!WASI_t.timestamp} atim
   * @param {!WASI_t.timestamp} mtim
   * @param {!WASI_t.fstflags} fst_flags
   * @return {!WASI_t.errno}
   * @override
   */
  sys_path_filestat_set_times(fd, flags, path_ptr, path_len, atim, mtim,
                              fst_flags) {
    const path = this.get_nullable_path_(path_ptr, path_len);
    if (typeof path === 'number') {
      return path;
    }

    return this.handle_path_filestat_set_times(
        fd, flags, path, atim, mtim, fst_flags);
  }

  /**
   * @param {!WASI_t.fd} old_fd
   * @param {!WASI_t.lookupflags} old_flags
   * @param {!WASI_t.pointer} old_path_ptr
   * @param {!WASI_t.size} old_path_len
   * @param {!WASI_t.fd} new_fd
   * @param {!WASI_t.pointer} new_path_ptr
   * @param {!WASI_t.size} new_path_len
   * @return {!WASI_t.errno}
   * @override
   */
  sys_path_link(old_fd, old_flags, old_path_ptr, old_path_len, new_fd,
                new_path_ptr, new_path_len) {
    const old_path = this.get_nullable_path_(old_path_ptr, old_path_len);
    if (typeof old_path === 'number') {
      return old_path;
    }

    const new_path = this.get_nullable_path_(new_path_ptr, new_path_len);
    if (typeof new_path === 'number') {
      return new_path;
    }

    return this.handle_path_link(old_fd, old_flags, old_path, new_fd, new_path);
  }

  /**
   * @param {!WASI_t.fd} dirfd
   * @param {!WASI_t.lookupflags} dirflags
   * @param {!WASI_t.pointer} path_ptr
   * @param {!WASI_t.size} path_len
   * @param {!WASI_t.oflags} o_flags
   * @param {!WASI_t.rights} fs_rights_base
   * @param {!WASI_t.rights} fs_rights_inheriting
   * @param {!WASI_t.fdflags} fdflags
   * @param {!WASI_t.pointer} fd_ptr
   * @return {!WASI_t.errno}
   * @override
   */
  sys_path_open(dirfd, dirflags, path_ptr, path_len, o_flags, fs_rights_base,
                fs_rights_inheriting, fdflags, fd_ptr) {
    const path = this.get_nullable_path_(path_ptr, path_len);
    if (typeof path === 'number') {
      return path;
    }
    this.debug(`  path = "${path}"`);

    const ret = this.handle_path_open(
        dirfd, dirflags, path, o_flags, fs_rights_base, fs_rights_inheriting,
        fdflags);
    if (typeof ret === 'number') {
      return ret;
    }

    const dv = this.getView_(fd_ptr, 4);
    dv.setUint32(0, ret.fd, true);
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.pointer} path_ptr
   * @param {!WASI_t.size} path_len
   * @param {!WASI_t.pointer} buf_ptr
   * @param {!WASI_t.size} buf_len
   * @param {!WASI_t.pointer} bufused_ptr
   * @return {!WASI_t.errno}
   * @override
   */
  sys_path_readlink(fd, path_ptr, path_len, buf_ptr, buf_len, bufused_ptr) {
    const path = this.get_nullable_path_(path_ptr, path_len);
    if (typeof path === 'number') {
      return path;
    }

    const buf = this.getMem_(buf_ptr, buf_ptr + buf_len);
    const ret = this.handle_path_readlink(fd, path, buf);
    if (typeof ret === 'number') {
      return ret;
    }

    const dv = this.getView_(bufused_ptr);
    dv.setUint32(0, ret.length, true);
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.pointer} path_ptr
   * @param {!WASI_t.size} path_len
   * @return {!WASI_t.errno}
   * @override
   */
  sys_path_remove_directory(fd, path_ptr, path_len) {
    const path = this.get_nullable_path_(path_ptr, path_len);
    if (typeof path === 'number') {
      return path;
    }

    return this.handle_path_remove_directory(fd, path);
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.pointer} old_path_ptr
   * @param {!WASI_t.size} old_path_len
   * @param {!WASI_t.fd} new_fd
   * @param {!WASI_t.pointer} new_path_ptr
   * @param {!WASI_t.size} new_path_len
   * @return {!WASI_t.errno}
   * @override
   */
  sys_path_rename(fd, old_path_ptr, old_path_len, new_fd, new_path_ptr,
                  new_path_len) {
    const old_path = this.get_nullable_path_(old_path_ptr, old_path_len);
    if (typeof old_path === 'number') {
      return old_path;
    }

    const new_path = this.get_nullable_path_(new_path_ptr, new_path_len);
    if (typeof new_path === 'number') {
      return new_path;
    }

    return this.handle_path_rename(fd, old_path, new_fd, new_path);
  }

  /**
   * @param {!WASI_t.pointer} old_path_ptr
   * @param {!WASI_t.size} old_path_len
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.pointer} new_path_ptr
   * @param {!WASI_t.size} new_path_len
   * @return {!WASI_t.errno}
   * @override
   */
  sys_path_symlink(old_path_ptr, old_path_len, fd, new_path_ptr, new_path_len) {
    const old_path = this.get_nullable_path_(old_path_ptr, old_path_len);
    if (typeof old_path === 'number') {
      return old_path;
    }

    const new_path = this.get_nullable_path_(new_path_ptr, new_path_len);
    if (typeof new_path === 'number') {
      return new_path;
    }

    return this.handle_path_symlink(old_path, fd, new_path);
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.pointer} path_ptr
   * @param {!WASI_t.size} path_len
   * @return {!WASI_t.errno}
   * @override
   */
  sys_path_unlink_file(fd, path_ptr, path_len) {
    const path = this.get_nullable_path_(path_ptr, path_len);
    if (typeof path === 'number') {
      return path;
    }

    return this.handle_path_unlink_file(fd, path);
  }

  /**
   * @param {!WASI_t.pointer} subscriptions_ptr
   * @param {!WASI_t.pointer} events_ptr
   * @param {!WASI_t.size} nsubscriptions
   * @param {!WASI_t.pointer} nevents_ptr
   * @return {!WASI_t.errno}
   * @override
   */
  sys_poll_oneoff(subscriptions_ptr, events_ptr, nsubscriptions, nevents_ptr) {
    const dvNevents = this.getView_(nevents_ptr);
    if (nsubscriptions <= 0) {
      dvNevents.setUint32(0, 0, true);
      return ESUCCESS;
    }

    const subscriptions = Array(nsubscriptions);
    const dvSubscriptions = this.getView_(subscriptions_ptr);
    let offset = 0;
    for (let i = 0; i < nsubscriptions; ++i) {
      const subscription = dvSubscriptions.getSubscription(offset, true);
      if (subscription.tag > ENUM_END) {
        return EINVAL;
      }
      subscriptions[i] = subscription;
      offset += subscription.struct_size;
    }

    const ret = this.handle_poll_oneoff(subscriptions);
    if (typeof ret === 'number') {
      return ret;
    }

    // TODO(vapier): This call does not belong here.  This should be in wassh.
    // But the current sys_poll_oneoff logic is not factored well for hooking.
    if (ret.signals !== undefined &&
        this.process_.instance_.exports.__wassh_signal_deliver !== undefined) {
      ret.signals.forEach(
          /** @type {{__wassh_signal_deliver: function(number)}} */ (
              this.process_.instance_.exports).__wassh_signal_deliver);
      if (ret.events.length === 0) {
        // If there are no other events, return EINTR so the caller knows that a
        // signal came in.  It should retry the call automatically.
        return EINTR;
      }
    }

    const dvEvents = this.getView_(events_ptr);
    offset = 0;
    ret.events.forEach((event) => {
      dvEvents.setEvent(offset, event, true);
      offset += WasiView.event_t.struct_size;
    });
    dvNevents.setUint32(0, ret.events.length, true);
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.exitcode} status
   * @throws {!util.CompletedProcessError}
   * @override
   */
  sys_proc_exit(status) {
    this.handle_proc_exit(status);

    // Handler shouldn't return, but just in case.
    throw new CompletedProcessError({status});
  }

  /**
   * @param {!WASI_t.signal} signal
   * @throws {!util.CompletedProcessError}
   * @override
   */
  sys_proc_raise(signal) {
    this.handle_proc_raise(signal);

    // Handler shouldn't return, but just in case.
    throw new CompletedProcessError({signal});
  }

  /**
   * @param {!WASI_t.pointer} buf
   * @param {!WASI_t.size} buf_len
   * @return {!WASI_t.errno}
   * @override
   */
  sys_random_get(buf, buf_len) {
    const bytes = this.getMem_(buf, buf + buf_len);
    return this.handle_random_get(bytes);
  }

  /**
   * @return {!WASI_t.errno}
   * @override
   */
  sys_sched_yield() {
    return this.handle_sched_yield();
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.pointer} ri_data_ptr
   * @param {!WASI_t.size} ri_data_len
   * @param {!WASI_t.u16} ri_flags
   * @param {!WASI_t.pointer} ro_datalen_ptr
   * @param {!WASI_t.pointer} ro_flags_ptr
   * @return {!WASI_t.errno}
   * @override
   */
  sys_sock_recv(fd, ri_data_ptr, ri_data_len, ri_flags, ro_datalen_ptr,
                ro_flags_ptr) {
    if (ri_flags !== 0) {
      return ENOTSUP;
    }
    return this.sys_fd_read(fd, ri_data_ptr, ri_data_len, ro_datalen_ptr);
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.pointer} si_data_ptr
   * @param {!WASI_t.size} si_data_len
   * @param {!WASI_t.u16} si_flags
   * @param {!WASI_t.pointer} so_datalen_ptr
   * @return {!WASI_t.errno}
   * @override
   */
  sys_sock_send(fd, si_data_ptr, si_data_len, si_flags, so_datalen_ptr) {
    if (si_flags !== 0) {
      return ENOTSUP;
    }
    return this.sys_fd_write(fd, si_data_ptr, si_data_len, so_datalen_ptr);
  }

  /**
   * @param {!WASI_t.fd} fd
   * @param {!WASI_t.u32} how
   * @return {!WASI_t.errno}
   * @override
   */
  sys_sock_shutdown(fd, how) {
    return this.handle_sock_shutdown(fd, how);
  }
}

const syscall_entry = /*#__PURE__*/Object.freeze({
__proto__: null,
Base: Base$2,
WasiPreview1: WasiPreview1
});

// Copyright 2020 The ChromiumOS Authors

/**
 * Base class for creating syscall handlers.
 *
 * @abstract
 * @extends {SyscallHandler}
 */
class Base$1 {
  constructor() {
    /** @type {?Process} */
    this.process_ = null;
  }

  /**
   * @param {!Process} process
   * @override
   */
  setProcess(process) {
    this.process_ = process;
  }

  debug(...args) {
    this.process_.debug(...args);
  }

  getHandlers_() {
    const gen = getAllPropertyNames(this);
    return new Set(/** @type {!Iterable<string>} */ ({
      [Symbol.iterator]: function* () {
        while (1) {
          const ele = gen.next();
          if (ele.value && ele.value.startsWith('handle_')) {
            yield ele.value;
          }
          if (ele.done) {
            break;
          }
        }
      },
    }));
  }
}

/**
 * This handler dispatches all requests to a worker thread.
 *
 * @unrestricted https://github.com/google/closure-compiler/issues/1737
 */
class ProxyWasiPreview1 extends Base$1 {
  constructor(worker, sab, handlers) {
    super();

    this.worker = worker;
    this.syscallLock = new SyscallLock(sab);

    handlers.forEach((handler) => {
      if (handler.startsWith('handle_') && !(handler in this)) {
        this[handler] = this.dispatch_.bind(this, handler.slice(7));
      }
    });
  }

  dispatch_(...args) {
    if (!this.syscallLock.lock()) {
      throw new Error('Overlapped syscall');
    }
    this.worker.postMessage('syscall', ...args);
    this.syscallLock.wait();
    const ret = this.syscallLock.getRetcode();
    if (ret == -1) {
      return this.syscallLock.getData();
    } else {
      return ret;
    }
  }

  /**
   * @param {!WASI_t.exitcode} status
   * @return {!WASI_t.errno}
   * @override
   */
  handle_proc_exit(status) {
    this.worker.postMessage('exit', status);
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.signal} signal
   * @return {!WASI_t.errno}
   * @override
   */
  handle_proc_raise(signal) {
    this.worker.postMessage('signal', signal);
    return ESUCCESS;
  }
}

/**
 * How many nanoseconds in one millisecond.
 */
const kNanosecToMillisec = 1000000;

/**
 * This handler implements syscalls directly.
 */
class DirectWasiPreview1 extends Base$1 {
  /**
   * @return {!WASI_t.errno|{argv: !Array<string|!ArrayBufferView>}}
   * @override
   */
  handle_args_get() {
    return {argv: this.process_.argv};
  }

  /**
   * @return {!WASI_t.errno|{argc: !WASI_t.size, argv_size: !WASI_t.size}}
   * @override
   */
  handle_args_sizes_get() {
    const te = new TextEncoder();
    const argv = this.process_.argv;
    return {
      argc: argv.length,
      argv_size: argv.reduce((acc, str) => acc + te.encode(str).length + 1, 0),
    };
  }

  /**
   * @param {!WASI_t.clockid} clockid
   * @return {!WASI_t.errno|{res: bigint}}
   * @override
   */
  handle_clock_res_get(clockid) {
    switch (clockid) {
      case REALTIME:
        // JavaScript's Date.now is millisecond resolution.
        // performance.now provides microseconds, but browsers have disabled it
        // due to security concerns.
        return {res: BigInt(kNanosecToMillisec)};
      case MONOTONIC:
        // performance.now is guaranteed to be monotonic and provides
        // microsecond resolution.
        return {res: BigInt(1000)};
      default:
        return EINVAL;
    }
  }

  /**
   * @param {!WASI_t.clockid} clockid
   * @return {!WASI_t.errno|{now: bigint}}
   * @override
   */
  handle_clock_time_get(clockid) {
    switch (clockid) {
      case REALTIME: {
        // Convert milliseconds to nanoseconds.
        return {now: BigInt(Date.now()) * BigInt(kNanosecToMillisec)};
      }
      case MONOTONIC: {
        return {
          now: BigInt(Math.floor(performance.now() * kNanosecToMillisec)),
        };
      }
      default:
        return EINVAL;
    }
  }

  /** @return {!Array<string>} */
  flattenEnviron_() {
    const ret = [];
    Object.entries(this.process_.environ).forEach(
        ([key, val]) => ret.push(`${key}=${val}`));
    return ret;
  }

  /**
   * @return {!WASI_t.errno|{env: !Array<string|!ArrayBufferView>}}
   * @override
   */
  handle_environ_get() {
    return {env: this.flattenEnviron_()};
  }

  /**
   * @return {!WASI_t.errno|{length: !WASI_t.size, size: !WASI_t.size}}
   * @override
   */
  handle_environ_sizes_get() {
    const te = new TextEncoder();
    const env = this.flattenEnviron_();
    return {
      length: env.length,
      size: env.reduce((acc, str) => acc + te.encode(str).length + 1, 0),
    };
  }

  /**
   * @param {!WASI_t.fd} fd
   * @return {!WASI_t.errno}
   * @override
   */
  handle_fd_datasync(fd) {
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.fd} fd
   * @return {!WASI_t.errno}
   * @override
   */
  handle_fd_sync(fd) {
    return ESUCCESS;
  }

  /**
   * @param {!WASI_t.exitcode} status
   * @throws {!util.CompletedProcessError}
   * @override
   */
  handle_proc_exit(status) {
    this.process_.exit(status);
    throw new CompletedProcessError({status});
  }

  /**
   * @param {!Array<!WASI_t.subscription>} subscriptions
   * @return {!WASI_t.errno|
   *          {events: !Array<!WASI_t.event>,
   *           signals: (undefined|!Array<number>)}}
   * @override
   */
  handle_poll_oneoff(subscriptions) {
    // We can handle clock events only.
    const events = [];
    const now = BigInt(Date.now());

    // Find the earliest clock timeout.
    let timeout;
    let userdata;
    subscriptions.forEach((subscription) => {
      if (subscription.tag === CLOCK) {
        // The standard C lib doesn't use other clocks, so this is future-proof.
        if (subscription.clock.id !== REALTIME) {
          return ENOTSUP;
        }

        let subTimeout;
        // The timeout is in nanoseconds.  We can do milliseconds at best.
        subTimeout = subscription.clock.timeout / BigInt(kNanosecToMillisec);
        if ((subscription.clock.flags & 1) === 0) {
          // The timeout is relative.
          subTimeout += now;
        }

        if (!timeout || subTimeout < timeout) {
          userdata = subscription.userdata;
          timeout = subTimeout;
        }
      }
    });

    // If there's a timeout, wait for it.
    if (timeout !== undefined) {
      events.push(/** @type {!WASI_t.event} */({
        userdata: userdata,
        error: ESUCCESS,
        type: CLOCK,
        fd_readwrite: {
          flags: 0,
          nbytes: 0n,
        },
      }));
    } else {
      // If we found no clock events, but there are other events, then fail.
      if (subscriptions.length) {
        return ENOTSUP;
      }
    }

    return {events};
  }

  /**
   * @param {!WASI_t.signal} signal
   * @throws {!util.CompletedProcessError}
   * @override
   */
  handle_proc_raise(signal) {
    throw new CompletedProcessError({signal});
  }

  /**
   * @param {!Uint8Array|!ArrayBuffer|!SharedArrayBuffer} buf
   * @return {!WASI_t.errno}
   * @override
   */
  handle_random_get(buf) {
    // The crypto calls cannot operate on shared memory, so an additional copy
    // to a non-shared type is required. Other types of syscall will be able to
    // operate directly on the memory supplied.
    // https://github.com/w3c/webcrypto/issues/213
    if (ArrayBuffer.isView(buf) && buf.buffer instanceof SharedArrayBuffer) {
      const temp = new Uint8Array(buf.length);
      crypto.getRandomValues(temp);
      buf.set(temp);
    } else if (buf instanceof SharedArrayBuffer) {
      const u8 = new Uint8Array(buf);
      const temp = new Uint8Array(u8.length);
      crypto.getRandomValues(temp);
      u8.set(temp);
    } else {
      const temp = buf instanceof ArrayBuffer ? new Uint8Array(buf) : buf;
      crypto.getRandomValues(temp);
    }
    return ESUCCESS;
  }

  /**
   * @return {!WASI_t.errno}
   * @override
   */
  handle_sched_yield() {
    return ESUCCESS;
  }
}

const syscall_handler = /*#__PURE__*/Object.freeze({
__proto__: null,
Base: Base$1,
ProxyWasiPreview1: ProxyWasiPreview1,
DirectWasiPreview1: DirectWasiPreview1
});

// Copyright 2020 The ChromiumOS Authors

/**
 * Base class for creating your own background worker.
 *
 * You most likely only want to implement newProcess.
 *
 * @unrestricted https://github.com/google/closure-compiler/issues/1737
 */
class Base {
  /**
   * @param {!Worker} worker The WebWorker to bind to.
   * @param {{
   *   debug: (boolean|undefined),
   * }=} options
   */
  constructor(worker, {debug} = {}) {
    this.worker = worker;
    this.enableDebug_ = debug;
  }

  /**
   * Create a new process!
   *
   * @param {string} executable The path to the WASM program.
   * @param {!Array<string>} argv The program's command line opts.
   * @param {!Object<string, string>} environ The program's environment.
   * @param {!SharedArrayBuffer=} sab The shared array buffer memory.
   * @param {*=} handler_ids
   * @return {!Process.Foreground} The new process.
   */
  newProcess(executable, argv, environ, sab = undefined,
             handler_ids = undefined) {
    const sys_handlers = [];
    const sys_entries = [];
    return new Foreground(
        {executable, argv, environ, sys_handlers, sys_entries});
  }

  /**
   * Bind to the worker for handling incoming messages.
   */
  bind() {
    // Save a ref for console debugging.
    globalThis['wassh_worker_'] = this;
    this.worker.addEventListener(
        'message', /** @type {!EventListener} */ (this.onMessage.bind(this)));
  }

  /**
   * Log a debug message.
   *
   * @param {...*} args The message to log.
   */
  debug(...args) {
    if (!this.enableDebug_) {
      return;
    }

    console.debug(...args);
  }

  /**
   * Send an error message.
   *
   * @param {...*} args The message to log.
   */
  postError(...args) {
    this.debug('worker>>> error', args);
    postMessage({name: 'error', argv: args});
  }

  /**
   * Send a normal message.
   *
   * @param {string} name The message identifier.
   * @param {...*} args The message to log.
   */
  postMessage(name, ...args) {
    this.debug(`worker>>> postMessage ${name}`, args);
    this.worker.postMessage({name, argv: args});
  }

  /**
   * Handle an incoming messsage.
   *
   * The message must have a registered handler (see onMessage_*).
   *
   * @param {!MessageEvent} e The message sent to us.
   */
  async onMessage(e) {
    /**
     * @type {{
     *   name: string,
     *   argv: !Array<*>,
     * }}
     */
    const data = e.data;
    this.debug('>>>worker onMessage', data);

    const {name, argv} = data;

    const method = `onMessage_${name}`;
    if (method in this) {
      try {
        await this[method].apply(this, argv);
      } catch (e) {
        this.postError(`Error while handling ${name}: ${e}`, e);
      }
    } else {
      this.postError(`Unknown message "${name}"`);
    }
  }

  /**
   * Create & run the program.
   *
   * @param {string} executable The path to the WASM program.
   * @param {!Array<string>} argv The program's command line opts.
   * @param {!Object<string, string>} environ The program's environment.
   * @param {!SharedArrayBuffer} sab The shared array buffer memory.
   * @param {...*} handlers
   */
  async onMessage_run(executable, argv, environ, sab, handlers) {
    const proc = this.newProcess(executable, argv, environ, sab, handlers);
    const ret = await proc.run();
    this.postMessage('exit', ret);
  }
}

const worker = /*#__PURE__*/Object.freeze({
__proto__: null,
Base: Base
});

export { worker as BackgroundWorker, process as Process, syscall_entry as SyscallEntry, syscall_handler as SyscallHandler, wasi as WASI, WasiView, util };
