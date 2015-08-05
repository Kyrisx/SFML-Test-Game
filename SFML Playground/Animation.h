#ifndef ANIMATION_H
#define ANIMATION_H

#include "Character.h"

using sf::Sprite;
using sf::Keyboard;

using std::vector;

class Animation
{

private:
	
	
public:
	void moveLeft(vector <Sprite>&, Sprite&, unsigned int&, unsigned int&, unsigned int&, unsigned int, unsigned int, float&, bool&);
	void moveRight(vector <Sprite>&, Sprite&, unsigned int&, unsigned int&, unsigned int&, unsigned int, unsigned int, float&, bool&);
	void moveUp(vector <Sprite>&, Sprite&, unsigned int&, unsigned int&, unsigned int&, unsigned int, unsigned int, float&, bool&);
	void moveDown(vector <Sprite>&, Sprite&, unsigned int&, unsigned int&, unsigned int&, unsigned int, unsigned int, float&, bool&);
	
	//void draw(Sprite&);
};

#endif