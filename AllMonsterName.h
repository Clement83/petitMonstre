#if !defined (AllMonsterName_H)
#define AllMonsterName_H

const char strMecheBizard[] PROGMEM = "MecheBizard";
const char strFlottille[] PROGMEM = "Flottille";
const char strChampiFort[] PROGMEM = "ChampiFort";
const char strTerraBaffle[] PROGMEM = "TerraBaffle";


//Put all the different items together in a menu (an array of strings actually)
const char* const allMonsters[4] PROGMEM = {
  strMecheBizard,
  strFlottille,
  strChampiFort,
  strTerraBaffle,
};

#endif 

