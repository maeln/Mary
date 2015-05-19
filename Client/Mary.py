"""
:author: Maël Naccache
:brief: Main Window of the application.
"""

from PySide import QtGui
from ui import UIMainWindow

class MainWindow(QtGui.QMainWindow, UIMainWindow.Ui_MainWindow):
	def __init__(self, parent=None):
		super(MainWindow, self).__init__(parent)
		self.setupUi(self)

		self.actionAbout.triggered.connect(self.about)
		self.actionClose.triggered.connect(self.close_app)
		self.findbutton.clicked.connect(self.get_directory)

	def about(self):
		"""The About popup window."""
		QtGui.QMessageBox.about(self, "About Mary", u"Mary is your personal playlist assistant.")

	def close_app(self):
		print("Quitting Mary ...")
		self.close()

	def get_directory(self):
		dir_path = QtGui.QFileDialog.getExistingDirectory(self, "Music Library")
		self.pathedit.setText(dir_path)