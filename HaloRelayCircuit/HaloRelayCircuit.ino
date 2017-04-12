/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi  
  
  modified 8 Sep 2016
  by Colby Newman
*/
unsigned long time;
unsigned long lastChangeTime;
boolean lastChangeType = 0;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(LED_BUILTIN, OUTPUT);
  //pinMode(12, OUTPUT);
  DDRB = B11111111;
  PORTB = B00000000;

  time = millis();
  lastChangeTime = millis();

  //Serial.begin(9600);           // set up Serial library at 9600 bps
  
  //Serial.println("Hello world!");  // prints hello with ending line break 
}

// the loop function runs over and over again forever
void loop() {
  //digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  //DDRB = DDRB | B10000000;

  //91.73:355.33 = 263.6
  //2.53:266.14 = 263.61
  //2.83:266.45 = 263.62
  //0.97:264.59 = 263.62

  //500: 15.90->107.65 = 91.75
  //495: 107.65->194.79 = 87.14
  //499: 194.79->291.26 = 97.17
  //500: 23.01->114.76 = 91.75
  //499: 114.76->206.51 = 91.75
  //499: 206.51->298.26 = 91.75
  //498: 4.35->96.10 = 91.75
  //495: 96.10->183.24 = 87.14
  //494: 183.24->270.36 = 87.12
  //497: 2.26->94.01 = 91.75
  //496: 94.01->185.77 = 91.76
  //495: 185.77->272.90 = 87.13
  //501: 5.93->97.68 = 92.67
  //502: 97.68->189.43 = 91.75
  //503: 189.43->285.90 = 96.47
  //503: 5.39->101.86 = 96.47
  //500: 0.20->91.95 = 91.75

  unsigned long onTime = 660;
  unsigned long offTime = 2500;
  
  time = millis();
  if (lastChangeType) {
    if ((time - lastChangeTime) > onTime) {
      PORTB = B00000000;
      lastChangeType = 0;
      lastChangeTime = time;
      //lastChangeTime = millis();
    }
  } else {
    if ((time - lastChangeTime) > offTime) {
      PORTB = B11111111;
      lastChangeType = 1;
      lastChangeTime = time;
      //lastChangeTime = millis();
    }
  }
  
  //PORTB = B11111111;
  //delay(492);
  // 491 - 0.07:87.2
  // 492 - 359.98:91.73
  //delayMicroseconds(448000);                       // wait for a second
  
  //digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  //delay(2000);
  //delayMicroseconds(1000000); // wait for 2 second
  //digitalWrite(13, HIGH);
  //delay(50); // wait for 2 second
  //digitalWrite(13, LOW);
  //Serial.println("In loop!");  // prints hello with ending line break 
  //delay(10000);                       // wait for a second
}
