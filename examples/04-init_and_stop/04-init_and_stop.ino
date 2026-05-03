#include <dv_led_blink.h>

const int ledPin = 13;
const int buttonPin = 2;
DV_LedBlink led;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  led.init(ledPin, 200); // Blink LED every 200ms, forever
}

void loop() {
  bool blinking = led.update();

  static bool wasPressed = false;
  bool pressed = (digitalRead(buttonPin) == LOW);

  // On button press: stop if blinking, otherwise restart with another interval
  if (pressed && !wasPressed) {
    static bool fast = false;
    if (blinking) {
      led.stop();
    } else {
      fast = !fast;
      led.init(ledPin, fast ? 50 : 200); // Blink fast or slow
    }
  }
  wasPressed = pressed;
}
