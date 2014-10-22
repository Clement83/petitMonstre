#if !defined (Player_H)
#define Player_H

#include "Monster.h"
class Player
{
  public:
      Player();
  	int PosX;
  	int PosY;
  	int Area;
    bool IsMonster;//permet de savoir si on est sur un monstre seul ou un dresseur
    //Objet[] Inventaire;
    //liste des chose a dire
    void AddMonster(Monster monster);
    void Remove(Monster monster);
    Monster GetMonster(int index);
    Monster* ListeMonster();
    bool IsFull();
    int NbMonstre();
  protected:
  	static int const maxMonster = 3;
  	int nbMonstre;
  	Monster *Monsters;
};

#endif

