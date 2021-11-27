#include "Dwarves.h"

//Constructor
Dwarves::Dwarves(string newName, int newNumofUnits, int newAttackpoint, int newHealthpoint, int newUnitRegen)
{
	this->name = newName;
	this->numOfUnits = newNumofUnits;
	this->attackPoint = newAttackpoint;
	this->healthPoint = newHealthpoint;
	this->unitRegen = newUnitRegen;
	this->battleCry = "Taste the power of our axes!";
}

//Destructor
Dwarves::~Dwarves()
{
	delete firstEnemy;
	delete secondEnemy;
}

void Dwarves::RecieveAttack(string input, int damage)	//input is attacker's name
{
	this->numOfUnits -= damage / this->healthPoint;
}

void Dwarves::PerformAttack()
{
	int totalDamage = attackPoint * numOfUnits;

	if (firstEnemy->IsAlive() && secondEnemy->IsAlive())	//if both alive
	{
		firstEnemy->RecieveAttack("dwarves", totalDamage/2);
		secondEnemy->RecieveAttack("dwarves", totalDamage/2);
	}
	else if (firstEnemy->IsAlive() && !secondEnemy->IsAlive())	//if second is dead
	{
		firstEnemy->RecieveAttack("dwarves", totalDamage);
	}
	else//if first dead
	{
		secondEnemy->RecieveAttack("dwarves", totalDamage);
	}
}

int Dwarves::PurchaseWeapons(int input)
{
	attackPoint += input;
	return 10 * input;//gold
}

int Dwarves::PurchaseArmors(int input)
{
	healthPoint += input * 2;
	return input * 3;//gold
}

void Dwarves::Print()
{
	cout << battleCry << endl;
	Faction::Print();	//unnecessary to add redundant code
}