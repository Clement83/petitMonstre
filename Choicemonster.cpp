#include "Choicemonster.h"
#include <Gamebuino.h>
#include "IContexte.h"
#include "Constante.h"

  void  ChoiceMonster::Init()
  {
      this->isChangeState=false;
  }
  
  IContexte * ChoiceMonster::Update(Gamebuino gb, IContexte *ctx)
  {
    //Recherche des monstre du joueur 
    //Creation du menu grace a ca 
    int nbMonstre = ctx->Joueur.NbMonstre();
    char* menu[nbMonstre];

    for(int i=0;i<nbMonstre;i++)
    {
      menu[i] =  ctx->Joueur.GetMonster(i).Name;
    }

    switch(gb.menu(menu, nbMonstre)){
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
      
      return ctx;
  }
  
  void  ChoiceMonster::Draw(Gamebuino gb, IContexte *ctx)
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
  

