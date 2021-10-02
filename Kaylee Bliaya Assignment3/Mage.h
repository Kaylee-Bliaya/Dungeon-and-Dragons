#ifndef	MAGE_H
#define MAGE_H
#include "CommonStatistics.h"
using namespace std;

class Mage : public CommonStatistics
{
	public:
		Mage(string n);
		virtual void printStats();
		virtual int getInitRoll();
		virtual int getAttackDamage();
};
Mage::Mage(string n) : CommonStatistics(n)
{
	hp = 15;
	baseAttack = rand() % 4 + 1;
	armor = 2;
	attackMod = 7;
}
void Mage::printStats()
{
	cout << "Mage " << name << "'s current stats:\n";
	cout << "Health: " << hp << "\nBase Attack Die: 1 D4\n" << "Armor: " << armor 
		<< "\nAttack Modifier (Intellect): " << attackMod << '\n';
}
int Mage::getInitRoll() // calculates the initial roll by rolling a number from 1-20
{
	cout << "The Mage rolled one dice (1-20): Initiative score of " << initRoll
		<< " and has no bonus speed modifier\n";
	return initRoll;
}
int Mage::getAttackDamage() // calculates the attack damage by rolling a number from 1-4 and adding the
{							// intelligence modifier of 7
	baseAttack = rand() % 4 + 1;
	cout << name << " rolled one dice (1-4): Damage score of " << baseAttack
		<< " + an intellect modifier of " << attackMod << " for a total of "
		<< (baseAttack + attackMod) << '\n';
	return (baseAttack + attackMod);
}
#endif