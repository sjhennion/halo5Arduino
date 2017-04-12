#include <Servo.h> 

class Flasher
{
  // Class Member Variables
  // These are initialized at startup
  int ledPin;      // the number of the LED pin
  long OnTime;     // milliseconds of on-time
  long OffTime;    // milliseconds of off-time

  // These maintain the current state
  int ledState;                 // ledState used to set the LED
  unsigned long previousMillis;   // will store last time LED was updated

  // Constructor - creates a Flasher 
  // and initializes the member variables and state
  public:
  Flasher(int pin, long on, long off)
  {
  ledPin = pin;
  pinMode(ledPin, OUTPUT);     
    
  OnTime = on;
  OffTime = off;
  
  ledState = LOW; 
  previousMillis = 0;
  }

  void Update(unsigned long currentMillis)
  {
    if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
    {
      ledState = LOW;  // Turn it off
      previousMillis = currentMillis;  // Remember the time
      digitalWrite(ledPin, ledState);  // Update the actual LED
    }
    else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
    {
      ledState = HIGH;  // turn it on
      previousMillis = currentMillis;   // Remember the time
      digitalWrite(ledPin, ledState);   // Update the actual LED
    }
  }
};

 
Flasher led1(13, 500, 4000);

void setup() 
{ 
  // Timer0 is already used for millis() - we'll just interrupt somewhere
  // in the middle and call the "Compare A" function below
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);
} 

// 238.35:292.94 = 54.59
// 292.94:347.54 = 54.6
// 6.23:60.82 = 54.59
// 60.82:112.94 = 52.12
// 112.94:167.54 = 54.6
// 167.54:222.13 = 54.59
// 222.13:274.25 = 52.12
// 274.25:328.85 = 54.6
// 328.85:23.45 = 54.6
// 23.45:75.57 = 52.12
// 
 
// Interrupt is called once a millisecond, looks for any new GPS data, and stores it
SIGNAL(TIMER0_COMPA_vect) 
{
  unsigned long currentMillis = millis();

  /*
  if(digitalRead(2) == HIGH)
  {
     //sweeper2.Update(currentMillis);
     //led1.Update(currentMillis);
  }
  */

  led1.Update(currentMillis);
  
  //led2.Update(currentMillis);
  //led3.Update(currentMillis);
} 

void loop()
{
}
