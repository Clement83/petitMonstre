//imports the SPI library (needed to communicate with Gamebuino's screen)
#include <SPI.h>
#include <stdint.h>
//imports the Gamebuino library
#include <Gamebuino.h>
//creates a Gamebuino object named gb
Gamebuino gb;

#include "CoreGame.h";
#include "CoreExplore.h"
#include "AllMonsterName.h"
#include "IContexte.h"
#include "Player.h"
#include "Monster.h"

CoreGame petitMonstreGame;
IContexte * ctx;


void setup()
{
  
 // initialize the Gamebuino object
  gb.begin();
  //display the main menu:
  gb.titleScreen(F("les petits monstres"));
  petitMonstreGame.Init();
  
   ctx = new IContexte();
   Player *p1 = new Player();
   ctx->Joueur = *p1;

   Monster *m1 = new Monster();
   m1->Numero = 1;
   m1->Force = 2;
   m1->Vie = 10;
   m1->Vitesse = 5;
   m1->Defence = 1;
   Monster *m2= new Monster();
   m2->Numero = 2;
   m2->Force = 3;
   m2->Vie = 10;
   m2->Vitesse = 5;
   m2->Defence = 1;
   Monster *m3 = new Monster();
   m3->Numero = 3;
   m3->Force = 4;
   m3->Vie = 10;
   m3->Vitesse = 5;
   m3->Defence = 1;
   Monster *m4 = new Monster();
   m4->Numero = 4;
   m4->Force = 5;
   m4->Vie = 10;
   m4->Vitesse = 5;
   m4->Defence = 1;
  //All player have 4 monster because the menu is static
   ctx->Joueur.AddMonster(*m1);
   ctx->Joueur.AddMonster(*m2);
   ctx->Joueur.AddMonster(*m3);
   ctx->Joueur.AddMonster(*m4);



   Player *adv = new Player();
   ctx->Adversaire = *adv;
   ctx->IsMaster = true;

   Monster *m5 = new Monster();
   m5->Numero = 1;
   m5->Force = 2;
   m5->Vie = 15;
   m5->Vitesse = 3;
   m5->Defence = 1;
   /*Monster *m6= new Monster();
   m2->Numero = 2;
   m2->Force = 2;
   m2->Vie = 10;
   m2->Vitesse = 5;
   m2->Defence = 1;
   Monster *m3 = new Monster();
   m3->Numero = 3;
   m3->Force = 2;
   m3->Vie = 10;
   m3->Vitesse = 5;
   m3->Defence = 1;
   Monster *m4 = new Monster();
   m4->Numero = 4;
   m4->Force = 2;
   m4->Vie = 10;
   m4->Vitesse = 5;
   m4->Defence = 1;*/
  //All player have 4 monster because the menu is static
   ctx->Adversaire.AddMonster(*m5);
   ctx->Adversaire.SelectMonster(0);
  //TODO recherche de l user
}

void loop()
{
  //returns true when it's time to render a new frame (20 times/second)
  if(gb.update())
  {
    gb.battery.show = false;
   // ctx->Joueur.SelectMonster(1);
    //gb.display.print("nb : ");
    //gb.display.print(ctx->Adversaire.NbMonstre());
     //gb.display.print(ctx->IsMaster);
    
    petitMonstreGame.Update(gb,ctx);
    petitMonstreGame.Draw(gb,ctx);
    //if multiplayer refresh ctx in I2C
    
    //TODO mettre ça ou il faut IA plus que basic
   // if(ctx->Joueur.IsSelectedMonster())
    {
        //gb.display.print("J2 select M");
       // if(!ctx->Adversaire.IsSelectedMonster())
       //if(ctx->Joueur.GetSelectedMonster().IsSelectedAttack())
        {
                    //gb.display.print("J2 select A");
         //   if(!ctx->Adversaire.GetSelectedMonster().IsSelectedAttack())
              ctx->Adversaire.GetSelectedMonster()->SetSelectedAttack(0);
        } 
    }

  }
}
