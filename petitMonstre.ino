//imports the SPI library (needed to communicate with Gamebuino's screen)
#include <SPI.h>
#include <stdint.h>
//imports the Gamebuino library
#include <Gamebuino.h>
//creates a Gamebuino object named gb
Gamebuino gb;


#include "InterfaceCombatSprite.h"
#include "AllMonstersSprite.h"
#include "AllWorldSprite.h"
#include "AllMonsterName.h"
#include "AllPersoSprite.h"
#include "IContexte.h"
#include "Player.h"
#include "Monster.h"
#include "AllAttakName.h"

extern const byte font3x3[]; //a really tiny font
extern const byte font3x5[]; //a small but efficient font (default)
extern const byte font5x7[]; //a large, comfy font

//Prototype
void CombatAttack(Monster *att, Monster *def);
void decrementOldVie(Monster *m,int nbframe);

//CoreGame petitMonstreGame;
IContexte * ctx;


uint8_t state;
unsigned  int cptArea; 
unsigned int cptKill; 
bool monsterVue[Nb_MONSTERS];
uint8_t nbVue; 
void setup()
{
  nbVue = 0;
  cptArea= 0;
  cptKill = 0;
 state = 0; 
 // initialize the Gamebuino object
  gb.begin();
  //display the main menu:
  gb.titleScreen(F("Futuromon"));
  gb.pickRandomSeed();
  //petitMonstreGame.Init();
  
   ctx = new IContexte();
   Player *p1 = new Player();
   ctx->Joueur = *p1;

  //All player have 4 monster because the menu is static
   ctx->Joueur.AddMonster(0,35,5,15,27);
   ctx->Joueur.AddMonster(0,20,9,25,17);
   ctx->Joueur.AddMonster(0,24,15,10,8);
   ctx->Joueur.AddMonster(0,10,2,3,4);
   
   ctx->IsMaster = true;
   
   
   //TODO a mettre dans un endroit approprie
   
   Player *adv = new Player();
   ctx->Adversaire = *adv;
   
  initGame();
}

void loop()
{
  //returns true when it's time to render a new frame (20 times/second)
  if(gb.update())
  {

    switch(state)
    {
      case 0 :
      //Mode exploration
      state = UpdateModeExploration();
      break;
      case 1 :
      //mode combat
      state = CombatMonste();
      break;
    }
    gb.battery.show = false;
  }
}


uint8_t UpdateModeExploration()
{
  /*if(gb.buttons.pressed(BTN_A))
  {
   Player *adv = new Player();
   ctx->Adversaire = *adv;
Monster *m5 = new Monster();
   m5->Numero = random(0,4);
   m5->Force = random(1,4);
   m5->ForceMax = m5->Force;
   m5->Vie = random(10,20);
   m5->VieMax = m5->Vie;
   m5->Vitesse = random(1,5);
   m5->VitesseMax = m5->Vitesse;
   m5->Defence = random(1,5);
   m5->DefenceMax = m5->Defence;
   ctx->Adversaire.AddMonster(*m5);
   ctx->Adversaire.SelectMonster(0);

    return 1;
  }
  gb.display.println(F("Press A")); */
  return ExplorationUpdate();
  
  //gb.display.println(F("CoreExplore : update!"));
}

  uint8_t CombatMonste()
  {
    AnimationDebutCombat();
    //TODO attention si pas sauvage peut etre pas de monstre !
    CombatArriverMonsterSauvage();
    ctx->Joueur.UnSelectMonster();
    do
    {
      CombatChoiceMonsterAdversaire();
      CombatChoiceMonster();
      CombatChoiceAttackAdversaire();
      CombatChoiceAttack();
    }while(ResolutionCombat());
    CombatFinCombat();
    return 0;
  }

