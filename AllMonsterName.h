#if !defined (AllMonsterName_H)
#define AllMonsterName_H

#define NB_MONSTER_EQUIPE 4

const char strMecheBizard[] PROGMEM = "Fut 1";
const char strFlottille[] PROGMEM = "Fut 2";
const char strChampiFort[] PROGMEM = "Fut 3";
const char strTerraBaffle[] PROGMEM = "Fut 4";


//Put all the different items together in a menu (an array of strings actually)
const char* const allMonsters[NB_MONSTER_EQUIPE] PROGMEM = {
  strMecheBizard,
  strFlottille,
  strChampiFort,
  strTerraBaffle,
};

#endif 

