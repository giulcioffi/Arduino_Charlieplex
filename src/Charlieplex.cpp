#include "Charlieplex.h"

Charlieplex::Charlieplex(uint8_t* userPins, uint8_t numberOfUserPins){
	pins = userPins;
	numberOfPins = numberOfUserPins;
	clear();
	mapPins();
}

void Charlieplex::mapPins(){
	int count = 0;
	for(int i = 0; i < numberOfPins; i++) {
		for(int j = 0; j<(((numberOfPins*2)-(2*(i+1)))/2); j++) {
		leds[count] = { i, (numberOfPins-1-j)};
		count = count + 1;
		leds[count] = { (numberOfPins-1-j), i };
		count = count + 1;
		}
	}
}

void Charlieplex::turnOn(uint8_t led){
	setVcc(leds[led-1].vcc);
	setGnd(leds[led-1].gnd);
}

void Charlieplex::turnOff(uint8_t led){
	clearVcc(leds[led-1].vcc);
}

//set a pin HIGH 
void Charlieplex::setVcc(uint8_t pin){
	pinMode( pins[pin] , OUTPUT );
	digitalWrite( pins[pin] , HIGH );
}

//set a pin LOW 
void Charlieplex::setGnd(uint8_t pin){
	pinMode( pins[pin] , OUTPUT );
	digitalWrite( pins[pin] , LOW );
}

void Charlieplex::clearVcc(uint8_t pin){
	pinMode( pins[pin] , INPUT );
}

//set all as input
void Charlieplex::clear(){
	for (uint8_t i=0; i<numberOfPins; i++){
		pinMode( pins[i] , INPUT);
	}
}