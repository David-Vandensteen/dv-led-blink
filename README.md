# dv_led_blink
Simple Arduino library to blink an LED in a non-blocking way.

## Installation

### Via Arduino Library Manager (recommended)
1. Open the Arduino IDE
2. Go to Tools > Manage Libraries...
3. Search for "dv_led_blink"
4. Click Install

### Manual
1. Download this repository as a ZIP file.
2. In the Arduino IDE, go to Sketch > Include Library > Add .ZIP Library...
3. Select the downloaded ZIP file to install the library.

## Features
- Non-blocking LED blinking (does not use delay)
- Easy to use API
- Customizable interval and number of cycles
- Forever mode with `DV_LedBlink::FOREVER`

## Usage

### Basic Example
```cpp
#include <Arduino.h>
#include <dv_led_blink.h>

DV_LedBlink led; // Blink LED on pin LED_BUILTIN or 13 (default) every 100ms (default) in a non-blocking way
// DV_LedBlink led(10); // Blink LED on pin 10 every 100ms (default) in a non-blocking way

void setup() {}

void loop() {
	led.update();
}
```

### Cycle Example
```cpp
#include <Arduino.h>
#include <dv_led_blink.h>

DV_LedBlink led(13, 500, 15); // Blink LED on pin 13 every 500ms for 15 cycles (non-blocking)

void setup() {}

void loop() {
	led.update();
}
```

### Interval
```cpp
#include <Arduino.h>
#include <dv_led_blink.h>

DV_LedBlink led(13, 50); // Blink LED on pin 13 every 50ms in a non-blocking way
// DV_LedBlink led(13, 50, DV_LedBlink::FOREVER); with explicit cycle parameter

void setup() {}

void loop() {
	led.update();
}
```

### Init and Stop Example
```cpp
#include <Arduino.h>
#include <dv_led_blink.h>

const uint8_t ledPin = 13;
const uint8_t buttonPin = 2;
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
```
This example demonstrates how to use `stop()` to halt blinking and how to restart with a different interval on each button press.

## API

**Constructors:**
- `DV_LedBlink()`
- `DV_LedBlink(uint8_t pin)`
- `DV_LedBlink(uint8_t pin, unsigned long interval)`
- `DV_LedBlink(uint8_t pin, unsigned long interval, uint8_t cycle)`

**Methods:**
- `void init()`
- `void init(uint8_t pin)`
- `void init(uint8_t pin, unsigned long interval)`
- `void init(uint8_t pin, unsigned long interval, uint8_t cycle)`
- `void setInterval(unsigned long interval)` — Change the blink interval on the fly
- `void setCycle(uint8_t cycle)` — Set or reset the number of remaining cycles
- `bool update()` — Call as often as possible in `loop()`, returns true if blinking is active
- `void stop()` — Stops blinking and turns off the LED

**Constant:**
- `DV_LedBlink::FOREVER` — Use for infinite blinking

## License

MIT License — see [LICENSE](LICENSE)

## Author

David Vandensteen
