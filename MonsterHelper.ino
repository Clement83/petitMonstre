
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
}

void LevelUpMonster(Monster *monsterAgenerer)
{
  GenerateMonsterByLvl(monsterAgenerer,monsterAgenerer->Niveau+1,monsterAgenerer->Numero);
}
