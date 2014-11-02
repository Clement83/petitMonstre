//imports the SPI library (needed to communicate with Gamebuino's screen)
#include <SPI.h>
#include <stdint.h>
//imports the Gamebuino library
#include <Gamebuino.h>
//creates a Gamebuino object named gb
Gamebuino gb;


#include "InterfaceCombatSprite.h"
#include "AllMonstersSprite.h"
#include "AllMonsterName.h"
#include "IContexte.h"
#include "Player.h"
#include "Monster.h"
#include "AllAttakName.h"

//Prototype
void CombatAttack(Monster *att, Monster *def);

//CoreGame petitMonstreGame;
IContexte * ctx;


uint8_t state;

void setup()
{
 state = 0; 
 // initialize the Gamebuino object
  gb.begin();
  //display the main menu:
  gb.titleScreen(F("les petits monstres"));
  //petitMonstreGame.Init();
  
   ctx = new IContexte();
   Player *p1 = new Player();
   ctx->Joueur = *p1;

   Monster *m1 = new Monster();
   m1->Numero = 0;
   m1->Force = 2;
   m1->ForceMax = 2;
   m1->Vie = 10;
   m1->VieMax = 10;
   m1->Vitesse = 5;
   m1->VitesseMax = 5;
   m1->Defence = 1;
   m1->DefenceMax = 1;

   Monster *m2= new Monster();
   m2->Numero = 1;
   m2->Force = 3;
   m2->ForceMax = 3;
   m2->Vie = 10;
   m2->VieMax = 10;
   m2->Vitesse = 5;
   m2->VitesseMax = 5;
   m2->Defence = 1;
   m2->DefenceMax = 1;
   Monster *m3 = new Monster();
   m3->Numero = 2;
   m3->Force = 4;
   m3->ForceMax = 4;
   m3->Vie = 10;
   m3->VieMax = 10;
   m3->Vitesse = 5;
   m3->VitesseMax = 5;
   m3->Defence = 1;
   m3->DefenceMax = 1;
   Monster *m4 = new Monster();
   m4->Numero = 3;
   m4->Force = 5;
   m4->ForceMax = 5;
   m4->Vie = 10;
   m4->VieMax = 10;
   m4->Vitesse = 5;
   m4->VitesseMax = 5;
   m4->Defence = 1;
   m4->DefenceMax = 1;
  //All player have 4 monster because the menu is static
   ctx->Joueur.AddMonster(*m1);
   ctx->Joueur.AddMonster(*m2);
   ctx->Joueur.AddMonster(*m3);
   ctx->Joueur.AddMonster(*m4);
   
   ctx->IsMaster = true;
   
   
   //TODO a mettre dans un endroit approprie
   
   Player *adv = new Player();
   ctx->Adversaire = *adv;

   Monster *m5 = new Monster();
   m5->Numero = 2;
   m5->Force = random(1,4);
   m5->ForceMax = m5->Force;
   m5->Vie = random(10,20);
   m5->VieMax = m5->Vie;
   m5->Vitesse = random(1,5);
   m5->VitesseMax = m5->Vitesse;
   m5->Defence = random(1,5);
   m5->DefenceMax = m5->Defence;
   ctx->Adversaire.AddMonster(*m5);
   ctx->Adversaire.SelectMonster(0);
}

void loop()
{
  //returns true when it's time to render a new frame (20 times/second)
  if(gb.update())
  {

    switch(state)
    {
      case 0 :
      //Mode exploration
      state = UpdateModeExploration();
      break;
      case 1 :
      //mode combat
      state = CombatMonste();
      break;
    }
    gb.battery.show = false;


  }
}


