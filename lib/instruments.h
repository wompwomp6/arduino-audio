#pragma once
#include "defs.h"

void InstrumentSawtooth(DWORD stepTime)
{
    for (i16 i = 0; i <= 255; i++)
    {
        analogWrite(PIN_LEFT, i);
        delayMicroseconds(stepTime);
    }
    analogWrite(PIN_LEFT, ANALOG_LOW);
}

BYTE TriangleAnalog(DWORD stepTime, DWORD time)
{
    DWORD realTime = time % (stepTime * 2);

    if (realTime < stepTime)
        return (BYTE)((realTime * 255UL) / stepTime);
    else
        return (BYTE)(255UL - ((realTime - stepTime) * 255UL) / stepTime);
}

void InstrumentTriangle(DWORD stepTime, DWORD time)
{
    analogWrite(PIN_LEFT, TriangleAnalog(stepTime, time));
}

BYTE SquareAnalog(DWORD stepTime, DWORD time)
{
    DWORD realTime = time % (stepTime * 2);

    if (realTime < stepTime)
        return ANALOG_HIGH;
    else
        return ANALOG_LOW;
}

void InstrumentSquare(DWORD stepTime, DWORD time)
{
    analogWrite(PIN_LEFT, SquareAnalog(stepTime, time));
}


static WORD noiseSeed = 0xACE1;

BYTE NoiseAnalog()
{
    WORD bit = ((noiseSeed >> 0) ^
        (noiseSeed >> 2) ^
        (noiseSeed >> 3) ^
        (noiseSeed >> 5)) & 1;

    noiseSeed = (noiseSeed >> 1) | (bit << 15);

    return (noiseSeed & 1) ? 255 : 0;
}

void InstrumentNoise(DWORD stepTime, DWORD time)
{
    analogWrite(PIN_LEFT, NoiseAnalog());
}

#ifdef NO_SAMPLE
#define SAMPLE_RATE 1
PROGMEM const unsigned char sample[] = {};
#else
#include "../sample.h"
#endif



BYTE SampleAnalog(DWORD stepTime, DWORD time)
{
    DWORD sampleRate = Time(us, SAMPLE_RATE);

    DWORD realTime = time / sampleRate;
    if (realTime >= ARRAY_SIZE(sample))
        return NULL;

    return pgm_read_byte(&sample[realTime]);
}

void InstrumentSample(DWORD stepTime, DWORD time)
{
    analogWrite(PIN_LEFT, SampleAnalog(stepTime, time));//fix samples todo
}

Instrument_t InstrumentsLUT[5] =
{
    { STEPS_SQUARE,   &InstrumentSquare },
    { STEPS_TRIANGLE, &InstrumentTriangle },
    { STEPS_SAWTOOTH, &InstrumentSawtooth },
    { STEP_CONST, &InstrumentNoise },
    { STEP_CONST, &InstrumentSample },
};
