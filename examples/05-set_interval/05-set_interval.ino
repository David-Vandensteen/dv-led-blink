#include <Arduino.h>
#include <dv_led_blink.h>

#define BUTTON_PIN 2

DV_LedBlink led;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  led.init(LED_BUILTIN, 500); // Default interval: 500ms
}

void loop() {
  led.update();
  static bool lastButtonState = true;
  bool buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == LOW && lastButtonState == true) { // Button press detected
    static bool fast = false;
    fast = !fast;
    led.setInterval(fast ? 100 : 500); // Toggle between 100ms and 500ms
  }
  lastButtonState = (buttonState == HIGH);
}
