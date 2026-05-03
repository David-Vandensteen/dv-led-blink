#include <Arduino.h>
#include <dv_led_blink.h>

DV_LedBlink led(); // Blink LED on pin LED_BUILTIN or 13 (default) every 100ms (default) in a non-blocking way
// DV_LedBlink led(10); // Blink LED on pin 10 every 100ms (default) in a non-blocking way

void setup() {}

void loop() {
  led.update();
}
