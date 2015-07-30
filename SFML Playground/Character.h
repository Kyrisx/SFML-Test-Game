#ifndef CHARACTER_H
#define CHARACTER_H

#include "SFML\Graphics.hpp"
#include "Animation.h"
#include <vector>

using sf::Texture;
using sf::Sprite;

using std::vector;

using Animation::moveLeft;

class Character
{
private:
	Texture texture;
	unsigned int moveSpeed;
	unsigned int attackSpeed;
	unsigned int animationSpeed;
	unsigned int direction;
	vector <Sprite> left;
	vector <Sprite> right;
	vector <Sprite> up;
	vector <Sprite> down;

	

public:
	Character();
	~Character();

	void setTexture(Texture t);
		
	void setMoveSpeed(unsigned int ms);
	void setAttackSpeed(unsigned int ats);
	void setAnimationSpeed(unsigned int ans);
	void setDirection(unsigned int d);

	unsigned int getMoveSpeed();
	unsigned int getAttackSpeed();
	unsigned int getAnimationSpeed();
	unsigned int getDirection();

	void addLeft(Sprite l);
	void addRight(Sprite r);
	void addUp(Sprite u);
	void addDown(Sprite d);
	void moveLeft();
	void moveRight(Character c);
	void moveUp(Character c);
	void moveDown(Character c);


};

Character::Character()
{
	moveSpeed = 0;
	attackSpeed = 0;
	animationSpeed = 0;	
	direction = 0;
}

Character::~Character()
{

}

void Character::setTexture(Texture t) {	texture = t; }

void Character::setMoveSpeed(unsigned int ms) {	moveSpeed = ms; }
void Character::setAttackSpeed(unsigned int ats) { attackSpeed = ats; }
void Character::setAnimationSpeed(unsigned int ans) { attackSpeed = ans; }
void Character::setDirection(unsigned int d) { direction = d; }

unsigned int Character::getMoveSpeed() { return moveSpeed; }
unsigned int Character::getAttackSpeed() { return attackSpeed; }
unsigned int Character::getAnimationSpeed() { return animationSpeed; }
unsigned int Character::getDirection() { return direction; }

void Character::addLeft(Sprite l) { left.push_back(l); }
void Character::addRight(Sprite r) { right.push_back(r); }
void Character::addUp(Sprite u) { up.push_back(u); }
void Character::addDown(Sprite d) { down.push_back(d); }


void Character::moveLeft() {
	Animation::moveLeft()
}


#endif
