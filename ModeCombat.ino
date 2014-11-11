
bool isCaptureMode=false;
bool isCatch=false;


uint8_t CombatMonste()
{
  AnimationDebutCombat();
  //TODO attention si pas sauvage peut etre pas de monstre !
  CombatArriverMonsterSauvage();
  ctx->Joueur.UnSelectMonster();
  do
  {
    CombatChoiceMonsterAdversaire();
    CombatChoiceMonster();
    CombatChoiceAttackAdversaire();
    CombatChoiceAttack();
  }
  while(ResolutionCombat());
  CombatFinCombat();

  if(!ctx->Joueur.HaveMonsterOk())
  {
    //Fin de partie! 
    return 99;
  }

  return 0;
}

void AnimationDebutCombat()
{
  int nbFrameAnnim = 20;
  bool isWhite = false;
  while(true)
  {
    if(gb.update())
    {
      if(nbFrameAnnim >0)
      {
        nbFrameAnnim--;

        if(nbFrameAnnim%3 ==0)
        {
          isWhite = !isWhite;
        }
      }
      else
      {
        break;
      }

      //#define LCDWIDTH 48
      //#define LCDHEIGHT 84

      for(uint8_t i=0;i<15;i++)
      {
        for(uint8_t y=0;y<15;y++)
        {
          if(isWhite)
          {
            if(y%2 == 0)
            {
              if(i%2 == 0)
              {
                gb.display.fillRect(i*4, y*7, 4, 7);
                gb.display.setColor(BLACK);
              }
            }
            else
            {
              if(i%2 != 0)
              {
                gb.display.fillRect(i*4, y*7, 4, 7);
                gb.display.setColor(BLACK);
              }
            }

          }
          else
          {

            if(y%2 == 0)
            {
              if(i%2 != 0)
              {
                gb.display.fillRect(i*4, y*7, 4, 7);
                gb.display.setColor(BLACK);
              }
            }
            else
            {
              if(i%2 == 0)
              {
                gb.display.fillRect(i*4, y*7, 4, 7);
                gb.display.setColor(BLACK);
              }
            }
          }
        }
      }
    }
  }
}

void CombatArriverMonsterSauvage()
{

  isCatch=false;
  uint8_t nbFrame = 60;
  if(ctx->Adversaire.IsMonster)
  {
    gb.popup(F("Un Futuromon attaque!"),60);
  }
  else 
  {
    gb.popup(F("Un defi dresseur !"),60);
  }
  while(true)
  {
    if(gb.update())
    {
      uint8_t xpos = 60;
      if(nbFrame>30)
      {
        xpos = 30+ nbFrame;
      }
      else
      {
        if(gb.buttons.pressed(BTN_A) || nbFrame <= 0)
        {
          break;
        }
      }
      nbFrame--;
      gb.display.drawBitmap(xpos, 0, GetSpriteMonsterByNumero(ctx->Adversaire.GetSelectedMonster()->Numero, true));
    }
  }
}

void CombatChoiceMonster()
{
  if(!ctx->Joueur.IsSelectedMonster())
  {
    do
    {
      uint8_t choix = gb.menu(allMonsters, NB_MONSTER_EQUIPE);
      ctx->Joueur.SelectMonster(choix);
    }
    while(ctx->Joueur.GetSelectedMonster()->Vie <= 0);

    uint8_t nbFrame = 60;
    gb.popup(F("En avant!"),60);
    while(true)
    {
      if(gb.update())
      {
        uint8_t xpos = 2;
        if(nbFrame>30)
        {
          xpos = 28 - nbFrame;
        }
        else
        {
          if(gb.buttons.pressed(BTN_A) || nbFrame <= 0)
          {
            break;
          }
        }
        nbFrame--;
        gb.display.drawBitmap(60, 0, GetSpriteMonsterByNumero(ctx->Adversaire.GetSelectedMonster()->Numero, true));//allSpriteMonstersFront[ctx->Adversaire.GetSelectedMonster()->Numero]);
        gb.display.drawBitmap(xpos, 24, GetSpriteMonsterByNumero(ctx->Joueur.GetSelectedMonster()->Numero, false));

        drawHud();
      }
    }
  }

}
void CombatChoiceMonsterAdversaire()
{
  if(!ctx->Adversaire.IsSelectedMonster())
  {
    byte cpt=0;
    do
    {
      ctx->Adversaire.SelectMonster(cpt);
      cpt++;
    }
    while(!ctx->Adversaire.GetSelectedMonster()->IsAlive() && cpt<ctx->Adversaire.NbMonstre());
    //gb.popup(F("Choix P2 OK"),20);
  }
  if(!monsterVue[ctx->Adversaire.GetSelectedMonster()->Numero])
  {  
    monsterVue[ctx->Adversaire.GetSelectedMonster()->Numero] = true;
    nbVue++;
  }
}


