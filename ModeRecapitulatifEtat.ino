
void DysplayEtatAllFuturomon()
{
  uint8_t cptMonster = 0;
  ctx->Joueur.SelectMonster(cptMonster);
  while(cptMonster<ctx->Joueur.NbMonstre())
  {
    if(gb.update())
    {      
        DysplayEtatFuturomon(*ctx->Joueur.GetSelectedMonster());
        cptMonster++;
        ctx->Joueur.SelectMonster(cptMonster);
    }
  }
  while(true)
  {
    if(gb.update())
    {  
      DisplayEtatgame();
      if(gb.buttons.pressed(BTN_A))
      {
       break;
      }
    }
    
  }
  ctx->Joueur.UnSelectMonster();
}


void DysplayFuturodex()
{
  uint8_t cptMonster = 0;
  while(cptMonster<Nb_MONSTERS)
  {
    if(gb.update())
    {    
        while(!monsterVue[cptMonster] && cptMonster<Nb_MONSTERS)
          cptMonster++;
          
         
        if(monsterVue[cptMonster] && cptMonster<Nb_MONSTERS)
        {
          Monster tempM;
          tempM.Numero = cptMonster;
          DysplayFuturoDex(tempM);
        }
        else 
        {
          gb.popup(F("Fin"),40);
        }
        cptMonster++;
    }
  }
  ctx->Joueur.UnSelectMonster();
}


void DysplayEtatFuturomon(Monster monster)
{
  uint8_t offset = 30;
  
  while(true)
  {
    if(gb.update())
    {      
      gb.display.drawBitmap(60  , 0- offset, GetSpriteMonsterByNumero(monster.Numero, true));
      
      if(offset>0)offset -= 3;
      
      gb.display.println(F(""));
      
      gb.display.print(F("LvL:"));
      gb.display.println(monster.Niveau);
      
      gb.display.print(F("Vie:"));
      gb.display.print(monster.Vie);
      gb.display.print(F("/"));
      gb.display.println(monster.VieMax);

      gb.display.print(F("Vit:"));
      gb.display.print(monster.Vitesse);
      gb.display.print(F("/"));
      gb.display.println(monster.VitesseMax);

      gb.display.print(F("For:"));
      gb.display.print(monster.Force);
      gb.display.print(F("/"));
      gb.display.println(monster.ForceMax);

      gb.display.print(F("Def:"));
      gb.display.print(monster.Defence);
      gb.display.print(F("/"));
      gb.display.println(monster.DefenceMax);
      
      gb.display.print(F("XP :"));
      gb.display.print(monster.Xp);
      gb.display.print(F("/"));
      gb.display.println(monster.NextNiveau);
      
      if(gb.buttons.pressed(BTN_A))
      {
       break;
      }
    }
  }
}

void DisplayEtatgame()
{
  
      gb.display.setFont(font3x5);
      gb.display.print(F("Area :"));
      gb.display.print(cptArea);
      gb.display.print(F(" Kill :"));
      gb.display.println(cptKill);
      gb.display.print(F("Vue  :"));
      gb.display.print(nbVue);
      gb.display.print(F(" Attrape  :"));
      gb.display.println(nbCatch);
      
      for(byte i =0; i<NB_THEMES;i++)
      {
        gb.display.print(F("Zone "));
        gb.display.print(i+1);
        gb.display.print(F(" "));
        gb.display.println(DresseurByTheme[i]);
      }
}

void DysplayFuturoDex(Monster monster)
{
  uint8_t offset = 30;
  
  while(true)
  {
    if(gb.update())
    {      
      
         if(MonsterCatch[monster.Numero])
         {
           gb.display.print(F("Capture"));
         }
         else
         {
           gb.display.print(F("Vue"));
         }
      gb.display.drawBitmap(60  , 0- offset, GetSpriteMonsterByNumero(monster.Numero, true));
      
      if(offset>0)offset -= 3;
      
      if(gb.buttons.pressed(BTN_A))
      {
       break;
      }
    }
  }
}






