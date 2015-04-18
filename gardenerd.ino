#include "irrigators.h"
#include "relays.h"
#include <SPI.h>

void setup() {
  SPI.begin();
}

void loop() {
  Irrigators::check_irrigators();
}
