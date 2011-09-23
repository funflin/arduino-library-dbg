#ifndef _DBG_H_
#define _DBG_H
#include <WProgram.h>

#define DEBUG_ENABLED 1

#ifdef DEBUG_ENABLED
class Dbg {
public:
	Dbg();

	void begin(int serial = 1, int rate = 9600);
	
	void log(const char *fmt, ...)
        __attribute__((format(printf, 2, 3)));

private:
	HardwareSerial* m_serial;
	
};

#define dbg(fmt, ...) (Debug.log(fmt, ## __VA_ARGS__))

#else
class Dbg {
public:
	Dbg();
	
	void begin(int serial = 1, int rate = 9600) {};
	void log(const char *fmt, ...)
		__attribute__((format(printf, 2, 3))) {};
	
};

#define dbg(fmt, ...) ((void)0)

#endif

extern Dbg Debug;

#endif
