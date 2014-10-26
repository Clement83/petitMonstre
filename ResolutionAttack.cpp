#include "ResolutionAttack.h"
#include <Gamebuino.h>
#include "IContexte.h"
#include "Constante.h"
#include "AllMonsterName.h"
#include "ChoiceAttack.h"

  void  ResolutionAttack::Init()
  {
      this->isChangeState=false;
      this->IsFinish = false;
      this->nbFrameAnnim = 100;
      this->attackOk = false;
  }
  
  IContexte * ResolutionAttack::Update(Gamebuino gb, IContexte *ctx)
  {
    
    if(!this->attackOk)
    {
     
      if(ctx->IsMaster)
      { 
          if(ctx->Adversaire.IsSelectedMonster())
          {
            //if(ctx->Adversaire.GetSelectedMonster().IsSelectedAttack())
            {
              this->ResolutionOfAttack(ctx);
              this->attackOk = true;
            }
          }
         // else 
          {
            //TODO : Attente de la selection d'un monster
           // gb.display.print("Attente J2 M");
          }
      }
      else 
      {
        //TODO : uniquement pour le jeux en reseau
        gb.display.print("i m j2");
      }
    }  
    
    if(this->nbFrameAnnim<=0)
    {
       this->isChangeState = true;
    }
    this->nbFrameAnnim--;
    
    return ctx;
  }
  
  void  ResolutionAttack::Draw(Gamebuino gb, IContexte *ctx)
  {
    if(this->attackOk)
    {
      gb.display.print("C'est la guerre!");
    }
    else 
    {
       gb.display.print("c'est pas wait!");
    }
  }
  
  bool  ResolutionAttack::NeedChangeState()
  {
    return this->isChangeState;
  }

  void ResolutionAttack::ResolutionOfAttack(IContexte *ctx)
  {
    //TODO uniquement pour test
    this->Attack(ctx->Joueur.GetSelectedMonster(),ctx->Adversaire.GetSelectedMonster());
    //ctx->Adversaire.GetSelectedMonster()->Vie = 2;
    /*if(ctx->Joueur.GetSelectedMonster().Vitesse > ctx->Adversaire.GetSelectedMonster().Vitesse)
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
    }*/
    
    
    ctx->Joueur.GetSelectedMonster()->UnSelectedAttack();
    ctx->Adversaire.GetSelectedMonster()->UnSelectedAttack();
  }

  void ResolutionAttack::Attack(Monster *att, Monster *def)
  {
      //TODO faire avec le choix des attaque ! 
      def->Vie = def->Vie - att->Force; 
  }

  IFightState *  ResolutionAttack::NewState()
  {
    if(false)//this->IsFinish)
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
