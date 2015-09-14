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

	unsigned int weapon1, weapon2;

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

public:
	Character();
	~Character();

	void addTexture(Texture*);
	Texture* printTexture();

	Sprite* getState();

	void setW1();
	void setW2();
	unsigned int getW1;
	unsigned int getW2;
			
	void setMS(unsigned int);
	void setAns(unsigned int);
	unsigned int getMS();
	unsigned int getAns();

	float getPlane();

	void addLeft(vector <Sprite>&);
	void addRight(vector <Sprite>&);
	void addUp(vector <Sprite>&);
	void addDown(vector <Sprite>&);

	void move();
	bool attack();

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
