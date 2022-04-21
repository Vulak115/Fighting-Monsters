#ifndef MONSTER_H
#define MONSTER_H
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include <string>
using namespace std;
class Monster : public LinkedList<Monster>
{
private:
	string monsterName;
	int monsterHP;
	int currMonHP;
	int monsterMinDMG;
	int monsterMaxDMG;
	int position;
public:
	Monster() { monsterHP = 0; monsterMinDMG = 0; monsterMaxDMG = 0; position = 0; currMonHP = 0; }
	Monster(int p) { position = p; }
	Monster(string mn, int mhp, int mid, int mmd) { monsterName = mn; monsterHP = mhp; monsterMinDMG = mid; monsterMaxDMG = mmd; }
	string getMName() { return monsterName; }
	int getMonsterHP() { return monsterHP; }
	int getmMinDmg() { return monsterMinDMG; }
	int getmMaxDmg() { return monsterMaxDMG; }
	int getCurMonHP() { return currMonHP; }
	int getPosition() { return position; }
	void MHP(int atk) { currMonHP -= atk; if (currMonHP < 0) currMonHP = 0;
	}
	int getMAttack(string);
	void UpdateMHP(string,int);
	void getMHP(string);
	string pickMonster();
	friend ostream& operator<<(ostream&, Monster&);
	bool operator==(Monster);
	Monster operator++(int);
	void operator=(Monster &right)
	{
		monsterName = right.monsterName;
		monsterHP = right.monsterHP;
		monsterMinDMG = right.monsterMinDMG;
		monsterMaxDMG = right.monsterMaxDMG;
		position = right.position;
	//	getmMaxDmg() = right.getmMaxDmg();
	//	getmMinDmg() = right.getmMinDmg();
	}
	string toString() const { return monsterName; } //lets me turn objects into strings so that I can store them in different classes or parameters
	template <typename T>
	string to_string(const T& object) {
		std::ostringstream ss;
		ss << object;
		return ss.str();
	}
	//operator string(

};
#endif

void Monster::UpdateMHP(string n,int atk)
{
	/*int p = 1;
	bool status = true;
	ListNode<Monster>* nodePtr;
	nodePtr = LinkedList<Monster>::head;
	cout << n << atk << " atk"<<endl;
	while (nodePtr != nullptr)
	{
		
		if (n == nodePtr->value.getMName())
		{
			nodePtr->value.MHP(atk);
		}
		nodePtr = nodePtr->next;
	}*/
	MHP(atk);
}
void Monster::getMHP(string n)
{
	int p = 0;
	bool status = true;
	ListNode<Monster>* nodePtr;
	nodePtr = LinkedList<Monster>::head;

	while (nodePtr != nullptr)
	{	
		if (n == nodePtr->value.getMName())
		{
			currMonHP = nodePtr->value.getMonsterHP();
			monsterHP = nodePtr->value.getMonsterHP();
		//return currMonHP;
		}
		nodePtr = nodePtr->next;
	}
	
}
ostream& operator<< (ostream& outs, const Monster& obj) {
	return outs << obj.toString();
}


ostream& operator<<(ostream& out, Monster& items) //overloaded << for the Item class
{
	out <<left<<setw(15)<< items.getMName() << items.getMonsterHP() <<setw(5)<<right<< items.getmMinDmg() << setw(5) << items.getmMaxDmg();
	return out;
}
int Monster::getMAttack(string s)
{
	int p = 1;
	bool status = true;
	ListNode<Monster>* nodePtr;
	nodePtr = LinkedList<Monster>::head;
	cout << left << setw(18) << "Character Name" << left << setw(13) << "Class" << "Race" << setw(10) << right << "Server: " << s << endl;
	while (nodePtr != nullptr)
	{
		if (s == nodePtr->value.getMName())
		{
			int damage = 0;
			srand(time(NULL));
			damage = rand() % (nodePtr->value.getmMaxDmg() - nodePtr->value.getmMinDmg() + 1) + nodePtr->value.getmMinDmg();
			status = false;
			return damage;
		}
		nodePtr = nodePtr->next;
	}
	if (status)
		return 0;
}
string Monster::pickMonster()
{
	string mName;
	int random = 0;
	srand(time(NULL));
	random = rand() % (11-1+1)+1;
		mName = to_string(get(random));
		cout << mName << " check " <<random<< endl;
		return mName;
}
bool Monster::operator==(Monster c)
{
	bool status;

	if (getPosition() == c.getPosition())
		status = true;
	else
		status = false;

	return status;
}
Monster Monster::operator++(int)
{
	position++;
	return *this;
}




