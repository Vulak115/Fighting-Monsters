#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
using namespace std;


class Character : public LinkedList<Races>, public LinkedList<Classes>, public LinkedList<Character>
{
protected:
	string Class;
	string race;
	int position;
	string name;
	long double experience;
	long double lvl;
	double currHP;
	double healthPoints;
	int minDmg;
	int maxDmg;
	double dodge;
public:

	Character() { healthPoints = 1; Class = " "; position = 0; name = " ";  race = " "; experience = 0; lvl = 0; currHP = 0; minDmg = 0; maxDmg = 0; dodge = 0; }
	~Character() {  }
	//Character(string c = "ff" , string r ="dd" , string n = "dde", int s = 55  ){ Class = c; race = r; name = n; experience = s; cout << "Character con" << endl; }
	//Character(string c, string r, string n, int s, int t);
	Character(string n) { name = n; } //the sp is a blank spot its just there to let me call the constructor and not the name one up it
	Character(int r) { position = r; } //for the get function in LinkedList
	string getName() { return name; }
	string getRace() { return race; }
	string getClass() { return Class; }
	long double getExp() { return experience; }
	double getHP() { return healthPoints; }
	double getCurrHP() { return currHP; }
	double getDodge() { return dodge; }
	int getMinDmg() { return minDmg; }
	int getMaxDmg() { return maxDmg; }
	int increaseEXP(int hp) { return experience += hp; }
	virtual	void updateCharHP(int atk,string,Character*) { currHP -= atk; if (currHP < 0) currHP = 0; }
	virtual int Attack();
	double getLvl(string);
	double getl() { return lvl;  }
	int getPosition() { return position; }
	void updateEXP(string ,int);
	bool operator <(Character);
	bool operator!=(Character);
	bool operator==(Character);
	Character operator++(int);
	friend ostream& operator<<(ostream&, Character&);
	void displayServerCharacters(string s);
	void printOut();
	void insertCharacter(string, string, string, int);
	virtual void setStats(double);
	virtual void print(string);
	string toString() const { return name; } //lets me turn objects into strings so that I can store them in different classes or parameters
	template <typename T>
	string to_string(const T& object) {
		std::ostringstream ss;
		ss << object;
		return ss.str();
	}
	//operator string() const { return serverList; }//lets me turn objects into strings so that I can store them in different classes or parameters not as specific as the above function though
	virtual void setRacials(Character*,bool&);
	void operator=(Character &right)
	{
		
		Class = right.Class;
		position = right.position;
		race = right.race;
		name = right.name;
		experience = right.experience;
			healthPoints = right.healthPoints;
			currHP = right.currHP;
			lvl = right.lvl;
			dodge = right.dodge;
		getName() = right.getName();
	}
	
};
#endif
void Character::setRacials(Character*c,bool &status)
{
	dodge = rand() % (100 - 1 + 1) + 1;
	if (c->getRace() == "Troll"&&getCurrHP() <= (getHP() - 5)) currHP += 5;
	else if (c->getRace()=="Troll")currHP = getHP();

	if (c->getRace() == "Orc"&&status)
	{
		minDmg +=10;
		maxDmg += 10;
	}
	if (c->getRace() == "Elf" && dodge < 55 && c->getClass() == "Rogue")
		dodge = 1;
	else if (c->getRace() == "Elf" && dodge < 91 && c->getClass() == "Wizard")
		dodge = 20;
	else if (c->getRace() == "Elf"&&status)
	{
		currHP += (currHP*.1);
		healthPoints += (healthPoints*.1);
	}
	if (c->getRace() == "Auren"&&status)
	{
		currHP += (currHP*.1);
		healthPoints += (healthPoints*.1);
	}
//fairy racial is in monsterAttack
}
void Character::updateEXP(string n,int hp)
{
	
	bool status = true;
	ListNode<Character> * nodePtr;
	nodePtr = LinkedList<Character>::head;

		
	while (nodePtr != nullptr)
	{
		if (!(n != nodePtr->value.getName()))
		{
			nodePtr->value.increaseEXP(hp);
			status = false;
		}
		nodePtr = nodePtr->next;
	}

	if (status)
		cout << "Not found!" << endl;

}
void Character::print(string n)
{
	cout << "badly" << endl;
	bool status = true;
	ListNode<Character> * nodePtr;
	nodePtr = LinkedList<Character>::head;
	if (nodePtr == nullptr)
		cout << "Nothing here" << endl;
	while (nodePtr != nullptr)
	{
		cout << n << nodePtr->value.getName() << "namesss" << endl;
		if (!(n != nodePtr->value.getName()))
		{
			cout << nodePtr->value.getName() << nodePtr->value.getClass() << nodePtr->value.getRace() <<
				nodePtr->value.getExp()  << "Rogueeeeeeeee" << endl;
			status = false;
		}
		nodePtr = nodePtr->next;
	}

	if (status)
		cout << "Not found!" << endl;

}
void Character::setStats(double lvl)
{
	healthPoints = healthPoints*(2);
	
}
double Character::getLvl(string n)
{
	ListNode<Character>* nodePtr;
	nodePtr = LinkedList<Character>::head;
	if (nodePtr == nullptr)
	{
		cout << "Nothing here" << endl;
	}
	while (nodePtr != nullptr)
	{
		if (!(n != nodePtr->value.getName()))
		{
			lvl = nodePtr->value.getExp() / (100+ (.001*nodePtr->value.getExp()));		
			cout << n << " is " << lvl << endl;
			return lvl;
		}
		nodePtr = nodePtr->next;
	}
	return 0;
}

