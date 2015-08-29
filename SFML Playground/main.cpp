#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Load.h"
#include <iostream>
#include <vector>
#include <cstdlib>

using std::cout;
using std::endl;
using std::vector;

using sf::Sprite;
using sf::Texture;
using sf::Drawable;
using sf::Event;
using sf::Transform;
using sf::Keyboard;
using sf::IntRect;
using sf::RenderWindow;
using sf::VideoMode;
using sf::RectangleShape;
using sf::Vector2f;
using sf::Color;
using sf::Text;
using sf::Font;

void display(RenderWindow&, vector <Drawable*>, vector <Drawable*>);
void stats(Character&, bool, bool);

int main()
{
	RenderWindow window(VideoMode(1280, 720), "Testing Grounds");
	window.setVerticalSyncEnabled(true);

	vector <Drawable*> sBuffer;		// Static Drawables
	vector <Drawable*> dBuffer;		// Dynamic Drawables

	/*RectangleShape hud1(Vector2f(90, 75));	
	hud1.setFillColor(Color::Transparent);	
	hud1.setOutlineThickness(10);	
	hud1.setOutlineColor(Color::Blue);	
	hud1.setOrigin(hud1.getLocalBounds().width, 0);
	hud1.setPosition(window.getSize().x / 2.0f, 0);
	sBuffer->push_back(hud1);

	RectangleShape hud2(Vector2f(90, 75));
	hud2.setFillColor(Color::Transparent);
	hud2.setOutlineThickness(10);
	hud2.setOutlineColor(Color::Blue);
	hud2.setOrigin(0, 0);
	hud2.setPosition(window.getSize().x / 2.0f, 0);
	sBuffer->push_back(hud2);

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
	item1.setPosition((window.getSize().x / 2.0f) - 105, 0);
	sBuffer->push_back(item1);

	Text item2;
	item2.setFont(font);
	item2.setString("B");
	item2.setCharacterSize(32);
	item2.setColor(Color::Blue);
	item2.setPosition((window.getSize().x / 2.0f) + 10, 0);
	sBuffer->push_back(item2);*/

	Character link;
	Load l;
	l.load(link);

	bool isEvent = false;
	bool pause = false;

	while (window.isOpen())
	{
		Event event;
		
		while (window.pollEvent(event)) {
			switch (event.type) {

			case Event::Closed:
				window.close();
				break;

			case Event::KeyPressed:
				if (event.key.code == Keyboard::Escape) {
					window.close();
				}
				if (event.key.code == Keyboard::S && !pause) {
					window.setKeyRepeatEnabled(false);
					isEvent = true;
				}
				break;

			case Event::LostFocus:
				pause = true;
				break;

			case Event::GainedFocus:
				pause = false;
				break;		
			
			default:
				break;
			}
		} // END WHILE - EVENT POLL

		if (!pause) {	
			if (isEvent) {
				if (!link.attack()) {
					isEvent = false;
				}	
			}
			if (!isEvent) {
				link.move();
			}
			
			
			dBuffer.push_back();

			display(window, sBuffer, dBuffer);	
		} // END IF - PAUSED STATE	

		stats(link, pause, isEvent);
	} //END WHILE - WINDOW OPEN

	return 0;

} // END MAIN

void display(RenderWindow &window, vector <Drawable*> sbuffer, vector <Drawable*> dbuffer) {
	window.clear();

	for (vector <Drawable*>::iterator it = sbuffer.begin(); it != sbuffer.end(); it++) {
		window.draw(**it);
	}
	
	while (!dbuffer.empty()) {
		window.draw(*dbuffer.back());
		dbuffer.pop_back();
	}

	window.display();
	return;
}

void stats(Character& c, bool a, bool b) {
	system("CLS");
	cout << "Game State: ";
	if (a) {
		cout << "Paused" << endl;
	}
	else cout << "Running" << endl;
	cout << "Location: " << c.x() << ", " << c.y() << endl;
	cout << "Heading: " << c.getPriorMove() << endl;
	cout << "Facing: " << c.getFacing() << endl;
	cout << "Action: ";
	if (c.getPriorMove() == "-")	{
		if (b) {
			cout << "Attacking" << "\t" << "Progress [";
			unsigned int count = 0;
			while (count < c.getAttack.attackPhase * 3) {
				cout << "===";
				count += 3;
			}
			for (unsigned int i = 0; i < c.getAtkDirSize() * 3 - count; i++) {
				cout << " ";
			}
			cout << "]" << endl;
		}
		else { cout << "Standing" << endl; }
	}
	else  {
		cout << "Walking" << endl;
	}
	return;
}