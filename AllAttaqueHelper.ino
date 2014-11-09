
#define NB_ATTAQUE_BY_MONSTER 4
#define NB_MAX_NUM_ATTAQUE_BY_IA 3

const char strAttkGriffe[] PROGMEM = "Griffe";//0
const char strAttkCharge[] PROGMEM = "Charge";//1
const char strAttkEau[] PROGMEM = "Eau";//2
const char strAttkFeux[] PROGMEM = "Feux";//3
const char strAttkTerre[] PROGMEM = "terre";//4
const char strAttkPlante[] PROGMEM = "Plante";//5
const char strAttkElec[] PROGMEM = "Electrique";//6

const char strAttkChangeMonster[] PROGMEM = "Change";//7

const char strAttkCatchMonster[] PROGMEM = "Attrappe";//8


//Put all the different items together in a menu (an array of strings actually)
const char* const attkFeuxPattern[NB_ATTAQUE_BY_MONSTER] PROGMEM = {
 	strAttkGriffe,
	strAttkCharge,
	strAttkFeux,
	strAttkChangeMonster,
};

const char* const attkEauPattern[NB_ATTAQUE_BY_MONSTER] PROGMEM = {
 	strAttkGriffe,
	strAttkCharge,
	strAttkEau,
	strAttkChangeMonster,
};

const char* const attkPlantePattern[NB_ATTAQUE_BY_MONSTER] PROGMEM = {
 	strAttkGriffe,
	strAttkCharge,
	strAttkPlante,
	strAttkChangeMonster,
};

const char* const attkTerrePattern[NB_ATTAQUE_BY_MONSTER] PROGMEM = {
 	strAttkGriffe,
	strAttkCharge,
	strAttkTerre,
	strAttkChangeMonster,
};

const char* const attkElecPattern[NB_ATTAQUE_BY_MONSTER] PROGMEM = {
 	strAttkGriffe,
	strAttkCharge,
	strAttkElec,
	strAttkChangeMonster,
};


const char* const * GetAttakByPatternNumero(uint8_t num)
{
	switch(num)
	{
		case 0 : 
		return attkFeuxPattern;
		break;
		case 1 : 
		return attkEauPattern;
		break;
		case 2 : 
		return attkPlantePattern;
		break;
		case 3 : 
		return attkTerrePattern;
		break;
		case 4 : 
		return attkElecPattern;
		break;
	}
}


//Put all the different items together in a menu (an array of strings actually)
const uint8_t attkFeuxPatternNumero[NB_ATTAQUE_BY_MONSTER] = {
 	0,
	1,
	3,
	7,
};

const uint8_t attkEauPatternNumero[NB_ATTAQUE_BY_MONSTER] = {
 	0,
	1,
	2,
	7,
};

const uint8_t attkPlantePatternNumero[NB_ATTAQUE_BY_MONSTER] = {
 	0,
	1,
	5,
	7,
};

const uint8_t attkTerrePatternNumero[NB_ATTAQUE_BY_MONSTER] = {
 	0,
	1,
	4,
	7,
};

const uint8_t attkElecPatternNumero[NB_ATTAQUE_BY_MONSTER]  = {
 	0,
	1,
	6,
	7,
};

const uint8_t * GetAttaqueNumeroByNumPattern(uint8_t num)
{
	switch(num)
	{
		case 0 : 
		return attkFeuxPatternNumero;
		break;
		case 1 : 
		return attkEauPatternNumero;
		break;
		case 2 : 
		return attkPlantePatternNumero;
		break;
		case 3 : 
		return attkTerrePatternNumero;
		break;
		case 4 : 
		return attkElecPatternNumero;
		break;
	}
}

