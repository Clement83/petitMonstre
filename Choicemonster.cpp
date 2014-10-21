

#include "Choicemonster.h"
#include "Constante.cpp"
#include <Gamebuino.h>

  void  ChoiceMonster::Init()
  {
      this->isChangeState=false;
  }
  
  IContexte  ChoiceMonster::Update(Gamebuino gb, IContexte ctx)
  {
    //Recherche des monstre du joueur 
    //Creation du menu grace a ça 
    const char* const menu[MENUMAXLENGTHCHOIXMONSTER] = {
      strMonster1,
      strMonster2,
      strMonster3,
    };

    switch(gb.menu(menu, MENUMAXLENGTHCHOIXMONSTER)){
    case 0: //display system info
        gb.popup(F("monstre 1"), 100);
      break;
    case 1: //change game
        gb.popup(F("monstre 2"), 100);
      break;
    case 2: //change game
        gb.popup(F("monstre 3"), 100);
      break;
    default:
      break;
      }
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
  
