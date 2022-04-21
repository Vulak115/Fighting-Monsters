#ifndef ROGUE_H
#define ROGUE_H


#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
using namespace std;

class Rogue : public Character
{
private:
	int minDmg;
	int maxDmg;
public:
	
	virtual int Attack();
	virtual void setStats();
	void print(string);
	void makeRogue(string, string, string, int);
	int getMinDmg() { return minDmg; }
	int getMaxDmg() {return maxDmg;}
	virtual	void updateCharHP(int atk);
	Rogue() { minDmg = 0; maxDmg = 0; lvl = 0; }
	Rogue(string c, string r, string n, int exp) {
		Class = c; race = r; ; name = n; experience = exp;
	}
	Rogue(string c, string r, string n, int exp, int mid, int mmd) {
		Class = c; race = r; ; name = n; experience = exp; minDmg = mid; maxDmg = mmd;
	}
	Rogue(string n) { name = n; }
};
#endif
void Rogue::updateCharHP(int atk)
{ 
	int dodge = 0;
	srand(time(NULL));
	dodge = rand() % (10 - 1 + 1) + 1;
	if (dodge > 5)
		cout << "You dodged the attack and took zero damage" << endl;
	else 
	{
		currHP -= atk;
		if (currHP < 0)
			currHP = 0;
	}
}


/*void Rogue::makeRogue(string c,string r,string n,int exp)
{
	int lvl = getLvl();
//	healthPoints = healthPoints*(.1*lvl);
	minDmg = 20 *(.1*lvl);
	maxDmg = 60*(.1*lvl);
	LinkedList<Character>::insertNode(Rogue(c, r, n, exp, minDmg, maxDmg));

}*/
void Rogue::setStats()
{
	
	cout << experience<<" "<<lvl <<" lvl" << endl;
	healthPoints = 100+(4*lvl);
	currHP = healthPoints;
	minDmg = 20+(2*lvl);
	maxDmg = 60+(2*lvl);
}
int Rogue::Attack()
{
	int damage = 0;
	srand(time(NULL));
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