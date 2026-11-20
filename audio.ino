#include "lib/core.h"

Note_t SquareMelody[] =
{
    // Intro
    { 523, 150 },  // C5
    { 659, 150 },  // E5
    { 784, 300 },  // G5
    {   0, 100 },

    { 784, 150 },  // G5
    { 880, 150 },  // A5
    { 988, 300 },  // B5
    {   0, 100 },

    // Main melody
    { 1047, 150 }, // C6
    { 988, 150 },  // B5
    { 880, 150 },  // A5
    { 784, 300 },  // G5

    { 659, 150 },  // E5
    { 784, 150 },  // G5
    { 880, 300 },  // A5

    // Variation
    { 988, 150 },  // B5
    { 1047, 150 }, // C6
    { 1175, 300 }, // D6
    { 1047, 150 }, // C6
    { 988, 150 },  // B5

    { 880, 300 },  // A5
    {   0, 100 },

    // Ending
    { 784, 150 },  // G5
    { 659, 150 },  // E5
    { 523, 450 },  // C5
    {   0, 200 }
};

Note_t TriangleBass[] =
{
    // Intro
    { 131, 300 },  // C3
    { 196, 300 },  // G3
    { 165, 300 },  // E3
    { 196, 300 },  // G3

    // Main melody
    { 131, 300 },  // C3
    { 196, 300 },  // G3
    { 220, 300 },  // A3
    { 196, 300 },  // G3

    // Variation
    { 175, 300 },  // F3
    { 220, 300 },  // A3
    { 147, 300 },  // D3
    { 220, 300 },  // A3

    // Ending
    { 131, 300 },  // C3
    { 196, 300 },  // G3
    { 131, 600 },  // C3
    {   0, 200 }
};

Track_t melody = { INSTRUMENT_SQUARE, ARRAY_SIZE(SquareMelody), SquareMelody };
Track_t bass = { INSTRUMENT_SQUARE, ARRAY_SIZE(TriangleBass), TriangleBass };

void loop() 
{
    //AudioPlayTrack(&melody);
    AudioPlayTrack(&bass);
}

void setup() 
{
}