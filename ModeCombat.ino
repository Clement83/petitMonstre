
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
        }while(ctx->Joueur.GetSelectedMonster()->Vie <= 0);
      
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
         
          if(ctx->Joueur.HaveMonsterOk() && ctx->Adversaire.HaveMonsterOk())
          {
             if(ctx->Adversaire.GetSelectedMonster()->Vie == 0)
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
  
  void  CombatResolutionAttackAnnimation()
  {
      uint8_t nbFrame = 90;
    while(true)//nbFrame>0)
    {
      if(gb.update())
      {
          
       drawHud();
        if(nbFrame<50 && nbFrame%3==0 && nbFrame>30 )
        {
          //clignotement apres attaque
        }
        else 
        {
          gb.display.drawBitmap(60, 0, GetSpriteMonsterByNumero(ctx->Adversaire.GetSelectedMonster()->Numero, true));
  
          gb.display.drawBitmap(2, 24, GetSpriteMonsterByNumero(ctx->Joueur.GetSelectedMonster()->Numero, false));
        }
        
        if(nbFrame>75)
         {
           uint8_t nbframe1 = (nbFrame - 75)*2;
           gb.display.setColor(INVERT);
           gb.display.drawBitmap(32 - nbframe1,  nbframe1,attaqueGriffe );
           gb.display.setColor(BLACK);

         }
         else if(nbFrame>60)
         {
           uint8_t nbframe1 = (nbFrame - 60)*2;
           gb.display.setColor(INVERT);
           gb.display.drawBitmap(40 + (30 -nbframe1),  nbframe1,attaqueGriffe );
           gb.display.setColor(BLACK);
         }
         else 
         {
        
            if(gb.buttons.pressed(BTN_A) || nbFrame <= 0)
            {
              break;
            }
         }
         nbFrame--;
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
      def->Vie = def->Vie - att->Force; 
      if(def->Vie<0) def->Vie = 0;
  }
  void CombatResolutionOfAttack()
  {
    //TODO uniquement pour test
    CombatAttack(ctx->Joueur.GetSelectedMonster(),ctx->Adversaire.GetSelectedMonster());
    CombatAttack(ctx->Adversaire.GetSelectedMonster(),ctx->Joueur.GetSelectedMonster());
    //ctx->Adversaire.GetSelectedMonster()->Vie = 2;
    /*if(ctx->Joueur.GetSelectedMonster().Vitesse > ctx->Adversaire.GetSelectedMonster().Vitesse)
    {
      this->Attack(ctx->Joueur.GetSelectedMonster(),ctx->Adversaire.GetSelectedMonster());
      if(ctx->Adversaire.GetSelectedMonster().IsAlive())
      {
        this->Attack(ctx->Adversaire.GetSelectedMonster(),ctx->Joueur.GetSelectedMonster());
        if(ctx->Joueur.GetSelectedMonster().IsAlive())
        {
          //on continu le combat
        }
        else 
        {
          //fin de partie
          this->IsFinish = true;
        }
      }
        else 
        {
          //fin de partie
          this->IsFinish = true;
        }
    }
    else 
    {
      this->Attack(ctx->Adversaire.GetSelectedMonster(),ctx->Joueur.GetSelectedMonster());
      if(ctx->Joueur.GetSelectedMonster().IsAlive())
      {
        this->Attack(ctx->Joueur.GetSelectedMonster(),ctx->Adversaire.GetSelectedMonster());
        if(ctx->Adversaire.GetSelectedMonster().IsAlive())
        {
          //on continu le combat
        }
        else 
        {
          //fin de partie
          this->IsFinish = true;
        }
      }
    }*/
    
    
    ctx->Joueur.GetSelectedMonster()->UnSelectedAttack();
    ctx->Adversaire.GetSelectedMonster()->UnSelectedAttack();
  }

  
  ///FIin resolution combat
