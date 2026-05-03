#include <Arduino.h>
#include <dv_led_blink.h>

DV_LedBlink led(13); // Blink LED on pin 13 every 100ms (default) in a non-blocking way

void setup() {}

void loop() {
  led.update();
}