void CombatChoiceAttack()
{
  uint8_t selectedAttak =  gb.menu(GetAttakByPatternNumero(ctx->Joueur.GetSelectedMonster()->GetPatternAttaque()), NB_ATTAQUE_BY_MONSTER);
  isCaptureMode = false;
  switch(selectedAttak)
  {
  case 3 :
    {
      //isAttack = false;
      ctx->Joueur.UnSelectMonster();
      break;
    }
  case 4 :
    {
      //Attrape le monstre
      //ctx->Joueur.UnSelectMonster();
      isCaptureMode = true;
      //pas de breack car on execute l'animation
    }
  default :
    {
      ctx->Joueur.GetSelectedMonster()->SetSelectedAttack(selectedAttak);
      ctx->Joueur.GetSelectedMonster()->SetSelectedAttack(selectedAttak);
    }
  };

}

void CombatChoiceAttackAdversaire()
{
  ctx->Adversaire.GetSelectedMonster()->SetSelectedAttack(random(0,NB_MAX_NUM_ATTAQUE_BY_IA));

}

void  CombatFinCombat()
{

  int cptFrame = 35;
  if(ctx->Joueur.HaveMonsterOk())
    gb.popup(F("Youpy!"),cptFrame);
  else 
    gb.popup(F("..."),cptFrame);
  while(cptFrame>0)
  {
    if(gb.update())
    {
      cptFrame--;
    }
  }
  ctx->Joueur.UnSelectMonster();
  ctx->Adversaire.UnSelectMonster();
  ctx->Adversaire.ClearMonster();
}


///// RESOLUTION du combat
bool ResolutionCombat()
{
  if(ctx->Adversaire.IsSelectedMonster() && ctx->Joueur.IsSelectedMonster())
  {
    if(!isCaptureMode)
    {
      CombatResolutionOfAttack();
    }
    else 
    {
      CombatResolutionOfCatch();
    }

    CombatResolutionAttackAnnimation();

    if(!ctx->Adversaire.GetSelectedMonster()->IsAlive())
    {
      cptKill++;
    }
    if(isCatch && isCaptureMode)
    {
      DysplayEtatFuturomon(*ctx->Adversaire.GetSelectedMonster());
      ChoixAddMonsterTeam();
    }
    else if(!ctx->Adversaire.GetSelectedMonster()->IsAlive() && ctx->Joueur.GetSelectedMonster()->IsAlive())
    {
      ctx->Joueur.GetSelectedMonster()->Xp += 2  * ctx->Adversaire.GetSelectedMonster()->Niveau;
      if(ctx->Joueur.GetSelectedMonster()->Xp>ctx->Joueur.GetSelectedMonster()->NextNiveau)
      {
        LevelUpMonster(ctx->Joueur.GetSelectedMonster());
        DysplayEtatFuturomon(*ctx->Joueur.GetSelectedMonster());
      }

    }

    if(isCatch)
    {
      //on a attraper le futuromon fin du combat
      return false;
    }

    if(ctx->Joueur.HaveMonsterOk() && ctx->Adversaire.HaveMonsterOk())
    {
      if(!ctx->Adversaire.GetSelectedMonster()->IsAlive())
      {
        ctx->Adversaire.UnSelectMonster();
      }
      if(!ctx->Joueur.GetSelectedMonster()->IsAlive())
      {
        ctx->Joueur.UnSelectMonster();
      }

      return true;
    }

    return false;
  }
  return true;
}

