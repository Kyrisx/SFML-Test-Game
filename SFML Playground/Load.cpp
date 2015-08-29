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
	if (!t->loadFromFile("link3.png")) {
		cout << "Couldn't open sprite file" << endl;
		return;
	}
	link.addTexture(t);
			
	Sprite Awl0, Awl1, Awl2, Awl3, Awl4, Awl5, Awl6;
	Sprite Awr0, Awr1, Awr2, Awr3, Awr4, Awr5, Awr6;
	Sprite Awu0, Awu1, Awu2, Awu3, Awu4, Awu5, Awu6;
	Sprite Awd0, Awd1, Awd2, Awd3, Awd4, Awd5, Awd6;
	/*Sprite Asl0, Asl1, Asl2, Asl3, Asl4;
	Sprite Asr0, Asr1, Asr2, Asr3, Asr4;
	Sprite Asu0, Asu1, Asu2, Asu3, Asu4;
	Sprite Asd0, Asd1, Asd2, Asd3, Asd4, Asd5;*/

	loadHelper(Awl0, 4, 70, 19, 23);
	loadHelper(Awl1, 7, 216, 19, 23);
	loadHelper(Awl2, 38, 217, 23, 22);
	loadHelper(Awl3, 70, 217, 24, 22);
	loadHelper(Awl4, 104, 216, 19, 23);
	loadHelper(Awl5, 133, 217, 23, 22);
	loadHelper(Awl6, 171, 217, 24, 22);
	
	loadHelper(Awu0, 4, 23, 18, 23);
	loadHelper(Awu1, 9, 187, 18, 24);
	loadHelper(Awu2, 40, 184, 18, 27);
	loadHelper(Awu3, 73, 186, 18, 25);
	loadHelper(Awu4, 105, 187, 18, 24);
	loadHelper(Awu5, 137, 184, 18, 27);
	loadHelper(Awu6, 173, 186, 18, 25);
	
	loadHelper(Awd0, 5, 116, 18, 26);
	loadHelper(Awd1, 7, 245, 18, 29);
	loadHelper(Awd2, 38, 243, 18, 28);
	loadHelper(Awd3, 68, 246, 18, 25);
	loadHelper(Awd4, 102, 246, 18, 29);
	loadHelper(Awd5, 134, 245, 18, 28);
	loadHelper(Awd6, 171, 248, 18, 25);
	
	/*loadHelper(Asl0, 1051, 400, 78, 100);
	loadHelper(Asl1, 1164, 400, 113, 104);
	loadHelper(Asl2, 1281, 404, 135, 91);
	loadHelper(Asl3, 1420, 404, 122, 91);
	loadHelper(Asl4, 1559, 382, 100, 135);

	loadHelper(Asr0, 1051, 795, 78, 95);
	loadHelper(Asr1, 1164, 799, 113, 96);
	loadHelper(Asr2, 1281, 795, 135, 91);
	loadHelper(Asr3, 1420, 795, 122, 91);
	loadHelper(Asr4, 1559, 773, 100, 135);
	
	loadHelper(Asu0, 0, 795, 83, 95);
	loadHelper(Asu1, 130, 778, 96, 130);
	loadHelper(Asu2, 265, 764, 87, 152);
	loadHelper(Asu3, 387, 778, 104, 130);
	loadHelper(Asu4, 500, 791, 139, 99);

	loadHelper(Asd0, 4, 400, 87, 100);
	loadHelper(Asd1, 130, 400, 96, 104);
	loadHelper(Asd2, 265, 382, 87, 135);
	loadHelper(Asd3, 395, 382, 87, 135);
	loadHelper(Asd4, 500, 387, 121, 126);
	loadHelper(Asd5, 630, 391, 139, 117);*/

	vector <Sprite> Awl = { Awl0, Awl1, Awl2, Awl3, Awl4, Awl5, Awl6 };
	vector <Sprite> Awr = { Awr0, Awr1, Awr2, Awr3, Awr4, Awr5, Awr6 };
	vector <Sprite> Awu = { Awu0, Awu1, Awu2, Awu3, Awu4, Awu5, Awu6 };
	vector <Sprite> Awd = { Awd0, Awd1, Awd2, Awd3, Awd4, Awd5, Awd6 };
	/*vector <Sprite> Asl = { Asl0, Asl1, Asl2, Asl3, Asl4 };
	vector <Sprite> Asr = { Asr0, Asr1, Asr2, Asr3, Asr4 };
	vector <Sprite> Asu = { Asu0, Asu1, Asu2, Asu3, Asu4 };
	vector <Sprite> Asd = { Asd0, Asd1, Asd2, Asd3, Asd4, Asd5 };*/

	for (unsigned int i = 0; i < Awr.size(); i++) {
		Awr[i] = Awl[i];
		Awr[i].setScale(-1, 1);
	}

	vector <vector<Sprite>> movement = { Awl, Awr, Awu, Awd };
	//vector <vector<Sprite>> attack = { Asl, Asr, Asu, Asd };

	bindMovement(movement, link.printTexture());
	//bindAttack(attack, movement, link.printTexture());

	link.addLeft(movement[0]);
	link.addRight(movement[1]);
	link.addUp(movement[2]);
	link.addDown(movement[3]);

	/*link.addAtkLeft(attack[0]);
	link.addAtkRight(attack[1]);
	link.addAtkUp(attack[2]);
	link.addAtkDown(attack[3]);*/

	link.setMS(0);
	link.setAns(75);
	link.getAttack.attackSpeed = 3;
	return;
}

void loadHelper(Sprite &s, int left, int top, int width, int height) {
	s.setTextureRect(IntRect(left, top, width, height));
	return;
}

void bindMovement(vector <vector<Sprite>> &vec, Texture* t) {
	for (unsigned int i = 0; i < vec.size(); i++) {
		for (unsigned int j = 0; j < vec[i].size(); j++) {
			vec[i][j].setTexture(*t);
			vec[i][j].setOrigin(vec[i][j].getLocalBounds().width/2, vec[i][j].getLocalBounds().height);
			vec[i][j].scale(3, 3);
		}
	}
	return;
}

void bindAttack(vector <vector<Sprite>> &vecAtk, vector <vector<Sprite>> &vecMov, Texture* t) {
	for (unsigned int i = 0; i < vecAtk[0].size(); i++) {
		vecAtk[0][i].setTexture(*t);
		vecAtk[0][i].setOrigin(vecAtk[0][i].getLocalBounds().width, min(vecAtk[0][i].getLocalBounds().height, vecMov[0][0].getLocalBounds().height));
	}
	for (unsigned int i = 0; i < vecAtk[1].size(); i++) {
		vecAtk[1][i].setTexture(*t);
		vecAtk[1][i].setOrigin(min(vecAtk[1][i].getLocalBounds().width, vecMov[1][0].getLocalBounds().width), min(vecMov[1][0].getLocalBounds().height, vecMov[1][0].getLocalBounds().height));
	}
	for (unsigned int i = 0; i < vecAtk[2].size(); i++) {
		vecAtk[2][i].setTexture(*t);
		vecAtk[2][i].setOrigin(max(vecAtk[2][i].getLocalBounds().width, vecMov[2][0].getLocalBounds().width), vecAtk[2][i].getLocalBounds().height);
	}
	for (unsigned int i = 0; i < vecAtk[3].size(); i++) {
		vecAtk[3][i].setTexture(*t);
		vecAtk[3][i].setOrigin(min(vecAtk[3][i].getLocalBounds().width, vecMov[3][0].getLocalBounds().width), vecMov[3][0].getLocalBounds().height);
	}
	return;
}