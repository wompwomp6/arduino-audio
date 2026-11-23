#include "commons.h"
#include "instruments.h"
//#include "multiplexer.h"

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
    if (instrumentId == INSTRUMENT_NONE ||
        instrumentId == INSTRUMENT_INVALID ||
        !note || !note->duration)
        return;

    if (note->freq == FREQ_DELAY)
    {
        delay(note->duration);
        return;
    }

    BYTE index = instrumentId - 1;
    if (index >= ARRAY_SIZE(InstrumentsLUT))
        return;

    Instrument_t* instrument = &InstrumentsLUT[index];

    if (!instrument->step || !instrument->play)
        return;

    DWORD stepTime = Time(us, note->freq) / instrument->step;
    if (!stepTime)
        return;

    DWORD duration = (DWORD)note->duration * 1000UL;

    DWORD start = micros();

    while (TRUE)
    {
        DWORD elapsed = micros() - start;
        if (elapsed >= duration)
            break;
        instrument->play(stepTime, elapsed);
    }

    analogWrite(PIN_LEFT, ANALOG_LOW);
}

void AudioPlayTrack(Track_t* track)
{
    if (!track || !track->noteCount || !track->notes |
        track->instrument == INSTRUMENT_NONE || 
        track->instrument == INSTRUMENT_INVALID)
        return;

    for (size_t i = 0; i < track->noteCount; i++)
    {
        AudioPlayNote(track->instrument, &track->notes[i]);
    }
}

void AudioPlayAsync();