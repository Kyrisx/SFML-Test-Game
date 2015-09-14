#include "Load.h"

/* Character Reference

A	:	Link

*/

// A	Link

void loadHelper(Sprite&, int, int, int, int);
void bindMovement(vector <vector<Sprite>>&, Texture*);
void bindAttack(vector <vector<Sprite>>&, vector <vector<Sprite>>&, Texture*);

void Load::load(Character& link)
{
	Texture* t = new Texture;
	if (!t->loadFromFile("link.png")) {
		cout << "Couldn't open sprite file" << endl;
		return;
	}
	link.addTexture(t);
			
	Sprite Awl0, Awl1, Awl2, Awl3, Awl4, Awl5, Awl6, Awl7;
	Sprite Awr0, Awr1, Awr2, Awr3, Awr4, Awr5, Awr6, Awr7;
	Sprite Awu0, Awu1, Awu2, Awu3, Awu4, Awu5, Awu6, Awu7;
	Sprite Awd0, Awd1, Awd2, Awd3, Awd4, Awd5, Awd6, Awd7;
	Sprite Asl0, Asl1, Asl2, Asl3, Asl4, Asl5, Asl6;
	Sprite Asr0, Asr1, Asr2, Asr3, Asr4, Asr5, Asr6;
	Sprite Asu0, Asu1, Asu2, Asu3, Asu4, Asu5, Asu6;
	Sprite Asd0, Asd1, Asd2, Asd3, Asd4, Asd5, Asd6;

	loadHelper(Awl0, 4, 70, 19, 23);
	loadHelper(Awl1, 7, 216, 19, 23);
	loadHelper(Awl2, 38, 217, 23, 22);
	loadHelper(Awl3, 70, 217, 24, 22);
	loadHelper(Awl4, 4, 70, 19, 23);
	loadHelper(Awl5, 104, 216, 19, 23);
	loadHelper(Awl6, 133, 217, 23, 22);
	loadHelper(Awl7, 171, 217, 24, 22);
	
	loadHelper(Awu0, 4, 23, 18, 23);
	loadHelper(Awu1, 9, 187, 18, 24);
	loadHelper(Awu2, 40, 184, 18, 27);
	loadHelper(Awu3, 73, 186, 18, 25);
	loadHelper(Awu4, 3, 23, 18, 23);
	loadHelper(Awu5, 105, 187, 18, 24);
	loadHelper(Awu6, 137, 184, 18, 27);
	loadHelper(Awu7, 173, 186, 18, 25);
	
	loadHelper(Awd0, 5, 116, 18, 26);
	loadHelper(Awd1, 7, 245, 18, 29);
	loadHelper(Awd2, 38, 243, 18, 28);
	loadHelper(Awd3, 68, 246, 18, 25);
	loadHelper(Awd4, 4, 116, 18, 26);
	loadHelper(Awd5, 102, 246, 18, 29);
	loadHelper(Awd6, 134, 245, 18, 28);
	loadHelper(Awd7, 171, 248, 18, 25);

	loadHelper(Asl0, 184, 67, 19, 26);
	loadHelper(Asl1, 216, 70, 26, 23);
	loadHelper(Asl2, 247, 70, 33, 23);
	loadHelper(Asl3, 283, 71, 34, 22);
	loadHelper(Asl4, 324, 71, 30, 23);
	loadHelper(Asl5, 371, 70, 23, 30);
	loadHelper(Asl6, 417, 70, 17, 31);
	
	loadHelper(Asu0, 183, 22, 25, 24);
	loadHelper(Asu1, 221, 22, 23, 25);
	loadHelper(Asu2, 256, 15, 22, 32);
	loadHelper(Asu3, 294, 11, 18, 36);
	loadHelper(Asu4, 329, 15, 22, 32);
	loadHelper(Asu5, 363, 22, 29, 25);
	loadHelper(Asu6, 401, 23, 33, 24);

	loadHelper(Asd0, 178, 115, 26, 25);
	loadHelper(Asd1, 220, 114, 22, 31);
	loadHelper(Asd2, 257, 112, 19, 38);
	loadHelper(Asd3, 296, 112, 18, 41);
	loadHelper(Asd4, 335, 114, 23, 37);
	loadHelper(Asd5, 374, 117, 29, 31);
	loadHelper(Asd6, 414, 117, 32, 24);

	vector <Sprite> Awl = { Awl0, Awl1, Awl2, Awl3, Awl4, Awl5, Awl6, Awl7 };
	vector <Sprite> Awr = { Awr0, Awr1, Awr2, Awr3, Awr4, Awr5, Awr6, Awr7 };
	vector <Sprite> Awu = { Awu0, Awu1, Awu2, Awu3, Awu4, Awu5, Awu6, Awu7 };
	vector <Sprite> Awd = { Awd0, Awd1, Awd2, Awd3, Awd4, Awd5, Awd6, Awd7 };
	vector <Sprite> Asl = { Asl0, Asl1, Asl2, Asl3, Asl4, Asl5, Asl6 };
	vector <Sprite> Asr = { Asr0, Asr1, Asr2, Asr3, Asr4, Asr5, Asr6 };
	vector <Sprite> Asu = { Asu0, Asu1, Asu2, Asu3, Asu4, Asu5, Asu6 };
	vector <Sprite> Asd = { Asd0, Asd1, Asd2, Asd3, Asd4, Asd5, Asd6 };

	for (unsigned int i = 0; i < Awr.size(); i++) {
		Awr[i] = Awl[i];
		Awr[i].setScale(-1, 1);
	}
	for (unsigned int i = 0; i < Asr.size(); i++) {
		Asr[i] = Asl[i];
		Asr[i].setScale(-1, 1);
	}

	vector <vector<Sprite>> movement = { Awl, Awr, Awu, Awd };
	vector <vector<Sprite>> attack = { Asl, Asr, Asu, Asd };

	bindMovement(movement, link.printTexture());
	bindAttack(attack, movement, link.printTexture());

	link.addLeft(movement[0]);
	link.addRight(movement[1]);
	link.addUp(movement[2]);
	link.addDown(movement[3]);

	link.addAtkLeft(attack[0]);
	link.addAtkRight(attack[1]);
	link.addAtkUp(attack[2]);
	link.addAtkDown(attack[3]);

	link.setMS(5);
	link.setAns(2);
	link.getAttack.attackSpeed = 70;

	if (link.getMS() == 0 || link.getAns() == 0) { cout << "WARNING: Essential Character Speed Variable is 0" << endl; }
	return;
}

