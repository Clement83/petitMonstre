



#define WORLD_W 16
#define WORLD_H 16
byte world[WORLD_W][WORLD_H];

byte getSpriteID(byte x, byte y){
  return world[x][y] & B00111111;
}

byte getRotation(byte x, byte y){
  return (world[x][y] >> 6)  & B00000011;
}

void setTile(byte x, byte y, byte spriteID, byte rotation){
  world[x][y] = (rotation << 6) + spriteID;
}

// cursor
int cursor_x, cursor_y,cursor_x_T, cursor_y_T;
byte directionPerso;
bool isMove;
int NbChanceAppearMonster;

bool isDresseur=false;
uint8_t ExplorationUpdate(){

    if(updatePerso())
    {
      drawWorld();
      drawPerso();
      return 0;
    }
    else 
    {
      if(!isDresseur)
      {
        int numM = random(0,Nb_MONSTERS);
        /*if(!monsterVue[numM])
        {  
          monsterVue[numM] = true;
          nbVue++;
        }*/
       ctx->Adversaire.AddMonster(0,0,0,0,0,0,0,0);
       ctx->Adversaire.SelectMonster(0);
       (&ctx->Adversaire)->IsMonster = true;
        Monster *m = ctx->Adversaire.GetSelectedMonster();
        GenerateMonsterByLvlAndNumZone(m, random(cptArea/2,cptArea+cptArea/2), currentTheme);
          //New monster !
      }
      else 
      {
           (&ctx->Adversaire)->IsMonster = false;
        for(int i=0;i<4;i++)
        {
            int numM = random(0,Nb_MONSTERS);
           ctx->Adversaire.AddMonster(0,0,0,0,0,0,0,0);
            Monster *m = ctx->Adversaire.GetMonster(i);
        //    GenerateMonsterByLvl(m, random(cptArea/2,cptArea+cptArea/2), numM);
          GenerateMonsterByLvlAndNumZone(m, random(cptArea/2,cptArea+cptArea/2), currentTheme);
        }
       ctx->Adversaire.SelectMonster(0 );
      }
      return 1;
    }
}

void initGame(){
  //gb.titleScreen(F("DYNAMIC TILE MAP DEMO"));
  gb.pickRandomSeed(); //pick a different random seed each time for games to be different
  initWorld();
 cursor_x_T  = random(WORLD_W/4,WORLD_W/2);
  cursor_y_T = random(WORLD_H/4,WORLD_H/2);
  cursor_x = cursor_x_T*8;
    cursor_y = cursor_y_T*8;
  directionPerso = 0;//0bas , 1 droite , 2 haut , 3 gauche
      isMove = false;
      NbChanceAppearMonster = 500;
  //gb.popup(F("\25:change \26:rotate"),60);
}

void initWorld(){
  cptArea++;
  currentTheme  = random(0,NB_THEMES);
  byte add = currentTheme * 4;
  
  //Contour
  for(byte y = 0; y < WORLD_H; y++){
    setTile(0, y, 3+add, random(0,4)); 
    setTile(WORLD_W-1, y, 3+add, random(0,4)); 
  }
    for(byte x = 0; x < WORLD_W; x++){
      setTile(x, 0, 3+add, random(0,4));
      setTile(x, WORLD_H-1, 3+add, random(0,4)); 
    }
  //Choix du sol
   byte spId = random(0,2)+add;
  //on pose le sol
  for(byte y = 1; y < WORLD_H-1; y++){
    for(byte x = 1; x < WORLD_W-1; x++){
      if( y>1 && y<WORLD_H-2 && x>1 && x<WORLD_W-2 &&  random(0,5)==0)
      {
        //de temps a autre on pause un block
        setTile(x, y, 3+add, 0);
      }
      else 
      {
        setTile(x, y, spId, random(0,4));
      }
    }
  }
  //les sorties
  setTile(WORLD_W/2, 0, 2, 0);
  setTile(WORLD_W/2, WORLD_H-1, 2, 0);
  setTile(0, WORLD_H/2, 2, 1);
  setTile(WORLD_W-1, WORLD_H/2, 2, 1);
  GenerteAllBonus();
   initialiseNbChance();
}

void initialiseNbChance()
{
        NbChanceAppearMonster = random(50,500);
        // NbChanceAppearMonster -= cptArea* cptArea;
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
      
     // int x_screenP = cursor_x_T*8 - camera_x;
      //int y_screenP = cursor_y_T*8 - camera_y;
      /*if(x_screenP == x_screen && y_screenP == y_screen)
      {
        continue;//posjoueur
      }*/
      gb.display.drawBitmap(x_screen, y_screen, sprites[spriteID], rotation, 0);
    }
  }
   drawAllBonus();
  
    gb.display.setFont(font3x3);
        gb.display.print(F("Area:"));
    gb.display.print(cptArea);
        gb.display.print(F(".Kill:"));
        gb.display.print(cptKill);
        gb.display.print(F(".View:"));
        gb.display.print(nbVue);
    gb.display.setFont(font3x5);
    
    
}