uint8_t UpdateModeExploration()
{
  if(gb.buttons.pressed(BTN_A))
  {
   /*Player *adv = new Player();
   ctx->Adversaire = *adv;

   Monster *m5 = new Monster();
   m5->Numero = 1;
   m5->Force = random(1,4);
   m5->ForceMax = m5->Force;
   m5->Vie = random(10,20);
   m5->VieMax = m5->Vie;
   m5->Vitesse = random(1,5);
   m5->VitesseMax = m5->Vitesse;
   m5->Defence = random(1,5);
   m5->DefenceMax = m5->Defence;
   ctx->Adversaire.AddMonster(*m5);
   ctx->Adversaire.SelectMonster(0);*/

    return 1;
  }
  gb.display.println(F("Press A"));
  return 0;
  
  //gb.display.println(F("CoreExplore : update!"));
}

  uint8_t CombatMonste()
  {
    AnimationDebutCombat();
    
    do
    {
      CombatChoiceMonster();
      CombatChoiceMonsterAdversaire();
      CombatChoiceAttack();
      CombatChoiceAttackAdversaire();
    }while(ResolutionCombat());
    CombatFinCombat();
    return 0;
  }

  void AnimationDebutCombat()
  {
    int nbFrameAnnim = 20;
    bool isWhite = false;
    while(true)
    {

      if(gb.update())
      {
        if(nbFrameAnnim >0)
        {
          nbFrameAnnim--;
          
          if(nbFrameAnnim%3 ==0)
          {
            isWhite = !isWhite;
          }
        }
        else 
        {
          break;
        }
        
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
      }
    }
  }
  
   void CombatChoiceMonster()
  {
    
      //if(!ctx->Joueur.IsSelectedMonster())
      {
        uint8_t choix = gb.menu(allMonsters, 4);
        ctx->Joueur.SelectMonster(choix);
      }

  }
   void CombatChoiceMonsterAdversaire()
  {
        ctx->Adversaire.SelectMonster(0);
  }
  
    void CombatChoiceAttack()
  {
        uint8_t selectedAttak =  gb.menu(GetAttakByNumero(ctx->Joueur.GetSelectNumMonster()), 4);
        switch(selectedAttak)
        {
          case 3 : 
          {
            //isAttack = false;
            ctx->Joueur.UnSelectMonster();
          }
          default : 
          {
            ctx->Joueur.GetSelectedMonster()->SetSelectedAttack(selectedAttak);
            ctx->Joueur.GetSelectedMonster()->SetSelectedAttack(selectedAttak);
          }
        };

  }
  
    void CombatChoiceAttackAdversaire()
  {
            ctx->Adversaire.GetSelectedMonster()->SetSelectedAttack(0);

  }
  
  void     CombatFinCombat()
  {
    ctx->Joueur.UnSelectMonster();
    ctx->Adversaire.UnSelectMonster();
  }
  
  
  ///// RESOLUTION du combat 
  bool ResolutionCombat()
  {
    
    if(ctx->Adversaire.IsSelectedMonster() && ctx->Joueur.IsSelectedMonster())
    {
          CombatResolutionOfAttack();
          CombatResolutionAttackAnnimation();
          if(ctx->Joueur.GetSelectedMonster()->Vie == 0 || ctx->Adversaire.GetSelectedMonster()->Vie == 0)
            return false;
         return true;
    }
    return true;
  }
  
  void  CombatResolutionAttackAnnimation()
  {
      uint8_t nbFrame = 30;
    while(true)//nbFrame>0)
    {
      if(gb.update())
      {
  
       /* if(ctx->Joueur.IsSelectedMonster())
          {
             gb.display.print("vie 1: ");
             gb.display.println(ctx->Joueur.GetSelectedMonster()->Numero);
          }
        if(ctx->Adversaire.IsSelectedMonster())
          {
             gb.display.print("vie 2: ");
             gb.display.println(ctx->Adversaire.GetSelectedMonster()->Numero);
          }*/
          gb.display.drawBitmap(2, 0, sprBarreViej2);
          gb.display.drawBitmap(60, 0, allSpriteMonstersFront[2]);//allSpriteMonstersFront[ctx->Adversaire.GetSelectedMonster()->Numero]);
//          gb.display.drawBitmap(60, 0, sprChampiFortFront);
          gb.display.fillRect(3, 1,GetWidthBarreVie(ctx->Adversaire.GetSelectedMonster()->GetPourcentVieRestant() ,22), 6);
  
          int numMonster =  ctx->Joueur.GetSelectedMonster()->Numero;
          //gb.display.print(numMonster);
          gb.display.drawBitmap(60, 32, sprBarreViej1);
          gb.display.drawBitmap(2, 24, allSpriteMonstersBack[0]);//allSpriteMonstersBack[ctx->Joueur.GetSelectedMonster()->Numero]);
          uint8_t wdBarrevie = GetWidthBarreVie(ctx->Joueur.GetSelectedMonster()->GetPourcentVieRestant() ,22);
          gb.display.fillRect(61 + (22 - wdBarrevie), 41,wdBarrevie, 6);
        
        if(nbFrame>0)
         {
           gb.display.setColor(INVERT);
           gb.display.drawBitmap(32 - nbFrame, 24,attaqueGriffe );
           gb.display.setColor(BLACK);
           nbFrame--;
         }
        
        if(gb.buttons.pressed(BTN_A) && nbFrame <= 0)
        {
          break;
        }
        
      }
    }
  }

  int8_t GetWidthBarreVie(uint8_t pourcentVie, uint8_t tailleMaxPx)
  {
    return pourcentVie * tailleMaxPx / 100;
  }
  
  void CombatAttack(Monster *att, Monster *def)
  {
      //TODO faire avec le choix des attaque ! 
      def->Vie = def->Vie - att->Force; 
      if(def->Vie<0) def->Vie = 0;
  }
  void CombatResolutionOfAttack()
  {
    //TODO uniquement pour test
    CombatAttack(ctx->Joueur.GetSelectedMonster(),ctx->Adversaire.GetSelectedMonster());
    CombatAttack(ctx->Adversaire.GetSelectedMonster(),ctx->Joueur.GetSelectedMonster());
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

  
  ///FIin resolution combat
