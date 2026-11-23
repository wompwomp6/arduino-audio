#pragma once

#define STEPS_SQUARE 2
#define STEPS_SAWTOOTH 256
#define STEPS_TRIANGLE 512
#define STEPS_SAMPLE 8000

//f = 1 / t
//t = 1 / f

//f = frequency
//t = time

#define Freq(timeScale, times) ((timeScale) / (times))
#define Time(timeScale, freq) ((timeScale) / (freq))