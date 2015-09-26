#include "Animation.h"

void Animation::moveLeft(vector <Sprite> &spriteList, Sprite &state, unsigned int &priorMove, unsigned int &step_phase, unsigned int &count, unsigned int ms, unsigned int ans, pair <float, float>& loc) {
	if (!Keyboard::isKeyPressed(Keyboard::Right)) {
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			loc.second -= ms;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			loc.second += ms;
		}
		if (priorMove != 1) {
			step_phase = 0;
			count = ans;
			priorMove = 1;
		}
		if (count == ans) {
			step_phase++;
			if (step_phase == spriteList.size()) { step_phase = 0; }
			count = 0;
		}
		else { 
			count++; 
		}
		state = spriteList[step_phase];			
		loc.first -= ms;
	}
	return;
}

void Animation::moveRight(vector <Sprite> &spriteList, Sprite &state, unsigned int &priorMove, unsigned int &step_phase, unsigned int &count, unsigned int ms, unsigned int ans, pair <float, float>& loc) {
	if (!Keyboard::isKeyPressed(Keyboard::Left)) {
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			loc.second -= ms;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			loc.second += ms;
		}
		if (priorMove != 2) {
			step_phase = 0;
			count = ans;
			priorMove = 2;
		}
		if (count == ans) {
			step_phase++;
			if (step_phase == spriteList.size()) { step_phase = 0; }
			count = 0;
		}
		else { 
			count++;
		}
		state = spriteList[step_phase];
		loc.first += ms;
	}
	return;
}

void Animation::moveUp(vector <Sprite> &spriteList, Sprite &state, unsigned int &priorMove, unsigned int &step_phase, unsigned int &count, unsigned int ms, unsigned int ans, pair <float, float>& loc) {
	if (!Keyboard::isKeyPressed(Keyboard::Down)) {
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			loc.first -= ms;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			loc.first += ms;
		}
		if (priorMove != 3) {
			step_phase = 0;
			count = ans;
			priorMove = 3;
		}
		if (count == ans) {
			step_phase++;
			if (step_phase == spriteList.size()) { step_phase = 0; }
			count = 0;
		}
		else { 
			count++;
		}
		state = spriteList[step_phase];
		loc.second -= ms;
	}
	return;
}

void Animation::moveDown(vector <Sprite> &spriteList, Sprite &state, unsigned int &priorMove, unsigned int &step_phase, unsigned int &count, unsigned int ms, unsigned int ans, pair <float, float>& loc) {
	if (!Keyboard::isKeyPressed(Keyboard::Up)) {
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			loc.first -= ms;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			loc.first += ms;
		}
		if (priorMove != 4) {
			step_phase = 0;
			count = ans;
			priorMove = 4;
		}
		if (count == ans) {
			step_phase++;
			if (step_phase == spriteList.size()) { step_phase = 0; }
			count = 0;
		}
		else { 
			count++;
		}
		state = spriteList[step_phase];
		loc.second += ms;
	}
	return;
}

void Animation::noMove(vector <Sprite> &spriteList, Sprite &state) {
	state = spriteList[0];
	return;
}

//bool Animation::attack(vector <Sprite> &spriteList, Sprite &state, Character::attackQuery &aq) {
//	aq.attackCount++;
//	
//	if (aq.attackPhase == spriteList.size()) {
//		aq.attackPhase = 0;
//		return false;
//	}
//
//	state = spriteList[aq.attackPhase];
//
//	if (aq.attackCount == aq.attackSpeed) {
//		aq.attackPhase++;
//		aq.attackCount = 0;
//	}
//	return true;	
//}