const byte attaqueGriffe[] PROGMEM = {16,16,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xC0,0x1C,0x0,0x30,0x10,0x20,0xF0,0x63,0x80,0x4C,0x0,0x18,0x38,0x10,0xE0,0x11,0x80,0x3,0x0,0x2,0x0,0x0,0x0,0x0,0x0,};
const byte Charge[] PROGMEM = {8,4,0x7F,0x0,0xFE,0x0,};
const byte Electrique[] PROGMEM = {16,16,0x0,0x80,0x21,0x0,0x30,0x84,0x19,0x82,0x8F,0xE4,0x4C,0x38,0x28,0x12,0x19,0x9D,0x19,0x98,0x58,0x10,0xAC,0x3C,0x7,0xE2,0x5,0x85,0x18,0x80,0x20,0x40,0x10,0x80,};
const byte Feuille[] PROGMEM = {16,16,0x0,0x0,0x7,0xE0,0x8,0x38,0x18,0x6C,0x30,0xC6,0x21,0x82,0x63,0x2,0x46,0x6,0x4C,0xC,0x58,0x38,0x50,0x60,0x70,0xC0,0x43,0x80,0x5E,0x0,0x70,0x0,0x0,0x0,};
const byte Feux[] PROGMEM = {16,16,0x0,0x0,0xE,0x0,0x7,0x0,0x3,0x80,0x1,0xC0,0x1,0x60,0x1,0x20,0x2,0x20,0x4,0x30,0x4,0x10,0x8,0x10,0x8,0x10,0x4,0x20,0x2,0x40,0x1,0x80,0x0,0x0,};
const byte GoutteDeau[] PROGMEM = {8,4,0x40,0x60,0x90,0xE0,};


void ResolutionAttaqueAnimation(uint8_t numAttaque,uint8_t numPattern,bool isP1,uint8_t nbFrame)
{
  uint8_t numAttk =  GetAttaqueNumeroByNumPattern(numPattern)[numAttaque];
            
  switch (numAttk)
  {
    case 0 : 
      AttaqueGriffe(isP1,nbFrame);
    break;
    case 1 : 
      AttaqueCharge(isP1,nbFrame);
    break;
    case 2 : 
      AttaqueEau(isP1,nbFrame);
    break;
    case 3 : 
      AttaqueFeux(isP1,nbFrame);
    break;
    case 4 : 
      AttaqueTerre(isP1,nbFrame);
    break;
    case 5 : 
      AttaquePlante(isP1,nbFrame);
    break;
    case 6 : 
      AttaqueElectrique(isP1,nbFrame);
    break;
    case 7 : 
      //Change monster 
    break;
    case 8 : 
    //Attrape le monstre
      //AttaqueElectrique(isP1,nbFrame);
    break;
  }
}

void AttaqueGriffe(bool isP1,uint8_t nbFrame)
{
  if(isP1)
  {
      if(nbFrame>30)
      {
        uint8_t nbframe1 =  45 - nbFrame;
        gb.display.setColor(INVERT);
        gb.display.drawBitmap(58 + nbframe1,  10 - nbframe1,attaqueGriffe );
        gb.display.setColor(BLACK);
      }
  }
  else 
  {
      if(nbFrame>30)
      {
        uint8_t nbframe1 =  45 - nbFrame;
        gb.display.setColor(INVERT);
        gb.display.drawBitmap(30 - nbframe1,  18 + nbframe1,attaqueGriffe );
        gb.display.setColor(BLACK);
      }
  }
}



void AttaqueCharge(bool isP1,uint8_t nbFrame)
{
  if(isP1)
  {
      if(nbFrame>30)
      {
        uint8_t nbframe1 =  (45 - nbFrame)*2;
        gb.display.setColor(INVERT);
        gb.display.drawBitmap(60 + nbframe1,  2 ,Charge,0,0);
        gb.display.drawBitmap(70 + nbframe1,  10 ,Charge,0,0);
        gb.display.drawBitmap(65 + nbframe1,  20 ,Charge,0,0);
        gb.display.setColor(BLACK);
      }
  }
  else 
  {
      if(nbFrame>30)
      {
        uint8_t nbframe1 =  (nbFrame - 45)*2;
        gb.display.setColor(INVERT);
        gb.display.drawBitmap(25 + nbframe1,  28 ,Charge, 0, 0);
        gb.display.drawBitmap(15 + nbframe1,  36 ,Charge, 0, 0);
        gb.display.drawBitmap(20 + nbframe1,  40 ,Charge, 0, 0);
        gb.display.setColor(BLACK);
      }
  }
}


