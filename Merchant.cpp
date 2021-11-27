#include "Merchant.h"

//Constructor

Merchant::Merchant(int startWeaponPoint, int startArmorPoint)
{
	this->startWeaponPoint = startWeaponPoint;
	this->startArmorPoint = startArmorPoint;
}

void Merchant::AssignFactions(Faction* first, Faction* second, Faction* third)
{
	this->firstFaction = first;
	this->secondFaction = second;
	this->thirdFaction = third;
}

bool Merchant::SellWeapons(string name, int input)
{
	if (name == this->firstFaction->getName())		//trying to sell to orcs
	{
		if (!this->firstFaction->IsAlive())	//orcs is not alive
		{
			cout << "The faction you want to sell weapons is dead!" << endl;
			return false;
		}
		else if (input > this->weaponPoint) //weaponPoint is not enough
		{
			cout << "You try to sell more weapons than you have in possession." << endl;
			return false;
		}
		else//success
		{
			revenue += this->firstFaction->PurchaseWeapons(input);
			cout << "Weapons sold!" << endl;
			return true;
		}
	}
	else if (name == this->secondFaction->getName())//trying to sell dwarves
	{
		if (!this->firstFaction->IsAlive())
		{
			cout << "The faction you want to sell weapons is dead!" << endl;
			return false;
		}
		else if (input > this->weaponPoint)
		{
			cout << "You try to sell more weapons than you have in possession." << endl;
			return false;
		}
		else
		{
			revenue += this->secondFaction->PurchaseWeapons(input);
			cout << "Weapons sold!" << endl;
			return true;
		}
	}
	else//trying to sell elves
	{
		if (!this->firstFaction->IsAlive())
		{
			cout << "The faction you want to sell weapons is dead!" << endl;
			return false;
		}
		else if (input > this->weaponPoint)
		{
			cout << "You try to sell more weapons than you have in possession." << endl;
			return false;
		}
		else
		{
			revenue += this->thirdFaction->PurchaseWeapons(input);
			cout << "Weapons sold!" << endl;
			return true;
		}
	}
}

bool Merchant::SellArmors(string name, int input)
{
	if (name == this->firstFaction->getName())//trying to sell to orcs
	{
		if (!this->firstFaction->IsAlive())		//orcs is not alive
		{
			cout << "The faction you want to sell armors is dead!" << endl;
			return false;
		}
		else if (input > this->weaponPoint)//weaponPoint is not enough
		{
			cout << "You try to sell more armors than you have in possession." << endl;
			return false;
		}
		else//success
		{
			revenue += this->firstFaction->PurchaseArmors(input);
			cout << "Armors sold!" << endl;
			return true;
		}
	}
	else if (name == this->secondFaction->getName())//trying to sell dwarves
	{
		if (!this->firstFaction->IsAlive())
		{
			cout << "The faction you want to sell armors is dead!" << endl;
			return false;
		}
		else if (input > this->weaponPoint)
		{
			cout << "You try to sell more armors than you have in possession." << endl;
			return false;
		}
		else
		{
			revenue += this->secondFaction->PurchaseArmors(input);
			cout << "Armors sold!" << endl;
			return true;
		}
	}
	else//trying to sell elves
	{
		if (!this->firstFaction->IsAlive())
		{
			cout << "The faction you want to sell armors is dead!" << endl;
			return false;
		}
		else if (input > this->weaponPoint)
		{
			cout << "You try to sell more armors than you have in possession." << endl;
			return false;
		}
		else
		{
			revenue += this->thirdFaction->PurchaseArmors(input);
			cout << "Armors sold!" << endl;
			return true;
		}
	}
}

void Merchant::EndTurn()
{
	weaponPoint = startWeaponPoint;
	armorPoint = startArmorPoint;
}