//imports the SPI library (needed to communicate with Gamebuino's screen)
#include <SPI.h>
#include <stdint.h>
//imports the Gamebuino library
#include <Gamebuino.h>
//creates a Gamebuino object named gb
Gamebuino gb;


#define NB_DRESSEUR_THEME 1
////declare all the variables needed to make a menu
//number of items in the menu
#define STARTMENULENGTH 3
//The different strings to put in the menu
//each string can be used in different menus
const char strMonsterInfos[] PROGMEM = "Team";
const char strFuturodex[] PROGMEM = "Futurodex";
const char strChangeGame[] PROGMEM = "Change game";
//Put all the different items together in a menu (an array of strings actually)
const char* const menu[STARTMENULENGTH] PROGMEM = {
  strMonsterInfos,
  strFuturodex,
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
void GenerateMonsterByLvlAndNumZone(Monster *monsterAgenerer, uint8_t lvl, uint8_t numeroZone);
void GenerateStartMonster(Monster *monsterAgenerer, uint8_t  numero);
void LevelUpMonster(Monster *monsterAgenerer);
void DysplayEtatFuturomon(Monster monster);
void DysplayFuturoDex(Monster monster);
void AddMonster(Player *p, Monster m, uint8_t pos);
uint8_t  HaveBonusAttak(uint8_t numAttaque,uint8_t numPattern,uint8_t typeDef);
void getnumMonsterByNumZone(uint8_t numZone, Monster *m);
bool IsCaseBonus(byte x , byte y);
//CoreGame petitMonstreGame;
IContexte * ctx;
uint8_t state;
unsigned  int cptArea;
unsigned int cptKill;
bool monsterVue[Nb_MONSTERS];
uint8_t nbVue;
bool MonsterCatch[Nb_MONSTERS];
uint8_t nbCatch;

byte DresseurByTheme[NB_THEMES];
byte currentTheme;

int camera_x, camera_y;

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

  ctx->IsMaster = true;

  Player *adv = new Player();
  ctx->Adversaire = *adv;
  InitialisationGame();
}

void InitialisationGame()
{
  nbVue = 0;
  cptArea= 0;
  cptKill = 0;
  state = 50;
  ctx->Joueur.ClearMonster();

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
          DysplayEtatAllFuturomon();
          break;
        case 1: //change game
          DysplayFuturodex();
          break;
        case 2: //change game
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
      if(TestFinPartie())
      {
         state = 99; 
      }
      
      
      break;
    case 50 :
      //scene de debut
      state = StartScene();
      break;
    case 51 :
      //scene de debut
      state = ChoixMonsterDebut();
      break;
    case 99 :
      //mode game over
      state = GameOverScreen();
      break;
    }

    gb.battery.show = false;
  }
}
bool TestFinPartie()
{
    for(byte i =0;i<NB_THEMES;i++)
    {
      if(DresseurByTheme[i]<NB_DRESSEUR_THEME)
        return false;
    }
    return true;
}

uint8_t GameOverScreen()
{

  gb.display.setFont(font5x7);
  gb.display.println(F("Game over"));
  DisplayEtatgame();

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





