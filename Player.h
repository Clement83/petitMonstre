#if !defined (Player_H)
#define Player_H

#include "Monster.h"
class Player
{
  public:
      Player();
  	uint8_t PosX;
  	uint8_t PosY;
  	uint8_t Area;
    bool IsMonster;//permet de savoir si on est sur un monstre seul ou un dresseur
    //Objet[] Inventaire;
    //liste des chose a dire
    void AddMonster(uint8_t numero, uint8_t vie,uint8_t vitesse,uint8_t force,uint8_t defence,uint8_t lvl,int nextlvl,int xp);
    void Remove(Monster monster);
    Monster * GetMonster(uint8_t index);
    void  UnSelectMonster();
    Monster *GetSelectedMonster();
    Monster* ListeMonster();
    bool IsFull();
    bool IsSelectedMonster();
    uint8_t NbMonstre();
    void SelectMonster(uint8_t num);
    void ClearMonster();
    uint8_t GetSelectNumMonster();
    uint8_t SelectedMonster;
    bool  HaveMonsterOk();
  protected:
  	static uint8_t const maxMonster = 4;
  	uint8_t nbMonstre;
  	Monster Monsters[4];
};

#endif

