
const byte Fleche[] PROGMEM = {8,5,B00100000,B01100000,B11111100,B01100000,B00100000,};

uint8_t StartScene()
{
  uint8_t cpt = 0;
  gb.display.textWrap = true;
  while(true)
  {
     if(gb.update())
    {
      
      gb.display.println("I don't remember why i here.");
      
      if(cpt>0)
        gb.display.println("I wake up and a monster come help me.");
      if(cpt>1)
        gb.display.println("Without him I'd be dead.");
      if(cpt>2)
        gb.display.println("Now i want fight for my freedom!");
      
      if(cpt>3)
        break;
        
        if(gb.buttons.pressed(BTN_A))
        {
          cpt++;
        }
    }
  }
  gb.display.textWrap = false;
  return 51;
}

uint8_t ChoixMonsterDebut()
{
  int8_t cptChoix = 0;
  int8_t offset = 0;
  while(true)
  {
     if(gb.update())
    {
        gb.display.drawBitmap(5,10,Fleche);
        gb.display.drawBitmap(75,10,Fleche,NOROT,FLIPH);
        gb.display.drawBitmap(30 + offset, 24, GetSpriteMonsterByNumero(cptChoix, true));
      
        if(offset>0) offset -=8; else if(offset<0) offset +=8;
      
        if(gb.buttons.pressed(BTN_LEFT))
        {
          cptChoix++;
          cptChoix = cptChoix%3;
          offset = 40;
        }
        if(gb.buttons.pressed(BTN_RIGHT))
        {
          cptChoix--;
          cptChoix = cptChoix<0 ? 2 : cptChoix;
          offset = -40;
        }
        
        if(gb.buttons.pressed(BTN_A))
        {
          break;
        }
    }
  }
  
  
    ctx->Joueur.AddMonster(0,0,0,0,0,0,0,0);
    Monster *m = ctx->Joueur.GetMonster(0);
    GenerateStartMonster(m,cptChoix);

    monsterVue[cptChoix] = true;
    MonsterCatch[cptChoix] = true;
    nbVue++;
    nbCatch++;
  
  return 0;
}
