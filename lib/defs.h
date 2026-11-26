#pragma once
#include "commons.h"
#include "natives/natives.h"
#include "math.h"

#define AUDIO_LEFT  (1 << 0)
#define AUDIO_RIGHT (1 << 1)
#define AUDIO_MIC   (1 << 2)

#define INSTRUMENT_NONE 0
//square    _|-|_|-|_|-|_|_
#define INSTRUMENT_SQUARE 1
//triangle  /\/\/\/\/\/\/\/
#define INSTRUMENT_TRIANGLE 2
//sawtooth  /|/|/|/|/|_/|_/|
#define INSTRUMENT_SAWTOOTH 3
//noise     -|/|-|_\/_\//|-|_\/
#define INSTRUMENT_NOISE 4
//sample
#define INSTRUMENT_SAMPLE 5
//#define INSTRUMENT_OVAL WAVE_TRIANGLE

//multiplexer

#define INSTRUMENT_INVALID 0xFF

#define MIN_VOICES 1
#define MAX_VOICES 16

#define FREQ_DELAY 0

#define PIN_INVALID 0xFF

#define AUDIO_MAX_VOICES  4

#define ANALOG_LOW 0
#define ANALOG_HIGH 255

typedef VFunc(void, PlayFn, DWORD stepTime, DWORD time);

typedef struct Instrument_t
{
    size_t step;
    PlayFn play;
}Instrument_t;

typedef struct Note_t
{
    WORD freq;//if freq is null its a delay
    WORD duration;
}Note_t;

typedef struct Track_t
{
    BYTE instrument;
    BYTE wrapAround;
    WORD noteCount;
    Note_t* notes;
}Track_t;

typedef struct Voice_t
{
    BYTE volume;
    Track_t track;
}Voice_t;

typedef struct Multiplexer_t
{
    Voice_t* voices[MAX_VOICES];
}Multiplexer_t;