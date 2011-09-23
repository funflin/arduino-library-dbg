#include <Dbg.h>

char prg_name[] = "Debug test";
unsigned int counter = 0;

void setup() {
  // Direct serial logging to Serial (standard serial port) at default 9600 baud
  Debug.begin();
  Debug.log("Dbg Library initialized: %lu", millis());

  Debug.log("This is the normal syntax");
  dbg("This is the preferred shorthand syntax that compiles out of existence when DEBUG_ENABLED is undefined");

  // Notice that the above dbg() call will be truncated to 79 characters!
  // This is defined as the max length and can be increased in Dbg.cpp

}

void loop() {

  delay(1000);
  counter++;

  // Log prg_name string and counter value
  // using printf formatting syntax and shorthand macro
  dbg("[%s]: Time = %lu Counter = %d", prg_name, millis(), counter);

  // Outputs:
  // [Debug test]: Time = <time in millis> Counter = 1
  //
  // ...on first pass...

}

