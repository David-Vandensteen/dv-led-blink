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
#include <dv_led_blink.h>

DV_LedBlink led(13); // Blink LED on pin 13 every 100ms (default) in a non-blocking way

void setup() {}

void loop() {
	led.update();
}
```

### Cycle Example
```cpp
#include <dv_led_blink.h>

DV_LedBlink led(13, 500, 15); // Blink LED on pin 13 every 500ms for 15 cycles (non-blocking)

void setup() {}

void loop() {
	led.update();
}
```

### Explicit Infinite Blink Example
```cpp
#include <dv_led_blink.h>

DV_LedBlink led(13, 50, DV_LedBlink::FOREVER); // Blink LED on pin 13 every 50ms in a non-blocking way

void setup() {}

void loop() {
	led.update();
}
```

## API

**Constructor:**
- `DV_LedBlink(uint8_t pin)`
- `DV_LedBlink(uint8_t pin, unsigned long interval)`
- `DV_LedBlink(uint8_t pin, unsigned long interval, uint8_t cycle = DV_LedBlink::FOREVER)`

**Methods:**
- `void update()` — Call as often as possible in `loop()`

**Constant:**
- `DV_LedBlink::FOREVER` — Use for infinite blinking

## License

MIT License — see [LICENSE](LICENSE)

## Author

David Vandensteen
