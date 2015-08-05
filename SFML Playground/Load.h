#ifndef LOAD_H
#define LOAD_H

#include "Character.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using std::vector;



using std::cout;
using std::endl;
using std::min;
using std::max;

using sf::Sprite;
using sf::Texture;
using sf::IntRect;



class Load
{
private:

public:
	void loadit(Character&);
};

#endif