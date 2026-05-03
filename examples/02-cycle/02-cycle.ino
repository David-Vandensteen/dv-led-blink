#include <dv_led_blink.h>

DV_LedBlink led(13, 500, 15); // Blink LED on pin 13 every 500ms for 15 cycles (non-blocking)

void setup() {}

void loop() {
  led.update();
}
