#include "irrigators.h"

namespace Irrigators {
  Irrigator::Irrigator(Relays::Relay* a, MCP3008::MCP3008* b, uint8_t c, uint16_t d):
    relay(a), mcp3008(b), channel(c), desired_moisture(d) {}
  
  void Irrigator::check_sensor() {
    if (mcp3008->read(channel) < desired_moisture) {
      relay->cycle();
    }
  }

  Irrigator irrigators[IRRIGATOR_COUNT] = {
      {&Relays::relays[0], &MCP3008::mcp3008, 0, 500},
      {&Relays::relays[1], &MCP3008::mcp3008, 1, 500},
      {&Relays::relays[2], &MCP3008::mcp3008, 2, 500},
      {&Relays::relays[3], &MCP3008::mcp3008, 3, 500},
      {&Relays::relays[4], &MCP3008::mcp3008, 4, 500},
      {&Relays::relays[5], &MCP3008::mcp3008, 5, 500},
      {&Relays::relays[6], &MCP3008::mcp3008, 6, 500},
      {&Relays::relays[7], &MCP3008::mcp3008, 7, 500}
  };

  void check_irrigators() {
    for (uint8_t irrigator = 0; irrigator < IRRIGATOR_COUNT; irrigator++) {
      irrigators[irrigator].check_sensor();
    }
  }
}