int Character::Attack()
{
	cout << "Character!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	return 0;

}


/*Character::Character(string c, string r, string n, int s)
{

	Class = c; race = r; name = n; experience = s; cout << "Character con" << endl;
}*/

/*Character::Character(string c, string r, string n, int s,int t)
{

	Class = c; race = r; name = n; experience = s; cout << "Character con" << endl;
}*/

/*void Character::insertCharacter(string c, string r, string n, int s)
{
	//cout << "make it" << endl;
	bool status;
	status = LinkedList<Character>::search(Character(n));
	if (!status)
	{
		LinkedList<Character>::insertNode(Character(c, r, n, s));
	}
	else
		cout << "Name already in use!" << endl;

}*/


ostream& operator<< (ostream& outs, const Character& obj) {
	return outs << obj.toString(); cout << "to string" << endl;
}

ostream& operator<<(ostream& out, Character& items) //overloaded << for the Item class
{

	out <<left << setw(18) << items.getName() << left << setw(13)<< items.getClass() <<  items.getRace() <<setw(10)<< right << items.getExp();
	return out;
}

bool Character::operator<(Character cc) //overloaded < for the Item class
{
	
	bool status;

	if (getClass() < cc.getClass())
		status = true;
	else
		status = false;
	return status;
}


bool Character::operator==(Character c)
{
	
	bool status;

	if (getPosition() == c.getPosition())
		status = true;
	else
		status = false;

	return status;
}
Character Character::operator++(int)
{

	position++;
	return *this;
}

bool Character::operator!=(Character c)
{

	if (getName() != c.getName())
		return true;
	return false;
}

/*void Character::displayServerCharacters(string s)
{
	int p = 1;
	bool status = true;
	ListNode<Character>* nodePtr;
	nodePtr = LinkedList<Character>::head;
	cout << left << setw(18) << "Character Name" << left << setw(13) << "Class" << "Race" << setw(10)
		<< right << "Server: " << s << endl;
	while (nodePtr != nullptr)
	{
		if (s == nodePtr->value.getServer())
		{
			status = false;
			cout << p++ << ". " << left << setw(15) << nodePtr->value.getName() << left 
				<< setw(13) << nodePtr->value.getClass() << nodePtr->value.getRace() << endl;

		}
		nodePtr = nodePtr->next;
	}
	if (status)
		cout << "You have no characters on this server.\n";





}*/

void Character::printOut()
{
	ListNode<Character> *nodePtr;
	nodePtr = LinkedList<Character>::head;
	int type = 0, type2 = 0;
	string c, r, n, s;
	ofstream myfile;
	myfile.open("savedCharacters.txt");
	while (nodePtr != nullptr)
	{
		c = nodePtr->value.getClass();
		r = nodePtr->value.getRace();
		n = nodePtr->value.getName();
		type2 = nodePtr->value.getExp();
		if (c == "Wizard") type = 3;
		if (c == "Rogue") type = 1;
		if (c == "Warrior")type = 2;

		myfile << 4 << " " << type << " " << type2<< " " <<0<<c << "," << r << "." << n << "?" << s << "\n";
		nodePtr = nodePtr->next;
	}
	myfile.close();
}


