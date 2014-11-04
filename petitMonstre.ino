//imports the SPI library (needed to communicate with Gamebuino's screen)
#include <SPI.h>
#include <stdint.h>
//imports the Gamebuino library
#include <Gamebuino.h>
//creates a Gamebuino object named gb
Gamebuino gb;


#include "InterfaceCombatSprite.h"
#include "AllMonstersSprite.h"
//#include "AllWorldSprite.h"
#include "AllMonsterName.h"
#include "IContexte.h"
#include "Player.h"
#include "Monster.h"
#include "AllAttakName.h"

//Prototype
void CombatAttack(Monster *att, Monster *def);

//CoreGame petitMonstreGame;
IContexte * ctx;


uint8_t state;

void setup()
{
 state = 0; 
 // initialize the Gamebuino object
  gb.begin();
  //display the main menu:
  gb.titleScreen(F("les petits monstres"));
  gb.pickRandomSeed();
  //petitMonstreGame.Init();
  
   ctx = new IContexte();
   Player *p1 = new Player();
   ctx->Joueur = *p1;

   Monster *m1 = new Monster();
   m1->Numero = 0;
   m1->Force = 2;
   m1->ForceMax = 2;
   m1->Vie = 30;
   m1->VieMax = 30;
   m1->Vitesse = 5;
   m1->VitesseMax = 5;
   m1->Defence = 1;
   m1->DefenceMax = 1;

   Monster *m2= new Monster();
   m2->Numero = 1;
   m2->Force = 3;
   m2->ForceMax = 3;
   m2->Vie = 30;
   m2->VieMax = 30;
   m2->Vitesse = 5;
   m2->VitesseMax = 5;
   m2->Defence = 1;
   m2->DefenceMax = 1;
   
   Monster *m3 = new Monster();
   m3->Numero = 2;
   m3->Force = 4;
   m3->ForceMax = 4;
   m3->Vie = 30;
   m3->VieMax = 30;
   m3->Vitesse = 5;
   m3->VitesseMax = 5;
   m3->Defence = 1;
   m3->DefenceMax = 1;
   
   Monster *m4 = new Monster();
   m4->Numero = 3;
   m4->Force = 5;
   m4->ForceMax = 5;
   m4->Vie = 30;
   m4->VieMax = 30;
   m4->Vitesse = 5;
   m4->VitesseMax = 5;
   m4->Defence = 1;
   m4->DefenceMax = 1;
  //All player have 4 monster because the menu is static
   ctx->Joueur.AddMonster(*m1);
   ctx->Joueur.AddMonster(*m2);
   ctx->Joueur.AddMonster(*m3);
   ctx->Joueur.AddMonster(*m4);
   
   ctx->IsMaster = true;
   
   
   //TODO a mettre dans un endroit approprie
   
   Player *adv = new Player();
   ctx->Adversaire = *adv;
    /*
   Monster *m5 = new Monster();
   m5->Numero = 2;
   m5->Force = random(1,4);
   m5->ForceMax = m5->Force;
   m5->Vie = random(10,20);
   m5->VieMax = m5->Vie;
   m5->Vitesse = random(1,5);
   m5->VitesseMax = m5->Vitesse;
   m5->Defence = random(1,5);
   m5->DefenceMax = m5->Defence;
   ctx->Adversaire.AddMonster(*m5);
   ctx->Adversaire.SelectMonster(0); */
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

