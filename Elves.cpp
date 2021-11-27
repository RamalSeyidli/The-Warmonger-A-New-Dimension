#include "Elves.h"

//Constructor
Elves::Elves(string newName, int newNumofUnits, int newAttackpoint, int newHealthpoint, int newUnitRegen)
{
	this->name = newName;
	this->numOfUnits = newNumofUnits;
	this->attackPoint = newAttackpoint;
	this->healthPoint = newHealthpoint;
	this->unitRegen = newUnitRegen;
	this->battleCry = "You cannot reach our elegance.";
}

//Destructor
Elves::~Elves()
{
	delete firstEnemy;
	delete secondEnemy;
}

void Elves::RecieveAttack(string input, int damage)	//input is attacker's name
{
	if (input == "orcs")	//in orcs case
	{
		damage = damage * 1.25;
	}
	else//in dwarves case
	{
		damage = damage * 0.75;
	}
	this->numOfUnits -= damage / this->healthPoint;
}

void Elves::PerformAttack()
{
	int totalDamage = attackPoint * numOfUnits;

	if (firstEnemy->IsAlive() && secondEnemy->IsAlive())	//if both alive
	{
		firstEnemy->RecieveAttack("elves", totalDamage * 0.6);
		secondEnemy->RecieveAttack("elves", totalDamage * 0.4 * 1.5);	//firstly, takes 40% then increases it to 150%
	}
	else if (firstEnemy->IsAlive() && !secondEnemy->IsAlive())	//if second is dead
	{
		firstEnemy->RecieveAttack("elves", totalDamage);
	}
	else//if first dead
	{
		secondEnemy->RecieveAttack("elves", totalDamage * 1.5);
	}
}


int Elves::PurchaseWeapons(int input)
{
	attackPoint += input * 2;
	return 15 * input;//gold
}

int Elves::PurchaseArmors(int input)
{
	healthPoint += input * 4;
	return input * 5;//gold
}

void Elves::Print()
{
	cout << battleCry << endl;
	Faction::Print();	//unnecessary to add redundant code
}