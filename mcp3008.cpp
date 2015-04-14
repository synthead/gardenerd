#include "mcp3008.h"
#include <Arduino.h>
#include <SPI.h>

namespace MCP3008 {
  MCP3008::MCP3008(uint8_t a):
    chip_select(a) {
      pinMode(chip_select, OUTPUT);
      digitalWrite(chip_select, HIGH);
  }
  
  uint16_t MCP3008::read(uint8_t channel) {
    digitalWrite(chip_select, LOW);
  
    SPI.transfer((channel << 2) + 0b01100000);
    uint16_t value = SPI.transfer(0) << 2;
    value += (SPI.transfer(0) & 0b11000000) >> 6;
  
    digitalWrite(chip_select, HIGH);
  
    return value;
  }

  MCP3008 mcp3008(10);
}
