#include "irrigators.h"
#include <Arduino.h>

#define IRRIGATOR_STATE_READY 0
#define IRRIGATOR_STATE_WATERING 1
#define IRRIGATOR_STATE_WAITING 2

namespace Irrigators {
  Irrigator::Irrigator(
      Relays::Relay* a, MCP3008::MCP3008* b, uint8_t c, uint16_t d, uint8_t e,
      uint8_t f):
    relay(a), mcp3008(b), mcp3008_channel(c), desired_moisture(d), watering_time(e),
    wait_time(f) {
      state = IRRIGATOR_STATE_READY;
  }
  
  void Irrigator::check_irrigator() {
    switch (state) {
      case IRRIGATOR_STATE_READY:
        if (mcp3008->read(mcp3008_channel) < desired_moisture &&
            relay->set(HIGH)) {
          watering_timeout = millis() + watering_time * 1000;
          wait_timeout = watering_timeout + wait_time * 1000;
          state = IRRIGATOR_STATE_WATERING;
        }
        break;
      case IRRIGATOR_STATE_WATERING:
        if (millis() >= watering_timeout) {
          relay->set(LOW);
          state = IRRIGATOR_STATE_WAITING;
        }
        break;
      case IRRIGATOR_STATE_WAITING:
        if (millis() >= wait_timeout) {
          state = IRRIGATOR_STATE_READY;
        }
        break;
    }
  }

  Irrigator irrigators[IRRIGATOR_COUNT] = {
      {&Relays::relays[0], &MCP3008::mcp3008, 7, 600, 5, 20},
      {&Relays::relays[1], &MCP3008::mcp3008, 6, 900, 5, 20},
      {&Relays::relays[2], &MCP3008::mcp3008, 5, 600, 5, 20},
      {&Relays::relays[3], &MCP3008::mcp3008, 4, 800, 5, 20},
      {&Relays::relays[4], &MCP3008::mcp3008, 3, 600, 5, 20},
      {&Relays::relays[5], &MCP3008::mcp3008, 2, 800, 5, 20},
      {&Relays::relays[6], &MCP3008::mcp3008, 1, 800, 5, 20},
      {&Relays::relays[7], &MCP3008::mcp3008, 0, 800, 5, 20}
  };

  void check_irrigators() {
    for (uint8_t irrigator = 0; irrigator < IRRIGATOR_COUNT; irrigator++) {
      irrigators[irrigator].check_irrigator();
    }
  }
}
