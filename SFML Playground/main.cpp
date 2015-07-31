#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Load.h"
#include <iostream>

using std::cout;
using std::endl;
using sf::Sprite;
using sf::Texture;
using sf::RenderWindow;
using sf::Event;
using sf::Transform;
using sf::Keyboard;
using sf::IntRect;
using sf::VideoMode;
using sf::RectangleShape;
using sf::Vector2f;
using sf::Color;
using sf::Text;
using sf::Font;
using std::min;
using std::max;



#define SPEED 7			// Animation speed. Higher is slower
#define STEP 5			// Movement speed. Higher is faster
#define SWORD_SPEED 3	// Sword swing speed. Higher is slower

int main()
{
	RenderWindow window(VideoMode(1280, 720), "Link Testing Grounds");
	window.setVerticalSyncEnabled(true);

	RectangleShape hud1(Vector2f(90, 75));	
	hud1.setFillColor(Color::Transparent);	
	hud1.setOutlineThickness(10);	
	hud1.setOutlineColor(Color::Blue);	
	hud1.setOrigin(hud1.getLocalBounds().width, 0);
	hud1.setPosition(window.getSize().x / 2, 0);


	RectangleShape hud2(Vector2f(90, 75));
	hud2.setFillColor(Color::Transparent);
	hud2.setOutlineThickness(10);
	hud2.setOutlineColor(Color::Blue);
	hud2.setOrigin(0, 0);
	hud2.setPosition(window.getSize().x / 2, 0);

	Text item1;
	Font font;
	if (!font.loadFromFile("sansation.ttf")) {
		cout << "Could not load font." << endl;
		window.close();
	}
	item1.setFont(font);
	item1.setString("A");
	item1.setCharacterSize(32);
	item1.setColor(Color::Blue);
	item1.setPosition((window.getSize().x / 2) - 105, 0);

	Text item2;
	item2.setFont(font);
	item2.setString("B");
	item2.setCharacterSize(32);
	item2.setColor(Color::Blue);
	item2.setPosition((window.getSize().x / 2) + 10, 0);
	
	// Animations

	//Sprite sl[] = { sl0, sl1, sl2, sl3, sl4 };
	//Sprite sr[] = { sr0, sr1, sr2, sr3, sr4 };
	//Sprite su[] = { su0, su1, su2, su3, su4 };
	//Sprite sd[] = { sd0, sd1, sd2, sd3, sd4, sd5 };

	//for (unsigned int i = 0; i < 5; i++) {
	//	sl[i].setTexture(char_link);
	//	sl[i].setOrigin(sl[i].getLocalBounds().width, min(sl[i].getLocalBounds().height, wl[0].getLocalBounds().height));
	//	sr[i].setTexture(char_link);
	//	sr[i].setOrigin(min(sr[i].getLocalBounds().width, wr[0].getLocalBounds().width), min(sr[i].getLocalBounds().height, wr[0].getLocalBounds().height));
	//	su[i].setTexture(char_link);
	//	su[i].setOrigin(max(su[i].getLocalBounds().width, wu[0].getLocalBounds().width), su[i].getLocalBounds().height);
	//}
	//for (unsigned int i = 0; i < 6; i++) {
	//	sd[i].setTexture(char_link);
	//	sd[i].setOrigin(min(sd[i].getLocalBounds().width, wd[0].getLocalBounds().width), wd[0].getLocalBounds().height);
	//}

	/*
		DIRECTION
		0 : Not Moving
		1 : WEST
		2 : EAST
		3 : NORTH
		4 : SOUTH		
	*/

	
	//unsigned int facing = 1;

	/*bool swingSword = false;
	unsigned int swingSpeed = 0;
	unsigned int swingCount = 0;*/

	load();

	bool pause = false;

	while (window.isOpen())
	{
		Event event;
		bool isEvent = false;
		
		while (window.pollEvent(event)) {
			switch (event.type) {

			case Event::Closed:
				isEvent = true;
				window.close();
				break;

			case Event::KeyPressed:
				if (event.key.code == Keyboard::Escape) {
					isEvent = true;
					window.close();
				}
				/*if (event.key.code == Keyboard::S) {
					isEvent = true;
					window.setKeyRepeatEnabled(false);	
					swingSword = true;				
				}*/
				break;

			case Event::LostFocus:
				pause = true;
				cout << endl << "-----------------------PAUSED-----------------------" << endl;
				break;

			case Event::GainedFocus:
				pause = false;
				cout << endl << "----------------------UNPAUSED----------------------" << endl;
				break;		
			
			default:
				break;
			}
		} // END WHILE - EVENT POLL

		bool madeMove = false;

		if (!pause) {
		/*	if (!Keyboard::isKeyPressed(Keyboard::Left) && direction == 1) { direction = 0; }
			if (!Keyboard::isKeyPressed(Keyboard::Right) && direction == 2) { direction = 0; }
			if (!Keyboard::isKeyPressed(Keyboard::Up) && direction == 3) { direction = 0; }
			if (!Keyboard::isKeyPressed(Keyboard::Down) && direction == 4) { direction = 0; }*/

			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				
			}

			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				
			}

			if (Keyboard::isKeyPressed(Keyboard::Up)) {
				
			}

			if (Keyboard::isKeyPressed(Keyboard::Down)) {
				
			}

			if (!madeMove) {
				
			}

			/*if (swingSword) {
				swingSpeed++;
				if (facing == 1) {
					if (swingCount == 5 || swingCount == 6) {
						swingSword = false;
						swingCount = 0;
					}
					state = sl[swingCount];
					if (swingSpeed == SWORD_SPEED) {
						cout << "Left swing count: " << swingCount << endl;
						swingCount++;
						swingSpeed = 0;
					}
				}
				else if (facing == 2) {
					if (swingCount == 5 || swingCount == 6) {
						swingSword = false;
						swingCount = 0;
					}
					state = sr[swingCount];
					if (swingSpeed == SWORD_SPEED) {
						cout << "Right swing count: " << swingCount << endl;
						swingCount++;
						swingSpeed = 0;
					}
				}
				else if (facing == 3) {			
					if (swingCount == 5 || swingCount == 6) {
						swingSword = false;
						swingCount = 0;
					}
					state = su[swingCount];
					if (swingSpeed == SWORD_SPEED) {
						cout << "Up swing count: " << swingCount << endl;
						swingCount++;
						swingSpeed = 0;
					}	
				}
				else {
					if (swingCount == 6) {
						swingSword = false;
						swingCount = 0;
					}
					state = sd[swingCount];
					if (swingSpeed == SWORD_SPEED) {
						cout << "Down swing count: " << swingCount << endl;
						swingCount++;
						swingSpeed = 0;
					}
				}	*/	
			}
			state.move(position_x, position_y);
		} // END IF - PAUSED STATE

		
		window.clear();	
		window.draw(state);
		window.draw(hud1);
		window.draw(hud2);
		window.draw(item1);
		window.draw(item2);
		window.display();

		if (previousPosition_x != state.getPosition().x || previousPosition_y != state.getPosition().y) {
			cout << state.getPosition().x << ", " << state.getPosition().y << "\t";
			if (facing == 1) { cout << "left" << endl; }
			else if (facing == 2) { cout << "right" << endl; }
			else if (facing == 3) { cout << "up" << endl; }
			else if (facing == 4) { cout << "down" << endl; }
			previousPosition_x = state.getPosition().x;
			previousPosition_y = state.getPosition().y;
		}
	} //END WHILE - WINDOW OPEN
	return 0;
} // END MAIN

//void swordSwing(int facing, Sprite sl[]) {
//
//}
	
