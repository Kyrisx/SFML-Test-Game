#ifndef ANIMATION_H
#define ANIMATION_H

#include "Character.h"

using sf::Sprite;
using sf::Keyboard;

using std::vector;
using std::pair;

class Animation
{

private:
	
	
public:
	void moveLeft(vector <Sprite>&, Sprite&, unsigned int&, unsigned int&, unsigned int&, unsigned int, unsigned int, pair <float, float>&);
	void moveRight(vector <Sprite>&, Sprite&, unsigned int&, unsigned int&, unsigned int&, unsigned int, unsigned int, pair <float, float>&);
	void moveUp(vector <Sprite>&, Sprite&, unsigned int&, unsigned int&, unsigned int&, unsigned int, unsigned int, pair <float, float>&);
	void moveDown(vector <Sprite>&, Sprite&, unsigned int&, unsigned int&, unsigned int&, unsigned int, unsigned int, pair <float, float>&);
	void noMove(vector <Sprite>&, Sprite&);
	void attack(vector <Sprite>&, Sprite&, Character::attackQuery&);
};

#endif