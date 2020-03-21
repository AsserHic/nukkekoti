/*
 Nukkekodin Arduino-ohjelma
 */

#include <Arduino.h>
#include <FastLED.h>

FASTLED_USING_NAMESPACE

// Rakenteelliset parametrit
#define LEDIEN_MAARA    30
#define LEDIEN_KIRKKAUS 64
#define LEDIEN_TYYPPI   WS2811
#define LEDIEN_VARIT    GRB

// Arduinon nastat:
#define LED_NAUHAN_OHJAUS 4
#define VARINAMOOTTORI    5
#define VALAISTUS_TILA    A3
#define VALOVASTUS_1      A1
#define VALOVASTUS_2      A2

CRGB leds[LEDIEN_MAARA];
uint8_t gHue = 0;

/*
 Alustusrutiini, joka ajetaan vain kerran.
 */
void setup() {
  pinMode(VALAISTUS_TILA, INPUT);
  pinMode(VALOVASTUS_1,   INPUT);
  pinMode(VALOVASTUS_2,   INPUT);

  pinMode(VARINAMOOTTORI, OUTPUT);

  delay(3000); // Kaynnistysviive
  FastLED.addLeds<LEDIEN_TYYPPI,
                  LED_NAUHAN_OHJAUS,
                  LEDIEN_VARIT>(leds, LEDIEN_MAARA).setCorrection(TypicalLEDStrip);
}

/*
 Ohjelman toiminnasta huolehtiva paattymaton silmukka.
 */
void loop() {
  if (onValotPaalla()) {
    FastLED.setBrightness(0);

  } else { // Valot poissa paalta
    FastLED.setBrightness(LEDIEN_KIRKKAUS);
    fill_rainbow(leds, LEDIEN_MAARA, gHue, 7);
    EVERY_N_MILLISECONDS(20) { gHue++; }
  }
  FastLED.show();
  FastLED.delay(100);
}

boolean onValotPaalla() {
  return digitalRead(VALAISTUS_TILA);
}

