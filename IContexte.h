#if !defined (IContexte_H)
#define IContexte_H

#include <Gamebuino.h>
#include "IGameObject.h"
#include "Player.h"

class IContexte 
{
  public:
      IContexte();
  	Player Joueur;
  	Player Monster;
  	Player Dresseur;
  	Player Joueur2;
  	int TypeAdversaire;//0 Monster, 1 Dresseur, 2 Joueur2
};
#endif 
