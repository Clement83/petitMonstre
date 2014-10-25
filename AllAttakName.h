#if !defined (AllAttakName_H)
#define AllAttakName_H

const char strAttkCharge[] PROGMEM = "Charge";
const char strAttkEsquive[] PROGMEM = "Esquive";
const char strAttkEau[] PROGMEM = "Eau";
const char strAttkFeux[] PROGMEM = "Feux";
const char strAttkTerre[] PROGMEM = "terre";
const char strAttkPlante[] PROGMEM = "Plante";

const char strAttkChangeMonster[] PROGMEM = "Change";


//Put all the different items together in a menu (an array of strings actually)
const char* const attkMecheBizard[4] PROGMEM = {
 	strAttkCharge,
	strAttkEsquive,
	strAttkFeux,
	strAttkChangeMonster,
};

const char* const attkstrFlottille[4] PROGMEM = {
 	strAttkCharge,
	strAttkEsquive,
	strAttkEau,
	strAttkChangeMonster,
};

const char* const attkChampiFort[4] PROGMEM = {
 	strAttkCharge,
	strAttkEsquive,
	strAttkPlante,
	strAttkChangeMonster,
};

const char* const attkTerraBaffle[4] PROGMEM = {
 	strAttkCharge,
	strAttkEsquive,
	strAttkTerre,
	strAttkChangeMonster,
};


const char* const * GetAttakByNumero(uint8_t num)
{
	switch(num)
	{
		case 0 : 
		return attkMecheBizard;
		break;
		case 1 : 
		return attkstrFlottille;
		break;
		case 2 : 
		return attkChampiFort;
		break;
		case 3 : 
		return attkTerraBaffle;
		break;
	}
}


#endif 