void drawHud()
{
  gb.display.drawBitmap(2, 0, sprBarreViej2);
  gb.display.fillRect(3, 1,GetWidthBarreVie(ctx->Adversaire.GetSelectedMonster()->GetPourcentVieRestant() ,43), 6);
  gb.display.drawBitmap(39, 41, sprBarreViej1);
  uint8_t wdBarrevie = GetWidthBarreVie(ctx->Joueur.GetSelectedMonster()->GetPourcentVieRestant() ,43);
  gb.display.fillRect(40 + (43 - wdBarrevie), 41,wdBarrevie, 6);
}

bool isP1First = true;
bool isPNonInitiativeAlive = true;

void  CombatResolutionAttackAnnimation()
{
  if(isP1First)
  {
    Player1AnnimCombat();
    if(isPNonInitiativeAlive)
      Player2AnnimCombat();

  }
  else
  {
    Player2AnnimCombat();
    if(isPNonInitiativeAlive)
      Player1AnnimCombat();
  }
  if(!ctx->Adversaire.GetSelectedMonster()->IsAlive())
    Player2AnnimMortCombat();
  else if(!ctx->Joueur.GetSelectedMonster()->IsAlive())
    Player1AnnimMortCombat();

  //on deselectionne les attaques
  ctx->Joueur.GetSelectedMonster()->UnSelectedAttack();
  ctx->Adversaire.GetSelectedMonster()->UnSelectedAttack();
}

void decrementOldVie(Monster *m,int nbframe)
{
  m->OldVie  -= (m->OldVie - m->Vie) / nbframe;

  if(m->OldVie < m->Vie)
  {
    m->OldVie = m->Vie;
  }
}

void Player1AnnimCombat()
{
  uint8_t nbFrame = 45;
  
  while(true)//nbFrame>0)
  {
    if(gb.update())
    {
      drawHud();
      if(nbFrame<25 && nbFrame%4>1 && nbFrame>5 )
      {
        //clignotement apres attaque
      }
      else
      {
        gb.display.drawBitmap(60, 0, GetSpriteMonsterByNumero(ctx->Adversaire.GetSelectedMonster()->Numero, true));

      }
      gb.display.drawBitmap(2, 24, GetSpriteMonsterByNumero(ctx->Joueur.GetSelectedMonster()->Numero, false));

      ResolutionAttaqueAnimation(ctx->Joueur.GetSelectedMonster()->GetSelectedAttack(),ctx->Joueur.GetSelectedMonster()->GetPatternAttaque(),true,nbFrame);
      if(nbFrame <= 0)
      {
        break;
      }
      decrementOldVie(ctx->Adversaire.GetSelectedMonster(),nbFrame);
      nbFrame--;
    }
  }
}

void Player2AnnimCombat()
{
  uint8_t nbFrame = 45;
  while(true)//nbFrame>0)
  {
    if(gb.update())
    {

      drawHud();
      if(nbFrame<25 && nbFrame%4>1 && nbFrame>5 )
      {
        //clignotement apres attaque
      }
      else
      {
        gb.display.drawBitmap(2, 24, GetSpriteMonsterByNumero(ctx->Joueur.GetSelectedMonster()->Numero, false));

      }
      gb.display.drawBitmap(60, 0, GetSpriteMonsterByNumero(ctx->Adversaire.GetSelectedMonster()->Numero, true));

      ResolutionAttaqueAnimation(ctx->Adversaire.GetSelectedMonster()->GetSelectedAttack(),ctx->Adversaire.GetSelectedMonster()->GetPatternAttaque(),false,nbFrame);
      if(nbFrame <= 0)
      {
        break;
      }

      decrementOldVie(ctx->Joueur.GetSelectedMonster(),nbFrame);
      nbFrame--;
    }
  }
}


void Player1AnnimMortCombat()
{
  uint8_t nbFrame = 0;
  while(true)//nbFrame>0)
  {
    if(gb.update())
    {

      drawHud();

      gb.display.drawBitmap(60, 0, GetSpriteMonsterByNumero(ctx->Adversaire.GetSelectedMonster()->Numero, true));
      gb.display.drawBitmap(2, 24 + nbFrame, GetSpriteMonsterByNumero(ctx->Joueur.GetSelectedMonster()->Numero, false));
      if(nbFrame >= 40)
      {
        break;
      }
      nbFrame++;
    }
  }
}


