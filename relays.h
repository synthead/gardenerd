#ifndef RELAYS_H
#define RELAYS_H

#include <stdint.h>

#define RELAY_COUNT 8

namespace Relays {
  class Relay {
      uint8_t pin;
      uint8_t watering_time;
      uint8_t wait_time;
      
      unsigned long watering_timeout;
      unsigned long wait_timeout;
  
      uint8_t state;
    public:
      Relay(uint8_t, uint8_t, uint8_t);
      void cycle();
      void check_state();
  };

  void check_states();

  extern Relay relays[RELAY_COUNT];
}

#endif
