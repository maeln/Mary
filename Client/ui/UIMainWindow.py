# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'MainWindow.ui'
#
# Created: Sat May 16 12:04:05 2015
#      by: pyside-uic 0.2.15 running on PySide 1.2.1
#
# WARNING! All changes made in this file will be lost!

from PySide import QtCore, QtGui

class Ui_MainWindow(object):
	def setupUi(self, MainWindow):
		MainWindow.setObjectName("MainWindow")
		MainWindow.resize(800, 600)
		self.centralwidget = QtGui.QWidget(MainWindow)
		self.centralwidget.setObjectName("centralwidget")
		self.verticalLayout = QtGui.QVBoxLayout(self.centralwidget)
		self.verticalLayout.setObjectName("verticalLayout")
		self.label_2 = QtGui.QLabel(self.centralwidget)
		self.label_2.setObjectName("label_2")
		self.verticalLayout.addWidget(self.label_2)
		self.widget = QtGui.QWidget(self.centralwidget)
		self.widget.setObjectName("widget")
		self.horizontalLayout = QtGui.QHBoxLayout(self.widget)
		self.horizontalLayout.setContentsMargins(0, 0, 0, 0)
		self.horizontalLayout.setObjectName("horizontalLayout")
		self.pathedit = QtGui.QLineEdit(self.widget)
		self.pathedit.setObjectName("pathedit")
		self.horizontalLayout.addWidget(self.pathedit)
		self.findbutton = QtGui.QPushButton(self.widget)
		self.findbutton.setObjectName("findbutton")
		self.horizontalLayout.addWidget(self.findbutton)
		self.acceptbutton = QtGui.QPushButton(self.widget)
		self.acceptbutton.setObjectName("acceptbutton")
		self.horizontalLayout.addWidget(self.acceptbutton)
		self.verticalLayout.addWidget(self.widget)
		self.widget_2 = QtGui.QWidget(self.centralwidget)
		self.widget_2.setObjectName("widget_2")
		self.verticalLayout_2 = QtGui.QVBoxLayout(self.widget_2)
		self.verticalLayout_2.setContentsMargins(0, 0, 0, 0)
		self.verticalLayout_2.setObjectName("verticalLayout_2")
		self.label = QtGui.QLabel(self.widget_2)
		self.label.setObjectName("label")
		self.verticalLayout_2.addWidget(self.label)
		self.tableView = QtGui.QTableView(self.widget_2)
		self.tableView.setObjectName("tableView")
		self.verticalLayout_2.addWidget(self.tableView)
		self.verticalLayout.addWidget(self.widget_2)
		MainWindow.setCentralWidget(self.centralwidget)
		self.menubar = QtGui.QMenuBar(MainWindow)
		self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 26))
		self.menubar.setObjectName("menubar")
		self.menuFile = QtGui.QMenu(self.menubar)
		self.menuFile.setObjectName("menuFile")
		self.menuAbout = QtGui.QMenu(self.menubar)
		self.menuAbout.setObjectName("menuAbout")
		MainWindow.setMenuBar(self.menubar)
		self.statusbar = QtGui.QStatusBar(MainWindow)
		self.statusbar.setObjectName("statusbar")
		MainWindow.setStatusBar(self.statusbar)
		self.actionClose = QtGui.QAction(MainWindow)
		self.actionClose.setObjectName("actionClose")
		self.actionAbout = QtGui.QAction(MainWindow)
		self.actionAbout.setObjectName("actionAbout")
		self.menuFile.addAction(self.actionClose)
		self.menuAbout.addAction(self.actionAbout)
		self.menubar.addAction(self.menuFile.menuAction())
		self.menubar.addAction(self.menuAbout.menuAction())

		self.retranslateUi(MainWindow)
		QtCore.QMetaObject.connectSlotsByName(MainWindow)

	def retranslateUi(self, MainWindow):
		MainWindow.setWindowTitle(QtGui.QApplication.translate("MainWindow", "MainWindow", None, QtGui.QApplication.UnicodeUTF8))
		self.label_2.setText(QtGui.QApplication.translate("MainWindow", "Music library :", None, QtGui.QApplication.UnicodeUTF8))
		self.pathedit.setPlaceholderText(QtGui.QApplication.translate("MainWindow", "Path to your music library ...", None, QtGui.QApplication.UnicodeUTF8))
		self.findbutton.setText(QtGui.QApplication.translate("MainWindow", "Find...", None, QtGui.QApplication.UnicodeUTF8))
		self.acceptbutton.setText(QtGui.QApplication.translate("MainWindow", "OK", None, QtGui.QApplication.UnicodeUTF8))
		self.label.setText(QtGui.QApplication.translate("MainWindow", "Music found :", None, QtGui.QApplication.UnicodeUTF8))
		self.menuFile.setTitle(QtGui.QApplication.translate("MainWindow", "File", None, QtGui.QApplication.UnicodeUTF8))
		self.menuAbout.setTitle(QtGui.QApplication.translate("MainWindow", "Help", None, QtGui.QApplication.UnicodeUTF8))
		self.actionClose.setText(QtGui.QApplication.translate("MainWindow", "Close", None, QtGui.QApplication.UnicodeUTF8))
		self.actionAbout.setText(QtGui.QApplication.translate("MainWindow", "About", None, QtGui.QApplication.UnicodeUTF8))

