#include "Character.h"

void Character::addTexture(Texture* t) { texture = std::unique_ptr<Texture>(t); }
Texture* Character::printTexture() { return texture.get(); }

Sprite* Character::getState() { return &state; }

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
	if (facing == 0) return "West";
	else if (facing == 1) return "East";
	else if (facing == 2) return "North";
	else return "South";
}

unsigned int Character::getStepPhase() { return stepPhase; }

float Character::x() { return loc.first; }
float Character::y() { return loc.second; }