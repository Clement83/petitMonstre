//imports the SPI library (needed to communicate with Gamebuino's screen)
#include <SPI.h>
//imports the Gamebuino library
#include <Gamebuino.h>
//creates a Gamebuino object named gb
Gamebuino gb;

#include "CoreGame.h";
#include "CoreExplore.h"
#include "Constante.cpp"
#include "IContexte.h"

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
  //TODO recherche de l user
}

void loop()
{
  //returns true when it's time to render a new frame (20 times/second)
  if(gb.update())
  {
    gb.battery.show = false;
    petitMonstreGame.Update(gb,ctx);
    petitMonstreGame.Draw(gb,ctx);
    //if multiplayer refresh ctx in I2C
  }
}
