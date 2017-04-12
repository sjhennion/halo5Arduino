/*
  Digital Pot Control

  This example controls an Analog Devices AD5206 digital potentiometer.
  The AD5206 has 6 potentiometer channels. Each channel's pins are labeled
  A - connect this to voltage
  W - this is the pot's wiper, which changes when you set it
  B - connect this to ground.

 The AD5206 is SPI-compatible,and to command it, you send two bytes,
 one with the channel number (0 - 5) and one with the resistance value for the
 channel (0 - 255).

 The circuit:
  * All A pins  of AD5206 connected to +5V
  * All B pins of AD5206 connected to ground
  * An LED and a 220-ohm resisor in series connected from each W pin to ground
  * CS - to digital pin 10  (SS pin)
  * SDI - to digital pin 11 (MOSI pin)
  * CLK - to digital pin 13 (SCK pin)

 created 10 Aug 2010
 by Tom Igoe

 Thanks to Heather Dewey-Hagborg for the original tutorial, 2005

*/

// inslude the SPI library:
#include <SPI.h>


unsigned long time;
unsigned long lastChangeTime;
boolean changeDirection = 1;
int channel = 0;

// set pin 10 as the slave select for the digital pot:
const int slaveSelectPin = 10;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(slaveSelectPin, OUTPUT);
  SPI.begin();
  
  //digitalWrite(slaveSelectPin, LOW);
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(LED_BUILTIN, OUTPUT);
  //pinMode(12, OUTPUT);
  //DDRB = B11111111;
  //PORTB = B00000000;

  time = millis();
  lastChangeTime = millis();

  //Serial.begin(9600);           // set up Serial library at 9600 bps
  
  //Serial.println("Hello world!");  // prints hello with ending line break
  changeDirection = 1; 
  //digitalPotWrite(channel, 128); 
}

// the loop function runs over and over again forever
void loop() {
  digitalPotWrite(channel, 128); 

  /*
    // change the resistance on this channel from min to max:
    for (int level = 0; level < 256; level++) {
      digitalPotWrite(channel, level);
      delay(1000);
    }
    // wait a second at the top:
    //delay(30000);
    
    //digitalPotWrite(channel, 256);
    */
    
   
  
  unsigned long onTime = 660;
  unsigned long offTime = 2500;

  int timeCheck = 1000;

  int curLevel = 0;
  int minLevel = 0;
  int maxLevel = 255;

  //digitalPotWrite(channel, 0);


  time = millis();
  if (changeDirection) {
    if ((time - lastChangeTime) > timeCheck) {
      //PORTB = B00000000;
      //curLevel++;
      /*
      if (curLevel > maxLevel) {
        curLevel--;
        //curLevel = 128;
        changeDirection = 0;
      }
      */
      changeDirection = 0;
      //digitalPotWrite(channel, minLevel);
      lastChangeTime = time;
      //delay(3000);
      //lastChangeType = 0;
      //lastChangeTime = millis();
    }
  } else {
    if ((time - lastChangeTime) > timeCheck) {
      //PORTB = B00000000;
      /*
      curLevel--;
      if (curLevel < minLevel) {
        curLevel++;
        changeDirection = 1;
      }
      */
      changeDirection = 1;
      //digitalPotWrite(channel, maxLevel);
      lastChangeTime = time;
      //lastChangeType = 0;
      //lastChangeTime = millis();
    }
  }    
                
}

void digitalPotWrite(int address, int value) {
  // take the SS pin low to select the chip:
  digitalWrite(slaveSelectPin, LOW);
  //  send in the address and value via SPI:
  SPI.transfer(address);
  SPI.transfer(value);
  // take the SS pin high to de-select the chip:
  digitalWrite(slaveSelectPin, HIGH);
}