bool updatePerso(){
  
  if(isMove)
  {
    if(cursor_x != cursor_x_T*8)
    {
      if(cursor_x_T*8 > cursor_x)
      {
        cursor_x++;
      }
      else 
      {
        cursor_x--;
      }
    }
    else if(cursor_y != cursor_y_T*8)
    {
      if(cursor_y_T*8 > cursor_y)
      {
        cursor_y++;
      }
      else 
      {
        cursor_y--;
      }
    }
    
    if(cursor_y == cursor_y_T*8 && cursor_x == cursor_x_T*8)
    {
      isMove = false;
    }
  }
  
  if(!isMove)
  {
    int last_cursor_x = cursor_x_T;
    int last_cursor_y = cursor_y_T;
    
    if(gb.buttons.repeat(BTN_RIGHT, 4)){
      cursor_x_T = wrap(cursor_x_T+1, WORLD_W);
      directionPerso = 1;
      //gb.sound.playTick();
    }
    if(gb.buttons.repeat(BTN_LEFT, 4)){
      cursor_x_T = wrap(cursor_x_T-1, WORLD_W);
          directionPerso = 3;
      //gb.sound.playTick();
    }
    if(gb.buttons.repeat(BTN_DOWN, 4)){
      cursor_y_T = wrap(cursor_y_T+1, WORLD_H);
          directionPerso = 0;
      //gb.sound.playTick();
    }
    if(gb.buttons.repeat(BTN_UP, 4)){
      cursor_y_T = wrap(cursor_y_T-1, WORLD_H);
          directionPerso = 2;
      //gb.sound.playTick();
    }
    byte spriteID = getSpriteID(cursor_x_T,cursor_y_T);
    
    if((spriteID+1) %4 == 0)
    {
      //rocher deplacement impossible
      cursor_x_T= last_cursor_x;
      cursor_y_T = last_cursor_y;
      spriteID = getSpriteID(cursor_x_T,cursor_y_T);
    }
    
    if(gb.buttons.pressed(BTN_A))
    {
     TestGetBonus(cursor_x_T,cursor_y_T);
    }
  
  
    if(last_cursor_x != cursor_x_T || last_cursor_y != cursor_y_T)
    {
      isMove = true;
      //si je suis en mouvement
      if((spriteID+2)%4 == 0)
      {
        initWorld();
        if(cursor_x_T == 0)
        {
          cursor_x_T =  WORLD_W- 1;
        }
        else if(cursor_x_T == WORLD_W-1)
        {
          cursor_x_T = 0;
        }
        else if(cursor_y_T == 0)
        {
          cursor_y_T = WORLD_H - 1;
        }
        else if(cursor_y_T == WORLD_H-1)
        {
          cursor_y_T = 0;
        }
        cursor_x= cursor_x_T*8;
        cursor_y= cursor_y_T*8;
      }
    }
  }
  //on peut en rencontrer partou !
  if(random(0,NbChanceAppearMonster)==0)
  {
    initialiseNbChance();
    isDresseur = false;
    return false;
  }
  else if(random(0,NbChanceAppearMonster*3)==0)
  {
    if(DresseurByTheme[currentTheme]<NB_DRESSEUR_THEME)
    {
      //Dresseur
      isDresseur = true;
      initialiseNbChance();
      DresseurByTheme[currentTheme]++;
      return false;
    }
  }
  else 
  {
    NbChanceAppearMonster--;
  }
  
  //target position of the camera for the cursor to be centered
  int camera_x_target = cursor_x - LCDWIDTH/2 + 8;
  int camera_y_target = cursor_y - LCDHEIGHT/2 + 8;
  //apply the target coordinate to the current coordinates with some smoothing
  camera_x = camera_x_target;//(camera_x*3 + camera_x_target)/4;
  camera_y = camera_y_target;//(camera_y*3 + camera_y_target)/4;
  return true;
}

void drawPerso(){
  int x_screen = cursor_x - camera_x;
  int y_screen = cursor_y - camera_y;
  if(!(x_screen < -16 || x_screen > LCDWIDTH || y_screen < -16 || y_screen > LCDHEIGHT)){
    //gb.display.drawRect(x_screen, y_screen, 8, 8);
//    gb.display.setColor(INVERT);

    byte index=directionPerso;
    if(isMove)
    {
     index =  index+directionPerso+4; //Ou 5
      
      int count = gb.frameCount;
      if(count%8 >3)
      {
        index++;
      }
    }
    gb.display.drawBitmap(x_screen, y_screen, spritesPerso[index], 0, 0);
    //gb.display.setColor(BLACK);
  }
}

