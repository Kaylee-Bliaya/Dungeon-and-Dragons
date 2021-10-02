#ifndef	WARRIOR_H
#define WARRIOR_H
#include "CommonStatistics.h"
using namespace std;

class Warrior : public CommonStatistics
{
	private:
		int healing; 
		int initMod;
	public:
		Warrior(string n);
		int heal();
		virtual void printStats();
		virtual int getInitRoll();
		virtual int getAttackDamage();
};
Warrior::Warrior(string n) : CommonStatistics(n)
{
	hp = 20;
	armor = 5;
	attackMod = 3;
	initMod = 4;
}
int Warrior::heal()
{
	healing = rand() % 10 + 2; // determines how how points can be added to the HP when healing
	cout << "You heal yourself for " << healing << " hit points!\n";
	hp = healing + hp;
	if (hp > 20) // if the total HP after healing is greater than 20, assign the HP to just 20
	{
		hp = 20;
		cout << "Total HP now at: " << hp << '\n';
	}
	return hp; // if the player's HP is less than 20 return the actual HP
}
void Warrior::printStats() 
{
	cout << "Warrior " << name << "'s current stats:\n";
	cout << "Health: " << hp << "\nHealing Die: 2 D5\n" << "Base Attack Die: 1 D6\n"
		<< "Armor: " << armor << "\nAttack Modifier (Strength): " << attackMod
		<< "\nInitiative Modifier (Speed): " << initMod << "\n\n";
}
int Warrior::getInitRoll() // calculates the initial roll by adding a random number from 1-20 and the 
{						   // speed modifier of 4
	cout << "You rolled one dice (1-20): Initiative score of " << initRoll
		<< " + a speed modifier of " << initMod << " for a total of "
		<< (initRoll + initMod) << '\n';
	return (initRoll + initMod);
}
int Warrior::getAttackDamage() // calculates the attack damage by adding a random number from 1-6 and the
{							   // strength modifier of 3
	baseAttack = rand() % 6 + 1;
	cout << "You rolled one dice (1-6): Damage score of " << baseAttack
		<< " + a strength modifier of " << attackMod << " for a total of "
		<< (baseAttack + attackMod) << '\n';
	return (baseAttack + attackMod);
}
#endif