#ifndef CHARACTER_H
#define CHARACTER_H

#include "SFML\Graphics.hpp"
#include "Animation.h"
#include <vector>
#include <iostream>

using sf::Sprite;

using std::vector;
using std::cout;

using Animation::moveLeft;
using Animation::moveRight;
using Animation::moveUp;
using Animation::moveDown;

class Character
{
private:
	Sprite state;

	unsigned int moveSpeed;
	unsigned int attackSpeed;
	unsigned int animationSpeed;
	unsigned int priorMove;
	unsigned int stepPhase;
	unsigned int count = animationSpeed;
	
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
void Character::setAnimationSpeed(unsigned int ans) { attackSpeed = ans; }

void Character::addLeft(vector <Sprite>& vec) { left = vec; }
void Character::addRight(vector <Sprite>& vec) { right = vec; }
void Character::addUp(vector <Sprite>& vec) { up = vec; }
void Character::addDown(vector <Sprite>& vec) { down = vec; }

void Character::move(unsigned int dir) {
	if (moveSpeed == 0 || animationSpeed == 0) { cout << "WARNING: Essential Character Speed Variable is 0" << endl; }

	bool madeMove = false;

	if (dir == 1) {
		madeMove = Animation::moveLeft(left, state, priorMove, stepPhase, count, moveSpeed, animationSpeed, x)
	}
	else if (dir == 2) {
		madeMove = Animation::moveRight(right, state, priorMove, stepPhase, count, moveSpeed, animationSpeed, x;
	}
	else if (dir == 3) {
		madeMove = Animation::moveUp(up, state, priorMove, stepPhase, count, moveSpeed, animationSpeed, y);
	}
	else {
		madeMove = Animation::moveDown(down, state, priorMove, stepPhase, count, moveSpeed, animationSpeed, y);
	}

	if (!madeMove) {
		step_phase = 0;
		count = SPEED;
		// Idle position code [HERE]
		direction = 0;
	}
}


#endif
