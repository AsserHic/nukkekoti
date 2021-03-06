/*
 Nukkekodin Arduino-ohjelma
 */

#include <Arduino.h>
#include <FastLED.h>

#include "Kattovalo.h"
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

Kattovalo kattovalo = Kattovalo(KATTOVALAISIN);

Valovastus valovastus1 = Valovastus(VALOVASTUS_1, 3);
Valovastus valovastus2 = Valovastus(VALOVASTUS_2);

Varina varina = Varina(VARINAMOOTTORI);

/*
 Alustusrutiini, joka ajetaan vain kerran.
 */
void setup() {
  pinMode(VALAISTUS_TILA, INPUT);

  delay(3000); // Kaynnistysviive
  FastLED.addLeds<LEDIEN_TYYPPI,
                  LED_NAUHAN_OHJAUS,
                  LEDIEN_VARIT>(leds, LEDIEN_MAARA).setCorrection(TypicalLEDStrip);

  varina.liikuta();
}

/*
 Ohjelman toiminnasta huolehtiva paattymaton silmukka.
 */
void loop() {
  boolean valoisaa1 = valovastus1.valoisaa();
  boolean valoisaa2 = valovastus2.valoisaa();
  boolean valot     = onValotPaalla();

  if (valot || valoisaa2) {
    FastLED.setBrightness(0);

  } else { // Valot poissa paalta ja pimeaa
    FastLED.setBrightness(LEDIEN_KIRKKAUS);
    fill_rainbow(leds, LEDIEN_MAARA, gHue, 7);
    EVERY_N_MILLISECONDS(20) { gHue++; }
  }
  if (varina.paalla()) {
    leds[random16(LEDIEN_MAARA)] += CRGB::White;
  }
  FastLED.show();
  FastLED.delay(100);

  if (kattovalo.seuraavaAskel(!valoisaa1)) {
     varina.liikuta();
  }

  if (valot || varina.paalla()) {
     varina.seuraavaAskel();
  }
}

boolean onValotPaalla() {
  return digitalRead(VALAISTUS_TILA);
}
