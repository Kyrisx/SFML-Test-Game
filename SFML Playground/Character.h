#ifndef CHARACTER_H
#define CHARACTER_H

#include "SFML\Graphics.hpp"
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
	
	pair <float, float> loc;
	float prior_x;
	float prior_y;
	
	vector <Sprite> left;
	vector <Sprite> right;
	vector <Sprite> up;
	vector <Sprite> down;
	vector <Sprite> atkLeft;
	vector <Sprite> atkRight;
	vector <Sprite> atkUp;
	vector <Sprite> atkDown;

public:
	Character();
	~Character();

	void addTexture(Texture*);
	Texture* printTexture();

	Sprite getState();
			
	void setMS(unsigned int ms);
	void setAns(unsigned int);

	void addLeft(vector <Sprite>&);
	void addRight(vector <Sprite>&);
	void addUp(vector <Sprite>&);
	void addDown(vector <Sprite>&);

	void addAtkLeft(vector <Sprite>&);
	void addAtkRight(vector <Sprite>&);
	void addAtkUp(vector <Sprite>&);
	void addAtkDown(vector <Sprite>&);

	void move();
	bool attack();

	struct attackQuery {
		unsigned int attackSpeed;
		unsigned int attackCount;
		unsigned int attackPhase;
	};

	attackQuery getAttack;

	// STATISTICS INFO //////
	char* getPriorMove();
	char* getFacing();
	unsigned int getStepPhase();
	float x();
	float y();
	unsigned int getAtkDirSize();
	/////////////////////////
	
};

#endif
