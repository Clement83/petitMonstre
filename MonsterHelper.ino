
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

 byte TypeFeux[] = { 5};//0
 byte TypeEau []  = { 4,6};//1
 byte Typeterre[]  = { 0};//2
 byte TypePlante[]  = { 8,1};//3
 byte TypeElec[]  = {3,2 };//4
 byte Typepsy[]  = {7,9};//5
 
 
void getnumMonsterByNumZone(uint8_t numZone, Monster *m)
{
  uint8_t rdm2 = random(0,2);
  switch(numZone)
  {
    case 0 :
      m->Numero = Typepsy[rdm2];
     m->Type = 5;
   break;
    case 1 :
    if(rdm2==0)
    {
      m->Numero =  TypeElec[rdm2];
     m->Type = 4;
    }
    else 
    {
      m->Numero =   TypeFeux[0];
     m->Type = 0;
    }
   break;
    case 2 :
    if(rdm2==0)
    {
      m->Numero =   Typeterre[0];
     m->Type = 2;
    }
    else 
    {
      m->Numero =   TypeEau[0];
     m->Type = 1;
    }
   break;
    case 3 :
    if(rdm2==0)
    {
      m->Numero =   Typeterre[0];
     m->Type = 2;
    }
    else 
    {
      m->Numero =   TypePlante[rdm2];
     m->Type = 3;
    }
   break;
    case 4 :
    if(rdm2==0)
    {
      m->Numero =   TypeEau[0];
     m->Type = 1;
    }
    else 
    {
      m->Numero =   TypeFeux[0];
     m->Type = 0;
    }
   break; 
    case 5 :
      m->Numero =   TypeElec[rdm2];
     m->Type = 4;
   break;
    
  }
}

void GenerateMonsterByLvlAndNumZone(Monster *monsterAgenerer, uint8_t lvl, uint8_t numeroZone)
{
    if(lvl<2)lvl = 2;
    uint8_t rdmAdd = 2*lvl+random(0,10);
    monsterAgenerer->Force = rdmAdd;
    monsterAgenerer->Vie =rdmAdd;
    monsterAgenerer->VieMax = rdmAdd;
    monsterAgenerer->OldVie = rdmAdd;
    monsterAgenerer->Vitesse = rdmAdd;
    monsterAgenerer->Defence = rdmAdd;
    monsterAgenerer->Niveau = lvl;
    monsterAgenerer->NextNiveau = (lvl*lvl)/2;
    monsterAgenerer->Xp = 0;
    
    getnumMonsterByNumZone(numeroZone,monsterAgenerer);
    monsterAgenerer->SetPatternAttaque(monsterAgenerer->Type);
}

void GenerateStartMonster(Monster *monsterAgenerer)
{
    monsterAgenerer->Numero = 0;
    monsterAgenerer->Force = 19;
    monsterAgenerer->Vie = 17;
    monsterAgenerer->VieMax = monsterAgenerer->Vie;
    monsterAgenerer->OldVie = monsterAgenerer->Vie;
    monsterAgenerer->Vitesse = 18;
    monsterAgenerer->Defence = 20;
    monsterAgenerer->Niveau = 5;
    monsterAgenerer->NextNiveau = 12;
    monsterAgenerer->Xp = 0;
  
    monsterAgenerer->SetPatternAttaque(2);
    monsterAgenerer->Type = 2;  
}

void LevelUpMonster(Monster *monsterAgenerer)
{    byte rdm = random(1,3);
    monsterAgenerer->Force += rdm;
    monsterAgenerer->VieMax += rdm;
    monsterAgenerer->Vie = monsterAgenerer->VieMax;
    monsterAgenerer->OldVie = monsterAgenerer->VieMax;
    monsterAgenerer->Vitesse += rdm;
    monsterAgenerer->Defence += rdm;
    monsterAgenerer->Niveau++;
    monsterAgenerer->Xp = monsterAgenerer->Xp - monsterAgenerer->NextNiveau;
    monsterAgenerer->NextNiveau = (monsterAgenerer->Niveau*monsterAgenerer->Niveau)/2;
}


void AddMonster(Player *p, Monster m, uint8_t pos)
{
  
  Monster *monsterAgenerer = ctx->Joueur.GetMonster(pos);
  
    monsterAgenerer->Numero = m.Numero;
    monsterAgenerer->Force = m.Force;
    monsterAgenerer->Vie = m.VieMax;
    monsterAgenerer->VieMax = m.VieMax;
    monsterAgenerer->OldVie = m.VieMax;
    monsterAgenerer->Vitesse = m.Vitesse;
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
