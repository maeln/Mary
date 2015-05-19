"""
:author: Maël Naccache
:Brief: QAbstractItemModel to display the music file on the table.
"""

from PySide import QtCore

class TableModel(QtCore.QAbstractItemModel):
	def __init__(self, parent=None):
		super(TableModel, self).__init__(parent)
		self.row = ["File", "MIBD", "GOT INFO", "ON BDD"]
		self.column = []

	def rowCount(self):
		return len(self.row)

	def columnCount(self):
		return len(self.column)

	def data(self, index, role = QtCore.Qt.DisplayRole)
		x = index.row()
		y = index.column()
		if self.rowCount() >= x:
			if self.columnCount() >= y:
				return self.column[y][x]
		return QtCore.QVariant()
