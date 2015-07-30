#ifndef ANIMATION_H
#define ANIMATION_H

#include "SFML\Graphics.hpp"
#include "Character.h"

using sf::Sprite;

class Animation
{

private:
	
	
public:
	void moveLeft(vector <Sprite> LSprites, unsigned int &d, );
	
};

void Animation::moveLeft() {
	if (c.getDirection != 2) {
		if (c.getDirection != 3 && c.getDirection != 4) {
			if (c.getDirection != 1) {
				step_phase = 0;
				count = SPEED;
				direction = 1;
			}
			if (count == SPEED) {
				step_phase++;
				if (step_phase == 7) { step_phase = 1; }
				count = 0;
			}
			else { count++; }
			state = wl[step_phase];
			facing = 1;
		}
		position_x += -STEP;
		madeMove = true;
	}
}



#endif