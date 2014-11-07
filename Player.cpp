#include "Player.h"


Player::Player()
{
  this->nbMonstre = 0;
  this->SelectedMonster = 255;
  //this->Monsters = new Monster[this->maxMonster];
/*
  for(int i=0;i<this->maxMonster;i++)
  {
    Monster *m1 = new Monster();
    m1->Index = 1;
    this->Monsters[i] = *m1;
  }*/
}

void Player::AddMonster(uint8_t numero, uint8_t vie,uint8_t vitesse,uint8_t force,uint8_t defence)
{
  if(!this->IsFull())
  {

    Monster *m1 = &this->Monsters[this->nbMonstre];
    m1->Numero = numero;
    m1->Force = force;
    m1->ForceMax = m1->Force;
    m1->Vie = vie;
    m1->VieMax = m1->Vie;
    m1->OldVie = m1->Vie;
    m1->Vitesse = vitesse;
    m1->VitesseMax = m1->Vitesse;
    m1->Defence = defence;
    m1->DefenceMax = m1->Defence;
    this->nbMonstre++;
  }
}

void Player::Remove(Monster monster)
{
  this->nbMonstre--;
  for (uint8_t i = monster.Index; i < this->nbMonstre; i++)
  {
    Monster *m2 = &this->Monsters[i + 1];
    Monster *m1 = &this->Monsters[i];
    m1->Numero = m2->Numero;
    m1->Force = m2->Force;
    m1->ForceMax = m2->Force;
    m1->Vie = m2->Vie;
    m1->VieMax = m2->Vie;
    m1->Vitesse = m2->Vitesse;
    m1->VitesseMax = m2->Vitesse;
    m1->Defence = m2->Defence;
    m1->DefenceMax = m2->Defence;
  }

}
void  Player::UnSelectMonster()
{
  this->SelectedMonster = 255;
}

void Player::ClearMonster()
{
  this->nbMonstre=0;
}

void Player::SelectMonster(uint8_t num)
{
  this->SelectedMonster = num;
}

bool  Player::HaveMonsterOk()
{
  for (uint8_t i = 0; i < this->nbMonstre; i++)
  {
    if(this->Monsters[i].Vie>0)
    {
      return true;
    };
  }

  return false;
}

bool Player::IsFull()
{
  return this->maxMonster<=this->nbMonstre;
}

bool Player::IsSelectedMonster()
{
  return this->SelectedMonster< 255;
}

uint8_t Player::GetSelectNumMonster()
{
  return this->SelectedMonster;
}

Monster Player::GetMonster(uint8_t index)
{
  return this->Monsters[index];
}

Monster* Player::GetSelectedMonster()
{
  return &this->Monsters[this->SelectedMonster];
}

uint8_t Player::NbMonstre()
{
  return this->nbMonstre;
}

Monster* Player::ListeMonster()
{
  Monster *lesMonstres = new Monster[this->nbMonstre];
  for(uint8_t i=0;i<this->nbMonstre;i++)
  {
    lesMonstres[i] = this->Monsters[i];
  }
  return lesMonstres;
}

