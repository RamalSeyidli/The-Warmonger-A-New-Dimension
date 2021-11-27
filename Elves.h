#ifndef ELVES_H
#define ELVES_H

#include "Faction.h"

class Elves : public Faction
{
public:
	Elves(string, int, int, int, int);
	~Elves();
	void PerformAttack();
	void RecieveAttack(string, int);
	int PurchaseWeapons(int);
	int PurchaseArmors(int);
	void Print();
};

#endif