#pragma once

#define PIN_LEFT  11
#define PIN_RIGHT 10
#define PIN_MIC   PIN_INVALID

#ifdef __INTELLISENSE__
extern void analogWrite(uint8_t pin, int val);
extern void delayMicroseconds(unsigned long);
extern void delay(unsigned long);
extern unsigned long millis();
extern unsigned long micros();
extern unsigned char pgm_read_byte();
#endif

typedef uint8_t		BYTE;
typedef uint16_t	WORD;
typedef uint32_t	DWORD;
typedef uint64_t	QWORD;

#define MS(sec)   ((sec) * 1000UL)
#define US(sec)   ((sec) * 1000000UL)

#define ms (MS(1))
#define us (US(1))

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif

#define VFunc(retType, name, ...) retType(*name)(__VA_ARGS__);

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

#define NO_DISCARD volatile

typedef int8_t	i8;
typedef int16_t	i16;
typedef int32_t	i32;
typedef int64_t	i64;

//typedef uint8_t	u8;
//typedef uint16_t	u16;
//typedef uint32_t	u32;
//typedef uint64_t	u64;