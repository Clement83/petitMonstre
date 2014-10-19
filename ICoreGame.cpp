#include "ICoreGame.h"
#include <Gamebuino.h>

void ICoreGame::Init()
{
  IGameObject::Init();
  //this->isChangeState = false;
}


void ICoreGame::Update(Gamebuino gb)
{
  gb.display.println(F("ICoreGame : Update"));
}

void ICoreGame::Draw(Gamebuino gb)
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
