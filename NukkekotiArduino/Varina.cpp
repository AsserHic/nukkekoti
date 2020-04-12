#include <Arduino.h>

#include "Varina.h"

Varina::Varina(int pin) {
  m_pin = pin;
  m_paalla = false;

  pinMode(m_pin, OUTPUT);
}

void Varina::sammuta() {
   m_paalla = false;
   digitalWrite(m_pin, LOW);
}

void Varina::liikuta(int vauhti=8) {
   m_paalla = true;
   analogWrite(m_pin, map(vauhti, 0, 9, 150, 250));
}

void Varina::seuraavaAskel() {
   if (m_paalla) {
      if (random(20) < 1) {
         sammuta();
      } else {
         liikuta(random(10));
      }
   } else if (random(800) < 1) {
      liikuta();
   }
}
