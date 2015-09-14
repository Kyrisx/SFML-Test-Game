#include "Character.h"
#include "Animation.h"

Character::Character()
{
	state.setPosition(loc.first, loc.second);

	moveSpeed = 0;
	animationSpeed = 0;
	priorMove = 0;
	stepPhase = 0;
	count = animationSpeed;
	facing = 2;

	loc.first = 100.00;
	loc.second = 100.00;
	prior_x = loc.first;
	prior_y = loc.second;
}

Character::~Character() {}

void Character::addTexture(Texture* t) { texture = std::unique_ptr<Texture>(t); }
Texture* Character::printTexture() { return texture.get(); }

Sprite* Character::getState() { 
	return &state; }

void Character::setMS(unsigned int ms) { moveSpeed = ms; }
void Character::setAns(unsigned int ans) { animationSpeed = ans; }

float Character::getPlane() {
	return getState()->getGlobalBounds().height;
}

unsigned int Character::getMS() { return moveSpeed; }
unsigned int Character::getAns() { return animationSpeed; }

char* Character::getPriorMove() { 
	if (priorMove == 0) return "-";
	else if (priorMove == 1) return "West";
	else if (priorMove == 2) return "East";
	else if (priorMove == 3) return "North";
	else return "South";
}

char* Character::getFacing() {
	if (facing == 1) return "West";
	else if (facing == 2) return "East";
	else if (facing == 3) return "North";
	else return "South";
}

unsigned int Character::getStepPhase() { return stepPhase; }
unsigned int Character::getAtkDirSize() {
	if (facing == 1) return atkLeft.size();
	else if (facing == 2) return atkRight.size();
	else if (facing == 3) return atkUp.size();
	else return atkDown.size();
}

float Character::x() { return loc.first; }
float Character::y() { return loc.second; }

void Character::addLeft(vector <Sprite>& vec) { left = vec; }
void Character::addRight(vector <Sprite>& vec) {
	right = vec; 
	state = right[0];
}
void Character::addUp(vector <Sprite>& vec) { up = vec; }
void Character::addDown(vector <Sprite>& vec) { down = vec; }

void Character::move() {
	Animation anim;

	if (Keyboard::isKeyPressed(Keyboard::Left) && (priorMove == 0 || priorMove == 1)) {
		anim.moveLeft(left, state, priorMove, stepPhase, count, moveSpeed, animationSpeed, loc);
		facing = 1;
	}

	else if (Keyboard::isKeyPressed(Keyboard::Right) && (priorMove == 0 || priorMove == 2)) {
		anim.moveRight(right, state, priorMove, stepPhase, count, moveSpeed, animationSpeed, loc);
		facing = 2;
	}

	else if (Keyboard::isKeyPressed(Keyboard::Up) && (priorMove == 0 || priorMove == 3)) {
		anim.moveUp(up, state, priorMove, stepPhase, count, moveSpeed, animationSpeed, loc);
		facing = 3;
	}

	else if (Keyboard::isKeyPressed(Keyboard::Down) && (priorMove == 0 || priorMove == 4)) {
		anim.moveDown(down, state, priorMove, stepPhase, count, moveSpeed, animationSpeed, loc);
		facing = 4;
	}
	else {
		stepPhase = 0;
		count = animationSpeed;
		if (facing == 1) {
			anim.noMove(left, state);
		}
		else if (facing == 2) {
			anim.noMove(right, state);
		}
		else if (facing == 3) {
			anim.noMove(up, state);
		}
		else if (facing == 4) {
			anim.noMove(down, state);
		}
		priorMove = 0;
	}
	state.setPosition(loc.first, loc.second);
	return;
}

bool Character::attack() {
	Animation anim;
	
	if (facing == 1) {
		if (!anim.attack(atkLeft, state, getAttack)) {
			return false;
		}
	}
	if (facing == 2) {
		if (!anim.attack(atkRight, state, getAttack)) {
			return false;
		}
	}
	if (facing == 3) {
		if (!anim.attack(atkUp, state, getAttack)) {
			return false;
		}
	}
	if (facing == 4) {
		if (!anim.attack(atkDown, state, getAttack)) {
			return false;
		}
	}
	state.setPosition(loc.first, loc.second);
	return true;
}