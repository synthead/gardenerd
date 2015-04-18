#ifndef RELAYS_H
#define RELAYS_H

#include <stdint.h>
#include <stdbool.h>

#define RELAY_COUNT 8

namespace Relays {
  class Relay {
      uint8_t pin;
      uint8_t ma_rating;
    public:
      Relay(uint8_t, uint16_t);
      bool set(bool);
  };

  extern Relay relays[RELAY_COUNT];
}

#endif
