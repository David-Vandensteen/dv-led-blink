#include <dv_led_blink.h>

DV_LedBlink led(13, 50); // Blink LED on pin 13 every 50ms in a non-blocking way

void setup() {}

void loop() {
  led.update();
}
