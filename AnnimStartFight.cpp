
#include "AnnimStartFight.h"
#include "Choicemonster.h"
#include "IContexte.h"

#include <Gamebuino.h>

  void  AnnimStartFight::Init()
  {
    this->nbFrameAnnim = 20;//20 frame = 1 seconde 
      this->isChangeState=false;
      this->isWhite = false;
  }
  
  void AnnimStartFight::Update(Gamebuino gb, IContexte *ctx)
  {
    if(this->nbFrameAnnim >0)
    {
      this->nbFrameAnnim--;
      
      if(this->nbFrameAnnim%3 ==0)
      {
        this->isWhite = !this->isWhite;
      }
    }
    else 
    {
      this->isChangeState=true;
    }
  }
  void  AnnimStartFight::Draw(Gamebuino gb, IContexte *ctx)
  {
    
    //#define LCDWIDTH 48
    //#define LCDHEIGHT 84
    
    for(uint8_t i=0;i<15;i++)
    {
      for(uint8_t y=0;y<15;y++)
      {
        if(isWhite)
        {
            if(y%2 == 0)
            {
              if(i%2 == 0)
              {
                gb.display.fillRect(i*4, y*7, 4, 7);
                gb.display.setColor(BLACK);
              }
            }
            else 
            {
              if(i%2 != 0)
              {
                gb.display.fillRect(i*4, y*7, 4, 7);
                gb.display.setColor(BLACK);
              }
            }
          
        }
        else 
        {
          
            if(y%2 == 0)
            {
              if(i%2 != 0)
              {
                gb.display.fillRect(i*4, y*7, 4, 7);
                gb.display.setColor(BLACK);
              }
            }
            else 
            {
              if(i%2 == 0)
              {
                gb.display.fillRect(i*4, y*7, 4, 7);
                gb.display.setColor(BLACK);
              }
            }
          
        }
      }
    }
    //gb.display.print(this->nbFrameAnnim);
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

