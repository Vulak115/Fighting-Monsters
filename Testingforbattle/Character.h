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
	double experience;
	int lvl;
	int currHP;
	int healthPoints;
public:

	Character() { healthPoints = 0; Class = ""; position = 0; name = "";  race = " "; experience = 0; lvl = 0; currHP = 0; }
	Character(string c, string r, string n, int s);
	Character(string n) { name = n; } //the sp is a blank spot its just there to let me call the constructor and not the name one up it
	Character(int r) { position = r; } //for the get function in LinkedList
	string getName() { return name; }
	string getRace() { return race; }
	string getClass() { return Class; }
	double getExp() { return experience; }
	int getHP() { return healthPoints; }
	int getCurrHP() { return currHP; }
	virtual	void updateCharHP(int atk) { currHP -= atk; if (currHP < 0) currHP = 0; }
	virtual int Attack();
	void getLvl(string);
	int getl() { return lvl; cout << experience << " character expereience" << endl; }
	int getPosition() { return position; }
	bool operator <(Character);
	bool operator!=(Character);
	bool operator==(Character);
	Character operator++(int);
	friend ostream& operator<<(ostream&, Character&);
	void displayServerCharacters(string s);
	void printOut();
	void insertCharacter(string, string, string, int);
	virtual void setStats();
	virtual void print(string);
	string toString() const { return name; } //lets me turn objects into strings so that I can store them in different classes or parameters
	template <typename T>
	string to_string(const T& object) {
		std::ostringstream ss;
		ss << object;
		return ss.str();
	}
	//operator string() const { return serverList; }//lets me turn objects into strings so that I can store them in different classes or parameters not as specific as the above function though

	void operator=(Character &right)
	{
		cout << "= operator" << endl;
		Class = right.Class;
		position = right.position;
		race = right.race;
		name = right.name;
		experience = right.experience;
			healthPoints = right.healthPoints;
		getName() = right.getName();
	}
	
};
#endif
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
void Character::setStats()
{
	healthPoints = healthPoints*(.05);
	
}
void Character::getLvl(string n)
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
			lvl= nodePtr->value.getExp() / (100 + (.01*nodePtr->value.getExp()));		
		}
		nodePtr = nodePtr->next;
	}
}
int Character::Attack()
{
	return 0;
}


Character::Character(string c, string r, string n, int s)
{
	cout << experience << " " << s << " character exp now" << endl;
	Class = c; race = r; name = n; experience = s;
}

void Character::insertCharacter(string c, string r, string n, int s)
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

}


ostream& operator<< (ostream& outs, const Character& obj) {
	return outs << obj.toString(); cout << "to string" << endl;
}

ostream& operator<<(ostream& out, Character& items) //overloaded << for the Item class
{
	cout << "<< operator" << endl;
	out <<left << setw(18) << items.getName() << left << setw(13)<< items.getClass() <<  items.getRace() <<setw(10)<< right << items.getExp();
	return out;
}

bool Character::operator<(Character cc) //overloaded < for the Item class
{
	cout << "< operator" << endl;
	bool status;

	if (getClass() < cc.getClass())
		status = true;
	else
		status = false;
	return status;
}


bool Character::operator==(Character c)
{
	cout << "== operator" << endl;
	bool status;

	if (getPosition() == c.getPosition())
		status = true;
	else
		status = false;

	return status;
}
Character Character::operator++(int)
{
	cout << "++ operator" << endl;
	position++;
	return *this;
}

bool Character::operator!=(Character c)
{
	cout << "!= operator" << endl;
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
	string c, r, n, s;
	ofstream myfile;
	myfile.open("savedCharacters.txt");
	while (nodePtr != nullptr)
	{
		c = nodePtr->value.getClass();
		r = nodePtr->value.getRace();
		n = nodePtr->value.getName();

		myfile << 4 << " " << 1 << c << "," << r << "." << n << "?" << s << "\n";
		nodePtr = nodePtr->next;
	}
	myfile.close();
}


