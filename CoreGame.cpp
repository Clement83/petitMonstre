#include "CoreGame.h"
#include "CoreExplore.h"
#include "ICoreGame.h"
#include <Gamebuino.h>

void CoreGame::Init()
{
  IGameObject::Init();

  ICoreGame *cexp;
  cexp = new CoreExplore();
  cexp->Init();
   this->currentCoreState = cexp;
}

void CoreGame::Update(Gamebuino gb)
{
  this->currentCoreState->Update(gb);

   if(this->currentCoreState->NeedChangeState())
  {
    gb.display.println(F("CoreGame : Change state"));
    //Todo peut etre qu'il faut detruire l'object precedent? memory leek m'entend tu?
    this->currentCoreState = this->currentCoreState->NewState();
  }
}

void CoreGame::Draw(Gamebuino gb)
{
  //gb.display.println(F("CoreGame : Hello World!"));
  //Draw all link object
  this->currentCoreState->Draw(gb);
}
