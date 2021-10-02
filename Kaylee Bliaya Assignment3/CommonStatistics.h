#ifndef	COMMONSTATISTICS_H
#define COMMONSTATISTICS_H
#include <iostream>
#include <string>
using namespace std;

class CommonStatistics
{
	protected:
		string name;
		int hp;
		int baseAttack;
		int armor;
		int attackMod;
		int initRoll;
	public:
		CommonStatistics(string n);
		void minusHP(int dmgTaken);

		string getName();
		int getHP();

		virtual int getAttackDamage() = 0;
		virtual int getInitRoll() = 0;
		virtual void printStats() = 0;
};
CommonStatistics::CommonStatistics(string n) // overloaded constructor to assign the players names
{
	name = n;
	initRoll = rand() % 20 + 1;
}
void CommonStatistics::minusHP(int dmgTaken)
{
	dmgTaken = dmgTaken - armor; // calculate the damage by subtracting the player's armor from it
	hp = hp - dmgTaken; // calculate the HP by subtracting the damage from it
	if (hp > 0) // if the player's HP is greater than 0 cout the actual HP
	{
		cout << name << " has taken " << dmgTaken << " damage and is now at " << hp << " HP\n";
	}
	else // if the player's HP is less than 0, then the HP is just 0
	{
		hp = 0;
		cout << name << " has taken " << dmgTaken << " damage and is now at " << hp << " HP\n";
	}

}

string CommonStatistics::getName()
{
	return name;
}
int CommonStatistics::getHP()
{
	return hp;
}
#endif