#include <Arduino.h>

#include "Varina.h"

Varina::Varina(int pin) {
  m_pin = pin;
  m_askellaskuri = 0;

  pinMode(m_pin, OUTPUT);
}

void Varina::seuraavaAskel() {
   m_askellaskuri++;
   
   if m_askellaskuri == 1050 {
     digitalWrite(m_pin, LOW);
     m_askellaskuri = 0;
   } else
   if m_askellaskuri > 1000 {
     analogWrite(m_pin, map(m_askellaskuri, 1000, 1050, 100, 200);
   }
}

