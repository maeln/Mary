'''
:brief: This file contain the classes to fetch data from music (via taglib), from musicbrainz,
and from AcousticBrainz.
:author: Maël Naccache
'''

import taglib
import musicbrainzngs

class TagFetcher:
	@staticmethod
	def fetch(file):
		f = taglib.File(file)
		return (f.tags["TITLE"], f.tags["ARTIST"], f.tags["ALBUM"], f.tags["GENRE"])

class MusicbrainzFetcher:
	@staticmethod
	def fetch(tags):
		records = musicbrainzngs.search_recordings(recording=tags[0], artist=tags[1], release=tags[2])
		return records['recording-list'][0]['id']
