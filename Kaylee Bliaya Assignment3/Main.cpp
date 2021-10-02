// Kaylee Bliaya    May 8, 2020
// Section 17
// Assignment 3
// This program is a simplified version of D&D.

#include <iostream>
#include "CommonStatistics.h"
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"
#include <time.h>
#include <memory>
using namespace std;

// function to simulate the Warrior figthing with the Mage
void playRound1(shared_ptr<Warrior> &warrior, shared_ptr<Mage> &mage);
// function to simulate the Warrior figthing with the Rogue
void playRound2(shared_ptr<Warrior> &warrior, shared_ptr<Rogue> &rogue);
// functions for the user to choose whether to attack or heal 
void attackOrHeal1(shared_ptr<Warrior> &warrior, shared_ptr<Mage> &mage);
void attackOrHeal2(shared_ptr<Warrior>& warrior, shared_ptr<Rogue>& rogue);

int main()
{
    srand(time(0));

    shared_ptr<Warrior> warrior1 = make_shared<Warrior>("Knight Timmy");
    shared_ptr<Warrior> warrior2 = make_shared<Warrior>("Knight Timmy");
    shared_ptr<Mage> mage = make_shared<Mage>("Wizard Gandolfo");
    shared_ptr<Rogue> rogue = make_shared<Rogue>("Assassin Jim");
    
    playRound1(warrior1, mage); // calls the function for round 1 of the game
    if (mage->getHP() <= 0)
    {
        cout << "The Mage has been slain!\n\n";
    }

    playRound2(warrior2, rogue); // calls the function for round 2 of the game
    if (rogue->getHP() <= 0)
    {
        cout << "The Rogue has been slain!\n" << "You Won the Video Game!\n";
    }

    system("PAUSE");
    return 0;
}

void playRound1(shared_ptr<Warrior> &warrior, shared_ptr<Mage> &mage)
{
    int initW, initM, attack;
    cout << "You are now " << warrior->getName() << ", a ferocious Warrior\n";
    cout << "A Mage named " << mage->getName() << " appears and is ready to battle!\n\n";
    warrior->printStats(); // print stats for the Warrior
    mage->printStats(); // print stats for the Mage

    // loop while the Warrior and Mage's HP is NOT 0
    while (warrior->getHP() > 0 && mage->getHP() > 0)
    {
        cout << '\n';
        // these call getInitRoll() function in CommonStatistics
        initW = warrior->getInitRoll(); // assigns the Warrior's initial roll
        initM = mage->getInitRoll(); // assigns the Mage's initial roll
        cout << '\n';

        if (initW > initM) // enter if the Warrior's initial roll is larger than the Mage's roll
        {
            attackOrHeal1(warrior, mage); // call function to choose whether the Warrior attacks or heals
            cout << mage->getName() << "'s Move:\n";
            // prints the Mage's attack damage and assigns it to attack
            attack = mage->getAttackDamage();
            // subtract the Mage's attack damage from the Warrior's HP using minsHP() in CommonStatistics
            warrior->minusHP(attack);
        }
        else // enter if the Mage's initial roll is larger than the Warrior's
        {
            cout << mage->getName() << "'s Move:\n";
            attack = mage->getAttackDamage();
            warrior->minusHP(attack);
            attackOrHeal1(warrior, mage); 
        }
    }
}
void attackOrHeal1(shared_ptr<Warrior>& warrior, shared_ptr<Mage>& mage)
{
    int attack, move;

    cout << "Your Move:\n" << "What will you do?\n" << "1. Attack\n" << "2. Heal\n";
    cin >> move;
    if (move == 1) // enter if the user chooses to attack
    {
        // prints the Warrior's attack damage and assigns it to attack
        attack = warrior->getAttackDamage();
        // subtract the Warrior's attack damage from the Mage's HP using minsHP() in CommonStatistics
        mage->minusHP(attack);
    }
    else // enter if the user chooses to heal
    {
        warrior->heal(); // add points to the Warrior's HP with heal() in Warrior.h
    }
}

