#include <Charlieplex.h>

#define NUMBER_OF_PINS 3
//define pins in the order you want to adress them
byte pins[] = {A0,A1,A2};

//initialize object
Charlieplex charlieplex = Charlieplex(pins,NUMBER_OF_PINS);

boolean singleOn = false;
int N = NUMBER_OF_PINS;


void setup(){
}

void loop(){

  charlieplex.turnOn(1);
  delay(2000);
  charlieplex.turnOn(2);
  delay(2000);
  charlieplex.turnOn(3);
  delay(2000);
  charlieplex.turnOn(4);
  delay(2000);
  charlieplex.turnOn(5);
  delay(2000);
  charlieplex.turnOn(6);
  delay(2000);
  charlieplex.turnOff(6);
  delay(2000);
  charlieplex.turnOff(5);
  delay(2000);
  charlieplex.turnOff(4);
  delay(2000);
  charlieplex.turnOff(3);
  delay(2000);
  charlieplex.turnOff(2);
  delay(2000);
  charlieplex.turnOff(1);
  delay(5000);

}
