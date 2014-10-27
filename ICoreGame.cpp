#include "ICoreGame.h"
#include <Gamebuino.h>
#include "IContexte.h"

void ICoreGame::Init()
{
  IGameObject::Init();
  //this->isChangeState = false;
}

void ICoreGame::Update(Gamebuino gb, IContexte *ctx)
{
  gb.display.println(F("ICoreGame : Update"));
}

void ICoreGame::Draw(Gamebuino gb, IContexte *ctx)
{
  gb.display.println(F("ICoreGame : Draw"));
}

bool ICoreGame::NeedChangeState()
{
  return false;
}

ICoreGame * ICoreGame::NewState()
{
  ICoreGame *icg;
  icg = new ICoreGame();
  icg->Init();
  return icg;
}

