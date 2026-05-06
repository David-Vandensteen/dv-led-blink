#include <Arduino.h>
#include <dv_led_blink.h>

#define BUTTON_PIN 2

DV_LedBlink led;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  led.init(LED_BUILTIN, 200, 3);
}

void loop() {
  led.update();
  static bool lastButtonState = true;
  bool buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == LOW && lastButtonState == true) { // Button press detected
    static uint8_t cycles[] = {1, 3, 5, 10, DV_LedBlink::FOREVER};
    static uint8_t idx = 0;
    idx = (idx + 1) % 5;
    led.setCycle(cycles[idx]);
  }
  lastButtonState = (buttonState == HIGH);
}
