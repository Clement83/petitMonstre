

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
  return 0;
}
