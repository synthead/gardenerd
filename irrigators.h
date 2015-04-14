#ifndef IRRIGATORS_H
#define IRRIGATORS_H

#include "mcp3008.h"
#include "relays.h"

#define IRRIGATOR_COUNT 8

namespace Irrigators {
  class Irrigator {
      Relays::Relay* relay;
      MCP3008::MCP3008* mcp3008;
      uint8_t channel;
      uint16_t desired_moisture;
    public:
      Irrigator(Relays::Relay*, MCP3008::MCP3008*, uint8_t, uint16_t);
      void check_sensor();
  };

  void check_irrigators();

  extern Irrigator irrigators[IRRIGATOR_COUNT];
}

#endif
