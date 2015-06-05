"""
:author: Maël Naccache
:brief: Main Window of the application.
"""

import os
import re

from PySide import QtGui

from ui import UIMainWindow
from TableModel import TableModel
import ModelUpdater


class MainWindow(QtGui.QMainWindow, UIMainWindow.Ui_MainWindow):
	def __init__(self, parent=None):
		super(MainWindow, self).__init__(parent)
		self.setupUi(self)

		self.actionAbout.triggered.connect(self.about)
		self.actionClose.triggered.connect(self.close_app)
		self.findbutton.clicked.connect(self.get_directory)
		self.acceptbutton.clicked.connect(self.found_music_file)

		self.mu = ModelUpdater.ModelUpdater()
		self.mu.init()

	def about(self):
		"""The About popup window."""
		QtGui.QMessageBox.about(self, "About Mary", "Mary is your personal playlist assistant.")

	def close_app(self):
		print("Quitting Mary ...")
		self.close()

	def get_directory(self):
		"""Allow the user to select a directory to analyse."""
		dir_path = QtGui.QFileDialog.getExistingDirectory(self, "Music Library")
		self.pathedit.setText(dir_path)

	def found_music_file(self):
		dir = self.pathedit.text()
		audio_files = []
		directories = os.walk(dir)
		# Regex :
		for dirname, _, filenames in directories:
			for filename in filenames:
				path = os.path.join(dirname, filename)
				if re.match("^.*(\.mp3|\.ogg)$", path) is not None:
					audio_files.append(path)
		model = TableModel()
		for files in audio_files:
			model.add_row([files, "Not Yet Fetch", "NOT YET", "NO"])
		self.tableView.setModel(model)
		self.tableView.resizeColumnsToContents()

		self.mu.set_model(self.tableView.model())
		self.mu.start()

	def closeEvent(self, event):
		self.mu.stop()
		event.accept()
