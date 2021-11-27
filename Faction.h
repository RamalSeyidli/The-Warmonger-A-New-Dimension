
#ifndef FACTION_H
#define FACTION_H

#include <string>
#include <iostream>
using namespace std;

class Faction
{
protected:
	string name;
	Faction* firstEnemy;
	Faction* secondEnemy;
	int numOfUnits;
	int attackPoint;
	int healthPoint;
	int unitRegen;
	int totalHealth;
	bool status;
	string battleCry;	//Added by me to keep battle cry

public:
	Faction(string, int, int, int, int);
	Faction()
	{}
	~Faction();
	void AssignEnemies(Faction*, Faction*);
	virtual void PerformAttack() = 0;
	virtual void RecieveAttack(string, int) = 0;
	virtual int PurchaseWeapons(int) = 0;
	virtual int PurchaseArmors(int) = 0;
	virtual void Print();
	void EndTurn();

	bool IsAlive() {	//added because it is asked in main
		return status;
	}

	//Added to use in print function
	string statusChecker()
	{
		if (status)
		{
			return "Alive";
		}
		else
		{
			return "Defeated";
		}
	}

	//Setter function added by me to use in EndTurn function of Faction(s)
	void setStatus(bool input)
	{
		status = input;
	}

	//Getter function added by me to use in EndTurn function of Faction(s)
	int getNumOfUnits()
	{
		return numOfUnits;
	}

	//Setter function added by me to use in EndTurn function of Faction(s)
	void setNumOfUnits(int input)
	{
		numOfUnits = input;
	}

	//Getter function added by me to use in EndTurn function of Faction(s)
	int getTotalHealth()
	{
		return totalHealth;
	}

	//Setter function added by me to use in EndTurn function of Faction(s)
	void setTotalHealth(int input)
	{
		totalHealth = input;
	}

	//Added to be used in attack functions
	int getAttackPoint()
	{
		return attackPoint;
	}

	//Added to be used in attack functions
	int getHealthPoint()
	{
		return healthPoint;
	}

	//used in Merchant sell weapons
	string getName()
	{
		return name;
	}

	//Getter func to is in endturn
	int getUnitRegen() {
		return unitRegen;
	}
};


#endif