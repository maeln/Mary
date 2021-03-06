/*
 * test.c
 * 
 * Copyright 2015 Maël <maeln@Chise>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include "playbeat.hxx"
#include "notescounter.hxx"
#include <stdlib.h>
#include <stdexcept>
#include <algorithm>
#include <cmath>

// TagLib
#include <taglib/fileref.h>
#include <taglib/tag.h>
#include <taglib/tpropertymap.h>

PlayBeat::PlayBeat()
{
}

PlayBeat::~PlayBeat()
{

}

MusicMetadata PlayBeat::getMetadata(std::string file)
{
	// Metadata.
	MusicMetadata meta;

	// Init variable.
	uint_t bufferSize 	= 1024;
	uint_t hopSize 		= 512;
	uint_t samplerate	= 0;

	char_t* path		= (char_t*) file.c_str();
	char_t algo[8]		= "default";

	// Tag reader.
	TagLib::FileRef tagFile(path);
	if(tagFile.isNull())
	{
		std::cerr << "Error: Impossible to read tag from file." << std::endl;
	}
	else
	{
		TagLib::Tag *tags = tagFile.tag();
		meta.title = std::string(tags->title().toCString());
		meta.artists = std::string(tags->artist().toCString());
		meta.genre = std::string(tags->genre().toCString());
		/*
			TagLib::AudioProperties *prop =  tagFile.audioProperties();
			int sec = prop->length() % 60;
			int min = (prop->length() - sec) / 60;
			std::cout << "Length : " << min << ":" << sec << std::endl;
		 */
	}

	// Open audio file.
	aubio_source_t *audioFile = NULL;
	audioFile = new_aubio_source (path, samplerate, hopSize);
	if(!audioFile)
	{
		exit(1);
	}

	// Get the sample rate of the file.
	if (samplerate == 0) {
		samplerate = aubio_source_get_samplerate(audioFile);
	}

	// I/O Buffer.
	fvec_t* ibuf = new_fvec(hopSize);

	// Init variables for beat detection.
	aubio_tempo_t* tempo;
	fvec_t* tempo_out;
	smpl_t is_beat = 0;
	uint_t is_silence = 0.;
	smpl_t silence_threshold = -90.;

	tempo_out = new_fvec(2);
	tempo = new_aubio_tempo(algo, bufferSize, hopSize, samplerate);

	// Init variables for pitch detection.
	aubio_pitch_t* pitchDetector = new_aubio_pitch(algo, bufferSize, hopSize, samplerate);
	fvec_t* pitch = new_fvec(1);
	NotesCounter pitchs;
	NotesFactory noteGetter;

	// Process block.
	uint_t read = 0;
	uint_t total_read = 0;
	int blocks = 0;
	float beats = 0.;
	float lastBeat = 0.;

	do
	{
		// Read the file.
		aubio_source_do(audioFile, ibuf, &read);

		// Process beat detection.
		aubio_tempo_do (tempo, ibuf, tempo_out);

		is_beat = fvec_get_sample(tempo_out, 0);
		if (silence_threshold != -90.)
			is_silence = aubio_silence_detection(ibuf, silence_threshold);

		if (is_beat && !is_silence)
		{
			beats += 1.0;
			lastBeat = aubio_tempo_get_last_s(tempo);
		}

		// Process pitch detection.
		aubio_pitch_do(pitchDetector, ibuf, pitch);

		smpl_t pitch_found = fvec_get_sample(pitch, 0);

		try
		{
			Notes tmp = noteGetter.getNote(pitch_found);
			pitchs.addNote(tmp);
		}
		catch (std::logic_error& e)
		{
			// Current blocks is silent.
		}

		blocks++;
		total_read += read;
	} while (read == hopSize);

	// Show bpm :
	meta.bpm = floor(beats/(lastBeat/60.));
	meta.length = floor(lastBeat);

	// TO DO : Print top 10 pitch.
	std::vector<Notes> notes = pitchs.getSortedNotes();
	/*
		unsigned int totalCount = 0;
		for(unsigned int i=0; i<notes.size(); ++i)
		{
			totalCount += pitchs.getCount(notes.at(i));
		}

		for(unsigned int i=0; i<notes.size(); ++i)
		{
			unsigned int noteCount = pitchs.getCount(notes.at(i));
			double ratio = (double)noteCount / (double)totalCount;
			std::cout << "Note: " << notes.at(i).getNameWithOctave() << ", count : " << noteCount << "(" << ratio*100.0 << "%)" << std::endl;
		}
	 */
	meta.topNotes = notes;

	// Cleanup variable.
	del_aubio_tempo(tempo);
	del_aubio_pitch(pitchDetector);

	del_fvec(tempo_out);
	del_fvec(pitch);

	del_aubio_source(audioFile);

	del_fvec(ibuf);
	aubio_cleanup ();

	return meta;
}

