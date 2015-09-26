#ifndef CHARACTER_H
#define CHARACTER_H

#include "SFML\Graphics.hpp"
#include <memory>

using sf::Sprite;
using sf::Texture;

using std::vector;
using std::pair;

class Character
{
protected:
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

public:
	void addTexture(Texture*);
	Texture* printTexture();

	Sprite* getState();
			
	void setMS(unsigned int);
	void setAns(unsigned int);
	unsigned int getMS();
	unsigned int getAns();

	float getPlane();

	void addLeft(vector <Sprite>&);
	void addRight(vector <Sprite>&);
	void addUp(vector <Sprite>&);
	void addDown(vector <Sprite>&);

	virtual void move() = 0;
	virtual bool attack() = 0;

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
