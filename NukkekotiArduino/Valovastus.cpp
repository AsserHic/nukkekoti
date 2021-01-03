#include <Arduino.h>

#include "Valovastus.h"

Valovastus::Valovastus(int pin, int threshold) {
  m_pin = pin;
  m_threshold = threshold;

  pinMode(m_pin, INPUT);
}

boolean Valovastus::valoisaa() {
   return kuinkaValoisaa() > m_threshold;
}

int Valovastus::kuinkaValoisaa() {
  int mittaus = analogRead(m_pin);

  m_min = min(m_min, mittaus);
  m_max = max(m_max, mittaus);
  
  return map(mittaus, m_min, m_max, 0, 9);
}
