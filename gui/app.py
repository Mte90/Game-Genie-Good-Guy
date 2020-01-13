#!/usr/bin/python3
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *
import sys, signal, subprocess, os

from window import Ui_MainWindow

class MainWindow ( QMainWindow , Ui_MainWindow):

    #Create settings for the software
    settings = QSettings('GGGG','Game Genie Good Guy')
    settings.setFallbacksEnabled(False)
    version = '1.0.0'

    def __init__ ( self, parent = None ):
        QMainWindow.__init__( self, parent )
        #Load the ui
        self.ui = Ui_MainWindow()
        self.ui.setupUi( self )
        #Set the MainWindow Title
        self.setWindowTitle('Game Genie Good Guy - ' + self.version)
        #When the software are closed on console the software are closed
        signal.signal(signal.SIGINT, signal.SIG_DFL)
        self.ui.system.addItem("Game Boy/Gear/Master System")
        self.ui.system.addItem("Genesis/Mega Drive (no SMD roms)")
        self.ui.system.addItem("Nintendo")
        self.ui.system.addItem("Super Nintendo")
        self.ui.browse.clicked.connect(self.browse)
        self.ui.patch.clicked.connect(self.patch)
        self.ui.ips.clicked.connect(self.ips)
        self.ui.log.setReadOnly(True)
        if self.settings.value("rom"):
            self.ui.rom.setText(self.settings.value("rom"))
        if self.settings.value("system"):
            self.ui.system.setCurrentIndex(int(self.settings.value("system")))
        #Show the form
        self.show()

    def browse(self):
        options = QFileDialog.Options()
        options |= QFileDialog.DontUseNativeDialog
        fileName, _ = QFileDialog.getOpenFileName(self,"QFileDialog.getOpenFileName()", "","All Files (*);;", options=options)
        self.ui.rom.setText(str(fileName))
        self.settings.setValue("rom", str(fileName))

    def patch(self):
        rom = str(self.ui.rom.text())
        name, ext = os.path.splitext(rom)
        newrom = "{name}-{uid}{ext}".format(name=name, uid='new', ext=ext)
        system = int(self.ui.system.currentIndex()) + 1
        codes = str(self.ui.codes.toPlainText())
        self.settings.setValue("system", system - 1)
        if rom != '':
            out = subprocess.Popen(['./GGGG', codes, str(system), rom, newrom],
               stdout=subprocess.PIPE,
               stderr=subprocess.STDOUT)
            stdout,stderr = out.communicate()
            self.ui.log.clear()
            self.ui.log.appendPlainText(stdout.decode('ascii').strip())

    def ips(self):
        pass

def main():
	#Start the software
    app = QApplication(sys.argv)
    MainWindow_ = QMainWindow()
    ui = MainWindow()
    ui.setupUi(MainWindow_)
    #Add the close feature at the program with the X
    sys.exit(app.exec_())

#Execute the software
main()