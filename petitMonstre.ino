//imports the SPI library (needed to communicate with Gamebuino's screen)
#include <SPI.h>
#include <stdint.h>
//imports the Gamebuino library
#include <Gamebuino.h>
//creates a Gamebuino object named gb
Gamebuino gb;



////declare all the variables needed to make a menu
//number of items in the menu
#define STARTMENULENGTH 2
//The different strings to put in the menu
//each string can be used in different menus
const char strMonsterInfos[] PROGMEM = "Futurodex";
const char strChangeGame[] PROGMEM = "Change game";
//Put all the different items together in a menu (an array of strings actually)
const char* const menu[STARTMENULENGTH] PROGMEM = {
  strMonsterInfos,
  strChangeGame,
};


#include "InterfaceCombatSprite.h"
#include "AllMonstersSprite.h"
#include "AllWorldSprite.h"
#include "AllMonsterName.h"
#include "AllPersoSprite.h"
#include "IContexte.h"
#include "Player.h"
#include "Monster.h"

extern const byte font3x3[]; //a really tiny font
extern const byte font3x5[]; //a small but efficient font (default)
extern const byte font5x7[]; //a large, comfy font

//Prototype
void CombatAttack(Monster *att, Monster *def);
void decrementOldVie(Monster *m,int nbframe);
void GenerateMonsterByLvl(Monster *monsterAgenerer, uint8_t lvl, uint8_t numero);
void LevelUpMonster(Monster *monsterAgenerer);

//CoreGame petitMonstreGame;
IContexte * ctx;
uint8_t state;
unsigned  int cptArea; 
unsigned int cptKill; 
bool monsterVue[Nb_MONSTERS];
uint8_t nbVue; 
void setup()
{
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
   
   ctx->IsMaster = true;
   
   
   //TODO a mettre dans un endroit approprie
   
   Player *adv = new Player();
   ctx->Adversaire = *adv;
   InitialisationGame();
}

void InitialisationGame()
{
  nbVue = 0;
  cptArea= 0;
  cptKill = 0;
   state = 0; 
   //numero vie vitesse force defence
   ctx->Joueur.AddMonster(0,10,5,3,7,2,2,2);
   ctx->Joueur.AddMonster(1,10,9,3,7,2,2,2);
   ctx->Joueur.AddMonster(2,10,15,3,8,2,2,2);
   ctx->Joueur.AddMonster(3,10,2,3,4,2,2,2);
   
   for(uint8_t i=0;i<4;i++)
   {
      Monster *m = ctx->Joueur.GetMonster(i);
      GenerateMonsterByLvl(m, 5, i);
   }
   
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
      
         
        if(gb.buttons.pressed(BTN_C))
        {
          switch(gb.menu(menu, STARTMENULENGTH)){
            case 0: 
              DysplayEtatFuturomon();
              break;
            case 1: //change game
              gb.changeGame();
                gb.popup(F("Change game"),40);
              break;
            default:
              break;
          }
        }
      break;
      case 1 :
      //mode combat
      state = CombatMonste();
      break;
      case 99 :
      //mode combat
      state = GameOverScreen();
      break;
    }
    
    gb.battery.show = false;
  }
}


uint8_t GameOverScreen()
{
  
      gb.display.setFont(font5x7);
      gb.display.println(F("Game over"));
  
      gb.display.setFont(font3x5);
      gb.display.print(F("Area :"));
      gb.display.println(cptArea);
      gb.display.print(F("Kill :"));
      gb.display.println(cptKill);
      gb.display.print(F("Vue  :"));
      gb.display.println(nbVue);
      
      gb.display.print(F("Press :"));
      gb.display.print(F("\25"));
      gb.display.println(F(" to continue"));
      gb.display.print(F("\27"));
      gb.display.println(F(" to main menu"));
  
  if(gb.buttons.pressed(BTN_A))
  {
    InitialisationGame();
    return 0;
  }
  
  if(gb.buttons.pressed(BTN_C))
  {
    gb.changeGame();
    return 0;
  }
  
  return 99;
}

uint8_t UpdateModeExploration()
{
  return ExplorationUpdate();
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
    
    if(!ctx->Joueur.HaveMonsterOk())
    {
      //Fin de partie! 
      return 99;
    }
    
    return 0;
  }



