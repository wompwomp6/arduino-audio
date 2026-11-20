#pragma once
#if defined (__AVR_ATmega328P__)
	#include "hardware/avr328p.h"
#else
	#error natives.h: TargetNotFound
#endif