#ifndef WEAPON_H;
#define WEAPON_H

#include "SFML\Graphics.hpp"
#include <vector>
#include <memory>

using sf::Texture;
using sf::Sprite;
using sf::IntRect;
using std::vector;

class Weapon {

protected:
	Texture *texture;

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
	void loadHelper(Sprite &s, int left, int top, int width, int height) {
		s.setTextureRect(IntRect(left, top, width, height));
		return;
	}

	virtual void bindAttack(void) = 0;
};

#endif