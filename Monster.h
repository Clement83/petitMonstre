#if !defined (Monster_H)
#define Monster_H

#include "Attaque.h"

class Monster 
{
  public:
        Monster();
    uint8_t Vie;
    uint8_t Force;
    uint8_t Defence;
    uint8_t Vitesse;
    uint8_t VieMax;
    uint8_t ForceMax;
    uint8_t DefenceMax;
    uint8_t VitesseMax;
  	uint8_t Type;
  	char* Name;
  	uint8_t Numero;//permet de savoir a quel monstre on a affaire
    uint8_t Index;//index dans le tableau des monstre du joueur
    void AddAttaque(Attaque atta);
    void RemoveAttaque(Attaque atta);
    Attaque* ListAttaque();
    Attaque UseAttaque(uint8_t index);
    bool IsFull();
    bool IsAlive();
    bool IsSelectedAttack();
    void SetSelectedAttack(uint8_t num);
    Attaque GetSelectedAttack();
    void UnSelectedAttack();
    uint8_t GetPourcentVieRestant();
  protected:
   static uint8_t const maxAttaque = 4;
    uint8_t nbAttaque;
  	Attaque* Attaques;
    uint8_t selectedAttaque;

};


#endif

