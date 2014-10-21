#if !defined (Monster_H)
#define Monster_H

#include "Attaque.h"
#include "IGameObject.h"
#include <Gamebuino.h>

class Monster 
{
  public:
  	int Vie;
  	int Force;
  	int Vitesse;
  	int Type;
  	char[] name;
  	int Numero;//permet de savoir a quel monstre on a affaire

  	void AddAttaque(Attaque atta)
  private:
  	Attaque[] Attaques;
};


#endif
