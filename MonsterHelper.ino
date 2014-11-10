
const char strOui[] PROGMEM = "Oui";
const char strNon[] PROGMEM = "Non";


//Put all the different items together in a menu (an array of strings actually)
const char* const OuiNonMenu[2] PROGMEM = {
  strOui,
  strNon,
};



void GenerateMonsterByLvl(Monster *monsterAgenerer, uint8_t lvl, uint8_t numero)
{
    if(lvl<2)lvl = 2;
    monsterAgenerer->Numero = numero;
    monsterAgenerer->Force = 2*lvl+random(0,10);
    monsterAgenerer->ForceMax = monsterAgenerer->Force;
    monsterAgenerer->Vie = 2*lvl+random(0,10);
    monsterAgenerer->VieMax = monsterAgenerer->Vie;
    monsterAgenerer->OldVie = monsterAgenerer->Vie;
    monsterAgenerer->Vitesse = 2*lvl+random(0,10);
    monsterAgenerer->VitesseMax = monsterAgenerer->Vitesse;
    monsterAgenerer->Defence = 2*lvl+random(0,10);
    monsterAgenerer->DefenceMax = monsterAgenerer->Defence;
    monsterAgenerer->Niveau = lvl;
    monsterAgenerer->NextNiveau = (lvl*lvl)/2;
    monsterAgenerer->Xp = 0;
    
    if(numero<4)
    {
      monsterAgenerer->SetPatternAttaque(numero);
    }
    else
    {
      monsterAgenerer->SetPatternAttaque(numero%5);
    }
}

void LevelUpMonster(Monster *monsterAgenerer)
{
  GenerateMonsterByLvl(monsterAgenerer,monsterAgenerer->Niveau+1,monsterAgenerer->Numero);
}


void AddMonster(Player *p, Monster m, uint8_t pos)
{
  
  Monster *monsterAgenerer = ctx->Joueur.GetMonster(pos);
  
    monsterAgenerer->Numero = m.Numero;
    monsterAgenerer->Force = m.ForceMax;
    monsterAgenerer->ForceMax = m.ForceMax;
    monsterAgenerer->Vie = m.VieMax;
    monsterAgenerer->VieMax = m.VieMax;
    monsterAgenerer->OldVie = m.VieMax;
    monsterAgenerer->Vitesse = m.VitesseMax;
    monsterAgenerer->VitesseMax = m.VitesseMax;
    monsterAgenerer->Defence = m.DefenceMax;
    monsterAgenerer->DefenceMax = m.DefenceMax;
    monsterAgenerer->Niveau = m.NextNiveau;
    monsterAgenerer->NextNiveau = m.NextNiveau;
    monsterAgenerer->Xp = m.Xp;
}

void ChoixAddMonsterTeam()
{
    gb.popup(F("Ajout du futuromon?"),40);
    switch(gb.menu(OuiNonMenu, 2))
    {
      case 0:
      if(ctx->Joueur.IsFull())
      {
          gb.popup(F("Quel place?"),40);
          
         AddMonster(&ctx->Joueur,*ctx->Adversaire.GetSelectedMonster(), gb.menu(allMonsters, NB_MONSTER_EQUIPE));
      }
      else 
      {
        Monster mCatch = *ctx->Adversaire.GetSelectedMonster();
        ctx->Joueur.AddMonster(mCatch.Numero, mCatch.VieMax,mCatch.VitesseMax,mCatch.ForceMax,mCatch.DefenceMax,mCatch.Niveau,mCatch.NextNiveau,mCatch.Xp); 
      }
      
      break;
    }
}
