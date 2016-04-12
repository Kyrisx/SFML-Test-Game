#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Item.h"
#include "SFML\Graphics.hpp"
#include <memory>
#include <iostream>

using sf::Keyboard;
using sf::Sprite;
using sf::IntRect;

class Player : public Character
{
private:
	void bind();
	void endAction();

public:
	Item *slot0;
	Item *slot1;

	Player();
	void equip(Item*, unsigned int);
	void move();
	bool attack();

	// STATISTICS INFO //////
	unsigned int getAtkDirSize();
	/////////////////////////
};

Player::Player()
{
	state.setPosition(loc.first, loc.second);

	moveSpeed = 5;
	animationSpeed = 2;
	priorMove = 0;
	stepPhase = 0;
	count = animationSpeed;
	facing = 1;

	loc.first = 100.00;
	loc.second = 100.00;
	prior_x = loc.first;
	prior_y = loc.second;

	Texture* t = new Texture;
	if (!t->loadFromFile("link.png")) {
		std::cout << "Couldn't open sprite file" << std::endl;
		return;
	}
	texture = std::unique_ptr<Texture>(t);

	Sprite awl0, awl1, awl2, awl3, awl4, awl5, awl6, awl7;
	Sprite awr0, awr1, awr2, awr3, awr4, awr5, awr6, awr7;
	Sprite awu0, awu1, awu2, awu3, awu4, awu5, awu6, awu7;
	Sprite awd0, awd1, awd2, awd3, awd4, awd5, awd6, awd7;

	awl0.setTextureRect(IntRect(4, 70, 19, 23));
	awl1.setTextureRect(IntRect(7, 216, 19, 23));
	awl2.setTextureRect(IntRect(38, 217, 23, 22));
	awl3.setTextureRect(IntRect(70, 217, 24, 22));
	awl4.setTextureRect(IntRect(4, 70, 19, 23));
	awl5.setTextureRect(IntRect(104, 216, 19, 23));
	awl6.setTextureRect(IntRect(133, 217, 23, 22));
	awl7.setTextureRect(IntRect(171, 217, 24, 22));

	awu0.setTextureRect(IntRect(4, 23, 18, 23));
	awu1.setTextureRect(IntRect(9, 187, 18, 24));
	awu2.setTextureRect(IntRect(40, 184, 18, 27));
	awu3.setTextureRect(IntRect(73, 186, 18, 25));
	awu4.setTextureRect(IntRect(4, 23, 18, 23));
	awu5.setTextureRect(IntRect(105, 187, 18, 24));
	awu6.setTextureRect(IntRect(137, 184, 18, 27));
	awu7.setTextureRect(IntRect(173, 186, 18, 25));

	awd0.setTextureRect(IntRect(5, 116, 18, 26));
	awd1.setTextureRect(IntRect(7, 245, 18, 29));
	awd2.setTextureRect(IntRect(38, 243, 18, 28));
	awd3.setTextureRect(IntRect(68, 246, 18, 25));
	awd4.setTextureRect(IntRect(5, 116, 18, 26));
	awd5.setTextureRect(IntRect(102, 246, 18, 29));
	awd6.setTextureRect(IntRect(134, 245, 18, 28));
	awd7.setTextureRect(IntRect(171, 248, 18, 25));

	left = { awl0, awl1, awl2, awl3, awl4, awl5, awl6, awl7 };
	right = { awr0, awr1, awr2, awr3, awr4, awr5, awr6, awr7 };
	up = { awu0, awu1, awu2, awu3, awu4, awu5, awu6, awu7 };
	down = { awd0, awd1, awd2, awd3, awd4, awd5, awd6, awd7 };

	for (unsigned int i = 0; i < right.size(); i++) {
		right[i] = left[i];
		right[i].setScale(-1, 1);
	}

	bind();
}

unsigned int Player::getAtkDirSize() {
	if (facing == 1) return slot1->left.size();
	else if (facing == 2) return slot1->right.size();
	else if (facing == 3) return slot1->up.size();
	else return slot1->down.size();
}

