
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

  uint8_t nbFrame = 60;
  gb.popup(F("Un spacemon attaque!"),60);
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
      uint8_t choix = gb.menu(allMonsters, 4);
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
  ctx->Adversaire.SelectMonster(0);
}

void CombatChoiceAttack()
{
  uint8_t selectedAttak =  gb.menu(GetAttakByNumero(ctx->Joueur.GetSelectedMonster()->Numero), 4);
  switch(selectedAttak)
  {
  case 3 :
    {
      //isAttack = false;
      ctx->Joueur.UnSelectMonster();
      break;
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
  ctx->Adversaire.GetSelectedMonster()->SetSelectedAttack(0);

}

void  CombatFinCombat()
{

  int cptFrame = 35;
  if(ctx->Joueur.HaveMonsterOk())
    gb.popup(F("C'est gagne!"),cptFrame);
  else 
    gb.popup(F("Perdu..."),cptFrame);
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
    CombatResolutionOfAttack();
    CombatResolutionAttackAnnimation();
    if(!ctx->Adversaire.HaveMonsterOk())
    {
      cptKill++;
    }
    if(ctx->Adversaire.GetSelectedMonster()->Vie <= 0 && ctx->Joueur.GetSelectedMonster()->Vie>0)
    {
      /*
    unsigned int NextNiveau;
    unsigned int Xp
    */
      ctx->Joueur.GetSelectedMonster()->Xp += 2  * ctx->Adversaire.GetSelectedMonster()->Niveau;
      if(ctx->Joueur.GetSelectedMonster()->Xp>ctx->Joueur.GetSelectedMonster()->NextNiveau)
        LevelUpMonster(ctx->Joueur.GetSelectedMonster());
    }

    if(ctx->Joueur.HaveMonsterOk() && ctx->Adversaire.HaveMonsterOk())
    {
      if(ctx->Adversaire.GetSelectedMonster()->Vie <= 0)
      {
        ctx->Adversaire.UnSelectMonster();
      }
      if(ctx->Joueur.GetSelectedMonster()->Vie <= 0)
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
  gb.display.drawBitmap(39, 32, sprBarreViej1);
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

      if(nbFrame>30)
      {
        uint8_t nbframe1 =  45 - nbFrame;
        gb.display.setColor(INVERT);
        gb.display.drawBitmap(58 + nbframe1,  10 - nbframe1,attaqueGriffe );
        gb.display.setColor(BLACK);
      }
      else
      {

        if(nbFrame <= 0)
        {
          break;
        }
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

      if(nbFrame>30)
      {
        uint8_t nbframe1 =  45 - nbFrame;
        gb.display.setColor(INVERT);
        gb.display.drawBitmap(30 - nbframe1,  18 + nbframe1,attaqueGriffe );
        gb.display.setColor(BLACK);
      }
      else
      {
        if(nbFrame <= 0)
        {
          break;
        }
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
  def->Vie = def->Vie - att->Force;
  if(def->Vie<0) def->Vie = 0;
}
void CombatResolutionOfAttack()
{
  //TODO uniquement pour test

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


///FIin resolution combat

