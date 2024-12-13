#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"

using namespace std;

class Monster: public GameCharacter
{
private:
    Poison* poison;
public:
    Monster();
    Monster(string name, int maxHealth, int attack, int defense, Poison *poison);

    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
    bool triggerEvent(Object*);
    Poison* getPoison();
    void setPoison(Poison* newPoison);
    
};


#endif // MONSTER_H_INCLUDED
