#include "ResolutionAttack.h"
#include <Gamebuino.h>
#include "IContexte.h"
#include "Constante.h"
#include "AllMonsterName.h"
#include "ChoiceAttack.h"

  void  ResolutionAttack::Init()
  {
      this->isChangeState=false;
  }
  
  IContexte * ResolutionAttack::Update(Gamebuino gb, IContexte *ctx)
  {
    
    if(ctx->IsMaster)
    {
        if(ctx->Adversaire.IsSelectedMonster() && ctx->Adversaire.GetSelectedMonster().IsSelectedAttack())
        {
          this->ResolutionOfAttack(ctx);

          //TODO on changera d'etat apres les animations
          this->isChangeState = true;
        }
        else 
        {
          //TODO : Attente de la selection d'un monster
          gb.display.print("Attente J2 M");
        }
    }
    else 
    {
      //TODO : uniquement pour le jeux en reseau
      gb.display.print("Attente J2 R");
    }

      
    return ctx;
  }
  
  void  ResolutionAttack::Draw(Gamebuino gb, IContexte *ctx)
  {

  }
  
  bool  ResolutionAttack::NeedChangeState()
  {
    return this->isChangeState;
  }

  IFightState *  ResolutionAttack::NewState()
  {
    if(this->IsFinish)
    {
      /*IFightState *fightNext;
      fightNext = new ChoiceAttack();
      fightNext->Init();
      return fightNext;*/
    }
    else 
    {
      IFightState *fightNext;
      fightNext = new ChoiceAttack();
      fightNext->Init();
      return fightNext;
    }
  }

  void ResolutionAttack::ResolutionOfAttack(IContexte *ctx)
  {
    if(ctx->Joueur.GetSelectedMonster().Vitesse > ctx->Adversaire.GetSelectedMonster().Vitesse)
    {
      this->Attack(ctx->Joueur.GetSelectedMonster(),ctx->Adversaire.GetSelectedMonster());
      if(ctx->Adversaire.GetSelectedMonster().IsAlive())
      {
        this->Attack(ctx->Adversaire.GetSelectedMonster(),ctx->Joueur.GetSelectedMonster());
        if(ctx->Joueur.GetSelectedMonster().IsAlive())
        {
          //on continu le combat
        }
        else 
        {
          //fin de partie
          this->IsFinish = true;
        }
      }
        else 
        {
          //fin de partie
          this->IsFinish = true;
        }
    }
    else 
    {
      this->Attack(ctx->Adversaire.GetSelectedMonster(),ctx->Joueur.GetSelectedMonster());
      if(ctx->Joueur.GetSelectedMonster().IsAlive())
      {
        this->Attack(ctx->Joueur.GetSelectedMonster(),ctx->Adversaire.GetSelectedMonster());
        if(ctx->Adversaire.GetSelectedMonster().IsAlive())
        {
          //on continu le combat
        }
        else 
        {
          //fin de partie
          this->IsFinish = true;
        }
      }
    }
  }

  void ResolutionAttack::Attack(Monster att, Monster def)
  {
      //TODO faire avec le choix des attaque ! 

    def.Vie = att.Force - def.Defence; 
  }
