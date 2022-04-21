#ifndef RACES_H
#define RACES_H
#include <string>
using namespace std;
class Races
{
protected:
	string raceList;
	string raceDesc;
	string racialBonuses;
	int position;
public:
	Races() { raceList = " "; }
	~Races() {  }
	Races(string rl, string rd) { raceList = rl; raceDesc = rd; }
	Races(int p) { position = p; }
	int getPosition() { return position; }
	string getRaceDesc() { return raceDesc; }
	string getRaceList() { return raceList; }
	bool operator==(Races);
	Races operator++(int);
	string toString() const { return raceList; }
	template <typename T>
	string to_string(const T& object) {
		std::ostringstream ss;
		ss << object;
		return ss.str();
	}
	bool operator<(Races);
	friend ostream& operator<<(ostream&, Races&);
};
#endif


ostream& operator<<(ostream& out, Races& items) //overloaded << for the Item class
{
	out << items.getRaceList() << items.getRaceDesc();
	return out;
}

bool Races::operator<(Races cc) //overloaded < for the Item class
{
	bool status;
	if (getRaceList()< cc.getRaceList())
		status = true;
	else
		status = false;
	return status;
}

ostream& operator<< (ostream& outs, const Races& obj) {
	return outs << obj.toString();
}
bool Races::operator==(Races c)
{
	if (getPosition() == c.getPosition())
		return true;
	return false;
}
Races Races::operator++(int)
{
	position++;
	return *this;
}

