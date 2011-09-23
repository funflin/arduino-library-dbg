#include "Dbg.h"

#ifdef DEBUG_ENABLED

#define DBG_MAX_LENGTH	80

Dbg::Dbg() {
}

void Dbg::begin(int serial, int rate )
{
	switch(serial) {
		case 1:
			m_serial = &Serial;
			break;
#if defined(__AVR_ATmega1280__) || defined (__AVR_ATmega2560__)
		case 2:
			m_serial = &Serial1;
			break;
		case 3:
			m_serial = &Serial2;
			break;
		case 4:
			m_serial = &Serial3;
			break;
#endif
		default:
			m_serial = &Serial;
			break;
	}
	
	m_serial->begin(rate);
	
}

void Dbg::log(const char *fmt, ...)
{
	char buf[DBG_MAX_LENGTH];
	
	va_list ap;
    	va_start(ap, fmt);

    	vsnprintf(buf, (DBG_MAX_LENGTH - 1), fmt, ap);
    	va_end(ap);
	m_serial->println(buf);
}

#endif

Dbg Debug;
