'''
:author: Maël Naccache
:brief: A threaded-class who will fecth info on the music.
'''

import Fetcher
import musicbrainzngs
import threading

class ModelUpdater(threading.Thread):
	def init(self):
		self.model = None
		self.lock = threading.Event()

	def set_model(self, model):
		self.model = model

	def stop(self):
		self.lock.set()

	def run(self):
		musicbrainzngs.set_useragent("Mary", "Alpha", "contact@maeln.com")
		if self.model is not None:
			for row in self.model.row:
				self.find_mbid(row)
				if self.lock.is_set():
					break

	def find_mbid(self, row):
		self.model.layoutAboutToBeChanged.emit()
		row[1] = Fetcher.MusicbrainzFetcher.fetch(Fetcher.TagFetcher.fetch(row[0]))
		self.model.layoutChanged.emit()