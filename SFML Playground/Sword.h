#ifndef SWORD_H
#define SWORD_H

#include "SFML\Graphics.hpp"
#include "Weapon.h"

using sf::Sprite;

class Sword : public Weapon {

public:
	Sword();
	void bindAttack(void) {
		for (unsigned int i = 0; i < left.size(); i++) {
			left[i].setTexture(*texture);
			if (i == 1 || i == 5) left[i].setOrigin(left[i].getLocalBounds().width / 2, (left[i].getLocalBounds().height / 2) + 3.0f);
			else if (i == 2 || i == 6) left[i].setOrigin(left[i].getLocalBounds().width / 2, (left[i].getLocalBounds().height / 2) + 2.0f);
			else left[i].setOrigin(left[i].getLocalBounds().width / 2, left[i].getLocalBounds().height / 2);
			left[i].scale(3, 3);
		}
		for (unsigned int i = 0; i < right.size(); i++) {
			right[i].setTexture(*texture);
			if (i == 1 || i == 5) right[i].setOrigin(right[i].getLocalBounds().width / 2, (right[i].getLocalBounds().height / 2) + 3.0f);
			else if (i == 2 || i == 6) right[i].setOrigin(right[i].getLocalBounds().width / 2, (right[i].getLocalBounds().height / 2) + 2.0f);
			else right[i].setOrigin(right[i].getLocalBounds().width / 2, right[i].getLocalBounds().height / 2);
			right[i].scale(3, 3);
		}
		for (unsigned int i = 0; i < up.size(); i++) {
			up[i].setTexture(*texture);
			if (i == 1 || i == 5) up[i].setOrigin(up[i].getLocalBounds().width / 2, (up[i].getLocalBounds().height / 2) + 2.0f);
			else if (i == 3 || i == 7) up[i].setOrigin(up[i].getLocalBounds().width / 2, (up[i].getLocalBounds().height / 2) - 1.0f);
			else up[i].setOrigin(up[i].getLocalBounds().width / 2, up[i].getLocalBounds().height / 2);
			up[i].scale(3, 3);
		}
		for (unsigned int i = 0; i < down.size(); i++) {
			down[i].setTexture(*texture);
			if (i == 1 || i == 5) down[i].setOrigin(down[i].getLocalBounds().width / 2, (down[i].getLocalBounds().height / 2) + 3.0f);
			else if (i == 2 || i == 6) down[i].setOrigin(down[i].getLocalBounds().width / 2, (down[i].getLocalBounds().height / 2) + 4.0f);
			else if (i == 3 || i == 7) down[i].setOrigin(down[i].getLocalBounds().width / 2, (down[i].getLocalBounds().height / 2) + 1.0f);
			else down[i].setOrigin(down[i].getLocalBounds().width / 2, down[i].getLocalBounds().height / 2);
			down[i].scale(3, 3);
		}
		return;
	}
};

Sword::Sword() {
	ID = 1;
	damage = 0.5;
	speed = 3;

	Sprite asl0, asl1, asl2, asl3, asl4, asl5, asl6;
	Sprite asr0, asr1, asr2, asr3, asr4, asr5, asr6;
	Sprite asu0, asu1, asu2, asu3, asu4, asu5, asu6;
	Sprite asd0, asd1, asd2, asd3, asd4, asd5, asd6;

	loadHelper(asl0, 184, 67, 19, 26);
	loadHelper(asl1, 216, 70, 26, 23);
	loadHelper(asl2, 247, 70, 33, 23);
	loadHelper(asl3, 283, 71, 34, 22);
	loadHelper(asl4, 324, 71, 30, 23);
	loadHelper(asl5, 371, 70, 23, 30);
	loadHelper(asl6, 417, 70, 17, 31);

	loadHelper(asu0, 183, 22, 25, 24);
	loadHelper(asu1, 221, 22, 23, 25);
	loadHelper(asu2, 256, 15, 22, 32);
	loadHelper(asu3, 294, 11, 18, 36);
	loadHelper(asu4, 329, 15, 22, 32);
	loadHelper(asu5, 363, 22, 29, 25);
	loadHelper(asu6, 401, 23, 33, 24);

	loadHelper(asd0, 178, 115, 26, 25);
	loadHelper(asd1, 220, 114, 22, 31);
	loadHelper(asd2, 257, 112, 19, 38);
	loadHelper(asd3, 296, 112, 18, 41);
	loadHelper(asd4, 335, 114, 23, 37);
	loadHelper(asd5, 374, 117, 29, 31);
	loadHelper(asd6, 414, 117, 32, 24);

	left = { asl0, asl1, asl2, asl3, asl4, asl5, asl6 };
	right = { asr0, asr1, asr2, asr3, asr4, asr5, asr6 };
	up = { asu0, asu1, asu2, asu3, asu4, asu5, asu6 };
	down = { asd0, asd1, asd2, asd3, asd4, asd5, asd6 };

	for (unsigned int i = 0; i < right.size(); i++) {
		right[i] = left[i];
		right[i].setScale(-1, 1);
	}

	bindAttack();

	return;
}

#endif