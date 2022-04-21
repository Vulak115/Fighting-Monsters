#ifndef ROGUE_H
#define ROGUE_H


#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
using namespace std;

class Rogue : public Character
{
private:
	
public:
	Rogue() : Character(){}
	~Rogue(){}
	int Attack();
	void test(Character*);
	void setStats(double);
	void print(string);
	void makeRogue(string, string, string, int);
	void updateCharHP(int atk,string,Character*);
//	Rogue() { minDmg = 0; maxDmg = 0; lvl = 0; }
	Rogue(string c, string r, string n, int exp) /*: Character(Class, name, race, experience)*/ {
		Class = c; race = r; ; name = n; experience = exp; 
		//makeRogue(c, r, n, exp);	
	}

	Rogue(string c, string r, string n, int exp, int mid) {
		Class = c; race = r; ; name = n; experience = exp;
	}
	Rogue(string n) { name = n; }
};
#endif
void Rogue::test(Character*c)
{
	cout << c->getName() << " rogue\n";
}
void Rogue::updateCharHP(int atk,string mname,Character*c)
{ 
	if (dodge < 50&&atk)
	{
		cout << "You dodged the attack and took zero damage" << endl;
		cout << c->getName() << " has " << getCurrHP() << "/" << getHP() << " hp left.\n";
	}
	else if (atk)
	{
		currHP -= atk;
		if (currHP < 0)
			currHP = 0;
		cout << mname << " hits " << c->getName() << " for " << atk << " damage.\n";
		cout << c->getName() << " has " << getCurrHP() << "/" << getHP() << " hp left.\n";

	}
	else
	cout << c->getName() << " has " << getCurrHP() << "/" << getHP() << " hp left.\n";
}


void Rogue::makeRogue(string c,string r,string n,int exp)
{
	Class = c;
	race = r;
	name = n;
	experience = exp;

	LinkedList<Character>::insertNode(Rogue(Class, race, name, experience,exp));

}
void Rogue::setStats(double lvl)
{
	
	
	healthPoints = 100+(4*lvl);
	currHP = healthPoints;
	minDmg = 20+(2*lvl);
	maxDmg = 60+(3*lvl);
	

}
int Rogue::Attack()
{
	int damage = 0;
	damage = rand() % (maxDmg - minDmg + 1) + minDmg;
	return damage;
}
void Rogue::print(string n)
{
	
	bool status = true;
	ListNode<Character>* nodePtr;
	nodePtr = LinkedList<Character>::head;
	if (nodePtr == nullptr)
	{
		cout << nodePtr << endl;
		cout << "Nothing here" << endl;
	}
	while (nodePtr != nullptr)
	{
		if (!(n != nodePtr->value.getName()))
		{
			cout << "in" << endl;
			cout << nodePtr->value.getName() << nodePtr->value.getClass() << nodePtr->value.getRace() << nodePtr->value.getExp()<<" "<<
				lvl <<" "<< minDmg<<" "<<maxDmg<<" realrogueeee" <<healthPoints<< endl;
			status = false;
		}
		nodePtr = nodePtr->next;
	}

	if (status)
		cout << "Not found!" << endl;
}