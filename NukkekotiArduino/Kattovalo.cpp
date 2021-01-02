#include <Arduino.h>

#include "Kattovalo.h"

Kattovalo::Kattovalo(int pin) {
  m_pin = pin;
  m_paalla = false;

  pinMode(m_pin, OUTPUT);
}

void Kattovalo::sammuta() {
   m_paalla = false;
   digitalWrite(m_pin, LOW);
}

void Kattovalo::sytyta() {
   m_paalla = true;
   digitalWrite(m_pin, HIGH);
}

boolean Kattovalo::seuraavaAskel(boolean pimeaa) {
   long    arpa   = random(500);
   boolean touhua = false;  // Joku puuhastelee huoneessa.

   if (m_paalla) {
      if (arpa < (pimeaa ? 2 : 3)) {
         sammuta();
      } else if (arpa < 20) {
         digitalWrite(m_pin, LOW);
         touhua = !pimeaa && (arpa > 300);
      } else if (arpa > 400) {
         digitalWrite(m_pin, HIGH);
      }
   } else if (arpa < (pimeaa ? 2 : 1)) {
      sytyta();
   }
   return touhua;
}
