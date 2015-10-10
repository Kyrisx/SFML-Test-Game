#ifndef ITEM_H
#define ITEM_H

#include "SFML\Graphics.hpp"
#include <vector>
#include <memory>

using sf::Texture;
using std::vector;

class Item 
{
protected:

	std::unique_ptr<Texture> texture;

public:

	unsigned int ID;
	unsigned int speed;
	unsigned int count;
	unsigned int phase;

	vector <Sprite> left;
	vector <Sprite> right;
	vector <Sprite> up;
	vector <Sprite> down;

	//virtual void use() = 0;
};
	
#endif