void loadHelper(Sprite &s, int left, int top, int width, int height) {
	s.setTextureRect(IntRect(left, top, width, height));
	return;
}

void bindMovement(vector <vector<Sprite>> &vec, Texture* t) {
	for (unsigned int i = 0; i < vec[0].size(); i++) {
		vec[0][i].setTexture(*t);
		if (i == 1 || i == 5) vec[0][i].setOrigin(vec[0][i].getLocalBounds().width / 2, (vec[0][i].getLocalBounds().height / 2) + 3.0f);
		else if (i == 2 || i == 6) vec[0][i].setOrigin(vec[0][i].getLocalBounds().width / 2, (vec[0][i].getLocalBounds().height / 2) + 2.0f);
		else vec[0][i].setOrigin(vec[0][i].getLocalBounds().width / 2, vec[0][i].getLocalBounds().height / 2);
		vec[0][i].scale(3, 3);
	}
	for (unsigned int i = 0; i < vec[1].size(); i++) {
		vec[1][i].setTexture(*t);
		if (i == 1 || i == 5) vec[1][i].setOrigin(vec[1][i].getLocalBounds().width / 2, (vec[1][i].getLocalBounds().height / 2) + 3.0f);
		else if (i == 2 || i == 6) vec[1][i].setOrigin(vec[1][i].getLocalBounds().width / 2, (vec[1][i].getLocalBounds().height / 2) + 2.0f);
		else vec[1][i].setOrigin(vec[1][i].getLocalBounds().width / 2, vec[1][i].getLocalBounds().height / 2);
		//vec[1][i].scale(3, 3);
	}
	for (unsigned int i = 0; i < vec[2].size(); i++) {
		vec[2][i].setTexture(*t);
		if (i == 1 || i == 5) vec[2][i].setOrigin(vec[2][i].getLocalBounds().width / 2, (vec[2][i].getLocalBounds().height / 2) + 2.0f);
		else if (i == 3 || i == 7) vec[2][i].setOrigin(vec[2][i].getLocalBounds().width / 2, (vec[2][i].getLocalBounds().height / 2) - 1.0f);
		else vec[2][i].setOrigin(vec[2][i].getLocalBounds().width / 2, vec[2][i].getLocalBounds().height / 2);
		//vec[2][i].scale(3, 3);
	}
	for (unsigned int i = 0; i < vec[3].size(); i++) {
		vec[3][i].setTexture(*t);
		if (i == 1 || i == 5) vec[3][i].setOrigin(vec[3][i].getLocalBounds().width / 2, (vec[3][i].getLocalBounds().height / 2) + 3.0f);
		else if (i == 2 || i == 6) vec[3][i].setOrigin(vec[3][i].getLocalBounds().width / 2, (vec[3][i].getLocalBounds().height / 2) + 4.0f);
		else if (i == 3 || i == 7) vec[3][i].setOrigin(vec[3][i].getLocalBounds().width / 2, (vec[3][i].getLocalBounds().height / 2) + 1.0f);
		else vec[3][i].setOrigin(vec[3][i].getLocalBounds().width / 2, vec[3][i].getLocalBounds().height / 2);
		//vec[3][i].scale(3, 3);
	} 
	return;
}