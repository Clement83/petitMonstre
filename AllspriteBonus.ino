

#define NUM_SPRITES_BONUS 24


//Bonus sprite
const byte CapsDef[] PROGMEM = {
  8,8,0x3C,0x7E,0xB1,0xA9,0xA9,0xB1,0x7E,0x3C,};//0
const byte CapsForce[] PROGMEM = {
  8,8,0x3C,0x7E,0x9D,0x91,0x99,0x91,0x7E,0x3C,};//1
const byte CapsVitt[] PROGMEM = {
  8,8,0x3C,0x7E,0x81,0xA3,0x95,0x89,0x7E,0x3C,};//2
const byte Medikit[] PROGMEM = {
  8,8,0xFF,0xE7,0xE7,0x81,0x81,0xE7,0xE7,0xFF,};//3
const byte Capsule[] PROGMEM = {
  8,8,0x3C,0x7E,0x85,0x89,0x91,0xA1,0x7E,0x3C,};//4



#define NB_BONUS 3
byte bonus[NB_BONUS];

byte getBonusID(byte px, byte py, byte pos){
  if(bonus[pos]>0)
  {
    byte x = (bonus[pos]>> 3) & B00000111;
    byte y = (bonus[pos]) & B00000111;
    if(px == x && py == y)
    {
      return (bonus[pos]>> 6) & B00000011;
    }
  }
  return 255;
}

/*
byte getRotation(byte x, byte y){
 return (world[x][y] >> 6)  & B00000011;
 }*/

void setBonus(byte x, byte y, byte bonusID, byte numBonus){
  bonus[numBonus] = (bonusID << 6) + (x<<3)+y;
}

void GenerteAllBonus()
{
  for(byte i=0;i<NB_BONUS;i++)
  {
    setBonus(random(0,15),random(0,15),random(0,4),i);
  }
}
void drawAllBonus()
{
  for(byte i=0;i<NB_BONUS;i++)
  {
    if(bonus[i]>0)
    {
      byte x = (bonus[i]>> 3) & B00000111;
      byte y = (bonus[i]) & B00000111;
      byte id = (bonus[i]>> 6) & B00000011;
      int x_screen = (x+1)*8 - camera_x;
      int y_screen = (y+1)*8 - camera_y;
      gb.display.drawBitmap(x_screen, y_screen, GetSpriteBonusByNumero(id));
    }
  }
}

const byte * GetSpriteBonusByNumero(byte num)
{
  switch(num)
  {
  case 0 :
    return     CapsDef;
    break;
  case 1 :
    return     CapsForce;
    break;
  case 2 :
    return     CapsVitt;
    break;
  case 3 :
    return     Medikit;
    break;
  }
}

void TestGetBonus(byte x, byte y)
{
  for(byte i=0;i<NB_BONUS;i++)
  {
    byte id = getBonusID(x-1,y-1,i);
    if(id<255)
    {
      setBonus(0, 0, 0, i);
      if(id == 0)
      {
        for(byte i=0;i<ctx->Joueur.NbMonstre();i++)
        {
          ctx->Joueur.GetMonster(i)->Defence++;
        }
      }
      else if(id == 1)
      {
        for(byte i=0;i<ctx->Joueur.NbMonstre();i++)
        {
          ctx->Joueur.GetMonster(i)->Force++;
        }
      }
      else if(id == 2)
      {
        for(byte i=0;i<ctx->Joueur.NbMonstre();i++)
        {
          ctx->Joueur.GetMonster(i)->Vitesse++;
        }
      }
      else if(id == 3)
      {
        for(byte i=0;i<ctx->Joueur.NbMonstre();i++)
        {
          ctx->Joueur.GetMonster(i)->Vie = ctx->Joueur.GetMonster(i)->VieMax;
        }
      }
    }
  }
}



