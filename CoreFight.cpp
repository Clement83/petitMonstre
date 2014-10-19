#include "CoreFight.h"
#include "AnnimStartFight.h"
#include "IFightState.h"
#include <Gamebuino.h>


void CoreFight::Init()
{
  ICoreGame::Init();

  IFightState *fightAnnim;
  fightAnnim = new AnnimStartFight();
  fightAnnim->Init();
   this->currentCoreState = fightAnnim;

}

void CoreFight::Update(Gamebuino gb)
{
  this->currentCoreState->Update(gb);
  if(this->currentCoreState->NeedChangeState())
  {
      //on passe au choix du monster 
    this->currentCoreState = this->currentCoreState->NewState();
  }
}

void CoreFight::Draw(Gamebuino gb)
{
  this->currentCoreState->Draw(gb);
}

bool CoreFight::NeedChangeState()
{
  return false;
}

ICoreGame * CoreFight::NewState()
{

  //choix du mode combat
  //Create engine fight
  ICoreGame *coreFight;
  coreFight = new CoreFight();
  coreFight->Init();
  return coreFight;
}
