#include "Animation.h"

void Animation::moveLeft(vector <Sprite> &spriteList, Sprite &state, unsigned int &priorMove, unsigned int &step_phase, unsigned int &count, unsigned int ms, unsigned int ans, float &x, bool &madeMove) {
	if (!Keyboard::isKeyPressed(Keyboard::Right)) {
		if (!Keyboard::isKeyPressed(Keyboard::Up) && !Keyboard::isKeyPressed(Keyboard::Down)) {
			if (priorMove != 1) {
				step_phase = 0;
				count = ans;
				priorMove = 1;
			}
			if (count == ans) {
				step_phase++;
				if (step_phase > spriteList.size()) { step_phase = 1; }
				count = 0;
			}
			else { count++; }
			state = spriteList[step_phase];
			//facing = 1;
		}
		signed int displacement = ms;
		x += -displacement;
		madeMove = true;
	}
	return;
}

void Animation::moveRight(vector <Sprite> &spriteList, Sprite &state, unsigned int &priorMove, unsigned int &step_phase, unsigned int &count, unsigned int ms, unsigned int ans, float &x, bool &madeMove) {
	if (!Keyboard::isKeyPressed(Keyboard::Left)) {
		if (!Keyboard::isKeyPressed(Keyboard::Up) && !Keyboard::isKeyPressed(Keyboard::Down)) {
			if (priorMove != 2) {
				step_phase = 0;
				count = ans;
				priorMove = 2;
			}
			if (count == ans) {
				step_phase++;
				if (step_phase > spriteList.size()) { step_phase = 1; }
				count = 0;
			}
			else { count++; }
			state = spriteList[step_phase];
			//facing = 2;
		}
		signed int displacement = ms;
		x += displacement;
		madeMove = true;
	}
	return;
}

void Animation::moveUp(vector <Sprite> &spriteList, Sprite &state, unsigned int &priorMove, unsigned int &step_phase, unsigned int &count, unsigned int ms, unsigned int ans, float &y, bool &madeMove) {
	if (!Keyboard::isKeyPressed(Keyboard::Down)) {
		if (!Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Right)) {
			if (priorMove != 3) {
				step_phase = 0;
				count = ans;
				priorMove = 3;
			}
			if (count == ans) {
				step_phase++;
				if (step_phase > spriteList.size()) { step_phase = 1; }
				count = 0;
			}
			else { count++; }
			state = spriteList[step_phase];
			//facing = 3;
		}
		signed int displacement = ms;
		y += -displacement;
		madeMove = true;
	}
	return;
}

void Animation::moveDown(vector <Sprite> &spriteList, Sprite &state, unsigned int &priorMove, unsigned int &step_phase, unsigned int &count, unsigned int ms, unsigned int ans, float &y, bool &madeMove) {
	if (!Keyboard::isKeyPressed(Keyboard::Up)) {
		if (!Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Right)) {
			if (priorMove != 4) {
				step_phase = 0;
				count = ans;
				priorMove = 4;
			}
			if (count == ans) {
				step_phase++;
				if (step_phase > spriteList.size()) { step_phase = 1; }
				count = 0;
			}
			else { count++; }
			state = spriteList[step_phase];
			//facing = 4;
		}
		signed int displacement = ms;
		y += displacement;
		madeMove = true;
	}
	return;
}