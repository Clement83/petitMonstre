
#define NB_ATTAQUE_BY_MONSTER 5
#define NB_MAX_NUM_ATTAQUE_BY_IA 3
#define NB_PATTERN_ATTAQUE 5
#define NUMERO_ATTAQUE_CHANGE 8
#define NUMERO_ATTAQUE_CAPTURE 9

const char strAttkGriffe[] PROGMEM = "Griffe";//0
const char strAttkCharge[] PROGMEM = "Charge";//1
const char strAttkEau[] PROGMEM = "Eau";//2
const char strAttkFeux[] PROGMEM = "Feux";//3
const char strAttkTerre[] PROGMEM = "terre";//4
const char strAttkPlante[] PROGMEM = "Plante";//5
const char strAttkElec[] PROGMEM = "Electrique";//6
const char strAttkPsy[] PROGMEM = "Psy";//7

const char strAttkChangeMonster[] PROGMEM = "Change";//8

const char strAttkCatchMonster[] PROGMEM = "Capture";//9

const int8_t TypeIsFaibleAttk[NB_PATTERN_ATTAQUE] PROGMEM = 
{
  2,//Feux
  0,//Eau
  1,//Plante
  4,//Terre
  2,//Elec
};

//Put all the different items together in a menu (an array of strings actually)
const char* const attkFeuxPattern[NB_ATTAQUE_BY_MONSTER] PROGMEM = {
 	strAttkGriffe,
	strAttkCharge,
	strAttkFeux,
	strAttkChangeMonster,
        strAttkCatchMonster,
};

const char* const attkEauPattern[NB_ATTAQUE_BY_MONSTER] PROGMEM = {
 	strAttkGriffe,
	strAttkCharge,
	strAttkEau,
	strAttkChangeMonster,
        strAttkCatchMonster,
};

const char* const attkPlantePattern[NB_ATTAQUE_BY_MONSTER] PROGMEM = {
 	strAttkGriffe,
	strAttkCharge,
	strAttkPlante,
	strAttkChangeMonster,
        strAttkCatchMonster,
};

const char* const attkTerrePattern[NB_ATTAQUE_BY_MONSTER] PROGMEM = {
 	strAttkGriffe,
	strAttkCharge,
	strAttkTerre,
	strAttkChangeMonster,
        strAttkCatchMonster,
};

const char* const attkElecPattern[NB_ATTAQUE_BY_MONSTER] PROGMEM = {
 	strAttkGriffe,
	strAttkCharge,
	strAttkElec,
	strAttkChangeMonster,
        strAttkCatchMonster,
};

const char* const attkPsyPattern[NB_ATTAQUE_BY_MONSTER] PROGMEM = {
 	strAttkGriffe,
	strAttkCharge,
	strAttkPsy,
	strAttkChangeMonster,
        strAttkCatchMonster,
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
		case 5 : 
		return attkPsyPattern;
		break;
	}
}


//Put all the different items together in a menu (an array of strings actually)
const uint8_t attkFeuxPatternNumero[NB_ATTAQUE_BY_MONSTER] = {
 	0,
	1,
	3,
	NUMERO_ATTAQUE_CHANGE,
	NUMERO_ATTAQUE_CAPTURE,
};

const uint8_t attkEauPatternNumero[NB_ATTAQUE_BY_MONSTER] = {
 	0,
	1,
	2,
	NUMERO_ATTAQUE_CHANGE,
	NUMERO_ATTAQUE_CAPTURE,
};

const uint8_t attkPlantePatternNumero[NB_ATTAQUE_BY_MONSTER] = {
 	0,
	1,
	5,
	NUMERO_ATTAQUE_CHANGE,
	NUMERO_ATTAQUE_CAPTURE,
};

const uint8_t attkTerrePatternNumero[NB_ATTAQUE_BY_MONSTER] = {
 	0,
	1,
	4,
	NUMERO_ATTAQUE_CHANGE,
	NUMERO_ATTAQUE_CAPTURE,
};

const uint8_t attkElecPatternNumero[NB_ATTAQUE_BY_MONSTER]  = {
 	0,
	1,
	6,
	NUMERO_ATTAQUE_CHANGE,
	NUMERO_ATTAQUE_CAPTURE,
};
const uint8_t attkPsyPatternNumero[NB_ATTAQUE_BY_MONSTER]  = {
 	0,
	1,
	7,
	NUMERO_ATTAQUE_CHANGE,
	NUMERO_ATTAQUE_CAPTURE,
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
		case 5 : 
		return attkPsyPatternNumero;
		break;
	}
}

