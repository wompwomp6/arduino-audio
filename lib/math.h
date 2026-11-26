#pragma once

#define STEPS_SQUARE 2
#define STEPS_SAWTOOTH 256
#define STEPS_TRIANGLE 512
#define STEP_CONST 1

//f = 1 / t
//t = 1 / f

//f = frequency
//t = time

#define Freq(timeScale, times) ((timeScale) / (times))
#define Time(timeScale, freq) ((timeScale) / (freq))