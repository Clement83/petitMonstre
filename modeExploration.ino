


  /*
const byte Fleure[] PROGMEM = {16,16,0x0,0x0,0x45,0x0,0x22,0x2,0x45,0x54,0x0,0x22,0x55,0x50,0x22,0x0,0x55,0xA,0x0,0xA4,0x14,0x4A,0x8,0xA0,0x14,0x0,0x1,0x4A,0x50,0x84,0x21,0x4A,0x70,0x0,};
const byte herbe[] PROGMEM = {16,16,0x0,0x0,0x40,0x12,0x41,0x12,0x41,0x12,0x59,0x12,0x11,0x0,0x11,0x4C,0x54,0x48,0x94,0x48,0x94,0x48,0x94,0x48,0x85,0x4A,0x85,0x42,0x85,0x42,0x85,0x2,0x81,0x0,};
const byte Roche[] PROGMEM = {16,16,0xF,0xFC,0x38,0x8C,0x61,0x46,0xC7,0x43,0x9C,0x65,0x90,0xAD,0x91,0x99,0x91,0xD1,0x95,0x61,0x96,0x25,0xC8,0xED,0xCC,0x9,0xC6,0xFB,0x62,0x6,0x38,0x4,0xF,0xFC,};
const byte terre[] PROGMEM = {16,16,0x0,0x0,0x42,0x0,0x0,0x22,0x12,0x0,0x0,0x0,0x1,0x24,0x20,0x0,0x0,0x0,0x0,0x40,0x8,0x8,0x40,0x0,0x1,0x0,0x0,0x0,0x0,0x40,0x10,0x4,0x0,0x0,};*/

const byte Fleure[] PROGMEM = {8,8,0x5,0x2,0x5,0x0,0xA0,0x4A,0xA4,0xA,};
const byte herbe[] PROGMEM = {8,8,0x0,0x4,0x44,0x55,0x55,0x55,0x55,0x55,};
const byte Roche[] PROGMEM = {8,8,0x3C,0x26,0xDB,0xA5,0xAD,0x93,0x44,0x3C,};
const byte terre[] PROGMEM = {8,8,0x0,0x50,0x4,0x40,0x2,0x10,0x2,0x40,};
const byte Perso[] PROGMEM = {8,8,0x7E,0x54,0x7C,0x10,0x7C,0x10,0x28,0x44,};


#define NUM_SPRITES 4
const byte* sprites[NUM_SPRITES] = {
  Fleure, herbe,  terre,Roche};


/*
The world is stored in bi-dimensional array of bytes.
This array is stored in RAM so it can be too large.
For large maps see the PROGMEM tile map examples.
Each tile of the world is stored in a byte. A byte is made of 8 bits.
The bits B000000XX define the sprite's ID (so there is 4 different sprites max)
The bits B0000XX00 define the sprite rotation (4 values of rotation)
You can notice that 4 bits are unused for each byte (these one: BXXXX0000).
This means that we could save even more memory by storing 2 tiles per byte,
but that would make accessing the the tiles coordinates more complicated.
It will be the subject of another example.
We could also store more than 4 different sprites.
*/
#define WORLD_W 16
#define WORLD_H 16
byte world[WORLD_W][WORLD_H];

byte getSpriteID(byte x, byte y){
  return world[x][y] & B00000011;
}
byte getRotation(byte x, byte y){
  return (world[x][y] >> 2)  & B00000011;
}
void setTile(byte x, byte y, byte spriteID, byte rotation){
  world[x][y] = (rotation << 2) + spriteID;
}

// cursor
int cursor_x, cursor_y;
int camera_x, camera_y;



uint8_t ExplorationUpdate(){

    if(updateCursor())
    {
      drawWorld();
      drawCursor();
      return 0;
    }
    else 
    {
      Monster *m5 = new Monster();
     m5->Numero = random(0,4);
     m5->Force = random(1,4);
     m5->ForceMax = m5->Force;
     m5->Vie = random(10,20);
     m5->VieMax = m5->Vie;
     m5->Vitesse = random(1,5);
     m5->VitesseMax = m5->Vitesse;
     m5->Defence = random(1,5);
     m5->DefenceMax = m5->Defence;
     ctx->Adversaire.AddMonster(*m5);
     ctx->Adversaire.SelectMonster(0);
        //New monster !
      return 1;
    }

}

