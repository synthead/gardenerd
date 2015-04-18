#ifndef IRRIGATORS_H
#define IRRIGATORS_H

#include "mcp3008.h"
#include "relays.h"

#define IRRIGATOR_COUNT 8

namespace Irrigators {
  class Irrigator {
      Relays::Relay* relay;
      MCP3008::MCP3008* mcp3008;
      uint8_t mcp3008_channel;

      uint16_t desired_moisture;
      uint8_t watering_time;
      uint8_t wait_time;

      unsigned long watering_timeout;
      unsigned long wait_timeout;

      uint8_t state;
    public:
      Irrigator(
          Relays::Relay*, MCP3008::MCP3008*, uint8_t, uint16_t, uint8_t,
          uint8_t);
      void check_irrigator();
  };

  void check_irrigators();

  extern Irrigator irrigators[IRRIGATOR_COUNT];
}

#endif
