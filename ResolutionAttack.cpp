#include "ResolutionAttack.h"
#include <Gamebuino.h>
#include "IContexte.h"
#include "Constante.h"
#include "AllMonsterName.h"
#include "ChoiceAttack.h"
#include "InterfaceCombatSprite.h"
#include "AllMonstersSprite.h"

  void  ResolutionAttack::Init()
  {
      this->isChangeState=false;
      this->IsFinish = false;
      this->nbFrameAnnim = 100;
      this->attackOk = false;
  }
  
  void ResolutionAttack::Update(Gamebuino gb, IContexte *ctx)
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
  }
  
  void  ResolutionAttack::Draw(Gamebuino gb, IContexte *ctx)
  {
    if(this->attackOk)
    {
    /*
      if(ctx->Joueur.IsSelectedMonster())
        {
           gb.display.print("vie 1: ");
           gb.display.println(ctx->Joueur.GetSelectedMonster()->Vie);
        }
      if(ctx->Adversaire.IsSelectedMonster())
        {
           gb.display.print("vie 2: ");
           gb.display.println(ctx->Adversaire.GetSelectedMonster()->Vie);
        }
    */
        gb.display.drawBitmap(2, 0, sprBarreViej2);
        gb.display.drawBitmap(60, 0, allSpriteMonstersFront[ctx->Adversaire.GetSelectedMonster()->Numero]);
        gb.display.fillRect(3, 1,this->GetWidthBarreVie(ctx->Adversaire.GetSelectedMonster()->GetPourcentVieRestant() ,22), 5);


        gb.display.drawBitmap(60, 48, sprBarreViej1);
        gb.display.drawBitmap(2, 40, allSpriteMonstersBack[ctx->Joueur.GetSelectedMonster()->Numero]);
        gb.display.fillRect(61, 49, this->GetWidthBarreVie(ctx->Joueur.GetSelectedMonster()->GetPourcentVieRestant() ,22), 5);
    }
    else 
    {
       gb.display.print("c'est pas wait!");
    }
  }

  int8_t ResolutionAttack::GetWidthBarreVie(uint8_t pourcentVie, uint8_t tailleMaxPx)
  {
    return pourcentVie * tailleMaxPx / 100;
  }
  
  bool  ResolutionAttack::NeedChangeState()
  {
    return this->isChangeState;
  }

  void ResolutionAttack::ResolutionOfAttack(IContexte *ctx)
  {
    //TODO uniquement pour test
    this->Attack(ctx->Joueur.GetSelectedMonster(),ctx->Adversaire.GetSelectedMonster());
    this->Attack(ctx->Adversaire.GetSelectedMonster(),ctx->Joueur.GetSelectedMonster());
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
