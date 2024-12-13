#ifndef SWAMP_H_INCLUDED
#define SWAMP_H_INCLUDED

#include "Room.h"
#include "Player.h"
// #include "Poison.h" // Include Poison class header

class Swamp : public Room {
private:
    Poison* poison; // Instance of Poison to represent the poison in the swamp
public:
    Swamp(); 
    Swamp(bool, int, vector<Object*>);
    virtual bool environmentEvent(Object* obj) override;
    virtual bool findRestArea(Object*)  override;
    virtual bool triggerEvent(Object* obj) override; 
};

#endif // SWAMP_H_INCLUDED
