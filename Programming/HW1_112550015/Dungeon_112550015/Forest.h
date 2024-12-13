#ifndef FOREST_H_INCLUDED
#define FOREST_H_INCLUDED

#include "Room.h"
#include "Player.h"

class Forest : public Room {
private:
public:
    Forest();
    Forest(bool, int, vector<Object*>);
    virtual bool environmentEvent(Object* obj) override;
    virtual bool findRestArea(Object* obj) override;
    virtual bool triggerEvent(Object *obj) override;
};

#endif // FOREST_H_INCLUDED