void Player::equip(Item* item, unsigned int slot) {
	if (slot == 0) {
		slot0 = item;
	}
	else {
		slot1 = item;
	}
	return;
}

void Player::move() {
	if (Keyboard::isKeyPressed(Keyboard::Left) && (priorMove == 0 || priorMove == 1)) {
		if (!Keyboard::isKeyPressed(Keyboard::Right)) {
			if (Keyboard::isKeyPressed(Keyboard::Up)) {
				loc.second -= moveSpeed;
			}
			if (Keyboard::isKeyPressed(Keyboard::Down)) {
				loc.second += moveSpeed;
			}
			if (priorMove != 1) {
				stepPhase = 0;
				count = animationSpeed;
				priorMove = 1;
			}
			if (count == animationSpeed) {
				stepPhase++;
				if (stepPhase == left.size()) { stepPhase = 0; }
				count = 0;
			}
			else {
				count++;
			}
			state = left[stepPhase];
			loc.first -= moveSpeed;
		}
		facing = 0;
	}

	else if (Keyboard::isKeyPressed(Keyboard::Right) && (priorMove == 0 || priorMove == 2)) {
		if (!Keyboard::isKeyPressed(Keyboard::Left)) {
			if (Keyboard::isKeyPressed(Keyboard::Up)) {
				loc.second -= moveSpeed;
			}
			if (Keyboard::isKeyPressed(Keyboard::Down)) {
				loc.second += moveSpeed;
			}
			if (priorMove != 2) {
				stepPhase = 0;
				count = animationSpeed;
				priorMove = 2;
			}
			if (count == animationSpeed) {
				stepPhase++;
				if (stepPhase == right.size()) { stepPhase = 0; }
				count = 0;
			}
			else {
				count++;
			}
			state = right[stepPhase];
			loc.first += moveSpeed;
		}
		facing = 1;
	}

	else if (Keyboard::isKeyPressed(Keyboard::Up) && (priorMove == 0 || priorMove == 3)) {
		if (!Keyboard::isKeyPressed(Keyboard::Down)) {
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				loc.first -= moveSpeed;
			}
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				loc.first += moveSpeed;
			}
			if (priorMove != 3) {
				stepPhase = 0;
				count = animationSpeed;
				priorMove = 3;
			}
			if (count == animationSpeed) {
				stepPhase++;
				if (stepPhase == up.size()) { stepPhase = 0; }
				count = 0;
			}
			else {
				count++;
			}
			state = up[stepPhase];
			loc.second -= moveSpeed;
		}
		facing = 2;
	}

	else if (Keyboard::isKeyPressed(Keyboard::Down) && (priorMove == 0 || priorMove == 4)) {
		if (!Keyboard::isKeyPressed(Keyboard::Up)) {
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				loc.first -= moveSpeed;
			}
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				loc.first += moveSpeed;
			}
			if (priorMove != 4) {
				stepPhase = 0;
				count = animationSpeed;
				priorMove = 4;
			}
			if (count == animationSpeed) {
				stepPhase++;
				if (stepPhase == down.size()) { stepPhase = 0; }
				count = 0;
			}
			else {
				count++;
			}
			state = down[stepPhase];
			loc.second += moveSpeed;
		}
		facing = 3;
	}
	else {
		stepPhase = 0;
		count = animationSpeed;
		if (facing == 0) {
			state = left[0];
		}
		else if (facing == 1) {
			state = right[0];
		}
		else if (facing == 2) {
			state = up[0];
		}
		else if (facing == 3) {
			state = down[0];
		}
		priorMove = 0;
	}
	
	endAction();
	return;
}

