#if !defined (AllMonsterName_H)
#define AllMonsterName_H

#define NB_MONSTER_EQUIPE 4

const char strMecheBizard[] PROGMEM = "Slot 1";
const char strFlottille[] PROGMEM = "Slot 2";
const char strChampiFort[] PROGMEM = "Slot 3";
const char strTerraBaffle[] PROGMEM = "Slot 4";


//Put all the different items together in a menu (an array of strings actually)
const char* const allMonsters[NB_MONSTER_EQUIPE] PROGMEM = {
  strMecheBizard,
  strFlottille,
  strChampiFort,
  strTerraBaffle,
};

#endif 

