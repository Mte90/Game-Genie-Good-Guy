#!/usr/bin/python3
from PyQt5.QtCore import QSettings, QProcess
from PyQt5.QtWidgets import QMainWindow, QFileDialog, QApplication
import sys, signal, os

from window import Ui_MainWindow


class MainWindow (QMainWindow, Ui_MainWindow):

    # Create settings for the software
    settings = QSettings('GGGG', 'Game Genie Good Guy')
    settings.setFallbacksEnabled(False)
    version = '1.0.0'

    def __init__(self, parent=None):
        QMainWindow.__init__(self, parent)
        # Load the ui
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        # Set the MainWindow Title
        self.setWindowTitle('Game Genie Good Guy - ' + self.version)
        # When the software are closed on console the software are closed
        signal.signal(signal.SIGINT, signal.SIG_DFL)
        self.ui.system.addItem("Game Boy/Gear/Master System")
        self.ui.system.addItem("Genesis/Mega Drive (no SMD roms)")
        self.ui.system.addItem("Nintendo")
        self.ui.system.addItem("Super Nintendo")
        self.ui.browse.clicked.connect(self.browse)
        self.ui.patch.clicked.connect(self.generateRom)
        self.ui.ips.clicked.connect(self.generateIPS)
        self.ui.log.setReadOnly(True)
        self.process = QProcess()
        self.process.readyReadStandardOutput.connect(self.printLog)
        if self.settings.value("rom"):
            self.ui.rom.setText(self.settings.value("rom"))
        if self.settings.value("system"):
            self.ui.system.setCurrentIndex(int(self.settings.value("system")))
        # Show the form
        self.show()

    def browse(self):
        options = QFileDialog.Options()
        options |= QFileDialog.DontUseNativeDialog
        fileName, _ = QFileDialog.getOpenFileName(self, "QFileDialog.getOpenFileName()", "", "All Files (*);;", options=options)
        self.ui.rom.setText(str(fileName))
        self.settings.setValue("rom", str(fileName))

    def printLog(self):
        self.ui.log.clear()
        result = self.process.readAllStandardOutput().data().decode()
        self.ui.log.appendPlainText(result)

    def generateRom(self):
        self.rom = str(self.ui.rom.text())
        name, ext = os.path.splitext(self.rom)
        self.newrom = "{name}-{uid}{ext}".format(name=name, uid='new', ext=ext)
        system = int(self.ui.system.currentIndex()) + 1
        codes = str(self.ui.codes.toPlainText())
        self.settings.setValue("system", system - 1)
        system = str(system)
        if self.rom != '':
            self.process.start('./GGGG "' + codes + '" ' + system + ' "' + self.rom + '" "' + self.newrom + '"')
            self.process.waitForFinished();
            self.process.close();

    # Based on https://github.com/fbeaudet/ips.py/blob/master/ips.py
    def generateIPS(self):
        self.generateRom()
        FILE_LIMIT = 0x1000000 #16MB
        PATCH_ASCII = bytes((0x50, 0x41, 0x54, 0x43, 0x48))
        EOF_ASCII = bytes((0x45, 0x4f, 0x46))
        name, ext = os.path.splitext(self.rom)
        ipsfile = "{name}{uid}{ext}".format(name=name, uid='', ext='.ips')
        original = open(self.rom, 'rb').read()
        modified = open(self.newrom, 'rb').read()
        patch = open(ipsfile, 'wb')
        recording = False
        record = bytearray()
        size = bytearray(2)

        if len(modified) > FILE_LIMIT:
            self.ui.log.appendPlainText("\nModified file is too large for IPS format. Max: 16MB.")

        patch.write(PATCH_ASCII)
        for a in range(len(modified)):
            if not recording:
                if len(original) <= a or modified[a] != original[a]:
                    recording = True
                    record = bytearray()
                    offset = bytearray(3)

                    if a == EOF_ASCII:
                        record.append(modified[a-1])

                    record.append(modified[a])
                    for x in range(3):
                        offset[x] = (a >> (16 - x * 8)) % 256

                    patch.write(offset)

                    if a == len(modified) - 1:
                        recording = False
                        patch.write(b'\x00\x01')
                        patch.write(record)
            else:
                if len(original) <= a or modified[a] != original[a]:
                    record.append(modified[a])

                    if a == len(modified) - 1:
                        recording = False
                        for x in range(2):
                            size[x] = len(record) >> (8 - x * 8)

                        patch.write(size)
                        patch.write(record)
                else:
                    recording = False
                    for x in range(2):
                        size[x] = len(record) >> (8 - x * 8)

                    patch.write(size)
                    patch.write(record)

        patch.write(EOF_ASCII)
        patch.close()
        self.ui.log.appendPlainText("\nIPS file generated")


def main():
	# Start the software
    app = QApplication(sys.argv)
    MainWindow_ = QMainWindow()
    ui = MainWindow()
    ui.setupUi(MainWindow_)
    # Add the close feature at the program with the X
    sys.exit(app.exec_())

# Execute the software
main()
