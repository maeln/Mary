"""
:author: Maël Naccache
:brief: Main file of the project. Contain the QApplication.
"""

import sys
from PySide import QtGui
from Mary import MainWindow

if __name__ == '__main__':
	app = QtGui.QApplication(sys.argv)
	frame = MainWindow()
	frame.show()
	app.exec_()

