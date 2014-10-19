
#include "AnnimStartFight.h"
#include "Choicemonster.h"

#include <Gamebuino.h>

  void  AnnimStartFight::Init()
  {
    this->nbFrameAnnim = 20;//20 frame = 1 seconde 
      this->isChangeState=false;
  }
  void  AnnimStartFight::Update(Gamebuino gb)
  {
    int currentFrame = gb.frameCount;
    //l'animation sera de faire passer l'ecran du noir au blanc 

    if(this->nbFrameAnnim <1)
    {
      this->isChangeState=true;
    }

    this->nbFrameAnnim--;
    isWhite = !isWhite;
  }
  void  AnnimStartFight::Draw(Gamebuino gb)
  {
    if(isWhite)
    {
      /*gb.display.setColor(INVERT);
      gb.display.fillRect(x_screen, y_screen, s, s);
      gb.display.setColor(BLACK);*/
      gb.display.println(F("White"));
      
    }
    else 
    {
      //gb.display.setColor(INVERT);
      /*gb.display.fillRect(x_screen, y_screen, s, s);
      gb.display.setColor(BLACK);*/
      gb.display.println(F("Black?"));
      
    }
  }
  bool  AnnimStartFight::NeedChangeState()
  {
    return this->isChangeState;
  }
  IFightState * AnnimStartFight::NewState()
  {
    IFightState *fightNext;
    fightNext = new ChoiceMonster();
    fightNext->Init();
    return fightNext;
  }
