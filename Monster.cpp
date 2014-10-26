#include "Monster.h"
    Monster::Monster()
    {
      this->nbAttaque = 0;
      this->selectedAttaque = 255;
    }
    void Monster::AddAttaque(Attaque atta)
    {
    	if(!IsFull()) 
    	{
    		atta.Index = this->nbAttaque;
			Attaques[this->nbAttaque] = atta;
    		this->nbAttaque++;
    	}
    }
    
    bool Monster::IsFull()
    {
    	return this->nbAttaque >= this->maxAttaque;
    }
    bool Monster::IsAlive()
    {
        return this->Vie >0;
    }

    void Monster::RemoveAttaque(Attaque atta)
    {
		this->nbAttaque--;
		for (uint8_t i = atta.Index; i < this->nbAttaque; i++)
		{
			this->Attaques[i] = this->Attaques[i + 1];
		} 
    }

    Attaque* Monster::ListAttaque()
    {
    	Attaque* lesAttaques = new Attaque[this->nbAttaque];
    	for(uint8_t i=0;i<this->nbAttaque;i++)
    	{
          lesAttaques[i] = this->Attaques[i];
    	}
    	return lesAttaques; 
    }

    Attaque Monster::UseAttaque(uint8_t index)
    {
		//if(index<this->nbAttaque)
		//{
			return this->Attaques[index];
		//}
		//throw 100;
    }


    bool Monster::IsSelectedAttack()
    {
        return this->selectedAttaque<255;
    }
    void Monster::SetSelectedAttack(uint8_t num)
    {
        this->selectedAttaque = num;
    }
    Attaque Monster::GetSelectedAttack()
    {
        return this->Attaques[this->selectedAttaque];
    }
    void Monster::UnSelectedAttack()
    {
        this->selectedAttaque=255;
    }

