#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"

using namespace std;

class Room
{
private:
    Room* upRoom;
    Room* downRoom;
    Room* leftRoom;
    Room* rightRoom;
    bool isExit;
    bool restAreaFound;
    bool beTriggered;
    int index;
    string tag;
    vector<Object*> objects; /*contain 1 or multiple objects, including monster, npc, etc*/
public:
    Room();
    Room(string tag, bool isExit, int index, vector<Object *> objects);
    bool popObject(Object*); /*pop out the specific object, used when the interaction is done*/
    virtual bool environmentEvent(Object*);
    virtual bool findRestArea(Object*);
    virtual bool triggerEvent(Object* obj);
    
   
    /* Set & Get function*/
    void setTag(string tag);
    void setUpRoom(Room*);
    void setDownRoom(Room*);
    void setLeftRoom(Room*);
    void setRightRoom(Room*);
    void setIsExit(bool);
    void setRestAreaFound(bool);
    void setBeTriggered(bool);
    void setIndex(int);
    void setObjects(vector<Object*>);
    string getTag();
    bool getIsExit();
    bool getRestAreaFound();
    bool getBeTriggered();
    int getIndex();
    vector<Object*> getObjects();
    Room* getUpRoom();
    Room* getDownRoom();
    Room* getLeftRoom();
    Room* getRightRoom();
};

#endif // ROOM_H_INCLUDED