const byte attaqueGriffe[] PROGMEM = {16,12,0x0,0x0,0xF,0x80,0x38,0x0,0x60,0x20,0x41,0xE0,0xC7,0x0,0x98,0x0,0x30,0x70,0x21,0xC0,0x23,0x0,0x6,0x0,0x4,0x0,};
const byte CatchThemAll[] PROGMEM = {16,16,0x3F,0xF8,0x20,0x0,0xAF,0xFC,0xA0,0x4,0xA0,0x74,0xA8,0x14,0xAB,0xD4,0xAA,0x14,0xAA,0x54,0x88,0xD5,0x88,0x11,0x8F,0xD1,0x80,0x5,0xFF,0xD,0x0,0x1,0xF,0xFF,};
const byte Charge[] PROGMEM = {8,3,0x7F,0x0,0xFE,};
const byte Electrique[] PROGMEM = {16,16,0x0,0x80,0x21,0x0,0x30,0x84,0x19,0x82,0x8F,0xE4,0x4C,0x38,0x28,0x12,0x19,0x9D,0x19,0x98,0x58,0x10,0xAC,0x3C,0x7,0xE2,0x5,0x85,0x18,0x80,0x20,0x40,0x10,0x80,};
const byte Feuille[] PROGMEM = {8,8,0x1D,0x26,0x49,0x91,0xA6,0xC8,0xB0,0xC0,};
const byte Feux[] PROGMEM = {8,14,0xE0,0x70,0x38,0x1C,0x16,0x12,0x2A,0x4B,0x55,0xA5,0x95,0x4A,0x24,0x18,};
const byte GoutteDeau[] PROGMEM = {8,4,0x40,0x60,0x90,0xE0,};
const byte psy[] PROGMEM = {16,16,0x1,0x0,0x1,0x0,0x1,0x0,0x1,0x0,0x1,0x0,0x1,0x0,0x3,0x80,0x2,0x80,0x2,0x80,0x4,0x40,0x8,0x20,0x1F,0xF0,0x18,0x38,0x20,0x4,0x40,0x2,0x80,0x1,};
const byte Terre[] PROGMEM = {16,5,0xC0,0x0,0x38,0xE7,0x85,0x2,0x72,0x79,0x4,0x4,};

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
      AttaquePsy(isP1,nbFrame);
    break;
    case NUMERO_ATTAQUE_CHANGE : 
      //Change monster 
    break;
    case NUMERO_ATTAQUE_CAPTURE : 
    //Attrape le monstre
      AttaqueCatch(isP1,nbFrame);
    break;
  }
}

bool HaveBonusAttak(uint8_t numAttaque,uint8_t numPattern,uint8_t typeDef)
{
  uint8_t numAttk =  GetAttaqueNumeroByNumPattern(numPattern)[numAttaque];
  
  if(numAttk - 2>0 && numAttk - 2<7)
  {
    return TypeIsFaibleAttk[numAttk - 2];
  }
  return false;
  
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
  if(isP1)
  {
      if(nbFrame>30)
      {
        uint8_t nbframe1 =  (45 - nbFrame)*2;
        gb.display.setColor(INVERT);
        gb.display.drawBitmap(60 + nbframe1,  2 ,Terre,0,0);
        gb.display.setColor(BLACK);
      }
  }
  else 
  {
      if(nbFrame>30)
      {
        uint8_t nbframe1 =  (nbFrame - 45)*2;
        gb.display.setColor(INVERT);
        gb.display.drawBitmap(25 + nbframe1,  28 ,Terre, 0, 0);
        gb.display.setColor(BLACK);
      }
  }
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
void AttaquePsy(bool isP1,uint8_t nbFrame)
{
  if(isP1)
  {
      if(nbFrame>30)
      {
        //uint8_t nbframe1 =  45 - nbFrame;
        gb.display.setColor(INVERT);
        gb.display.drawBitmap(65 + random(-4,4),  5 + random(-4,4) ,psy,random(0,4), random(0,4));
        gb.display.setColor(BLACK);
      }
  }
  else 
  {
      if(nbFrame>30)
      {
        uint8_t nbframe1 =  45 - nbFrame;
        gb.display.setColor(INVERT);
        gb.display.drawBitmap(5 + random(-4,4),  28 + random(-4,4) ,psy, random(0,4), random(0,4));
        gb.display.setColor(BLACK);
      }
  }
}

void AttaqueCatch(bool isP1,uint8_t nbFrame)
{
  if(isP1)
  {
      if(nbFrame>30)
      {
        //uint8_t nbframe1 =  45 - nbFrame;
        gb.display.setColor(INVERT);
        gb.display.drawBitmap(65 + random(-4,4),  5 + random(-4,4) ,CatchThemAll,random(0,4), random(0,4));
        gb.display.setColor(BLACK);
      }
  }
  else 
  {
      if(nbFrame>30)
      {
        uint8_t nbframe1 =  45 - nbFrame;
        gb.display.setColor(INVERT);
        gb.display.drawBitmap(5 + random(-4,4),  28 + random(-4,4) ,CatchThemAll, random(0,4), random(0,4));
        gb.display.setColor(BLACK);
      }
  }
}


