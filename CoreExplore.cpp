#include "CoreFight.h"
#include "CoreExplore.h"
#include <Gamebuino.h>
#include "IContexte.h"
    

void CoreExplore::Init()
{
  ICoreGame::Init();
}

void CoreExplore::Draw(Gamebuino gb, IContexte *ctx)
{
  gb.display.println(F("Press A"));
}

void CoreExplore::Update(Gamebuino gb, IContexte *ctx)
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

    this->isChangeState = true;
  }
  
  //gb.display.println(F("CoreExplore : update!"));
}

bool CoreExplore::NeedChangeState()
{
  return this->isChangeState;
}

ICoreGame * CoreExplore::NewState()
{
  //choix du mode combat
  //Create engine fight
  ICoreGame *coreFight;
  coreFight = new CoreFight();
  coreFight->Init();
  return coreFight;
}

