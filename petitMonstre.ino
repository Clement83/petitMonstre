//imports the SPI library (needed to communicate with Gamebuino's screen)
#include <SPI.h>
//imports the Gamebuino library
#include <Gamebuino.h>
//creates a Gamebuino object named gb
Gamebuino gb;

#include "CoreGame.h";
#include "CoreExplore.h"
#include "Constante.cpp"

CoreGame petitMonstreGame;

void setup()
{
  
 // initialize the Gamebuino object
  gb.begin();
  //display the main menu:
  gb.titleScreen(F("les petits monstres"));
  //gb.popup(F("lets go go go!!"), 100);
  
  petitMonstreGame.Init();
 

}

void loop()
{
  //returns true when it's time to render a new frame (20 times/second)
  if(gb.update()){
    gb.battery.show = false;
    petitMonstreGame.Update(gb);
    petitMonstreGame.Draw(gb);
    
    //gb.popup(F("gogogo"), 100);
  }
  
}
