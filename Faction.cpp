#include "Faction.h"

//Constructor
Faction::Faction(string newName, int newNumofUnits, int newAttackpoint, int newHealthpoint, int newUnitRegen)
{
	this->name = newName;
	this->numOfUnits = newNumofUnits;
	this->attackPoint = newAttackpoint;
	this->healthPoint = newHealthpoint;
	this->unitRegen = newUnitRegen;
};

//Destructor
Faction::~Faction()
{
	delete firstEnemy;
	delete secondEnemy;
}

//Definition of AssignEnemies function
void Faction::AssignEnemies(Faction* firstEnemy, Faction* secondEnemy)
{
	this->firstEnemy = firstEnemy;
	this->secondEnemy = secondEnemy;
}

//Definition of virtual print function
void Faction::Print()
{
	cout << "Faction name: " << this->name << endl;
	cout << "Status: " << statusChecker() << endl;		//Added by me
	cout << "Number of Units: " << numOfUnits << endl;
	cout << "Attack Point: " << attackPoint << endl;
	cout << "Health Point: " << healthPoint << endl;
	cout << "Unit Regen Number: " << unitRegen << endl;
	cout << "Total Faction Health: " << totalHealth << endl;
}

//Definition of EndTurn function as asked
void Faction::EndTurn()
{
	setNumOfUnits(getNumOfUnits() + getUnitRegen());
	if (getNumOfUnits() < 0)	//sets numOfUnits to 0 if it is below 0
	{
		setNumOfUnits(0);
	}
	if (getNumOfUnits() == 0 || getTotalHealth() == 0)	//updates status
	{
		setStatus(false);
	}
}





