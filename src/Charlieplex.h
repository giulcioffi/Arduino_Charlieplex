#ifndef CHARLIEPLEX_H
#define CHARLIEPLEX_H

#include <Arduino.h>

struct charliePin {
	uint8_t vcc;
	uint8_t gnd;
};

//typedef CharliePin charliePin;

class Charlieplex {

#define INDEX 1
#define NUMBER_OF_STATUSES ((_numberOfPins*_numberOfPins)-_numberOfPins)

public:
	Charlieplex(uint8_t* userPins, uint8_t numberOfUserPins);

	void mapPins();

	void turnOn(uint8_t led);
	void turnOff(uint8_t led);
	
	void setVcc(uint8_t pin);
	void setGnd(uint8_t pin);
	void clearVcc(uint8_t pin);
	
	void clear();
	
private:
	uint8_t numberOfPins;
	uint8_t* pins;
	charliePin leds[380];
};

#endif

