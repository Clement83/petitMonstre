#include "Player.h"


    Player::Player()
    {
        this->nbMonstre = 0;
        this->Monsters = new Monster[this->maxMonster];
    }
    
	void Player::AddMonster(Monster monster)
    {
    	if(!this->IsFull())
		{
			monster.Index = nbMonstre;
			this->Monsters[nbMonstre] = monster;
			nbMonstre++;
		}
    }

    void Player::Remove(Monster monster)
    {
		this->nbMonstre--;
		for (int i = monster.Index; i < this->nbMonstre; i++)
		{
			this->Monsters[i] = this->Monsters[i + 1];
		} 
    }

    bool Player::IsFull()
    {
    	return this->maxMonster<=this->nbMonstre;
    }

    Monster Player::GetMonster(int index)
    {
		//if(index<this->nbMonstre)
//		{
			return this->Monsters[index];
//		}
//		throw 101;
    }

    int Player::NbMonstre()
    {
        return this->nbMonstre;
    }

    Monster* Player::ListeMonster()
    {
    	Monster *lesMonstres = new Monster[this->nbMonstre];
    	for(int i=0;i<this->nbMonstre;i++)
    	{
			lesMonstres[i] = this->Monsters[i];
    	}
    	return lesMonstres; 
    }

