#include "Orcs.h"

//Constructor
Orcs::Orcs(string newName, int newNumofUnits, int newAttackpoint, int newHealthpoint, int newUnitRegen)
{
	this->name = newName;
	this->numOfUnits = newNumofUnits;
	this->attackPoint = newAttackpoint;
	this->healthPoint = newHealthpoint;
	this->unitRegen = newUnitRegen;
	this->battleCry = "Stop running, you'll only die tired!";
}

//Destructor
Orcs::~Orcs()
{
	delete firstEnemy;
	delete secondEnemy;
}

void Orcs::RecieveAttack(string input, int damage)	//input is attacker's name
{
	if (input == "elves")	//in elves case
	{
		damage = damage * 0.75;
	}
	else//in dwarves case
	{
		damage = damage * 0.8;
	}
	this->numOfUnits -= damage / this->healthPoint;
}

void Orcs::PerformAttack()
{
	int totalDamage = attackPoint * numOfUnits;

	if (firstEnemy->IsAlive() && secondEnemy->IsAlive())	//if both alive
	{
		firstEnemy->RecieveAttack("orcs", totalDamage * 0.7);
		secondEnemy->RecieveAttack("orcs", totalDamage * 0.3);
	}
	else if (firstEnemy->IsAlive() && !secondEnemy->IsAlive())	//if second is dead
	{
		firstEnemy->RecieveAttack("orcs", totalDamage);
	}
	else//if first dead
	{
		secondEnemy->RecieveAttack("orcs", totalDamage);
	}
}

int Orcs::PurchaseWeapons(int input)
{
	attackPoint += input * 2;
	return 20 * input;//gold
}

int Orcs::PurchaseArmors(int input)
{
	healthPoint += input * 3;
	return input;//gold
}

void Orcs::Print()
{
	cout << battleCry << endl;
	Faction::Print();	//unnecessary to add redundant code
}