void Player2AnnimMortCombat()
{
  uint8_t nbFrame = 0;
  while(true)//nbFrame>0)
  {
    if(gb.update())
    {

      drawHud();

      gb.display.drawBitmap(60, 0 - nbFrame, GetSpriteMonsterByNumero(ctx->Adversaire.GetSelectedMonster()->Numero, true));
      gb.display.drawBitmap(2, 24, GetSpriteMonsterByNumero(ctx->Joueur.GetSelectedMonster()->Numero, false));
      if(nbFrame >= 40)
      {
        break;
      }
      nbFrame++;
    }
  }
}

int8_t GetWidthBarreVie(uint8_t pourcentVie, uint8_t tailleMaxPx)
{
  return pourcentVie * tailleMaxPx / 100;
}

void CombatAttack(Monster *att, Monster *def)
{
  //TODO faire avec le choix des attaque !
  def->OldVie = def->Vie;
  int8_t dmg = (att->Force - def->Defence);
  if(HaveBonusAttak(att->GetSelectedAttack(),att->GetPatternAttaque(),def->Type))
  {
     dmg += TirrageDes(dmg);
     //gb.popup(F("Super efficace!"),40);
  }
  if(HaveBonusAttak(def->GetSelectedAttack(),def->GetPatternAttaque(),def->Type))
  {
     dmg = dmg / TirrageDes(dmg - dmg/2);
     //gb.popup(F("Pas efficace..."),40);
  }
  
  if(dmg<=0) dmg = 1;  
  def->Vie = def->Vie - dmg;
  if(def->Vie<0) def->Vie = 0;
}

void CombatResolutionOfAttack()
{
  int v1 = ctx->Joueur.GetSelectedMonster()->Vitesse + TirrageDes(ctx->Joueur.GetSelectedMonster()->Vitesse);
  int v2 = ctx->Adversaire.GetSelectedMonster()->Vitesse + TirrageDes(ctx->Adversaire.GetSelectedMonster()->Vitesse);

  Player *p1;
  Player *p2;
  //Initiative
  if(v1>v2)
  {
    p1 = &ctx->Joueur;
    p2 = &ctx->Adversaire;
    isP1First = true;
  }
  else
  {
    p2 = &ctx->Joueur;
    p1 = &ctx->Adversaire;
    isP1First = false;
  }

  CombatAttack(p1->GetSelectedMonster(),p2->GetSelectedMonster());
  if(p2->GetSelectedMonster()->IsAlive())
  {
    CombatAttack(p2->GetSelectedMonster(),p1->GetSelectedMonster());
    isPNonInitiativeAlive = true;
  }
  else
  {
    isPNonInitiativeAlive = false;
  }
}

uint8_t TirrageDes(uint8_t maximun)
{
  return random(1,maximun);
}



void CombatResolutionOfCatch()
{
  int v1 = ctx->Joueur.GetSelectedMonster()->Vitesse + TirrageDes(ctx->Joueur.GetSelectedMonster()->Vitesse);
  int v2 = ctx->Adversaire.GetSelectedMonster()->Vitesse + TirrageDes(ctx->Adversaire.GetSelectedMonster()->Vitesse);

  Player *p1;
  Player *p2;
  //Initiative
  p1 = &ctx->Joueur;
  p2 = &ctx->Adversaire;
  isP1First = true;

  //CombatAttack(p1->GetSelectedMonster(),p2->GetSelectedMonster());
  if(ctx->Adversaire.IsMonster == true && random(0,p2->GetSelectedMonster()->Vie) == 0)
  {
    isPNonInitiativeAlive = false;
    //il est attrape
    MonsterCatch[p2->GetSelectedMonster()->Numero] = true;
    isCatch = true;
    nbCatch++;
  }
  else
  {
    CombatAttack(p2->GetSelectedMonster(),p1->GetSelectedMonster());
    isPNonInitiativeAlive = true;
    //on ne l'a pas attrape
  }
}



///FIin resolution combat


