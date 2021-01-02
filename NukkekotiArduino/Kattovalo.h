#ifndef OTSAKE_KATTOVALO
  #define OTSAKE_KATTOVALO

class Kattovalo {

  private:

     int m_pin;
     int m_paalla;

  public:

     Kattovalo(int pin);

     void sammuta();

     void sytyta();

     boolean seuraavaAskel(boolean pimeaa);

};
#endif
