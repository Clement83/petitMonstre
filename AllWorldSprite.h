#if !defined (AllWorldSprite_H)
#define AllWorldSprite_H

#define NUM_SPRITES 8
const byte Fleure[] PROGMEM = {8,8,0x5,0x2,0x5,0x0,0xA0,0x4A,0xA4,0xA,};
const byte herbe[] PROGMEM = {8,8,0x0,0x4,0x44,0x55,0x55,0x55,0x55,0x55,};
const byte Perso[] PROGMEM = {8,8,0x7E,0x54,0x7C,0x10,0x7C,0x10,0x28,0x44,};
const byte Roche[] PROGMEM = {8,8,0x3C,0x26,0xDB,0xA5,0xAD,0x93,0x44,0x3C,};
const byte terre[] PROGMEM = {8,8,0x0,0x50,0x4,0x40,0x2,0x10,0x2,0x40,};


/*
const byte* sprites[NUM_SPRITES] = {
  Fleure, herbe, Roche, terre};*/
const byte Block[] PROGMEM = {8,8,0xBD,0x66,0xE7,0x99,0x99,0xE7,0x66,0xBD,};
const byte Entree[] PROGMEM = {8,8,0x8,0x48,0x4A,0x4A,0x4A,0x4A,0xA,0x8,};
const byte Sol1[] PROGMEM = {8,8,0x0,0x24,0x42,0x8,0x10,0x42,0x24,0x0,};
const byte Sol2[] PROGMEM = {8,8,0x0,0x42,0x0,0x18,0x18,0x0,0x42,0x0,};

const byte* sprites[NUM_SPRITES] = {
  Sol1, Sol2, Entree, Block,Fleure,terre,herbe,Roche};

#endif 
