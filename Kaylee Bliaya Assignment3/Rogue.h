#ifndef	ROGUE_H
#define ROGUE_H
#include "CommonStatistics.h"
using namespace std;

class Rogue : public CommonStatistics
{
	private:
		int dodge;
		int initMod;
	public:
		Rogue(string n);
		int getDodge();
		virtual void printStats();
		virtual int getInitRoll();
		virtual int getAttackDamage();
};
Rogue::Rogue(string n) : CommonStatistics(n)
{
	hp = 10;
	armor = 3;
	attackMod = 4;
	initMod = 5;
}
int Rogue::getDodge() // calculates and returns the chance of dodging an attack
{
	dodge = rand() % 2 + 1;
	return dodge;
}
int Rogue::getInitRoll() // calculates the initial roll by rolling a number from 1-20 and adding the 
{						 // speed modifier of 5
	cout << "The Rogue rolled one dice (1-20): Initiative score of " << initRoll
		<< " + a speed modifier of " << initMod << " for a total of "
		<< (initRoll + initMod) << '\n';
	return (initRoll + initMod);
}
void Rogue::printStats() 
{
	cout << "Rogue " << name << "'s current stats:\n";
	cout << "Health: " << hp << "\nBase Attack Die: 2 D4\n" << "Armor: " << armor
		<< "\nAttack Modifier (Agility): " << attackMod
		<< "\nInitiative Modifier (Speed): " << initMod
		<< "\nDodge: 50% chance to dodge an incoming attack";
}
int Rogue::getAttackDamage() // calculates the attack damage by rolling a number from 2-8 and adding the
{							 // agility modifier of 4
	baseAttack = rand() % 8 + 2;
	cout << name << " rolled two dice (1-4): Damage score of " << baseAttack
		<< " + an agility modifier of " << attackMod << " for a total of "
		<< (baseAttack + attackMod) << '\n';
	return (baseAttack + attackMod);
}
#endif