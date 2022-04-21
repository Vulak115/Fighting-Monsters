#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ios>
#include "LinkedList.h"
#include "Races.h"
#include "Classes.h"
#include "Character.h"
#include "Rogue.h"
#include "Monster.h"
using namespace std;

void fillLists(Character *c,Monster&m) //loads text from the fill.txt
{
	int type, type2, type3, type4;
	string  text, text2, text3, text4, line;
	Rogue *r;
	ifstream infile, infile2;
	infile.open("fill.txt");
	infile2.open("savedCharacters.txt");
	c->LinkedList<Character>::insertNode(Rogue("fdsfasf", "aaw", "daeew", 10));
	if (infile.is_open() || infile2.is_open())
	{
		while (getline(infile, line) || getline(infile2, line))
		{
			istringstream ss(line);
			if (!(ss >> type >> type2>>type3>>type4)) { break; }

			getline(ss, text, ',');
			getline(ss, text2, '.');
			getline(ss, text3, '?');
			getline(ss, text4);

			switch (type)
			{
			case 1:
				c->LinkedList<Classes>::insertNode( Classes(text, text2));
				break;
			case 2:
				c->LinkedList<Races>::insertNode(Races(text, text2));
				break;
			case 3:
				m.append(Monster(text, type2, type3, type4));
				break;
			case 4:
				switch (type2)
				{
				case 1:
				//	c = new Rogue(text, text2, text3, type3);
										//c->LinkedList<Character>::insertNode(new Rogue(text, text2, text3, type3))
				//	c->LinkedList<Character>::insertNode(Rogue(text,text2,text3,type3)) = new Rogue(text, text2, text3, type3);
					cout << type3 << " type3" << endl;
				c->LinkedList<Character>::insertNode(Rogue(text, text2, text3, type3));
					break;
				case 2:
					c->insertCharacter(text, text2, text3, type3);
					break;
				case 3:
					c->insertCharacter(text, text2, text3, type3);
					break;
				}
				//Character::Character(Character(text, text2, text3, text4));
				//c.insertCharacter(text, text2, text3, type3);
				
				break;

			}
		}
		infile2.close();
		infile.close();
	}
	else
		cout << "Unable to open file";
}

void makeChar(Character*tt)
{
	Character s;
	int cpick;
	string archtype, name, race;

	cout << "Pick a class!\n";
	tt->LinkedList<Classes>::displayList();
	cout << "Enter Choice: ";
	cin >> cpick;
	archtype = s.to_string(tt->LinkedList<Classes>::get(cpick));
	cout << "Pick a race for your character!\n";
	tt->LinkedList<Races>::displayList();
	cout << "Enter Choice: ";
	cin >> cpick;
	race = s.to_string(tt->LinkedList<Races>::get(cpick));
	cout << "Now to name your hero!\n" "Enter chararacters name: ";
	cin.ignore();
	getline(cin, name);
	//tt->insertCharacter(archtype, race, name, 10);
	


}
void makeChar(Character*);
void fillLists(Character*,Monster&);
int main()
{
	Rogue r;
	bool status = true;
	cout << setprecision(0) << fixed;
	int choice = 0, heroAttack = 0, monsterAttack = 0, monHP = 0;
	char pick = 'n';
	int cpick;
	string archtype, race, name, monsterName;
	Character *tt, s;
	tt = new Rogue();
	Monster m;
	fillLists(tt,m);
	while (choice != 5)
	{
		if (status) {
			cout << "Login to your server\n";
			m.displayList();
		
			cout << "Enter Choice: ";
			cin >> cpick;
			
			cout << endl;
			status = false;
		}
		cout << "1 - Make a Character\n" "2 - Delete a Character\n""3 - Change servers\n" "5 - Quit\n" "Enter Choice: ";
		cin >> choice;
		cout << endl;
		if (choice != 5)
		{
			switch (choice)
			{
			case 1:
				makeChar(tt);
				tt->LinkedList<Character>::displayList();
				break;
			case 2:
				cout << "Type in the name of the Character you would like to delete.\n" "Enter name: ";
				cin.ignore();
				getline(cin, name);
				tt->LinkedList<Character>::remove(name);
				tt->LinkedList<Character>::displayList();
				break;
			case 3:
				cout << "Pick your server - to view characters on that server\n";
				cout << left << setw(18) << "Character Name" << left << setw(13) << "Class" << "Race" << setw(10);
				tt->LinkedList<Character>::displayList();
				cin >> cpick;
				*tt= tt->LinkedList<Character>::get(cpick);
				name = tt->getName();
				tt->getLvl(name);
				tt->setStats();
				monsterName = m.pickMonster();
				m.getMHP(monsterName);
			while (tt->getCurrHP() > 0 && m.getCurMonHP() > 0)
			{
				heroAttack = tt->Attack();
				monsterAttack = m.getMAttack(monsterName);
				m.getMHP(name);
				cout << name << " hits " << monsterName << " for " << heroAttack << " damage.\n";
				m.MHP(heroAttack);
				cout << monsterName << " hits " << name << " for " << monsterAttack << " damage.\n";
				tt->updateCharHP(monsterAttack);
				cout << name << " has " << tt->getCurrHP() << "/" << tt->getHP() << " hp left.\n" <<
					monsterName << " has " << m.getCurMonHP() << "/" << m.getMonsterHP() << " hp left.\n";

			}
			if (m.getCurMonHP() <= 0)
				cout << "You won!!!\n";
			else
				cout << "You lost!!!\n";
			
			m.displayList();
				//tt->print(name);
				//cout << tt->Attack() << " atook" << endl;
					
				//	r.print(name);
					
					break;
		

			case 4:
				m.displayList();
				monsterName = m.pickMonster();
				cout << m.getMAttack(monsterName) << " rawr " <<monsterName <<endl;
				break;

			}
		}
	}
	tt->printOut();




	return 0;
}