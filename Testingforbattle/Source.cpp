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
#include "Monster.h"
#include "Rogue.h"
#include "Warrior.h"
#include "Wizard.h"

using namespace std;
enum note { middleC, Csharp, Cflat }; // Etc.
void Battle(Character*,Character&,Monster&,string);
void makeChar(Character*);
void fillLists(Character*, Monster&);

void fillLists(Character *c,Monster&m) //loads text from the fill.txt
{
	
	int type, type2, type3, type4;
	string  text, text2, text3, text4, line;
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
				c->LinkedList<Classes>::insertNode(Classes(text, text2));
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
				
					//c = new Rogue(Rogue(text, text2, text3, type3));
					 
										//c->LinkedList<Character>::insertNode(new Rogue(text, text2, text3, type3))
				//	c->LinkedList<Character>::insertNode(Rogue(text,text2,text3,type3)) = new Rogue(text, text2, text3, type3);
					
				c->LinkedList<Character>::insertNode(Rogue(text, text2, text3, type3));
					break;
				case 2:
				
				//	c = new Warrior();
					c->LinkedList<Character>::insertNode(Warrior(text, text2, text3, type3));
					break;
				case 3:
					
					//c = new Wizard();
					c->LinkedList<Character>::insertNode(Wizard(text, text2, text3, type3));
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
	if (archtype == "Wizard")
		tt->LinkedList<Character>::insertNode(Wizard(archtype, race, name, 0));
	if (archtype == "Rogue") 
		tt->LinkedList<Character>::insertNode(Rogue(archtype, race, name, 0));
	if (archtype == "Warrior")
		tt->LinkedList<Character>::insertNode(Warrior(archtype, race, name, 0));
}

// Identical function from before:
void Battle(Character*c,Character& i,Monster&m,string name) {
	int cpick = 0, heroAttack = 0, monsterAttack = 0, yu = 1;
	double lvl = 0;
	string  archtype, monsterName;
	Character s;
	char pick = 'b';
	bool status = true;
	
	lvl=c->getLvl(name);
	while (pick != 'n')
	{
	//	cout << "Enter Difficulty choice 1 is easy 2 is medium 3 is hard: ";
		//cin >> cpick;
		i.setStats(lvl);
		monsterName = m.pickMonster(lvl);
		m.getMHP(monsterName);
		while (i.getCurrHP() > 0 && m.getCurMonHP() > 0)
		{
			i.setRacials(c,status);
			cout << "Round " << yu++ << endl;
			heroAttack = i.Attack();
			monsterAttack = m.getMAttack(monsterName,c);
			m.getMHP(name);
			cout << name << " hits " << monsterName << " for " << heroAttack << " damage.\n";
			m.MHP(heroAttack);
			i.updateCharHP(monsterAttack,monsterName,c);
			cout<<	monsterName << " has " << m.getCurMonHP() << "/" << m.getMonsterHP() << " hp left.\n";
			status = false;
		}
		//	tt = new Character;
		if (m.getCurMonHP() <= 0)
		{
			cout << "You won!!!\n";
			c->updateEXP(name, m.getMonsterHP());
			lvl=c->getLvl(name);

		}
		else
			cout << "You lost!!!\n";
		status = true;
		yu = 1;
		c->printOut();
		cout << "Keep Battling?(y/n)";
		cin >> pick;
		//i.test(c);
	}
	pick = 'u';
	m.displayList();
}

// New function:
//void f(Instrument& i) { i.adjust(1); }

// Upcasting during array initialization:


int main()
{
	Wizard wiz;
	Warrior war;
	Rogue r;
	srand(time(NULL));
	bool status = true;
	cout << setprecision(0) << fixed;
	int choice = 0, heroAttack = 0, monsterAttack = 0, monHP = 0;
	char pick = 'u';
	int cpick;
	
	string archtype, race, name, monsterName;
	Character* tt = new Rogue;
	Character *oo = new Rogue;
	Character *io = new Warrior;
	//tt = new Rogue(), new Wizard(),new Warrior();
	//tt = new Wizard;
	//tt = new Wizard();
	Character s;
	//tt[3] = { new Rogue, new Wizard, new Warrior };
	//Character *b[3] = { new Rogue, new Wizard, new Warrior };
	Monster m;
	
	fillLists(tt,m);
		while (choice !=5)
		{ 
		cout << "1 - Make a Character\n" "2 - Delete a Character\n""3 - Goto Battle\n" "5 - Quit\n" "Enter Choice: ";
		cin >> choice;
		cout << endl;
		if (choice != 5)
		{
			switch (choice)
			{
			case 1:
				makeChar(tt);
				tt->LinkedList<Character>::displayList();
				tt->printOut();
				break;
			case 2:
				cout << "Type in the name of the Character you would like to delete.\n" "Enter name: ";
				cin.ignore();
				getline(cin, name);
				tt->LinkedList<Character>::remove(name);
				tt->LinkedList<Character>::displayList();
				tt->printOut();
				break;
			case 3:
				tt->LinkedList<Character>::displayList();
				cout << "Enter Choice: ";
				cin >> cpick;
				*tt = tt->LinkedList<Character>::get(cpick);
				name = tt->getName();
				archtype = tt->getClass();
				if (archtype == "Wizard")
					Battle(tt, wiz, m, name);
				if (archtype == "Warrior")
					Battle(tt, war, m, name);
				if (archtype == "Rogue")
					Battle(tt, r, m, name);


				break;


			case 4:
				break;
			}
		}
	}


	return 0;
}