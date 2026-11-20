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


void InstrumentTriangle(DWORD stepTime)
{
    for (i16 i = 0; i <= 255; i++)
    {
        analogWrite(PIN_LEFT, i);
        delayMicroseconds(stepTime);
    }

    for (i16 i = 255; i >= 0; i--)
    {
        analogWrite(PIN_LEFT, i);
        delayMicroseconds(stepTime);
    }
    analogWrite(PIN_LEFT, ANALOG_LOW);
}

void InstrumentSquare(DWORD stepTime)
{
    analogWrite(PIN_LEFT, ANALOG_HIGH);
    delayMicroseconds(stepTime);

    analogWrite(PIN_LEFT, ANALOG_LOW);
    delayMicroseconds(stepTime);
}

Instrument_t InstrumentsLUT[5] =
{
    { STEPS_SQUARE,   &InstrumentSquare },
    { STEPS_TRIANGLE, &InstrumentTriangle },
    { STEPS_SAWTOOTH, &InstrumentSawtooth },
    { NULL, NULL },
    { NULL, NULL },
};
