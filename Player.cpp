#include "Player.h"


    Player::Player()
    {
        this->nbMonstre = 0;
        this->SelectedMonster = 255;
        this->Monsters = new Monster[this->maxMonster];
    }
    
	void Player::AddMonster(Monster monster)
    {
    	if(!this->IsFull())
		{
			monster.Index = this->nbMonstre;
			this->Monsters[this->nbMonstre] = monster;
			this->nbMonstre++;
		}
    }

    void Player::Remove(Monster monster)
    {
        this->nbMonstre--;
        for (uint8_t i = monster.Index; i < this->nbMonstre; i++)
        {
            this->Monsters[i] = this->Monsters[i + 1];
        } 
    }
    void  Player::UnSelectMonster()
    {
        this->SelectedMonster = 255;
    }

    void Player::SelectMonster(uint8_t num)
    {
        this->SelectedMonster = num;
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
