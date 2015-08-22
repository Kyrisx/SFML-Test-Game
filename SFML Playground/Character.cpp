#include "Character.h"

Character::Character()
{
	state.setPosition(loc.first, loc.second);

	moveSpeed = 0;
	attackSpeed = 0;
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

Character::~Character()
{

}

void Character::addTexture(Texture* t)
{
	texture = std::unique_ptr<Texture>(t);
}

Texture* Character::printTexture() 
{
	return texture.get();
}

Sprite Character::getState() { return state; }

void Character::setMS(unsigned int ms) { moveSpeed = ms; }
void Character::setAS(unsigned int ats) { attackSpeed = ats; }
void Character::setAns(unsigned int ans) { animationSpeed = ans; }

void Character::addLeft(vector <Sprite>& vec) { left = vec; }
void Character::addRight(vector <Sprite>& vec) {
	right = vec; 
	state = right[0];
}
void Character::addUp(vector <Sprite>& vec) { up = vec; }
void Character::addDown(vector <Sprite>& vec) { down = vec; }

void Character::addAtkLeft(vector <Sprite>& vec) { atkleft = vec; }
void Character::addAtkRight(vector <Sprite>& vec) { atkright = vec;}
void Character::addAtkUp(vector <Sprite>& vec) { atkup = vec; }
void Character::addAtkDown(vector <Sprite>& vec) { atkdown = vec; }

void Character::move() {
	Animation anim;

	if (moveSpeed == 0 || animationSpeed == 0) { cout << "WARNING: Essential Character Speed Variable is 0" << endl; }

	if (Keyboard::isKeyPressed(Keyboard::Left) && (priorMove == 0 || priorMove == 1)) {
		anim.moveLeft(left, state, priorMove, stepPhase, count, moveSpeed, animationSpeed, loc);
	}

	else if (Keyboard::isKeyPressed(Keyboard::Right) && (priorMove == 0 || priorMove == 2)) {
		anim.moveRight(right, state, priorMove, stepPhase, count, moveSpeed, animationSpeed, loc);
	}

	else if (Keyboard::isKeyPressed(Keyboard::Up) && (priorMove == 0 || priorMove == 3)) {
		anim.moveUp(up, state, priorMove, stepPhase, count, moveSpeed, animationSpeed, loc);
	}

	else if (Keyboard::isKeyPressed(Keyboard::Down) && (priorMove == 0 || priorMove == 4)) {
		anim.moveDown(down, state, priorMove, stepPhase, count, moveSpeed, animationSpeed, loc);
	}
	else {
		stepPhase = 0;
		count = animationSpeed;
		if (priorMove == 1) {
			anim.noMove(left, state);
			facing = 1;
		}
		else if (priorMove == 2) {
			anim.noMove(right, state);
			facing = 2;
		}
		else if (priorMove == 3) {
			anim.noMove(up, state);
			facing = 3;
		}
		else if (priorMove == 4) {
			anim.noMove(down, state);
			facing = 4;
		}
		priorMove = 0;
	}
	state.setPosition(loc.first, loc.second);
	cout << "Prior Move: " << priorMove << endl;
		
	if (loc.first != prior_x || loc.second != prior_y) {
		cout << loc.first << ", " << loc.second << "\t";
		if (priorMove == 1) { cout << "left" << endl; }
		else if (priorMove == 2) { cout << "right" << endl; }
		else if (priorMove == 3) { cout << "up" << endl; }
		else if (priorMove == 4) { cout << "down" << endl; }
		prior_x = loc.first;
		prior_y = loc.second;
	}
}

void Character::attack() {
	Animation anim;

	if (facing == 1) {

	}
}