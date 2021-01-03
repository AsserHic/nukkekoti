#ifndef OTSAKE_VALOVASTUS
  #define OTSAKE_VALOVASTUS

class Valovastus {

  private:

     int m_pin;
     int m_min;
     int m_max;
     int m_threshold;

  public:

     Valovastus(int pin, int threshold=4);

     boolean valoisaa();

     int kuinkaValoisaa();

};
#endif
