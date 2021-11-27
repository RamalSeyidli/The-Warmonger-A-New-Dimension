#ifndef DWARVES_H
#define DWARVES_H

#include "Faction.h"

class Dwarves : public Faction
{
public:
	Dwarves(string, int, int, int, int);
	~Dwarves();
	void PerformAttack();
	void RecieveAttack(string, int);
	int PurchaseWeapons(int);
	int PurchaseArmors(int);
	void Print();
};

#endif