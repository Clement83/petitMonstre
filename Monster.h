#if !defined (Monster_H)
#define Monster_H

#include "Attaque.h"

class Monster 
{
  public:
        Monster();
  	int Vie;
  	int Force;
  	int Vitesse;
  	int Type;
  	char* Name;
  	int Numero;//permet de savoir a quel monstre on a affaire
    int Index;//index dans le tableau des monstre du joueur
    void AddAttaque(Attaque atta);
    void RemoveAttaque(Attaque atta);
    Attaque* ListAttaque();
    Attaque UseAttaque(int index);
    bool IsFull();
  protected:
   static int const maxAttaque = 4;
    int nbAttaque;
  	Attaque* Attaques;
};


#endif

