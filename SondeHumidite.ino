/**************************************************************************
  This is a library for several Adafruit displays based on ST77* drivers.

  This example works with the 1.14" TFT breakout
    ----> https://www.adafruit.com/product/4383
  The 1.3" TFT breakout
    ----> https://www.adafruit.com/product/4313
  The 1.47" TFT breakout
    ----> https://www.adafruit.com/product/5393
  The 1.54" TFT breakout
    ----> https://www.adafruit.com/product/3787
  The 1.69" TFT breakout
    ----> https://www.adafruit.com/product/5206
  The 1.9" TFT breakout
    ----> https://www.adafruit.com/product/5394
  The 2.0" TFT breakout
    ----> https://www.adafruit.com/product/4311


  Check out the links above for our tutorials and wiring diagrams.
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional).

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 **************************************************************************/

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>


  // For the breakout board, you can use any 2 or 3 pins.
  // These pins will also work for the 1.8" TFT shield.
  //#define TFT_CS        10
  //#define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
  //#define TFT_DC         8
#define cs D3
#define dc     D2
#define rst    D1
#define mosi     D7
#define clk    D5

// OPTION 1 (recommended) is to use the HARDWARE SPI pins, which are unique
// to each board and not reassignable. For Arduino Uno: MOSI = pin 11 and
// SCLK = pin 13. This is the fastest mode of operation and is required if
// using the breakout board's microSD card.

Adafruit_ST7789 tft = Adafruit_ST7789(cs, dc,mosi,clk, rst);

// OPTION 2 lets you interface the display using ANY TWO or THREE PINS,
// tradeoff being that performance is not as fast as hardware SPI above.
//#define TFT_MOSI 11  // Data out
//#define TFT_SCLK 13  // Clock out

//Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

int count = 0;
int sondepin = A0;
int sondevalue =0;
int sondehigh = 1024;
int sondelow = 0;
int humidity = 0;
int relaispin = D0;


//float p = 3.1415926;

void setup(void) {
  Serial.begin(9600);
  
  
  //delay(10000);
  //while(!Serial){

  //}
  Serial.print(F("Hello! ST77xx TFT Test"));

  // Use this initializer (uncomment) if using a 1.3" or 1.54" 240x240 TFT:
  tft.init(240, 320);           // Init ST7789 240x240
  tft.setSPISpeed(20000000);
  // OR use this initializer (uncomment) if using a 1.69" 280x240 TFT:
  //tft.init(240, 280);           // Init ST7789 280x240

  // OR use this initializer (uncomment) if using a 2.0" 320x240 TFT:
  //tft.init(240, 320);           // Init ST7789 320x240

  // OR use this initializer (uncomment) if using a 1.14" 240x135 TFT:
  //tft.init(135, 240);           // Init ST7789 240x135
  
  // OR use this initializer (uncomment) if using a 1.47" 172x320 TFT:
  //tft.init(172, 320);           // Init ST7789 172x320

  // OR use this initializer (uncomment) if using a 1.9" 170x320 TFT:
  //tft.init(170, 320);           // Init ST7789 170x320

  // SPI speed defaults to SPI_DEFAULT_FREQ defined in the library, you can override it here
  // Note that speed allowable depends on chip and quality of wiring, if you go too fast, you
  // may end up with a black screen some times, or all the time.
  //tft.setSPISpeed(40000000);
  Serial.println(F("Initialized"));
  
  uint16_t time = millis();
  tft.fillScreen(ST77XX_BLACK);
  time = millis() - time;
  pinMode(GPF8,OUTPUT);
  Serial.println(time, DEC);
  delay(500);

  tft.fillScreen(ST77XX_WHITE);

  Serial.println("done");
  delay(1000);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(relaispin, OUTPUT);

  //int test = ESP.getCpuFreqMHz();
  //Serial.println(test);
}

void loop() {
  //tft.fillScreen(ST77XX_BLACK);
  //yield();
  uint16_t time2 = 0;
  count++;
  //delay(1000);
  //digitalWrite(LED_BUILTIN, LOW);
  //ESP.wdtFeed();
  //tft.fillScreen(ST77XX_GREEN);


  time2 = millis();
  //for(int x=0;x <=tft.width();x++){
  //  tft.drawFastVLine(x ,0, tft.height(), ST77XX_RED);
    //ESP.wdtFeed();
  //}
  //time2 = millis() - time2;
  //Serial.println(time2,DEC);

  sondevalue = analogRead(sondepin);
  tft.setCursor(0, 0);  
  tft.setTextColor( ST77XX_BLACK,ST77XX_WHITE);
  tft.setTextWrap(true);
  tft.setTextSize(5);
  //tft.print("Il fonctionne cet écran");
  Serial.println(count);
  //digitalWrite(GPF8,HIGH);
  humidity = sondevalue*100/(sondehigh - sondelow);
  if(humidity>45){digitalWrite(relaispin,LOW);}//Apres un Test 37 - 38 correspondent a un pot de fleur humide 
  if(humidity<40){digitalWrite(relaispin,HIGH);}
  Serial.println(humidity);
  tft.setCursor(0,0);
  tft.print("Humidite");
  tft.setCursor(100,100);
  tft.fillRect(100, 100, 200, 100, ST77XX_WHITE);
  tft.print(humidity);
  //testtriangles();
  delay(500);
  //digitalWrite(GPF8,LOW);//Inutile
  //delay(500);
  //digitalWrite(relaispin,HIGH);
  //delay(1000);
  //delay(10000);
  //digitalWrite(LED_BUILTIN, HIGH);
  
}


void testtriangles() {
  tft.fillScreen(ST77XX_BLACK);
  uint16_t color = 0xF800;
  int t;
  int w = tft.width()/2;
  int x = tft.height()-1;
  int y = 0;
  int z = tft.width();
  for(t = 0 ; t <= 15; t++) {
    tft.drawTriangle(w, y, y, x, z, x, color);
    x-=4;
    y+=4;
    z-=4;
    color+=100;
  }
}
