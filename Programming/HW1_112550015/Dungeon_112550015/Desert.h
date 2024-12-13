#ifndef DESERT_H_INCLUDED
#define DESERT_H_INCLUDED

#include "Room.h"
#include "Player.h"

class Desert : public Room {
private:
public: 
    Desert();
    Desert(bool, int, vector<Object*>);
    virtual bool environmentEvent(Object* obj) override;
    virtual bool findRestArea(Object* obj) override;
    virtual bool triggerEvent(Object* obj) override;
};

#endif // DESERT_H_INCLUDED
