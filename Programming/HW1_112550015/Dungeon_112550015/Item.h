#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Player.h"

using namespace std;

class Player; // Forward declaration of Player class

class Item : public Object
{
private:
    int health;
    int attack;
    int defense;
    int hunger;
    int thirst;
    bool isDetoxic;
    int money;

public:
    Item();
    Item(string, int, int, int, int, int, bool, int);

    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    bool triggerEvent(Object*);

    /* Set & Get functions for health, attack, defense, hunger, thirst, and isDetoxic */
    int getHealth();
    int getAttack();
    int getDefense();
    int getHunger();
    int getThirst();
    bool getIsDetoxic();
    int getMoney();
    void setHealth(int);
    void setAttack(int);
    void setDefense(int);
    void setHunger(int);
    void setThirst(int);
    void setIsDetoxic(bool);
    void setMoney(int);
};

#endif // ITEM_H_INCLUDED