void playRound2(shared_ptr<Warrior> &warrior, shared_ptr<Rogue> &rogue)
{
    int initW, initR, attack;

    cout << "A magical fairy visits you, health has been reset to 20!\n";
    cout << "A Rogue named " << rogue->getName() << " appears and is ready to battle!\n\n";
    warrior->printStats(); // prints stats for Warrior
    rogue->printStats(); // prints stats for Rogue

    // loop while the Warrior and Rogue's HP is NOT 0
    while (warrior->getHP() > 0 && rogue->getHP() > 0)
    {
        cout << '\n';
        initW = warrior->getInitRoll(); // assigns the Warrior's initial roll
        initR = rogue->getInitRoll(); // assigns the Rogue's initial roll
        cout << '\n';
        if (initW > initR) // enter if the Warrior's initial roll is larger than the Rogue's
        {
            attackOrHeal2(warrior, rogue); 
            cout << rogue->getName() << "'s Move:\n";
            // prints the Rogue's attack damage and assigns it to attack
            attack = rogue->getAttackDamage();
            // subtract the Rogue's attack damage from the Warrior's HP using minsHP() in CommonStatistics
            warrior->minusHP(attack);
        }
        else // enter if the Rogue's initial roll is larger than the Warrior's
        {
            cout << rogue->getName() << "'s Move:\n";
            attack = rogue->getAttackDamage();
            warrior->minusHP(attack);
            attackOrHeal2(warrior, rogue);
        }
    }
}
void attackOrHeal2(shared_ptr<Warrior>& warrior, shared_ptr<Rogue>& rogue)
{
    int attack, move;

    cout << "\nYour Move:\n" << "What will you do?\n" << "1. Attack\n" << "2. Heal\n";
    cin >> move;
    if (move == 1)
    {
        attack = warrior->getAttackDamage();
        if (rogue->getDodge() == 1) // if getDodge() returns 1 then the Rogue doesn't take damage
        {
            cout << "Assassin Jim Dodged the attack!\n";
        }
        else
        {
            // subtract the Warrior's attack damage from the Rogue's HP using minsHP() in CommonStatistics
            rogue->minusHP(attack);
        }
    }
    else
    {
        warrior->heal();
    }
}

