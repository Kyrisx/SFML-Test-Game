#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Sword.h"
#include <iostream>
#include <vector>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

using sf::Drawable;
using sf::Event;
using sf::Transform;
using sf::Keyboard;
using sf::RenderWindow;
using sf::VideoMode;
using sf::RectangleShape;
using sf::Vector2f;
using sf::Color;
using sf::Text;
using sf::Font;

void display(RenderWindow&, vector <Drawable*>&, vector <Drawable*>&);
void stats(Player&, bool, bool);

int main()
{
	RenderWindow window(VideoMode(1280, 720), "Testing Grounds");
	window.setVerticalSyncEnabled(true);

	vector <Drawable*> sBuffer;		// Static Drawables
	vector <Drawable*> dBuffer;		// Dynamic Drawables

	RectangleShape *hud1 = new RectangleShape;
	hud1->setSize(Vector2f((float)window.getSize().x, 1.0f));
	hud1->setFillColor(Color::Green);
	hud1->setOrigin(0, 0);
	hud1->setPosition(0, 100);
	sBuffer.push_back(hud1);

	RectangleShape *hud2 = new RectangleShape;
	hud2->setSize(Vector2f(50.0f, (float)window.getSize().y));
	hud2->setFillColor(Color::Blue);
	hud2->setOrigin(0, 0);
	hud2->setPosition(100, 0);
	sBuffer.push_back(hud2);

	
	/*RectangleShape hud1(Vector2f(90, 75));	
	hud1.setFillColor(Color::Transparent);	
	hud1.setOutlineThickness(10);	
	hud1.setOutlineColor(Color::Blue);	
	hud1.setOrigin(hud1.getLocalBounds().width, 0);
	hud1.setPosition(window.getSize().x / 2.0f, 0);
	sBuffer.push_back(&hud1);

	RectangleShape hud2(Vector2f(90, 75));
	hud2.setFillColor(Color::Transparent);
	hud2.setOutlineThickness(10);
	hud2.setOutlineColor(Color::Blue);
	hud2.setOrigin(0, 0);
	hud2.setPosition(window.getSize().x / 2.0f, 0);
	sBuffer.push_back(&hud2);

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
	sBuffer.push_back(&item1);

	Text item2;
	item2.setFont(font);
	item2.setString("B");
	item2.setCharacterSize(32);
	item2.setColor(Color::Blue);
	item2.setPosition((window.getSize().x / 2.0f) + 10, 0);
	sBuffer.push_back(&item2);*/

	Player link;
	Sword sword;
	link.equip(&sword, 1);

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
				if (event.key.code == Keyboard::P) {
					string sel = "";
					unsigned int alt;
					cout << "Speed change: 'move' - 'anim' - 'atk':\t";
					cin >> sel;
					
					if (sel == "move") {
						cout << "Current: " << link.getMS() << endl;
						cout << "> ";
						cin >> alt;
						link.setMS(alt);
						cout << "Link move speed changed to " << alt << "." << endl;
					}
					else if (sel == "anim") {
						cout << "Current: " << link.getAns() << endl;
						cout << "> ";
						cin >> alt;
						link.setAns(alt);
						cout << "Link animation speed changed to " << alt << "." << endl;
					}
					else if (sel == "atk") {
						cout << "Current: " << sword.speed << endl;
						cout << "> ";
						cin >> alt;
						sword.speed = alt;
						cout << "Link attack speed changed to " << alt << "." << endl;
					}
					else {
						cout << "Invalid parameter" << endl;
					}
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

			RectangleShape *hud3 = new RectangleShape;
			hud3->setSize(Vector2f((float)window.getSize().x, 1.0f));
			hud3->setFillColor(Color::Red);
			hud3->setOrigin(0, 0);
			hud3->setPosition(0, link.y());
			dBuffer.push_back(hud3);

			RectangleShape *hud4 = new RectangleShape;
			hud4->setSize(Vector2f(1.0f, (float)window.getSize().y));
			hud4->setFillColor(Color::Red);
			hud4->setOrigin(0, 0);
			hud4->setPosition(link.x(), 0);
			dBuffer.push_back(hud4);
			
			dBuffer.push_back(link.getState());
			
			Text *item1 = new Text;
			Font font;
			if (!font.loadFromFile("sansation.ttf")) {
				cout << "Could not load font." << endl;
				window.close();
			}
			item1->setFont(font);
			item1->setString(std::to_string(link.y()));
			item1->setCharacterSize(12);
			item1->setColor(Color::White);
			item1->setPosition(10, link.y() + 10.0f);
			dBuffer.push_back(item1);

			Text *item2 = new Text;
			item2->setFont(font);
			item2->setString(std::to_string(link.x()));
			item2->setCharacterSize(12);
			item2->setColor(Color::White);
			item2->setPosition(link.x() + 10.0f, 10);
			dBuffer.push_back(item2);
			
			display(window, sBuffer, dBuffer);

		} // END IF - PAUSED STATE	

		stats(link, pause, isEvent);
	} //END WHILE - WINDOW OPEN

	return 0;

} // END MAIN

void display(RenderWindow &window, vector <Drawable*> &sbuffer, vector <Drawable*> &dbuffer) {
	window.clear();

	while (!dbuffer.empty()) {
		window.draw(*dbuffer.back());
		dbuffer.pop_back();
	}

	for (vector <Drawable*>::iterator it = sbuffer.begin(); it != sbuffer.end(); it++) {
		window.draw(**it);
	}

	window.display();
	return;
}

void stats(Player& c, bool a, bool b) {
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
			while (count < c.slot1->phase * 3) {
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