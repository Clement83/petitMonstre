#if !defined (Attaque_H)
#define Attaque_H
#include <stdint.h>

class Attaque 
{
  public:
  Attaque();
    uint8_t Type;//type attaque eau feux terre
    uint8_t Force;
    uint8_t Numero;//Numeros de l'attaque parmis toutes
    uint8_t Index;
};

#endif 