/*
--- Sample Output ---
You are now Knight Timmy, a ferocious Warrior
A Mage named Wizard Gandolfo appears and is ready to battle!

Warrior Knight Timmy's current stats:
Health: 20
Healing Die: 2 D5
Base Attack Die: 1 D6
Armor: 5
Attack Modifier (Strength): 3
Initiative Modifier (Speed): 4

Mage Wizard Gandolfo's current stats:
Health: 15
Base Attack Die: 1 D4
Armor: 2
Attack Modifier (Intellect): 7

You rolled one dice (1-20): Initiative score of 8 + a speed modifier of 4 for a total of 12
The Mage rolled one dice (1-20): Initiative score of 17 and has no bonus speed modifier

Wizard Gandolfo's Move:
Wizard Gandolfo rolled one dice (1-4): Damage score of 3 + an intellect modifier of 7 for a total of 10
Knight Timmy has taken 5 damage and is now at 15 HP
Your Move:
What will you do?
1. Attack
2. Heal
1
You rolled one dice (1-6): Damage score of 1 + a strength modifier of 3 for a total of 4
Wizard Gandolfo has taken 2 damage and is now at 13 HP

You rolled one dice (1-20): Initiative score of 8 + a speed modifier of 4 for a total of 12
The Mage rolled one dice (1-20): Initiative score of 17 and has no bonus speed modifier

Wizard Gandolfo's Move:
Wizard Gandolfo rolled one dice (1-4): Damage score of 1 + an intellect modifier of 7 for a total of 8
Knight Timmy has taken 3 damage and is now at 12 HP
Your Move:
What will you do?
1. Attack
2. Heal
1
You rolled one dice (1-6): Damage score of 5 + a strength modifier of 3 for a total of 8
Wizard Gandolfo has taken 6 damage and is now at 7 HP

You rolled one dice (1-20): Initiative score of 8 + a speed modifier of 4 for a total of 12
The Mage rolled one dice (1-20): Initiative score of 17 and has no bonus speed modifier

Wizard Gandolfo's Move:
Wizard Gandolfo rolled one dice (1-4): Damage score of 4 + an intellect modifier of 7 for a total of 11
Knight Timmy has taken 6 damage and is now at 6 HP
Your Move:
What will you do?
1. Attack
2. Heal
2
You heal yourself for 8 hit points!

You rolled one dice (1-20): Initiative score of 8 + a speed modifier of 4 for a total of 12
The Mage rolled one dice (1-20): Initiative score of 17 and has no bonus speed modifier

Wizard Gandolfo's Move:
Wizard Gandolfo rolled one dice (1-4): Damage score of 3 + an intellect modifier of 7 for a total of 10
Knight Timmy has taken 5 damage and is now at 9 HP
Your Move:
What will you do?
1. Attack
2. Heal
1
You rolled one dice (1-6): Damage score of 5 + a strength modifier of 3 for a total of 8
Wizard Gandolfo has taken 6 damage and is now at 1 HP

You rolled one dice (1-20): Initiative score of 8 + a speed modifier of 4 for a total of 12
The Mage rolled one dice (1-20): Initiative score of 17 and has no bonus speed modifier

Wizard Gandolfo's Move:
Wizard Gandolfo rolled one dice (1-4): Damage score of 4 + an intellect modifier of 7 for a total of 11
Knight Timmy has taken 6 damage and is now at 3 HP
Your Move:
What will you do?
1. Attack
2. Heal
1
You rolled one dice (1-6): Damage score of 5 + a strength modifier of 3 for a total of 8
Wizard Gandolfo has taken 6 damage and is now at 0 HP
The Mage has been slain!

A magical fairy visits you, health has been reset to 20!
A Rogue named Assassin Jim appears and is ready to battle!

Warrior Knight Timmy's current stats:
Health: 20
Healing Die: 2 D5
Base Attack Die: 1 D6
Armor: 5
Attack Modifier (Strength): 3
Initiative Modifier (Speed): 4

Rogue Assassin Jim's current stats:
Health: 10
Base Attack Die: 2 D4
Armor: 3
Attack Modifier (Agility): 4
Initiative Modifier (Speed): 5
Dodge: 50% chance to dodge an incoming attack
You rolled one dice (1-20): Initiative score of 11 + a speed modifier of 4 for a total of 15
The Rogue rolled one dice (1-20): Initiative score of 19 + a speed modifier of 5 for a total of 24

Assassin Jim's Move:
Assassin Jim rolled two dice (1-4): Damage score of 4 + an agility modifier of 4 for a total of 8
Knight Timmy has taken 3 damage and is now at 17 HP

Your Move:
What will you do?
1. Attack
2. Heal
1
You rolled one dice (1-6): Damage score of 2 + a strength modifier of 3 for a total of 5
Assassin Jim has taken 2 damage and is now at 8 HP

You rolled one dice (1-20): Initiative score of 11 + a speed modifier of 4 for a total of 15
The Rogue rolled one dice (1-20): Initiative score of 19 + a speed modifier of 5 for a total of 24

Assassin Jim's Move:
Assassin Jim rolled two dice (1-4): Damage score of 2 + an agility modifier of 4 for a total of 6
Knight Timmy has taken 1 damage and is now at 16 HP

Your Move:
What will you do?
1. Attack
2. Heal
1
You rolled one dice (1-6): Damage score of 5 + a strength modifier of 3 for a total of 8
Assassin Jim Dodged the attack!

You rolled one dice (1-20): Initiative score of 11 + a speed modifier of 4 for a total of 15
The Rogue rolled one dice (1-20): Initiative score of 19 + a speed modifier of 5 for a total of 24

Assassin Jim's Move:
Assassin Jim rolled two dice (1-4): Damage score of 2 + an agility modifier of 4 for a total of 6
Knight Timmy has taken 1 damage and is now at 15 HP

Your Move:
What will you do?
1. Attack
2. Heal
2
You heal yourself for 9 hit points!
Total HP now at: 20

You rolled one dice (1-20): Initiative score of 11 + a speed modifier of 4 for a total of 15
The Rogue rolled one dice (1-20): Initiative score of 19 + a speed modifier of 5 for a total of 24

Assassin Jim's Move:
Assassin Jim rolled two dice (1-4): Damage score of 2 + an agility modifier of 4 for a total of 6
Knight Timmy has taken 1 damage and is now at 19 HP

Your Move:
What will you do?
1. Attack
2. Heal
1
You rolled one dice (1-6): Damage score of 6 + a strength modifier of 3 for a total of 9
Assassin Jim has taken 6 damage and is now at 2 HP

You rolled one dice (1-20): Initiative score of 11 + a speed modifier of 4 for a total of 15
The Rogue rolled one dice (1-20): Initiative score of 19 + a speed modifier of 5 for a total of 24

Assassin Jim's Move:
Assassin Jim rolled two dice (1-4): Damage score of 3 + an agility modifier of 4 for a total of 7
Knight Timmy has taken 2 damage and is now at 17 HP

Your Move:
What will you do?
1. Attack
2. Heal
1
You rolled one dice (1-6): Damage score of 2 + a strength modifier of 3 for a total of 5
Assassin Jim has taken 2 damage and is now at 0 HP
The Rogue has been slain!
You Won the Video Game!
*/