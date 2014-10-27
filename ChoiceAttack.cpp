#include "ChoiceAttack.h"
#include "ChoiceMonster.h"
#include <Gamebuino.h>
#include "IContexte.h"
#include "Constante.h"
#include "AllAttakName.h"
#include "ResolutionAttack.h"

  void  ChoiceAttack::Init()
  {
      this->isChangeState=false;
  }
  
  void ChoiceAttack::Update(Gamebuino gb, IContexte *ctx)
  {
    /*
    uint8_t nbMonstre = ctx->Joueur.NbMonstre();
    const char*  monMenu[nbMonstre] PROGMEM;

    for(uint8_t i=0;i<nbMonstre;i++)
    {
      monMenu[i] = allMonsters[ctx->Joueur.GetMonster(i).Numero];
       //gb.display.println(ctx->Joueur.GetMonster(i).Name);
    }

*/
    uint8_t selectedAttak =  gb.menu(GetAttakByNumero(ctx->Joueur.GetSelectNumMonster()), 4);
    switch(selectedAttak)
    {
      case 3 : 
      {
        isAttack = false;
        ctx->Joueur.UnSelectMonster();
      }
      default : 
      {
        ctx->Joueur.GetSelectedMonster()->SetSelectedAttack(selectedAttak);
        isAttack = true;
      }
    };
    this->isChangeState = true;

  }
  
  void  ChoiceAttack::Draw(Gamebuino gb, IContexte *ctx)
  {

  }
  
  bool  ChoiceAttack::NeedChangeState()
  {
    return this->isChangeState;
  }

  IFightState *  ChoiceAttack::NewState()
  {
    if(!isAttack)
    {
      IFightState *fightNext;
      fightNext = new ChoiceMonster();
      fightNext->Init();
      return fightNext;
    }
    else 
    {
      IFightState *fightNext;
      fightNext = new ResolutionAttack();
      fightNext->Init();
      return fightNext;
    }
  }
  

