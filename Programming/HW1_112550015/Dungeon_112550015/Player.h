#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Room.h"
#include "Item.h"
#include "Poison.h"
#include "Monster.h"

using namespace std;

class Item;
class Poison;
class Monster;

class Player: public GameCharacter
{
private:
    int hunger;
    int thirst;
    int money;
    Room* currentRoom;
    Room* previousRoom;
    Poison* poison;
    vector<Item> inventory;
public:
    Player();
    Player(string,int,int,int,int,int,Poison*,int);
    void addItem(Item);
    void equipItem(Item item);
    void openBackpack();
    bool increaseStates(int,int,int,int,int,Poison*,int);
    bool handleStatus();
    bool changeRoom(Room*);

    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(Object*);
    

    /* Set & Get function*/
    void setHunger(int); 
    void setThirst(int); 
    void setMoney(int);
    void setPoison(Poison*);
    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    void setInventory(vector<Item>);
    int getHunger() const; 
    int getThirst() const;
    int getMoney() const;
    Poison* getPoison() const; 
    Room* getCurrentRoom();
    Room* getPreviousRoom();
    vector<Item> getInventory(); 
};

#endif // PLAYER_H_INCLUDED
