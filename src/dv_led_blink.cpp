#include <Arduino.h>
#include <dv_led_blink.h>

DV_LedBlink::DV_LedBlink() : _pin(0), _state{LOW, 100, FOREVER, 0} {}

DV_LedBlink::DV_LedBlink(uint8_t pin) : _pin(pin), _state{LOW, 100, FOREVER, 0} {
  pinMode(_pin, OUTPUT);
}

DV_LedBlink::DV_LedBlink(uint8_t pin, unsigned long interval) : _pin(pin), _state{LOW, interval, FOREVER, 0} {
  pinMode(_pin, OUTPUT);
}

DV_LedBlink::DV_LedBlink(uint8_t pin, unsigned long interval, uint8_t cycle) : _pin(pin), _state{LOW, interval, cycle, 0} {
  pinMode(_pin, OUTPUT);
}

void DV_LedBlink::init(uint8_t pin, unsigned long interval, uint8_t cycle) {
  _pin = pin;
  _state = State(LOW, interval, cycle, 0);
  pinMode(_pin, OUTPUT);
}

void DV_LedBlink::init(uint8_t pin, unsigned long interval) {
  init(pin, interval, FOREVER);
}

void DV_LedBlink::init(uint8_t pin) {
  init(pin, 100, FOREVER);
}

bool DV_LedBlink::update() {
  bool blinking = (_state.cycle > 0 || _state.cycle == FOREVER);
  if (blinking) {
    unsigned long now = millis();
    if (now - _state.lastChange >= _state.interval) {
      _state.current = !_state.current;
      digitalWrite(_pin, _state.current);
      _state.lastChange = now;
      if (_state.current == LOW && _state.cycle != FOREVER) _state.cycle--;
      blinking = (_state.cycle > 0 || _state.cycle == FOREVER);
    }
  }
  return blinking;
}

void DV_LedBlink::stop() {
  _state.cycle = 0;
  digitalWrite(_pin, LOW);
}