#ifndef CHARACTER_H
#define CHARACTER_H

#include "SFML\Graphics.hpp"
#include "Animation.h"
#include <iostream>

using sf::Sprite;
using sf::Texture;

using std::vector;
using std::cout;
using std::endl;

class Character
{
private:
	Texture texture;

	Sprite state;

	unsigned int moveSpeed;
	unsigned int attackSpeed;
	unsigned int animationSpeed;
	unsigned int priorMove;
	unsigned int stepPhase;
	unsigned int count;
	
	float prior_x;
	float prior_y;
	float x;
	float y;
	
	vector <Sprite> left;
	vector <Sprite> right;
	vector <Sprite> up;
	vector <Sprite> down;

public:
	Character();
	~Character();

	bool setTexture(Texture&, char*);
	Texture getTexture();
	
	Sprite getState();
			
	void setMoveSpeed(unsigned int);
	void setAttackSpeed(unsigned int);
	void setAnimationSpeed(unsigned int);

	void addLeft(vector <Sprite>&);
	void addRight(vector <Sprite>&);
	void addUp(vector <Sprite>&);
	void addDown(vector <Sprite>&);

	void move(unsigned int);
};

#endif
