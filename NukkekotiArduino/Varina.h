#ifndef OTSAKE_VARINA
  #define OTSAKE_VARINA

class Varina {

  private:

     int m_pin;
     int m_paalla;

  public:

     Varina(int pin);

     void liikuta(int vauhti);

     void sammuta();

     void seuraavaAskel();

};
#endif
