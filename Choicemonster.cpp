

#include "Choicemonster.h"
#include <Gamebuino.h>

  void  ChoiceMonster::Init()
  {
      this->isChangeState=false;
  }
  
  void  ChoiceMonster::Update(Gamebuino gb)
  {
    gb.display.println(F("Open menu !!"));
  }
  
  void  ChoiceMonster::Draw(Gamebuino gb)
  {

  }
  
  bool  ChoiceMonster::NeedChangeState()
  {
    return this->isChangeState;
  }

  IFightState *  ChoiceMonster::NewState()
  {
    IFightState *fightNext;
    fightNext = new ChoiceMonster();
    fightNext->Init();
    return fightNext;
  }
  
