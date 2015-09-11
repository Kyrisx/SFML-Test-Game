#ifndef WEAPON_H
#define WEAPON_H

#include "SFML\Graphics.hpp"
#include <vector>

using sf::Sprite;
using std::vector;

class Weapon {

protected:
	unsigned int ID;
	double damage;
	unsigned int speed;

	vector <Sprite> left;
	vector <Sprite> right;
	vector <Sprite> up;
	vector <Sprite> down;

	unsigned int count;
	unsigned int phase;

public:
	void setDamage(double);
	void setSpeed(unsigned int);

	void setLeft(vector <Sprite>);
	void setRight(vector <Sprite>);
	void setUp(vector <Sprite>);
	void setDown(vector <Sprite>);

	void loadHelper(Sprite &s, int left, int top, int width, int height) {
		s.setTextureRect(IntRect(left, top, width, height));
		return;
	}
};

#endif