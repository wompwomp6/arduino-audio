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

#include "../sample.h"

BYTE SampleAnalog(DWORD stepTime, DWORD time)
{
    DWORD realTime = time / stepTime;
    if (realTime >= ARRAY_SIZE(sample8000))
        return NULL;

    return sample8000[realTime];
}

void InstrumentSample(DWORD stepTime, DWORD time)
{
    analogWrite(PIN_LEFT, SampleAnalog(stepTime, time));
}

Instrument_t InstrumentsLUT[5] =
{
    { STEPS_SQUARE,   &InstrumentSquare },
    { STEPS_TRIANGLE, &InstrumentTriangle },
    { STEPS_SAWTOOTH, &InstrumentSawtooth },
    { NULL, NULL },
    { STEPS_SAMPLE, &InstrumentSample },
};
