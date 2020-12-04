#include "Charlieplex.h"

Charlieplex::Charlieplex(uint8_t* userPins, uint8_t numberOfUserPins):
	led_th(osPriorityNormal, 2048, NULL, "led_thread")
	{
	pins = userPins;
	numberOfPins = numberOfUserPins;
	numberOfLEDs = (numberOfUserPins*numberOfUserPins)-numberOfUserPins;
	clear();
	mapPins();
	led_th.start(mbed::callback(this, &Charlieplex::roundAmongLed));
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

void Charlieplex::roundAmongLed(){
	while (1) {
		int numOn = 0;
		for(int k=0; k<numberOfLEDs;k++){
			if(ledON[k]){
				numOn = numOn + 1;
				clear();
				setVcc(leds[k].vcc);
				setGnd(leds[k].gnd);
			}
			if (!numOn) {
				clear();
			}
		}
	}
}

void Charlieplex::turnOn(uint8_t led){
	ledON[led-1]=1;
}

void Charlieplex::turnOff(uint8_t led){
	ledON[led-1]=0;
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