void initGame(){
  //gb.titleScreen(F("DYNAMIC TILE MAP DEMO"));
  gb.pickRandomSeed(); //pick a different random seed each time for games to be different
  initWorld();
  cursor_x = 1;
  cursor_y = 1;
  //gb.popup(F("\25:change \26:rotate"),60);
}

void initWorld(){
  
  for(byte y = 0; y < WORLD_H; y++){
    setTile(0, y, 3, random(0,4)); 
    setTile(WORLD_W-1, y, 3, random(0,4)); 
  }
    for(byte x = 0; x < WORLD_W; x++){
      setTile(x, 0, 3, random(0,4));
      setTile(x, WORLD_H-1, 3, random(0,4)); 
    }
  

  for(byte y = 1; y < WORLD_H-1; y++){
    for(byte x = 1; x < WORLD_W-1; x++){
      byte spId = random(0,4);
      if(spId == 1)
      {
        //Haute herbe
        setTile(x, y, spId, 0);
      }
      else
      { 
        setTile(x, y, spId, random(0,4));
      }
    }
  }
}

void drawWorld(){
  for(byte y = 0; y < WORLD_H; y++){
    for(byte x = 0; x < WORLD_W; x++){
      byte spriteID = getSpriteID(x,y);
      byte rotation = getRotation(x,y);
      //coordinates on the screen depending on the camera position
      int x_screen = x*8 - camera_x;
      int y_screen = y*8 - camera_y;
      if(x_screen < -8 || x_screen > LCDWIDTH || y_screen < -8 || y_screen > LCDHEIGHT){
        continue; // don't draw sprites which are out of the screen
      }
      
      int x_screenP = cursor_x*8 - camera_x;
      int y_screenP = cursor_y*8 - camera_y;
      if(x_screenP == x_screen && y_screenP == y_screen)
      {
        continue;//posjoueur
      }
      gb.display.drawBitmap(x_screen, y_screen, sprites[spriteID], rotation, 0);
    }
  }
}

bool updateCursor(){
  
  
  int last_cursor_x = cursor_x;
  int last_cursor_y = cursor_y;
  if(gb.buttons.repeat(BTN_RIGHT, 4)){
    cursor_x = wrap(cursor_x+1, WORLD_W);
    //gb.sound.playTick();
  }
  if(gb.buttons.repeat(BTN_LEFT, 4)){
    cursor_x = wrap(cursor_x-1, WORLD_W);
    //gb.sound.playTick();
  }
  if(gb.buttons.repeat(BTN_DOWN, 4)){
    cursor_y = wrap(cursor_y+1, WORLD_H);
    //gb.sound.playTick();
  }
  if(gb.buttons.repeat(BTN_UP, 4)){
    cursor_y = wrap(cursor_y-1, WORLD_H);
    //gb.sound.playTick();
  }
  byte spriteID = getSpriteID(cursor_x,cursor_y);
  
  if(spriteID == 3)
  {
    //rocher deplacement impossible
    cursor_x= last_cursor_x;
    cursor_y = last_cursor_y;
    spriteID = getSpriteID(cursor_x,cursor_y);
  }
  
  if(spriteID == 1)
  {
    if(random(0,100)==0)
    {
      return false;
    }
  }
  
  //target position of the camera for the cursor to be centered
  int camera_x_target = cursor_x*8 - LCDWIDTH/2 + 8;
  int camera_y_target = cursor_y*8 - LCDHEIGHT/2 + 8;
  //apply the target coordinate to the current coordinates with some smoothing
  camera_x = (camera_x*3 + camera_x_target)/4;
  camera_y = (camera_y*3 + camera_y_target)/4;
  return true;
}

void drawCursor(){
  int x_screen = cursor_x*8 - camera_x;
  int y_screen = cursor_y*8 - camera_y;
  if(!(x_screen < -16 || x_screen > LCDWIDTH || y_screen < -16 || y_screen > LCDHEIGHT)){
    //gb.display.drawRect(x_screen, y_screen, 8, 8);
//    gb.display.setColor(INVERT);
    gb.display.drawBitmap(x_screen, y_screen, Perso, 0, 0);
    //gb.display.setColor(BLACK);
    
  }
  
  gb.display.print(F("X"));
  gb.display.print(cursor_x);
  gb.display.print(F(" Y"));
  gb.display.print(cursor_y);
  
  byte spriteID = getSpriteID(cursor_x, cursor_y);
  gb.display.print(F(" I"));
  gb.display.print(spriteID);
  byte rotation = getRotation(cursor_x, cursor_y);
  gb.display.print(F(" R"));
  gb.display.print(rotation);
}

