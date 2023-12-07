/*

 Arduino TFT Bitmap Logo example

 This example reads an image file from a micro-SD card
 and draws it on the screen, at random locations.

 In this sketch, the Arduino logo is read from a micro-SD card.
 There is a .bmp file included with this sketch.
 - open the sketch folder (Ctrl-K or Cmd-K)
 - copy the "arduino.bmp" file to a micro-SD
 - put the SD into the SD slot of the Arduino TFT module.

 This example code is in the public domain.

 Created 19 April 2013 by Enrico Gueli

 http://www.arduino.cc/en/Tutorial/TFTBitmapLogo

 */
/* Modified for tests*/

// include the necessary libraries
#include <SPI.h>
//#include <SD.h>
#include <TFT.h>  // Arduino LCD library

// pin definition for the Uno
//#define sd_cs  4
//#define lcd_cs 10
//#define dc     9
//#define rst    8

// pin definition for the Leonardo
//#define sd_cs  8
//#define lcd_cs 7
//#define dc     0
//#define rst    1


// pin definition for the NodeMCU
//#define sd_cs  8
#define lcd_cs D8
#define dc     D2
#define rst    D1
#define mosi     D7
#define clk    D5
TFT TFTscreen = TFT(lcd_cs, dc, mosi,clk,rst);

// this variable represents the image to be drawn on screen



void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  // initialize the GLCD and show a message
  // asking the user to open the serial line
  TFTscreen.begin();
  TFTscreen.background(255, 255, 255);

  TFTscreen.stroke(0, 0, 255);
  TFTscreen.println();
  TFTscreen.println(F("Arduino TFT Bitmap Example"));
  TFTscreen.stroke(0, 0, 0);
  TFTscreen.println(F("Open serial monitor"));
  TFTscreen.println(F("to run the sketch"));

  // initialize the serial port: it will be used to
  // print some diagnostic info
  Serial.begin(9600);
  while (!Serial) {
    // wait for serial port to connect. Needed for native USB port only
  }

  // clear the GLCD screen before starting
  Serial.write("Debut\n")
  TFTscreen.background(255, 255, 255);
  delay(1000)
  // try to access the SD card. If that fails (e.g.
  // no card present), the setup process will stop.
 TFTscreen.background(0, 255, 0);
digitalWrite(LED_BUILTIN, HIGH);

  // initialize and clear the GLCD screen
 
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
   Serial.write("New loop\n")
  TFTscreen.background(255, 255, 255);
  delay(1000)
  digitalWrite(LED_BUILTIN, LOW);
 Serial.write("Green\n")
 TFTscreen.background(0, 255, 0);


  delay(1500);
}
