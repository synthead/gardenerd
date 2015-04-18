#include "relays.h"
#include <Arduino.h>

#define SYSTEM_MA 40
#define TOTAL_MA_MAX 4000

namespace Relays {
  uint16_t total_ma = SYSTEM_MA;

  Relay::Relay(uint8_t a, uint16_t b):
    pin(a), ma_rating(b) {
      pinMode(pin, OUTPUT);
  }
  
  bool Relay::set(bool state) {
    bool return_value = false;

    switch (state) {
      case HIGH:
        if (total_ma + ma_rating <= TOTAL_MA_MAX) {
          total_ma += ma_rating;
          digitalWrite(pin, HIGH);
          return_value = true;
        }

        break;
      case LOW:
        total_ma -= ma_rating;
        digitalWrite(pin, LOW);

        break;
    }

    return return_value;
  }

  Relay relays[RELAY_COUNT] = {
      {0, 470},
      {1, 470},
      {2, 470},
      {3, 470},
      {4, 470},
      {5, 470},
      {6, 470},
      {7, 470}
  };
}
