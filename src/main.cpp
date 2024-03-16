#include <Arduino.h>
#include <FastLED.h>

#define DOWN_PIN   18
#define UP_PIN     19

#define RGB_PIN              4
#define RGB_LED_NUM          310
#define BRIGHTNESS           30
#define CHIP_SET             WS2812B
#define COLOR_CODE           GRB
#define TURN_ON_DELAY_SPEED  5

CRGB LEDs[RGB_LED_NUM];

void lightUpLEDs(int numLEDs);
void offUpLEDs(int numLEDs);
void lightDownLEDs(int numLEDs);
void offDownLEDs(int numLEDs);
void turnOffLEDs(void);

void setup() {
  pinMode(DOWN_PIN, INPUT);
  pinMode(UP_PIN, INPUT);

  FastLED.addLeds<CHIP_SET, RGB_PIN, COLOR_CODE>(LEDs, RGB_LED_NUM);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  FastLED.show();
}

void loop() {
  if (digitalRead(UP_PIN)) {
    lightUpLEDs(RGB_LED_NUM);

    delay(1000);

    while (digitalRead(UP_PIN) || digitalRead(DOWN_PIN)) {}

    offUpLEDs(RGB_LED_NUM);
  }

  if (digitalRead(DOWN_PIN)) {
    lightDownLEDs(RGB_LED_NUM);

    delay(1000);

    while (digitalRead(DOWN_PIN) || digitalRead(UP_PIN)) {}

    offDownLEDs(RGB_LED_NUM);
  }
}

void lightDownLEDs(int numLEDs) {
  for (int i = 0; i < numLEDs; i++) {
    LEDs[i] = CRGB(50, 50, 50); // Set the color to grey
    FastLED.show();
    delay(TURN_ON_DELAY_SPEED);
  }
}

void offDownLEDs(int numLEDs) {
  for (int i = 0; i < numLEDs; i++) {
    LEDs[i] = CRGB(0, 0, 0); // Set the led off
    FastLED.show();
    delay(TURN_ON_DELAY_SPEED);
  }
}

void lightUpLEDs(int numLEDs) {
  for (int i = numLEDs-1; i > -1; i--) {
    LEDs[i] = CRGB(50, 50, 50); // Set the color to grey
    FastLED.show();
    delay(TURN_ON_DELAY_SPEED);
  }
}

void offUpLEDs(int numLEDs) {
  for (int i = numLEDs-1; i > -1; i--) {
    LEDs[i] = CRGB(0, 0, 0); // Set the led off
    FastLED.show();
    delay(TURN_ON_DELAY_SPEED);
  }
}

void turnOffLEDs() {
  for (int i = 0; i < RGB_LED_NUM; i++) {
    LEDs[i] = CRGB(0, 0, 0); // Set the LED off
  }
  FastLED.show();
}
