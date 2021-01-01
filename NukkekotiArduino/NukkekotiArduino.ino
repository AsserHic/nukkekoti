/*
 Nukkekodin Arduino-ohjelma
 */

#include <Arduino.h>
#include <FastLED.h>

#include "Valovastus.h"
#include "Varina.h"

FASTLED_USING_NAMESPACE

// Rakenteelliset parametrit
#define LEDIEN_MAARA    30
#define LEDIEN_KIRKKAUS 64
#define LEDIEN_TYYPPI   WS2811
#define LEDIEN_VARIT    GRB

// Arduinon nastat:
#define LED_NAUHAN_OHJAUS 4
#define VARINAMOOTTORI    5
#define KATTOVALAISIN     12
#define VALAISTUS_TILA    A3
#define VALOVASTUS_1      A1
#define VALOVASTUS_2      A2

CRGB leds[LEDIEN_MAARA];
uint8_t gHue = 0;

Valovastus valovastus1 = Valovastus(VALOVASTUS_1);
Valovastus valovastus2 = Valovastus(VALOVASTUS_2);

Varina varina = Varina(VARINAMOOTTORI);

/*
 Alustusrutiini, joka ajetaan vain kerran.
 */
void setup() {
  pinMode(VALAISTUS_TILA, INPUT);
  pinMode(KATTOVALAISIN, OUTPUT);

  digitalWrite(KATTOVALAISIN, false);

  delay(3000); // Kaynnistysviive
  FastLED.addLeds<LEDIEN_TYYPPI,
                  LED_NAUHAN_OHJAUS,
                  LEDIEN_VARIT>(leds, LEDIEN_MAARA).setCorrection(TypicalLEDStrip);
}

/*
 Ohjelman toiminnasta huolehtiva paattymaton silmukka.
 */
void loop() {
  boolean valoisaa1 = valovastus1.valoisaa();
  boolean valoisaa2 = valovastus2.valoisaa();
  boolean valot     = onValotPaalla();

  if (valot || (valoisaa1 && valoisaa2)) {
    FastLED.setBrightness(0);

  } else { // Valot poissa paalta
    FastLED.setBrightness(LEDIEN_KIRKKAUS);
    fill_rainbow(leds, LEDIEN_MAARA, gHue, 7);
    EVERY_N_MILLISECONDS(20) { gHue++; }
  }
  FastLED.show();
  FastLED.delay(100);

  digitalWrite(KATTOVALAISIN, valoisaa2);

  if (valot) {
     varina.seuraavaAskel();
  } else {
     varina.sammuta();
  }
}

boolean onValotPaalla() {
  return digitalRead(VALAISTUS_TILA);
}
