#include "CoreGame.h"
#include "CoreExplore.h"
#include "CoreFight.h"
#include "ICoreGame.h"
#include <Gamebuino.h>
#include "IContexte.h"

void CoreGame::Init()
{
  IGameObject::Init();

  ICoreGame *cexp;
  cexp = new CoreExplore();
  //cexp = new CoreFight();
  cexp->Init();
   this->currentCoreState = cexp;
}

void CoreGame::Update(Gamebuino gb, IContexte *ctx)
{
  this->currentCoreState->Update(gb,ctx);

   if(this->currentCoreState->NeedChangeState())
  {
    //gb.display.println(F("CoreGame : Change state"));
    //Todo peut etre qu'il faut detruire l'object precedent? memory leek m'entend tu?
    ICoreGame *newState = this->currentCoreState->NewState();
    delete this->currentCoreState;
    this->currentCoreState = newState;
    
//    this->currentCoreState =this->currentCoreState->NewState();
  }
}

void CoreGame::Draw(Gamebuino gb, IContexte *ctx)
{
  //Draw all link object
  this->currentCoreState->Draw(gb,ctx);
}

