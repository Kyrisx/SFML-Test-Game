#ifndef SWORD_H
#define SWORD_H

#include "Weapon.h"

class Sword: public Weapon {

public:
	Sword();
};

Sword::Sword() {
	ID = 0;
	damage = 1.0;
	speed = 3;

	this->loadHelper(Asl0, 184, 67, 19, 26);
	loadHelper(Asl1, 216, 70, 26, 23);
	loadHelper(Asl2, 247, 70, 33, 23);
	loadHelper(Asl3, 283, 71, 34, 22);
	loadHelper(Asl4, 324, 71, 30, 23);
	loadHelper(Asl5, 371, 70, 23, 30);
	loadHelper(Asl6, 417, 70, 17, 31);

	loadHelper(Asu0, 183, 22, 25, 24);
	loadHelper(Asu1, 221, 22, 23, 25);
	loadHelper(Asu2, 256, 15, 22, 32);
	loadHelper(Asu3, 294, 11, 18, 36);
	loadHelper(Asu4, 329, 15, 22, 32);
	loadHelper(Asu5, 363, 22, 29, 25);
	loadHelper(Asu6, 401, 23, 33, 24);

	loadHelper(Asd0, 178, 115, 26, 25);
	loadHelper(Asd1, 220, 114, 22, 31);
	loadHelper(Asd2, 257, 112, 19, 38);
	loadHelper(Asd3, 296, 112, 18, 41);
	loadHelper(Asd4, 335, 114, 23, 37);
	loadHelper(Asd5, 374, 117, 29, 31);
	loadHelper(Asd6, 414, 117, 32, 24);
}



#endif