void AttaqueEau(bool isP1,uint8_t nbFrame)
{
  if(isP1)
  {
      if(nbFrame>30)
      {
        uint8_t nbframe1 =  45 - nbFrame;
        
        gb.display.setColor(INVERT);
        for(uint8_t cptGoutte = 0 ;cptGoutte<nbframe1;cptGoutte++)
        {
          if(cptGoutte%2==0)
          {
            gb.display.drawBitmap(65 + random(-9,10) ,  10 + random(-9,10) ,GoutteDeau,0,0);
          }
        }
        gb.display.setColor(BLACK);
      }
  }
  else 
  {
      if(nbFrame>30)
      {
        uint8_t nbframe1 =  45 - nbFrame;
        gb.display.setColor(INVERT);
        for(uint8_t cptGoutte = 0 ;cptGoutte<nbframe1;cptGoutte++)
        {
          if(cptGoutte%2==0)
          {
            gb.display.drawBitmap(10 + random(-9,10) ,  28+ random(-9,10) ,GoutteDeau,0,0);
          }
        }
        gb.display.setColor(BLACK);
      }
  }
}

int8_t offsetX = 0;
int8_t offsetY = 0;
void AttaqueFeux(bool isP1,uint8_t nbFrame)
{
  if(nbFrame%4)
  {
    offsetX = random(-4,4);
    offsetY = random(-4,4);
  }
  
  if(isP1)
  {
      if(nbFrame>30)
      {
        //uint8_t nbframe1 =  45 - nbFrame;
        gb.display.setColor(INVERT);
        gb.display.drawBitmap(65 + offsetX ,  5 + offsetY ,Feux,0, 0);
        gb.display.setColor(BLACK);
      }
  }
  else 
  {
      if(nbFrame>30)
      {
        uint8_t nbframe1 =  45 - nbFrame;
        gb.display.setColor(INVERT);
        gb.display.drawBitmap(5+ offsetX ,  35 + offsetY ,Feux, 0, 0);
        gb.display.setColor(BLACK);
      }
  }
}


void AttaqueTerre(bool isP1,uint8_t nbFrame)
{
  AttaqueCharge(isP1,nbFrame);
}


void AttaquePlante(bool isP1,uint8_t nbFrame)
{
  if(isP1)
  {
      if(nbFrame>37)
      {
        uint8_t offset =  (45 - nbFrame)*2;
        gb.display.setColor(INVERT);
        gb.display.drawBitmap(60 +offset ,  20 - offset,Feuille,0, 1);
        gb.display.setColor(BLACK);
      }
      else if(nbFrame>30)
      {
        uint8_t offset =  (nbFrame - 30)*2;
        gb.display.setColor(INVERT);
        gb.display.drawBitmap(65 +offset ,  20-offset ,Feuille,0, 1);
        gb.display.setColor(BLACK);
      }
  }
  else 
  {
      if(nbFrame>37)
      {
        uint8_t offset =  (nbFrame - 37 )*2;
        gb.display.setColor(INVERT);
        gb.display.drawBitmap(2 +offset ,  30 - offset,Feuille,0, 1);
        gb.display.setColor(BLACK);
      }
      else if(nbFrame>30)
      {
        uint8_t offset =  (37 - nbFrame )*2;
        gb.display.setColor(INVERT);
        gb.display.drawBitmap(2 +offset ,  30-offset ,Feuille,0, 1);
        gb.display.setColor(BLACK);
      }
  }
}


void AttaqueElectrique(bool isP1,uint8_t nbFrame)
{
  if(isP1)
  {
      if(nbFrame>30)
      {
        //uint8_t nbframe1 =  45 - nbFrame;
        gb.display.setColor(INVERT);
        gb.display.drawBitmap(65 + random(-4,4),  5 + random(-4,4) ,Electrique,random(0,4), random(0,4));
        gb.display.setColor(BLACK);
      }
  }
  else 
  {
      if(nbFrame>30)
      {
        uint8_t nbframe1 =  45 - nbFrame;
        gb.display.setColor(INVERT);
        gb.display.drawBitmap(5 + random(-4,4),  28 + random(-4,4) ,Electrique, random(0,4), random(0,4));
        gb.display.setColor(BLACK);
      }
  }
}


