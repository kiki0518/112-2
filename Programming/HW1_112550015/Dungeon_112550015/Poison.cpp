#include "Poison.h"

using namespace std;

// Default constructor
Poison::Poison() : name(""), level(0), duration(0), type(0) {}

// Parameterized constructor
Poison::Poison(string name, int level, int duration, int type) : name(name), level(level), duration(duration), type(type) {}

// Getter for poison level
int Poison::getLevel() const {
    return level;
}

// Getter for poison duration
int Poison::getDuration() const {
    return duration;
}

// Getter for poison type
int Poison::getType() const {
    return type;
}

// Getter for poison name
string Poison::getName() const {
    return name;
}

// Setter for poison level
void Poison::setLevel(int level) {
    this->level = level;
}

// Setter for poison duration
void Poison::setDuration(int duration) {
    this->duration = duration;
}

// Setter for poison type
void Poison::setType(int type) {
    this->type = type;
}

// Setter for poison name
void Poison::setName(string name) {
    this->name = name;
}

// Decrease poison duration
void Poison::decreaseDuration() {
    duration--;
}
