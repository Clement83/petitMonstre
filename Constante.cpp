#if !defined (Constante_H)
#define Constante_H

#include <SPI.h>

#define MENUMAXLENGTHCHOIXMONSTER 3


/**
Liste des noms de tous les monstre de l'appli
**/
char * StrLesMonstres[4] PROGMEM = { 
"MecheBizard", 
"Flottille", 
"ChampiFort", 
"TerraBaffle"};


char *StrLesAttaques[4] PROGMEM = { 
"Charge", 
"Feux", 
"Eau", 
"Terre"};

/*
const char strMonster1[] PROGMEM = "MecheBizard";
const char strMonster2[] PROGMEM = "Flottille";
const char strMonster3[] PROGMEM = "ChampiFort";
const char strMonster4[] PROGMEM = "TerraBaffle";*/

#endif
