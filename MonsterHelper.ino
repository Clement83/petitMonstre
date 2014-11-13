
const char strOui[] PROGMEM = "Yes";
const char strNon[] PROGMEM = "No";


//Put all the different items together in a menu (an array of strings actually)
const char* const OuiNonMenu[2] PROGMEM = {
  strOui,
  strNon,
};




/*
DARK = 0
FUTUR = 1
NEW = 2
EXT = 3
Space = 4
ELEC = 5
*/

 byte TypeFeux[] = { 0,19,20,6};//0
 byte TypeEau []  = { 8,1,15,17};//1
 byte Typeterre[]  = { 4,7,11,12,24};//2
 byte TypePlante[]  = { 2,3,13,23,26};//3
 byte TypeElec[]  = { 5,10,16,18,21};//4
 byte Typepsy[]  = { 9,14,22,25};//5
void getnumMonsterByNumZone(uint8_t numZone, Monster *m)
{
  uint8_t rdm2 = random(0,2);
  uint8_t rdm4 = random(0,4);
  uint8_t rdm5 = random(0,5);
  switch(numZone)
  {
    case 0 :
      m->Numero = Typepsy[rdm4];
     m->Type = 5;
   break;
    case 1 :
    if(rdm2==0)
    {
      m->Numero =  TypeElec[rdm5];
     m->Type = 4;
    }
    else 
    {
      m->Numero =   TypeFeux[rdm4];
     m->Type = 0;
    }
   break;
    case 2 :
    if(rdm2==0)
    {
      m->Numero =   Typeterre[rdm5];
     m->Type = 2;
    }
    else 
    {
      m->Numero =   TypeEau[rdm4];
     m->Type = 1;
    }
   break;
    case 3 :
    if(rdm2==0)
    {
      m->Numero =   Typeterre[rdm5];
     m->Type = 2;
    }
    else 
    {
      m->Numero =   TypePlante[rdm5];
     m->Type = 3;
    }
   break;
    case 4 :
    if(rdm2==0)
    {
      m->Numero =   TypeEau[rdm4];
     m->Type = 1;
    }
    else 
    {
      m->Numero =   TypeFeux[rdm4];
     m->Type = 0;
    }
   break; 
    case 5 :
      m->Numero =   TypeElec[rdm5];
     m->Type = 4;
   break;
    
  }
}

void GenerateMonsterByLvlAndNumZone(Monster *monsterAgenerer, uint8_t lvl, uint8_t numeroZone)
{
    if(lvl<2)lvl = 2;
    uint8_t rdmAdd = 2*lvl+random(0,10);
   // monsterAgenerer->Numero = numero;
    monsterAgenerer->Force = rdmAdd;
    //monsterAgenerer->ForceMax = monsterAgenerer->Force;
    monsterAgenerer->Vie =rdmAdd;// 2*lvl+random(0,10);
    monsterAgenerer->VieMax = rdmAdd;//monsterAgenerer->Vie;
    monsterAgenerer->OldVie = rdmAdd;//monsterAgenerer->Vie;
    monsterAgenerer->Vitesse = rdmAdd;//2*lvl+random(0,10);
   // monsterAgenerer->VitesseMax = monsterAgenerer->Vitesse;
    monsterAgenerer->Defence = rdmAdd;//2*lvl+random(0,10);
    //monsterAgenerer->DefenceMax = monsterAgenerer->Defence;
    monsterAgenerer->Niveau = lvl;
    monsterAgenerer->NextNiveau = (lvl*lvl)/2;
    monsterAgenerer->Xp = 0;
    
    getnumMonsterByNumZone(numeroZone,monsterAgenerer);
    monsterAgenerer->SetPatternAttaque(monsterAgenerer->Type);
}

void GenerateStartMonster(Monster *monsterAgenerer)
{
    monsterAgenerer->Numero = 0;
    monsterAgenerer->Force = 15;
    //monsterAgenerer->ForceMax = monsterAgenerer->Force;
    monsterAgenerer->Vie = 17;
    monsterAgenerer->VieMax = monsterAgenerer->Vie;
    monsterAgenerer->OldVie = monsterAgenerer->Vie;
    monsterAgenerer->Vitesse = 17;
    //monsterAgenerer->VitesseMax = monsterAgenerer->Vitesse;
    monsterAgenerer->Defence = 20;
    //monsterAgenerer->DefenceMax = monsterAgenerer->Defence;
    monsterAgenerer->Niveau = 5;
    monsterAgenerer->NextNiveau = (5*5)/2;
    monsterAgenerer->Xp = 0;
  
    monsterAgenerer->SetPatternAttaque(0);
    monsterAgenerer->Type = 0;  
}

void LevelUpMonster(Monster *monsterAgenerer)
{    
    //monsterAgenerer->ForceMax += random(1,5) ; 
    monsterAgenerer->Force += 2;//random(1,5) ; //monsterAgenerer->ForceMax;
    monsterAgenerer->VieMax += 2;//random(1,5);
    monsterAgenerer->Vie = monsterAgenerer->VieMax;
    monsterAgenerer->OldVie = monsterAgenerer->VieMax;
    //monsterAgenerer->VitesseMax+= random(1,5);
    monsterAgenerer->Vitesse += 2;//random(1,5);//monsterAgenerer->VitesseMax;
    //monsterAgenerer->DefenceMax += random(1,5);
    monsterAgenerer->Defence += 2;//random(1,5);//monsterAgenerer->DefenceMax;
    monsterAgenerer->Niveau++;
    monsterAgenerer->Xp = monsterAgenerer->Xp - monsterAgenerer->NextNiveau;
    monsterAgenerer->NextNiveau = (monsterAgenerer->Niveau*monsterAgenerer->Niveau)/2;
}


void AddMonster(Player *p, Monster m, uint8_t pos)
{
  
  Monster *monsterAgenerer = ctx->Joueur.GetMonster(pos);
  
    monsterAgenerer->Numero = m.Numero;
    monsterAgenerer->Force = m.Force;
    //monsterAgenerer->ForceMax = m.ForceMax;
    monsterAgenerer->Vie = m.VieMax;
    monsterAgenerer->VieMax = m.VieMax;
    monsterAgenerer->OldVie = m.VieMax;
    monsterAgenerer->Vitesse = m.Vitesse;
    //monsterAgenerer->VitesseMax = m.VitesseMax;
    //monsterAgenerer->Defence = m.Defence;
    //monsterAgenerer->DefenceMax = m.DefenceMax;
    monsterAgenerer->Niveau = m.NextNiveau;
    monsterAgenerer->NextNiveau = m.NextNiveau;
    monsterAgenerer->Xp = m.Xp;
    monsterAgenerer->Type = m.Type;
    monsterAgenerer->SetPatternAttaque(m.GetPatternAttaque());
}

void ChoixAddMonsterTeam()
{
    gb.popup(F("Add to team?"),40);
    switch(gb.menu(OuiNonMenu, 2))
    {
      case 0:
      if(ctx->Joueur.IsFull())
      {
          gb.popup(F("Switch"),40);
          
         AddMonster(&ctx->Joueur,*ctx->Adversaire.GetSelectedMonster(), gb.menu(allMonsters, NB_MONSTER_EQUIPE));
      }
      else 
      {
        Monster mCatch = *ctx->Adversaire.GetSelectedMonster();
        ctx->Joueur.AddMonster(0,0,0,0,0,0,0,0); 
        AddMonster(&ctx->Joueur, *ctx->Adversaire.GetSelectedMonster(), (ctx->Joueur.NbMonstre()-1));
      }
      
      break;
    }
}
