#include "Monster.h"
Monster::Monster()
{
  this->nbAttaque = 0;
  this->selectedAttaque = 255;
}
void Monster::SetPatternAttaque(uint8_t numPattern)
{
  this->numeroPattern = numPattern;
}
uint8_t Monster::GetPatternAttaque()
{
  return this->numeroPattern;
}

bool Monster::IsFull()
{
  return this->nbAttaque >= this->maxAttaque;
}
bool Monster::IsAlive()
{
  return this->Vie >0;
}

bool Monster::IsSelectedAttack()
{
  return this->selectedAttaque<255;
}
void Monster::SetSelectedAttack(uint8_t num)
{
  this->selectedAttaque = num;
}

uint8_t Monster::SetSelectedAttack()
{
  return this->selectedAttaque;
}

void Monster::UnSelectedAttack()
{
  this->selectedAttaque=255;
}

uint8_t Monster::GetPourcentVieRestant()
{
  return this->OldVie*100 / this->VieMax;
}


