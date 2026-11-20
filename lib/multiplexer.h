#pragma once
#include "defs.h"
#include "instruments.h"

Multiplexer_t multiplexer = {  };

BYTE MultiplexerMix(DWORD time)
{
	BYTE out = NULL;

	for (size_t i = 0; i < ARRAY_SIZE(multiplexer.voices); i++)
	{
		Voice_t* voice = &multiplexer.voices[i];
		if (!voice)
			continue;

		voice->volume;
		voice->track;

		Track_t* track = voice->track;
		if (!track)
			continue;

		Note_t* note;
		//if (!track->wrapAround)
		//{
		//	if (index > track->noteCount)
		//		continue;
		//
		//	note = track->notes[index];
		//}
		//else
		//{
		//	note = track->notes[index % track->noteCount];
		//}
		//
		//if (!note)
		//	continue;

		//if (track->instrument == INSTRUMENT_NONE || track->instrument == INSTRUMENT_INVALID
		//	|| !note->duration)
		//	return;
		//
		//if (note->freq == FREQ_DELAY)
		//{
		//	delay(note->duration);
		//	return;
		//}
		//
		//BYTE index = track->instrument - 1;
		//if (index > ARRAY_SIZE(InstrumentsLUT) - 1)
		//	return;
		//
		//Instrument_t* instrument = &InstrumentsLUT[index];
		//if (!instrument || !instrument->step || !instrument->play)
		//	return;
		//
		//DWORD stepTime = Time(us, note->freq) / instrument->step;
	}
}