"""
:author: Maël Naccache
:Brief: QAbstractItemModel to display the music file on the table.
"""

from PySide import QtCore

class TableModel(QtCore.QAbstractTableModel):
	def __init__(self, parent=None):
		super(TableModel, self).__init__(parent)
		self.column = ["File", "MIBD", "GOT INFO", "ON BDD"]
		self.row = []

	def add_row(self, data):
		self.layoutAboutToBeChanged.emit()
		self.row.append(data)
		self.layoutChanged.emit()

	def change_data(self, rowid, colid, newdata):
		self.layoutAboutToBeChanged.emit()
		self.row[rowid][colid] = newdata
		self.layoutChanged.emit()

	def rowCount(self, index=QtCore.QModelIndex()):
		return len(self.row)

	def columnCount(self, index=QtCore.QModelIndex()):
		return len(self.column)

	def flags(self, index):
		return (QtCore.Qt.ItemIsSelectable | QtCore.Qt.ItemIsEnabled | QtCore.Qt.ItemIsEditable)

	def setData(self, index, value, role=QtCore.Qt.EditRole):
		x = index.row()
		y = index.column()
		if self.rowCount() >= x:
			if self.columnCount() >= y:
				self.row[x][y] = value
				return True
		return False

	def data(self, index, role=QtCore.Qt.DisplayRole):
		if role != QtCore.Qt.DisplayRole:
			return None
		x = index.row()
		y = index.column()
		if self.rowCount() >= x:
			if self.columnCount() >= y:
				return self.row[x][y]
		return None

	def headerData(self, section, orientation, role = QtCore.Qt.DisplayRole):
		if orientation == QtCore.Qt.Horizontal and role == QtCore.Qt.DisplayRole:
			return self.column[section]
		return None
