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
		title = ""
		artist = ""
		album = ""
		genre = ""
		if "TITLE" in f.tags:
			title = f.tags["TITLE"]
		if "ARTIST" in f.tags:
			artist = f.tags["ARTIST"]
		if "ALBUM" in f.tags:
			album = f.tags["ALBUM"]
		if "GENRE" in f.tags:
			genre = f.tags["GENRE"]
		return (title, artist, album, genre)

class MusicbrainzFetcher:
	@staticmethod
	def fetch(tags):
		records = musicbrainzngs.search_recordings(recording=tags[0], artist=tags[1], release=tags[2])
		return records['recording-list'][0]['id']
