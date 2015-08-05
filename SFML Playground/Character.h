#ifndef CHARACTER_H
#define CHARACTER_H

#include "SFML\Graphics.hpp"
#include "Animation.h"
#include <iostream>

using sf::Sprite;

using std::vector;
using std::cout;
using std::endl;

class Character
{
private:
	Sprite state;

	unsigned int moveSpeed;
	unsigned int attackSpeed;
	unsigned int animationSpeed;
	unsigned int priorMove;
	unsigned int stepPhase;
	unsigned int count;
	
	float x;
	float y;
	
	vector <Sprite> left;
	vector <Sprite> right;
	vector <Sprite> up;
	vector <Sprite> down;

public:
	Character();
	~Character();
			
	void setMoveSpeed(unsigned int);
	void setAttackSpeed(unsigned int);
	void setAnimationSpeed(unsigned int);

	Sprite getState();

	void addLeft(vector <Sprite>&);
	void addRight(vector <Sprite>&);
	void addUp(vector <Sprite>&);
	void addDown(vector <Sprite>&);

	void move(unsigned int);
};

#endif
