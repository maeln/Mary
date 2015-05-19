"""
:author: Maël Naccache
:Brief: QAbstractItemModel to display the music file on the table.
"""

from PySide import QtCore

class TableModel(QtCore.QAbstractItemModel):
	def __init__(self, parent=None):
		super(TableModel, self).__init__(parent)
		self.row = ["File", "MIBD", "GOT INFO", "ON BDD"]
