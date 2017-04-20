#include<FastLED.h>

#define NUM_STRIPS 3
#define NUM_LEDS_PER_STRIP 240
#define NUM_LEDS NUM_LEDS_PER_STRIP * NUM_STRIPS

CRGB leds[NUM_STRIPS * NUM_LEDS_PER_STRIP];

// strip pins
const int stripBas = 7; // vert
const int stripMilieu = 2; // jaune
const int stripHaut = 8; // marron

// microphone pin
int micPin = A3;

// microphone value (0 à 250 environ)
int micValue = 0;

void setup() {
	Serial.begin(9600);
	// strip du bas du bas, indice 0 à 239
	FastLED.addLeds<NEOPIXEL, stripBas>(leds, 0, NUM_LEDS_PER_STRIP);
	// strip du milieu, indice 240 à 479
	FastLED.addLeds<NEOPIXEL, stripMilieu>(leds, NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
	// strip du haut, indice 480 à 719
	FastLED.addLeds<NEOPIXEL, stripHaut>(leds, 2 * NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
	// toutes les leds en bleu
	for (int j = 0; j < NUM_LEDS; j++) {
		leds[j] = CRGB(21, 68, 138);
	}
}

void loop() {
	micValue = constrain(analogRead(micPin) * 4, 0, 255);
	FastLED.setBrightness(micValue);
	FastLED.show();
	FastLED.delay(10);
}
