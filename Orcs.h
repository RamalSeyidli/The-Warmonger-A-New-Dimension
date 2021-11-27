#ifndef ORCS_H
#define ORCS_H

#include "Faction.h"

class Orcs : public Faction
{
public:
	Orcs(string, int, int, int, int);
	~Orcs();
	void PerformAttack();
	void RecieveAttack(string, int);
	int PurchaseWeapons(int);
	int PurchaseArmors(int);
	void Print();
};

#endif