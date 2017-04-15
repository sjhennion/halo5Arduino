#include <SPI.h>

//const byte ledPin = 12;
const byte interruptPin = 2;
volatile byte state = LOW;
int count = 0;

const int slaveSelectPin = 10;
int channel = 0;

void setup() {
// set the slaveSelectPin as an output:
  pinMode(slaveSelectPin, OUTPUT);
  // initialize SPI:
  SPI.begin();

  //pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);

  digitalWrite(slaveSelectPin, LOW);
  //digitalPotWrite(channel, 0);
}

void loop() {
  
}

void blink() {
  count++;

  if (count == 9) {
    //digitalWrite(ledPin, HIGH);  
    digitalPotWrite(channel, 0);
  } else if (count == 10) {
    //digitalWrite(ledPin, LOW);  
    digitalPotWrite(channel, 128);
    count = 0;
  }
  //state = !state;
}

void digitalPotWrite(int address, int value) {
  // take the SS pin low to select the chip:
  
  //  send in the address and value via SPI:
  SPI.transfer(address);
  SPI.transfer(value);
  // take the SS pin high to de-select the chip:
  //digitalWrite(slaveSelectPin, HIGH);
}
