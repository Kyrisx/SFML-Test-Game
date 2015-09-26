#ifndef SWORD_H
#define SWORD_H

#include "Weapon.h"
#include "SFML\Graphics.hpp"
#include <memory>
#include <iostream>

using sf::Sprite;
using sf::IntRect;



class Sword : public Weapon
{
private:
	void bind();

public:
	Sword();
};

Sword::Sword() {
	ID = 1;
	damage = 0.5;
	speed = 3;
	count = 0;
	phase = 0;

	Texture* t = new Texture;
	if (!t->loadFromFile("link.png")) {
		std::cout << "Couldn't open sprite file" << std::endl;
		return;
	}
	texture = std::unique_ptr<Texture>(t);

	Sprite asl0, asl1, asl2, asl3, asl4, asl5, asl6;
	Sprite asr0, asr1, asr2, asr3, asr4, asr5, asr6;
	Sprite asu0, asu1, asu2, asu3, asu4, asu5, asu6;
	Sprite asd0, asd1, asd2, asd3, asd4, asd5, asd6;

	asl0.setTextureRect(IntRect(184, 67, 19, 26));
	asl1.setTextureRect(IntRect(216, 70, 26, 23));
	asl2.setTextureRect(IntRect(247, 70, 33, 23));
	asl3.setTextureRect(IntRect(283, 71, 34, 22));
	asl4.setTextureRect(IntRect(324, 71, 30, 23));
	asl5.setTextureRect(IntRect(371, 70, 23, 30));
	asl6.setTextureRect(IntRect(417, 70, 17, 31));

	asu0.setTextureRect(IntRect(183, 22, 25, 24));
	asu1.setTextureRect(IntRect(221, 22, 23, 25));
	asu2.setTextureRect(IntRect(256, 15, 22, 32));
	asu3.setTextureRect(IntRect(294, 11, 18, 36));
	asu4.setTextureRect(IntRect(329, 15, 22, 32));
	asu5.setTextureRect(IntRect(363, 22, 29, 25));
	asu6.setTextureRect(IntRect(401, 23, 33, 24));

	asd0.setTextureRect(IntRect(178, 115, 26, 25));
	asd1.setTextureRect(IntRect(220, 114, 22, 31));
	asd2.setTextureRect(IntRect(257, 112, 19, 38));
	asd3.setTextureRect(IntRect(296, 112, 18, 41));
	asd4.setTextureRect(IntRect(335, 114, 23, 37));
	asd5.setTextureRect(IntRect(374, 117, 29, 31));
	asd6.setTextureRect(IntRect(414, 117, 32, 24));

	left = { asl0, asl1, asl2, asl3, asl4, asl5, asl6 };
	right = { asr0, asr1, asr2, asr3, asr4, asr5, asr6 };
	up = { asu0, asu1, asu2, asu3, asu4, asu5, asu6 };
	down = { asd0, asd1, asd2, asd3, asd4, asd5, asd6 };

	for (unsigned int i = 0; i < right.size(); i++) {
		right[i] = left[i];
		right[i].setScale(-1, 1);
	}

	bind();
}

void Sword::bind() {
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

#endif