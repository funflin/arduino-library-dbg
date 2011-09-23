#include <Dbg.h>

char prg_name[] = "Debug test";
unsigned int counter = 0;

void setup() {
  // The following requires an Arduino Mega, or similar board
  // with additional serial ports (2-4)

  // If compiled for an Uno, this will quietly default back to "Serial"

  // The valid id's for serial port numbers on Arduino Mega are:
  // 1 = Serial
  // 2 = Serial1
  // 3 = Serial2
  // 4 = Serial3

  // Direct serial logging to Serial1 at 9600 baud
  Debug.begin(2,9600);

  Debug.log("Dbg Library initialized: %lu", millis());

  Debug.log("This is the normal syntax");
  dbg("This is the preferred shorthand syntax");
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

