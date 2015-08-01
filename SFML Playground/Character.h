#ifndef CHARACTER_H
#define CHARACTER_H

#include "SFML\Graphics.hpp"
#include "Animation.h"
#include <vector>
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

Character::Character()
{
	state = right[0];
	moveSpeed = 0;
	attackSpeed = 0;
	animationSpeed = 0;	
	priorMove = 0;
	stepPhase = 0;
	count = animationSpeed;
	x = 0.0;
	y = 0.0;
}

Character::~Character()
{

}

void Character::setMoveSpeed(unsigned int ms) {	moveSpeed = ms; }
void Character::setAttackSpeed(unsigned int ats) { attackSpeed = ats; }
void Character::setAnimationSpeed(unsigned int ans) { animationSpeed = ans; }

Sprite Character::getState() { return state; }

void Character::addLeft(vector <Sprite>& vec) { left = vec; }
void Character::addRight(vector <Sprite>& vec) { right = vec; }
void Character::addUp(vector <Sprite>& vec) { up = vec; }
void Character::addDown(vector <Sprite>& vec) { down = vec; }

void Character::move(unsigned int dir) {
	Animation i;
	if (moveSpeed == 0 || animationSpeed == 0) { cout << "WARNING: Essential Character Speed Variable is 0" << endl; }

	bool madeMove = false;

	if (dir == 1) {
		i.moveLeft(left, state, priorMove, stepPhase, count, moveSpeed, animationSpeed, x, madeMove);
	}
	else if (dir == 2) {
		i.moveRight(right, state, priorMove, stepPhase, count, moveSpeed, animationSpeed, x, madeMove);
	}
	else if (dir == 3) {
		i.moveUp(up, state, priorMove, stepPhase, count, moveSpeed, animationSpeed, y, madeMove);
	}
	else {
		i.moveDown(down, state, priorMove, stepPhase, count, moveSpeed, animationSpeed, y, madeMove);
	}

	if (!madeMove) {
		stepPhase = 0;
		count = animationSpeed;
		// Idle position code [HERE]
		priorMove = 0;
	}
	else {
		state.move(x, y);
	}

}


#endif
