#ifndef WARRIOR_H
#define WARRIOR_H

class Warrior :public Character
{
public:
	Warrior() : Character(){}
	Warrior(string c, string r, string n, int exp) {
		Class = c; race = r; ; name = n; experience = exp; 
	}
	Warrior(string n) { name = n; }
	~Warrior(){}
	void setStats(double);
	int Attack();
	void updateCharHP(int atk,string,Character*);
};
#endif
void Warrior::updateCharHP(int atk,string mname,Character*c)
{
		/*int dodge = 0;
		dodge = rand() % (10 - 1 + 1) + 1;
		if (dodge > 5)
		{
			cout << "You dodged the attack and took zero damage" << endl;

		}
		else
		{*/
			currHP -= atk;
			if (currHP < 0)
				currHP = 0;
			cout << mname << " hits " << c->getName() << " for " << atk << " damage.\n";
			cout << c->getName() << " has " << getCurrHP() << "/" << getHP() << " hp left.\n";
		//}
}


void Warrior::setStats(double lvl)
{

	healthPoints = 200 + (12 * lvl);
	currHP = healthPoints;
	minDmg = 25 + (2 * lvl);
	maxDmg = 35 + (2 * lvl);
}
int Warrior::Attack()
{
	int damage = 0;
	damage = rand() % (maxDmg - minDmg + 1) + minDmg;
	//cout << "Warrior!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	return damage;

}