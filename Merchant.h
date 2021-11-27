#ifndef MERCHANT_H
#define MERCHANT_H

#include "Faction.h"

class Merchant
{
	Faction* firstFaction;
	Faction* secondFaction;
	Faction* thirdFaction;
	int startWeaponPoint;
	int startArmorPoint;
	int revenue;
	int weaponPoint;
	int armorPoint;
public:
	Merchant(int, int);
	bool SellWeapons(string, int); //name and input
	void AssignFactions(Faction*, Faction*, Faction*);
	bool SellArmors(string, int); //name and input
	void EndTurn();

	int GetRevenue()
	{
		return revenue;
	}
	int GetWeaponPoints()
	{
		return weaponPoint;
	}
	int GetArmorPoints()
	{
		return armorPoint;
	}

	void setRevenue(int input)
	{
		revenue = input;
	}
};


#endif