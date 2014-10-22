#include "Monster.h"
    Monster::Monster()
    {
      this->nbAttaque = 0;
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

    void Monster::RemoveAttaque(Attaque atta)
    {
		this->nbAttaque--;
		for (int i = atta.Index; i < this->nbAttaque; i++)
		{
			this->Attaques[i] = this->Attaques[i + 1];
		} 
    }

    Attaque* Monster::ListAttaque()
    {
    	Attaque* lesAttaques = new Attaque[this->nbAttaque];
    	for(int i=0;i<this->nbAttaque;i++)
    	{
          lesAttaques[i] = this->Attaques[i];
    	}
    	return lesAttaques; 
    }

    Attaque Monster::UseAttaque(int index)
    {
		//if(index<this->nbAttaque)
		//{
			return this->Attaques[index];
		//}
		//throw 100;
    }

