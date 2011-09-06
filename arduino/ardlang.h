#include "pins_arduino.h"

uint8_t set(uint8_t pin, uint8_t state) {
	if (state < 2) {
		digitalWrite(pin, state);
	} else {
		analogWrite(pin, state-2);
	}
	return 1;
}

uint8_t get(uint8_t pin) {
	// mask
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);
	volatile uint8_t *out;	

	// pins
	out = portOutputRegister(port);

	uint8_t pinvalue;
	pinvalue = *out & bit;

	if (pinvalue > 0) {
		return 1;
	} else {
		return 0;
	}
}

uint8_t wait(unsigned long miliseconds) {
	delay(miliseconds);
	return 1;
}

uint8_t read(uint8_t pin) {
	return digitalRead(pin);
}

