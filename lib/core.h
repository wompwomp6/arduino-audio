#include "commons.h"
#include "instruments.h"

void AudioSetup(BYTE flags)
{
    //pwm check
    //setup timer
}


void AudioDestory()
{
    //destory out pins
    //stop timer
}

void AudioPlayNote(BYTE instrumentId, Note_t* note)
{
    if (instrumentId == INSTRUMENT_NONE || instrumentId == INSTRUMENT_INVALID || 
        !note || !note->duration)
        return;

    if (note->freq == FREQ_DELAY)
    {
        delay(note->duration);
        return;
    }

    BYTE index = instrumentId - 1;
    if (index > ARRAY_SIZE(InstrumentsLUT) - 1)
        return;

    Instrument_t* instrument = &InstrumentsLUT[index];
    if (!instrument || !instrument->step || !instrument->play)
        return;

    DWORD stepTime = Time(us, note->freq) / instrument->step;

    DWORD start = millis();
    while ((millis() - start) < note->duration)
    {
        instrument->play(stepTime);
    }
    
    analogWrite(PIN_LEFT, ANALOG_LOW);
}

void AudioPlayTrack(Track_t* track)
{
    if (!track || !track->instrument ||
        !track->noteCount || !track->notes)
        return;

    for (size_t i = 0; i < track->noteCount; i++)
    {
        AudioPlayNote(track->instrument, &track->notes[i]);
    }
}

void AudioPlayAsync();