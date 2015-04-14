#ifndef MCP3008_H
#define MCP3008_H

#include <stdint.h>

namespace MCP3008 {
  class MCP3008 {
      uint8_t chip_select;
    public:
      MCP3008(uint8_t);
      uint16_t read(uint8_t);
  };

  extern MCP3008 mcp3008;
}

#endif
