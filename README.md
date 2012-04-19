#Dbg library for Arduino

##Version 1.1

by Felipe Acebes

See Dbg/examples/ directory for examples

##Installation:

- Copy the Dbg/ directory and all contents to your Arduino/libraries/  directory
- On Mac OSX this is ~/Documents/Arduino/libraries
- On other systems its the directory containing your sketches
- You may need to create the libraries/ subdirectory if it does not exist
- Restart Arduino IDE to pick up new libraries

##Simple usage:

    #include <Dbg.h>
    int port = 1; // 1 = Serial, [Mega: 2 = Serial1, 3 = Serial2, 4 = Serial3 ]
    int speed = 9600;
    void setup() {
      Debug.begin(port, speed);
      Debug.log(LEVELDEBUG,"Long form logging");
      dbg("Short form logging");
      dbg("Port: %d Speed: %d", port, speed);
      dbg("Inserting a %s is %s", "string", "easy");
    }

##License
[New BSD License](http://www.opensource.org/licenses/bsd-license.php)

##Version 1.0
By Byron Guernsey
contact: okachobi@gmail.com
See the online documentation here: [arduino-library-dbg](http://code.google.com/p/arduino-library-dbg/)
