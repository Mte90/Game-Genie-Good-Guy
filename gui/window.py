# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file './gui/window.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(352, 624)
        MainWindow.setMinimumSize(QtCore.QSize(352, 512))
        MainWindow.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.groupBox_2 = QtWidgets.QGroupBox(self.centralwidget)
        self.groupBox_2.setGeometry(QtCore.QRect(10, 90, 331, 71))
        self.groupBox_2.setObjectName("groupBox_2")
        self.system = QtWidgets.QComboBox(self.groupBox_2)
        self.system.setGeometry(QtCore.QRect(10, 30, 311, 31))
        self.system.setObjectName("system")
        self.groupBox_3 = QtWidgets.QGroupBox(self.centralwidget)
        self.groupBox_3.setGeometry(QtCore.QRect(10, 350, 331, 261))
        self.groupBox_3.setObjectName("groupBox_3")
        self.log = QtWidgets.QPlainTextEdit(self.groupBox_3)
        self.log.setEnabled(True)
        self.log.setGeometry(QtCore.QRect(10, 30, 311, 221))
        font = QtGui.QFont()
        font.setFamily("Monospace")
        self.log.setFont(font)
        self.log.setAcceptDrops(False)
        self.log.setUndoRedoEnabled(False)
        self.log.setObjectName("log")
        self.groupBox = QtWidgets.QGroupBox(self.centralwidget)
        self.groupBox.setGeometry(QtCore.QRect(10, 10, 331, 71))
        self.groupBox.setMinimumSize(QtCore.QSize(0, 60))
        self.groupBox.setObjectName("groupBox")
        self.horizontalLayoutWidget_2 = QtWidgets.QWidget(self.groupBox)
        self.horizontalLayoutWidget_2.setGeometry(QtCore.QRect(10, 30, 311, 34))
        self.horizontalLayoutWidget_2.setObjectName("horizontalLayoutWidget_2")
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout(self.horizontalLayoutWidget_2)
        self.horizontalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.rom = QtWidgets.QLineEdit(self.horizontalLayoutWidget_2)
        self.rom.setObjectName("rom")
        self.horizontalLayout_2.addWidget(self.rom)
        self.browse = QtWidgets.QPushButton(self.horizontalLayoutWidget_2)
        self.browse.setObjectName("browse")
        self.horizontalLayout_2.addWidget(self.browse)
        self.patch = QtWidgets.QCommandLinkButton(self.centralwidget)
        self.patch.setGeometry(QtCore.QRect(10, 300, 171, 41))
        self.patch.setObjectName("patch")
        self.ips = QtWidgets.QCommandLinkButton(self.centralwidget)
        self.ips.setGeometry(QtCore.QRect(190, 300, 151, 41))
        self.ips.setObjectName("ips")
        self.groupBox_4 = QtWidgets.QGroupBox(self.centralwidget)
        self.groupBox_4.setGeometry(QtCore.QRect(10, 170, 331, 121))
        self.groupBox_4.setObjectName("groupBox_4")
        self.codes = QtWidgets.QTextEdit(self.groupBox_4)
        self.codes.setGeometry(QtCore.QRect(10, 30, 311, 81))
        self.codes.setObjectName("codes")
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.groupBox_2.setTitle(_translate("MainWindow", "System"))
        self.groupBox_3.setTitle(_translate("MainWindow", "Log"))
        self.groupBox.setTitle(_translate("MainWindow", "ROM"))
        self.browse.setText(_translate("MainWindow", "Browse"))
        self.patch.setText(_translate("MainWindow", "Generate patched ROM"))
        self.ips.setText(_translate("MainWindow", "Generate IPS patch"))
        self.groupBox_4.setTitle(_translate("MainWindow", "Codes"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
