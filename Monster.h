#if !defined (Monster_H)
#define Monster_H
#include <SPI.h>
#include <stdint.h>

#define MAX_ARTTAQUE_MONSTER 4

class Monster 
{
  public:
    Monster();
    int8_t Vie;
    uint8_t Force;
    uint8_t Defence;
    uint8_t Vitesse;
    uint8_t VieMax;
    uint8_t OldVie;
    uint8_t ForceMax;
    uint8_t DefenceMax;
    uint8_t VitesseMax;
    uint8_t Niveau;
    unsigned int NextNiveau;
    unsigned int Xp;
    uint8_t Type;
    char* Name;
    int Numero;//permet de savoir a quel monstre on a affaire
    uint8_t Index;//index dans le tableau des monstre du joueur
    void    SetPatternAttaque(uint8_t numPattern);
    uint8_t GetPatternAttaque();
    bool IsFull();
    bool IsAlive();
    bool IsSelectedAttack();
    void SetSelectedAttack(uint8_t num);
    uint8_t GetSelectedAttack();
    void UnSelectedAttack();
    uint8_t GetPourcentVieRestant();
  protected:
   static uint8_t const maxAttaque = MAX_ARTTAQUE_MONSTER;
    uint8_t nbAttaque;
    uint8_t numeroPattern;
    uint8_t selectedAttaque;
};


#endif