bool Player::attack() {
	if (slot1 == NULL) {
		return false;
	}

	if (facing == 0) {
		slot1->count++;	
		if (slot1->phase == slot1->left.size()) {
			slot1->phase = 0;
			return false;
		}
		state = slot1->left[slot1->phase];
		
		if (slot1->count == slot1->speed) {
			slot1->phase++;
			slot1->count = 0;
		}
		endAction();
		return true;
	}
	else if (facing == 1) {
		slot1->count++;
		if (slot1->phase == slot1->right.size()) {
			slot1->phase = 0;
			return false;
		}
		state = slot1->right[slot1->phase];

		if (slot1->count == slot1->speed) {
			slot1->phase++;
			slot1->count = 0;
		}
		endAction();
		return true;
	}
	else if (facing == 2) {
		slot1->count++;
		if (slot1->phase == slot1->up.size()) {
			slot1->phase = 0;
			return false;
		}
		state = slot1->up[slot1->phase];

		if (slot1->count == slot1->speed) {
			slot1->phase++;
			slot1->count = 0;
		}
		endAction();
		return true;
	}
	else if (facing == 3) {
		slot1->count++;
		if (slot1->phase == slot1->down.size()) {
			slot1->phase = 0;
			return false;
		}
		state = slot1->down[slot1->phase];

		if (slot1->count == slot1->speed) {
			slot1->phase++;
			slot1->count = 0;
		}
		endAction();
		return true;
	}
	return true;
}

void Player::bind() {

	float midW;
	
	for (unsigned int i = 0; i < left.size(); i++) {
		left[i].setTexture(*texture);
		midW = left[i].getGlobalBounds().width / 2;
		if (i == 1 || i == 5) left[i].setOrigin(left[i].getGlobalBounds().width / 2, (left[i].getGlobalBounds().height / 2) + 3.0f);
		else if (i == 2 || i == 6) left[i].setOrigin(left[i].getGlobalBounds().width / 2, (left[i].getGlobalBounds().height / 2) + 2.0f);
		else left[i].setOrigin(left[i].getGlobalBounds().width / 2, left[i].getGlobalBounds().height / 2);
		left[i].scale(3, 3);
	}
	for (unsigned int i = 0; i < right.size(); i++) {
		right[i].setTexture(*texture);
		midW = right[i].getGlobalBounds().width / 2;
		if (i == 1 || i == 5) right[i].setOrigin(right[i].getGlobalBounds().width / 2 , (right[i].getGlobalBounds().height / 2) + 3.0f);
		else if (i == 2 || i == 6) right[i].setOrigin(right[i].getGlobalBounds().width / 2, (right[i].getGlobalBounds().height / 2) + 2.0f);
		else right[i].setOrigin(right[i].getGlobalBounds().width / 2, right[i].getGlobalBounds().height / 2);
		right[i].scale(3, 3);
	}
	for (unsigned int i = 0; i < up.size(); i++) {
		up[i].setTexture(*texture);
		if (i == 1 || i == 5) up[i].setOrigin(up[i].getGlobalBounds().width / 2, (up[i].getGlobalBounds().height / 2) + 2.0f);
		else if (i == 3 || i == 7) up[i].setOrigin(up[i].getGlobalBounds().width / 2, (up[i].getGlobalBounds().height / 2) - 1.0f);
		else up[i].setOrigin(up[i].getGlobalBounds().width / 2, up[i].getGlobalBounds().height / 2);
		up[i].scale(3, 3);
	}
	for (unsigned int i = 0; i < down.size(); i++) {
		down[i].setTexture(*texture);
		if (i == 1 || i == 5) down[i].setOrigin(down[i].getGlobalBounds().width / 2, (down[i].getGlobalBounds().height / 2) + 3.0f);
		else if (i == 2 || i == 6) down[i].setOrigin(down[i].getGlobalBounds().width / 2, (down[i].getGlobalBounds().height / 2) + 4.0f);
		else if (i == 3 || i == 7) down[i].setOrigin(down[i].getGlobalBounds().width / 2, (down[i].getGlobalBounds().height / 2) + 1.0f);
		else down[i].setOrigin(down[i].getGlobalBounds().width / 2, down[i].getGlobalBounds().height / 2);
		down[i].scale(3, 3);
	}
	return;
}

void Player::endAction() {
	state.setPosition(loc.first, loc.second);
	return;
}

#endif