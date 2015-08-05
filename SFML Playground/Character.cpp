#include "Character.h"

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

void Character::setMoveSpeed(unsigned int ms) { moveSpeed = ms; }
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