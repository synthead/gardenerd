#include "relays.h"
#include <Arduino.h>

#define RELAY_STATE_READY 0
#define RELAY_STATE_WATERING 1
#define RELAY_STATE_WAITING 2

namespace Relays {
  Relay::Relay(uint8_t a, uint8_t b, uint8_t c):
    pin(a), watering_time(b), wait_time(c) {
      pinMode(pin, OUTPUT);
      digitalWrite(pin, LOW);
      state = RELAY_STATE_READY;
  }
  
  void Relay::cycle() {
    if (state == RELAY_STATE_READY) {
      watering_timeout = millis() + watering_time * 1000;
      wait_timeout = watering_timeout + wait_time * 1000;
      state = RELAY_STATE_WATERING;
  
      digitalWrite(pin, HIGH);
    }
  }
  
  void Relay::check_state() {
    switch (state) {
      case RELAY_STATE_WATERING:
        if (millis() >= watering_timeout) {
          digitalWrite(pin, LOW);
          state = RELAY_STATE_WAITING;
        }
        break;
      case RELAY_STATE_WAITING:
        if (millis() >= wait_timeout) {
          state = RELAY_STATE_READY;
        }
        break;
    }
  }

  void check_states() {
    for (uint8_t relay = 0; relay < RELAY_COUNT; relay++) {
      relays[relay].check_state();
    }
  }

  Relay relays[RELAY_COUNT] = {
      {0, 5, 20},
      {1, 5, 20},
      {2, 5, 20},
      {3, 5, 20},
      {4, 5, 20},
      {5, 5, 20},
      {6, 5, 20},
      {7, 5, 20}
  };
}
