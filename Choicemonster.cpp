#include "Choicemonster.h"
#include <Gamebuino.h>
#include "IContexte.h"
#include "Constante.h"
#include "AllMonsterName.h"
#include "ChoiceAttack.h"

  void  ChoiceMonster::Init()
  {
      this->isChangeState=false;
  }
  
  void ChoiceMonster::Update(Gamebuino gb, IContexte *ctx)
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
    if(!ctx->Joueur.IsSelectedMonster())
    {
      uint8_t choix = gb.menu(allMonsters, 4);
      ctx->Joueur.SelectMonster(choix);
    }
   else
    {
      if(ctx->Adversaire.IsSelectedMonster())
      {
          this->isChangeState = true;
      }
      else
      {
        //TODO : Attente de la selection d'un monster
        gb.display.print("Attente j2");
      }
    }

  }
  
  void  ChoiceMonster::Draw(Gamebuino gb, IContexte *ctx)
  {
      gb.display.print("Choice monster");
  }
  
  bool  ChoiceMonster::NeedChangeState()
  {
    return this->isChangeState;
  }

  IFightState *  ChoiceMonster::NewState()
  {
    IFightState *fightNext;
    fightNext = new ChoiceAttack();
    fightNext->Init();
    return fightNext;
  }
  

