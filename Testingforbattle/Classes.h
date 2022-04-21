#ifndef CLASSES_H
#define CLASSES_H
#include <string>
using namespace std;

class Classes
{
protected:
	string *classNam;
	string *classDes;
	string className;
	string classDesc;
	int position;
public:
	Classes() { className = " "; classDesc = " "; position = 0; }
	Classes(string cn, string cd) { className = cn; classDesc = cd; }
	Classes(string *cn, string *cd) { classNam = cn; classDes = cd; }
	Classes(int p) { position = p; }
	int getPosition() { return position; }
	string getClassName() { return className; }
	string getClassDesc() { return classDesc; }
	bool operator<(Classes);
	bool operator==(Classes);
	Classes operator++(int);
	string toString() const { return className; }
	template <typename T>
	string to_string(const T& object) {
		std::ostringstream ss;
		ss << object;
		return ss.str();
	}
	friend ostream& operator<<(ostream&, Classes&);


};
#endif
bool Classes::operator<(Classes cc) //overloaded < for the Item class
{
	bool status;
	if (getClassName()< cc.getClassName())
		status = true;
	else
		status = false;
	return status;
}
ostream& operator<<(ostream& out, Classes& items) //overloaded << for the Item class
{
	out << items.getClassName() << items.getClassDesc();
	return out;
}
ostream& operator<< (ostream& outs, const Classes& obj) {
	return outs << obj.toString();
}
bool Classes::operator==(Classes c)
{
	if (getPosition() == c.getPosition())
		return true;
	return false;
}
Classes Classes::operator++(int)
{
	position++;
	return *this;
}


