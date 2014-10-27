#include "CoreFight.h"
#include "AnnimStartFight.h"
#include "IFightState.h"
#include <Gamebuino.h>
#include "IContexte.h"
#include "CoreExplore.h"


void CoreFight::Init()
{
  ICoreGame::Init();

  IFightState *fightAnnim;
  fightAnnim = new AnnimStartFight();
  fightAnnim->Init();
   this->currentCoreState = fightAnnim;

}

void CoreFight::Update(Gamebuino gb, IContexte *ctx)
{
  this->currentCoreState->Update(gb,ctx);
  if(this->currentCoreState->NeedChangeState())
  {
      //on passe au choix du monster 
    IFightState *newState =  this->currentCoreState->NewState();
    delete this->currentCoreState;
    this->currentCoreState = newState;
    /*if(this->currentCoreState->IsFinish)
    {
      this->isChangeState = true;
    }*/
  }
}

void CoreFight::Draw(Gamebuino gb, IContexte *ctx)
{
    this->currentCoreState->Draw(gb,ctx);
}

bool CoreFight::NeedChangeState()
{
  return this->isChangeState;
}

ICoreGame * CoreFight::NewState()
{
  ICoreGame *coreFight;
  coreFight = new CoreExplore();
  coreFight->Init();
  return coreFight;
}

