#ifndef _DBG_H_
#define _DBG_H
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#define DEBUG_ENABLED 1

#define LEVELFATAL 0
#define LEVELERROR 1
#define LEVELWARN 2
#define LEVELINFO 3
#define LEVELDEBUG 4

#ifdef DEBUG_ENABLED
class Dbg {
public:
  Dbg(){};

  void begin(int serial = 1, long int rate = 9600, byte maxlevel = LEVELDEBUG);

  void log(byte level, const char *fmt, ...)
        __attribute__((format(printf, 3, 4)));

private:
	HardwareSerial* m_serial;
        byte debug_level;

};

#define dbg(fmt, ...) (Debug.log(LEVELDEBUG,fmt, ## __VA_ARGS__))
#define info(fmt, ...) (Debug.log(LEVELINFO,fmt, ## __VA_ARGS__))
#define warn(fmt, ...) (Debug.log(LEVELWARN,fmt, ## __VA_ARGS__))
#define error(fmt, ...) (Debug.log(LEVELERROR,fmt, ## __VA_ARGS__))
#define fatal(fmt, ...) (Debug.log(LEVELFATAL,fmt, ## __VA_ARGS__))

#else
class Dbg {
public:
  Dbg(){};

  void begin(int serial = 1, long int rate = 9600, byte maxlevel = LEVELDEBUG){};
        void log(byte level, const char *fmt, ...)
		__attribute__((format(printf, 3, 4))) {};
};

#define dbg(fmt, ...)  ((void)0)
#define dbg(fmt, ...)  ((void)0)
#define info(fmt, ...) ((void)0)
#define warn(fmt, ...) ((void)0)
#define error(fmt, ...)((void)0)
#define fatal(fmt, ...)((void)0)
#endif

extern Dbg Debug;

#endif
