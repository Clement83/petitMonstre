

void DysplayEtatFuturomon()
{
  uint8_t cptMonster = 0;
  uint8_t offset = 30;
  ctx->Joueur.SelectMonster(cptMonster);
  while(cptMonster<4)
  {
    if(gb.update())
    {      
      gb.display.drawBitmap(60  , 0- offset, GetSpriteMonsterByNumero(ctx->Joueur.GetSelectedMonster()->Numero, true));//allSpriteMonstersFront[ctx->Adversaire.GetSelectedMonster()->Numero]);
      
      if(offset>0)offset -= 3;
      
      gb.display.println(F(""));
      gb.display.println(F(""));
      gb.display.print(F("Vie:"));
      gb.display.print(ctx->Joueur.GetSelectedMonster()->Vie);
      gb.display.print(F("/"));
      gb.display.println(ctx->Joueur.GetSelectedMonster()->VieMax);

      gb.display.print(F("Vit:"));
      gb.display.print(ctx->Joueur.GetSelectedMonster()->Vitesse);
      gb.display.print(F("/"));
      gb.display.println(ctx->Joueur.GetSelectedMonster()->VitesseMax);

      gb.display.print(F("For:"));
      gb.display.print(ctx->Joueur.GetSelectedMonster()->Force);
      gb.display.print(F("/"));
      gb.display.println(ctx->Joueur.GetSelectedMonster()->ForceMax);

      gb.display.print(F("Def:"));
      gb.display.print(ctx->Joueur.GetSelectedMonster()->Defence);
      gb.display.print(F("/"));
      gb.display.println(ctx->Joueur.GetSelectedMonster()->DefenceMax);

      if(gb.buttons.pressed(BTN_A))
      {
        cptMonster++;
        ctx->Joueur.SelectMonster(cptMonster);
        offset = 30;
      }
    }
  }
  ctx->Joueur.UnSelectMonster();
}


