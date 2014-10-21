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

<<<<<<< HEAD
IContexte * CoreFight::Update(Gamebuino gb, IContexte *ctx)
=======
IContexte CoreFight::Update(Gamebuino gb, IContexte ctx)
>>>>>>> origin/master
{
  this->currentCoreState->Update(gb);
  if(this->currentCoreState->NeedChangeState())
  {
      //on passe au choix du monster 
    this->currentCoreState = this->currentCoreState->NewState();
  }
}

<<<<<<< HEAD
void CoreFight::Draw(Gamebuino gb, IContexte *ctx)
=======
void CoreFight::Draw(Gamebuino gb, IContexte ctx)
>>>>>>> origin/master
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
