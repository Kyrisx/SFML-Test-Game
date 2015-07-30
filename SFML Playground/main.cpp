#include <SFML/Graphics.hpp>
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

	Texture char_link;
	if (!char_link.loadFromFile("spritesheet.png")) {
		cout << "Couldn't open sprite file" << endl;
		window.close();
	}
	
	// Animations
	Sprite wl0, wl1, wl2, wl3, wl4, wl5, wl6;
	Sprite wr0, wr1, wr2, wr3, wr4, wr5, wr6;
	Sprite wu0, wu1, wu2, wu3, wu4, wu5, wu6, wu7, wu8;
	Sprite wd0, wd1, wd2, wd3, wd4, wd5, wd6, wd7, wd8;
	Sprite sl0, sl1, sl2, sl3, sl4;
	Sprite sr0, sr1, sr2, sr3, sr4;
	Sprite su0, su1, su2, su3, su4;
	Sprite sd0, sd1, sd2, sd3, sd4, sd5;


	wl0.setTextureRect(IntRect(656, 9, 82, 100));
	wl1.setTextureRect(IntRect(1047, 139, 82, 104));
	wl2.setTextureRect(IntRect(1182, 139, 79, 104));
	wl3.setTextureRect(IntRect(1308, 139, 82, 100));
	wl4.setTextureRect(IntRect(1438, 139, 82, 100));
	wl5.setTextureRect(IntRect(1568, 139, 83, 104));
	wl6.setTextureRect(IntRect(1703, 139, 78, 104));
	wr0.setTextureRect(IntRect(911, 404, 82, 100));
	wr1.setTextureRect(IntRect(1047, 530, 82, 104));
	wr2.setTextureRect(IntRect(1182, 530, 78, 104));
	wr3.setTextureRect(IntRect(1308, 530, 82, 100));
	wr4.setTextureRect(IntRect(1438, 530, 82, 100));
	wr5.setTextureRect(IntRect(1568, 530, 83, 104));
	wr6.setTextureRect(IntRect(1703, 530, 78, 104));
	wu0.setTextureRect(IntRect(400, 534, 73, 96));
	wu1.setTextureRect(IntRect(9, 530, 74, 100));
	wu2.setTextureRect(IntRect(139, 530, 74, 104));
	wu3.setTextureRect(IntRect(269, 534, 74, 96));
	wu4.setTextureRect(IntRect(400, 534, 73, 96));
	wu5.setTextureRect(IntRect(530, 530, 74, 100));
	wu6.setTextureRect(IntRect(660, 530, 74, 104));
	wu7.setTextureRect(IntRect(791, 534, 73, 96));
	wu8.setTextureRect(IntRect(921, 534, 74, 96));
	wd0.setTextureRect(IntRect(143, 13, 70, 96));
	wd1.setTextureRect(IntRect(13, 143, 70, 96));
	wd2.setTextureRect(IntRect(143, 143, 70, 96));
	wd3.setTextureRect(IntRect(274, 139, 69, 100));
	wd4.setTextureRect(IntRect(404, 139, 69, 104));
	wd5.setTextureRect(IntRect(534, 143, 70, 96));
	wd6.setTextureRect(IntRect(665, 139, 69, 100));
	wd7.setTextureRect(IntRect(795, 139, 69, 100));
	wd8.setTextureRect(IntRect(925, 139, 70, 104));

	sl0.setTextureRect(IntRect(1051, 400, 78, 100));
	sl1.setTextureRect(IntRect(1164, 400, 113, 104));
	sl2.setTextureRect(IntRect(1281, 404, 135, 91));
	sl3.setTextureRect(IntRect(1420, 404, 122, 91));
	sl4.setTextureRect(IntRect(1559, 382, 100, 135));
	
	sr0.setTextureRect(IntRect(1051, 795, 78, 95));
	sr1.setTextureRect(IntRect(1164, 799, 113, 96));
	sr2.setTextureRect(IntRect(1281, 795, 135, 91));
	sr3.setTextureRect(IntRect(1420, 795, 122, 91));
	sr4.setTextureRect(IntRect(1559, 773, 100, 135));
	
	su0.setTextureRect(IntRect(0, 795, 83, 95));
	su1.setTextureRect(IntRect(130, 778, 96, 130));
	su2.setTextureRect(IntRect(265, 764, 87, 152));
	su3.setTextureRect(IntRect(387, 778, 104, 130));
	su4.setTextureRect(IntRect(500, 791, 139, 99));
	
	sd0.setTextureRect(IntRect(4, 400, 87, 100));
	sd1.setTextureRect(IntRect(130, 400, 96, 104));
	sd2.setTextureRect(IntRect(265, 382, 87, 135));
	sd3.setTextureRect(IntRect(395, 382, 87, 135));
	sd4.setTextureRect(IntRect(500, 387, 121, 126));
	sd5.setTextureRect(IntRect(630, 391, 139, 117));

	Sprite wl[] = { wl0, wl1, wl2, wl3, wl4, wl5, wl6 };
	Sprite wr[] = { wr0, wr1, wr2, wr3, wr4, wr5, wr6 };
	Sprite wu[] = { wu0, wu1, wu2, wu3, wu4, wu5, wu6, wu7, wu8 };
	Sprite wd[] = { wd0, wd1, wd2, wd3, wd4, wd5, wd6, wd7, wd8 };
	Sprite sl[] = { sl0, sl1, sl2, sl3, sl4 };
	Sprite sr[] = { sr0, sr1, sr2, sr3, sr4 };
	Sprite su[] = { su0, su1, su2, su3, su4 };
	Sprite sd[] = { sd0, sd1, sd2, sd3, sd4, sd5 };

	for (unsigned int i = 0; i < 7; i++) {
		wl[i].setTexture(char_link);
		wl[i].setOrigin(wl[i].getLocalBounds().width, wl[i].getLocalBounds().height);
		wr[i].setTexture(char_link);
		wr[i].setOrigin(wr[i].getLocalBounds().width, wr[i].getLocalBounds().height);
	}
	for (unsigned int i = 0; i < 9; i++) {
		wu[i].setTexture(char_link);
		wu[i].setOrigin(wu[i].getLocalBounds().width, wu[i].getLocalBounds().height);
		wd[i].setTexture(char_link);
		wd[i].setOrigin(wd[i].getLocalBounds().width, wd[i].getLocalBounds().height);
	}
	for (unsigned int i = 0; i < 5; i++) {
		sl[i].setTexture(char_link);
		sl[i].setOrigin(sl[i].getLocalBounds().width, min(sl[i].getLocalBounds().height, wl[0].getLocalBounds().height));
		sr[i].setTexture(char_link);
		sr[i].setOrigin(min(sr[i].getLocalBounds().width, wr[0].getLocalBounds().width), min(sr[i].getLocalBounds().height, wr[0].getLocalBounds().height));
		su[i].setTexture(char_link);
		su[i].setOrigin(max(su[i].getLocalBounds().width, wu[0].getLocalBounds().width), su[i].getLocalBounds().height);
	}
	for (unsigned int i = 0; i < 6; i++) {
		sd[i].setTexture(char_link);
		sd[i].setOrigin(min(sd[i].getLocalBounds().width, wd[0].getLocalBounds().width), wd[0].getLocalBounds().height);
	}

	/*
		DIRECTION
		0 : Not Moving
		1 : WEST
		2 : EAST
		3 : NORTH
		4 : SOUTH		
	*/

	unsigned int count = SPEED;
	float position_x = 0.0;
	float position_y = 0.0;
	float previousPosition_x = 0.0;
	float previousPosition_y = 0.0;

	unsigned int step_phase = 0;
	Sprite state = wr[step_phase];
	unsigned int direction = 0;
	unsigned int facing = 1;

	bool swingSword = false;
	unsigned int swingSpeed = 0;
	unsigned int swingCount = 0;

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
				if (event.key.code == Keyboard::S) {
					isEvent = true;
					window.setKeyRepeatEnabled(false);	
					swingSword = true;				
				}
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
			if (!Keyboard::isKeyPressed(Keyboard::Left) && direction == 1) { direction = 0; }
			if (!Keyboard::isKeyPressed(Keyboard::Right) && direction == 2) { direction = 0; }
			if (!Keyboard::isKeyPressed(Keyboard::Up) && direction == 3) { direction = 0; }
			if (!Keyboard::isKeyPressed(Keyboard::Down) && direction == 4) { direction = 0; }

			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				
			}

			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				if (direction != 1) {
					if (direction != 3 && direction != 4) {
						if (direction != 2) {
							step_phase = 0;
							count = SPEED;
							direction = 2;
						}
						if (count == SPEED) {
							step_phase++;
							if (step_phase == 7) { step_phase = 1; }
							count = 0;
						}
						else { count++; }
						state = wr[step_phase];
						facing = 2;
					}
					position_x += STEP;
					madeMove = true;
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::Up)) {
				if (direction != 4) {
					if (direction != 1 && direction != 2) {
						if (direction != 3) {
							step_phase = 0;
							count = SPEED;
							direction = 3;
						}
						if (count == SPEED) {
							step_phase++;
							if (step_phase == 9) { step_phase = 1; }
							count = 0;
						}
						else { count++; }
						state = wu[step_phase];
						facing = 3;
					}
					position_y += -STEP;
					madeMove = true;
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::Down)) {
				if (direction != 3) {
					if (direction != 1 && direction != 2) {
						if (direction != 4) {
							step_phase = 0;
							count = SPEED;
							direction = 4;
						}
						if (count == SPEED) {
							step_phase++;
							if (step_phase == 9) { step_phase = 1; }
							state = wd[step_phase];
							count = 0;
						}
						else { count++; }
						state = wd[step_phase];
						facing = 4;
					}
					position_y += STEP;
					madeMove = true;
				}
			}

			if (!madeMove) {
				step_phase = 0;
				count = SPEED;
				if (facing == 1) { state = wl[step_phase]; }
				else if (facing == 2) { state = wr[step_phase]; }
				else if (facing == 3) { state = wu[step_phase]; }
				else { state = wd[step_phase]; }
				direction = 0;
			}

			if (swingSword) {
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
				}		
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
	
