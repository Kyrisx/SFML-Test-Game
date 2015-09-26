#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include "SFML\Graphics.hpp"

class Weapon : public Item
{
protected:	
	double damage;
	
public:
	double getDamage();
	//void use();
};

double Weapon::getDamage() {
	return damage;
}

#endif