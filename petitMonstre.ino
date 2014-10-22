//imports the SPI library (needed to communicate with Gamebuino's screen)
#include <SPI.h>
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
   Player p1;
   ctx->Joueur = p1;

   Monster m1;
   m1.Name = "TUTU";
   Monster m2 ;
   m2.Name = "TaTa";
   Monster m3 ;
   m3.Name = "TYTY";

   ctx->Joueur.AddMonster(m1);
   ctx->Joueur.AddMonster(m2);
   ctx->Joueur.AddMonster(m3);
  //TODO recherche de l user
}

void loop()
{
  //returns true when it's time to render a new frame (20 times/second)
  if(gb.update())
  {
    gb.battery.show = false;
    
    int nbMonstre = ctx->Joueur.NbMonstre();
    char* menu[nbMonstre];

    for(int i=0;i<nbMonstre;i++)
    {
      menu[i] =  ctx->Joueur.GetMonster(i).Name;
    }

    switch(gb.menu( menu, nbMonstre)){
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
        
    //petitMonstreGame.Update(gb,ctx);
    //petitMonstreGame.Draw(gb,ctx);
    //if multiplayer refresh ctx in I2C
  }
}
