#include "Room.h"
// #define TEST

Room::Room() : tag(""), upRoom(nullptr), downRoom(nullptr), leftRoom(nullptr), rightRoom(nullptr), isExit(false), index(0), objects({}) {}

Room::Room(string tag, bool isExit, int index, vector<Object*> objects) : tag(tag), upRoom(nullptr), downRoom(nullptr), leftRoom(nullptr), rightRoom(nullptr), isExit(isExit), index(index), objects(objects), beTriggered(false), restAreaFound(false) {}

bool Room::environmentEvent(Object*){return false;}
bool Room::findRestArea(Object*){return false;}
bool Room::triggerEvent(Object*){return false;}

bool Room::popObject(Object* obj) {
    auto it = find(objects.begin(), objects.end(), obj);
    if (it != objects.end()) {
        objects.erase(it);
#ifdef TEST
    cout<<"Test:"<<"objects erase successfully"<<endl; //test
#endif
        return true;
    }
    return false;
}

void Room::setTag(string tag) {
    this->tag = tag;
}

void Room::setUpRoom(Room* room) {
    this->upRoom = room;
}

void Room::setDownRoom(Room* room) {
    this->downRoom = room;
}

void Room::setLeftRoom(Room* room) {
    this->leftRoom = room;
}

void Room::setRightRoom(Room* room) {
    this->rightRoom = room;
}

void Room::setIsExit(bool isExit) {
    this->isExit = isExit;
}

void Room::setIndex(int index) {
    this->index = index;
}

void Room::setObjects(vector<Object*> objects) {
    this->objects = objects;
}

void Room::setRestAreaFound(bool restAreaFound){
    this->restAreaFound = restAreaFound;
}

void Room::setBeTriggered(bool beTriggered) {
    this->beTriggered = beTriggered;
}

string Room::getTag() {
    return this->tag;
}

bool Room::getIsExit() {
    return this->isExit;
}

bool Room::getRestAreaFound() {
    return this->restAreaFound;
}

bool Room::getBeTriggered() {
    return this->beTriggered;
}

int Room::getIndex() {
    return this->index;
}

vector<Object*> Room::getObjects() {
    return this->objects;
}

Room* Room::getUpRoom() {
    return this->upRoom;
}

Room* Room::getDownRoom() {
    return this->downRoom;
}

Room* Room::getLeftRoom() {
    return this->leftRoom;
}

Room* Room::getRightRoom() {
    return this->rightRoom;
}
