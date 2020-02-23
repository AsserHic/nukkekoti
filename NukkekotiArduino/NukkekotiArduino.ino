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
#define VARINA_MOOTTORI   5

CRGB leds[LEDIEN_MAARA];
uint8_t gHue = 0;

/*
 Alustusrutiini, joka ajetaan vain kerran.
 */
void setup() {
  delay(3000); // Kaynnistysviive
  FastLED.addLeds<LEDIEN_TYYPPI, LED_NAUHAN_OHJAUS, LEDIEN_VARIT>(leds, LEDIEN_MAARA).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(LEDIEN_KIRKKAUS);
}

/*
 Ohjelman toiminnasta huolehtiva paattymaton silmukka.
 */
void loop() {
  fill_rainbow(leds, LEDIEN_MAARA, gHue, 7);
  FastLED.show();
  FastLED.delay(100);
  EVERY_N_MILLISECONDS(20) { gHue++; }
}
