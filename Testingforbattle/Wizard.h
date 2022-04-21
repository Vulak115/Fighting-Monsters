#ifndef WIZARD_H
#define WIZARD_H

class Wizard : public Character 
{
private:
public:
	Wizard() : Character(){}
	Wizard(string c, string r, string n, int exp) {
		Class = c; race = r; ; name = n; experience = exp; 
	}
	Wizard(string n) { name = n; }
	~Wizard(){}
	void setStats(double);
	int Attack();
	void updateCharHP(int atk,string,Character*);
};
#endif
void Wizard::updateCharHP(int atk,string mname,Character*c)
{
		if (dodge > 10&&atk)
		{
			cout << "Your magic shield absorbed the attack!!" << endl;
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


void Wizard::setStats(double lvll)
{
	lvl = lvll;
	healthPoints = 100 + (2* lvll);
	currHP = healthPoints;
	minDmg = 60 + (5 * lvll);
	maxDmg = 130 + (7 * lvll);
}
int Wizard::Attack()
{
	int chance = 0;
	int damage = 0;
	chance = rand() % (100 - 1 + 1) + 1;
	double critChance = 10 + (.1*lvl);
	if (lvl >= 100) critChance = 20;
	//cout << critChance << endl;
	if (chance < critChance)
	{
		damage = rand() % (maxDmg - minDmg + 1) + minDmg;
		cout << "Critical Hit!" << endl;
	}
	else
		damage = rand() % (((maxDmg/10) - (minDmg/10) + 1) + (minDmg/10));
		
	return damage;
}