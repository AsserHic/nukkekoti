#ifndef OTSAKE_VALOVASTUS
  #define OTSAKE_VALOVASTUS

class Valovastus {

  private:

     int m_pin;
     int m_min;
     int m_max;

  public:

     Valovastus(int pin);

     boolean valoisaa();

     int kuinkaValoisaa();

};
#endif
