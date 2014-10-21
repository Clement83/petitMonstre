#include "CoreFight.h"
#include "CoreExplore.h"
#include <Gamebuino.h>
    

void CoreExplore::Init()
{
  ICoreGame::Init();
}

void CoreExplore::Draw(Gamebuino gb, IContexte *ctx)
{
  gb.display.println(F("Press A"));
}

IContexte * CoreExplore::Update(Gamebuino gb, IContexte *ctx)
{
  if(gb.buttons.pressed(BTN_A))
  {
    this->isChangeState = true;
  }
  //gb.display.println(F("CoreExplore : update!"));
}

bool CoreExplore::NeedChangeState()
{
  return this->isChangeState;
}

ICoreGame * CoreExplore::NewState()
{
  //choix du mode combat
  //Create engine fight
  ICoreGame *coreFight;
  coreFight = new CoreFight();
  coreFight->Init();
  return coreFight;
}
