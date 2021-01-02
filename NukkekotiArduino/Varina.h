#ifndef OTSAKE_VARINA
  #define OTSAKE_VARINA

class Varina {

  private:

     int m_pin;
     int m_paalla;

  public:

     Varina(int pin);

     boolean paalla();

     void liikuta(int vauhti=8);

     void sammuta();

     void seuraavaAskel();

};
#endif
