#include "Dbg.h"

#ifdef DEBUG_ENABLED

#define DBG_MAX_LENGTH	80

//Dbg::Dbg() {
//}

void Dbg::begin(int serial, long int rate, byte maxlevel)
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
        debug_level = maxlevel;

}

void Dbg::log(byte level, const char *fmt, ...)
{
        if(debug_level >= level){
          char buf[DBG_MAX_LENGTH];

          va_list ap;
          va_start(ap, fmt);

          vsnprintf(buf, (DBG_MAX_LENGTH - 1), fmt, ap);
          va_end(ap);

          switch(level){
          case LEVELFATAL:
            m_serial->print("@@@");
            break;
          case LEVELERROR:
            m_serial->print("***");
            break;
          case LEVELWARN:
            m_serial->print("???");
            break;
          case LEVELINFO:
            m_serial->print("%%%");
            break;
          case LEVELDEBUG:
            m_serial->print("&&&");
            break;
          }
          m_serial->println(buf);
        }
}
#endif

Dbg Debug;
