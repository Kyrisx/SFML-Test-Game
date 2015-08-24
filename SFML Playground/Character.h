#ifndef CHARACTER_H
#define CHARACTER_H

#include "SFML\Graphics.hpp"
#include "Animation.h"
#include <iostream>
#include <memory>

using sf::Sprite;
using sf::Texture;

using std::vector;
using std::pair;
using std::cout;
using std::endl;

class Character
{
private:
	std::unique_ptr<Texture> texture;

	Sprite state;

	unsigned int moveSpeed;	
	unsigned int animationSpeed;
	unsigned int priorMove;
	unsigned int stepPhase;
	unsigned int count;
	unsigned int facing;

	unsigned int attackSpeed;
	unsigned int attackCount;
	unsigned int attackPhase;
	
	pair <float, float> loc;
	float prior_x;
	float prior_y;
	
	vector <Sprite> left;
	vector <Sprite> right;
	vector <Sprite> up;
	vector <Sprite> down;
	vector <Sprite> atkleft;
	vector <Sprite> atkright;
	vector <Sprite> atkup;
	vector <Sprite> atkdown;

	

public:
	Character();
	~Character();

	void addTexture(Texture*);
	Texture* printTexture();

	Sprite getState();
			
	void setMS(unsigned int);
	void setAS(unsigned int);
	void setAns(unsigned int);

	struct attackQuery {		
		unsigned int attackSpeed;
		unsigned int attackCount;
		unsigned int attackPhase;
	};

	attackQuery getAttack;

	void addLeft(vector <Sprite>&);
	void addRight(vector <Sprite>&);
	void addUp(vector <Sprite>&);
	void addDown(vector <Sprite>&);

	void addAtkLeft(vector <Sprite>&);
	void addAtkRight(vector <Sprite>&);
	void addAtkUp(vector <Sprite>&);
	void addAtkDown(vector <Sprite>&);

	void move();
	void attack();
	
};

#endif
