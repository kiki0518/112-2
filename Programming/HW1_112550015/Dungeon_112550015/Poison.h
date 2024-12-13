#ifndef POISON_H_INCLUDED
#define POISON_H_INCLUDED

#include <string>

using namespace std;

class Poison {
private:
    string name; // Poison name
    int level;  // Poison level
    int duration;  // Poison duration in turns
    int type;  // Type of poison (e.g., 1 for monster bite, 2 for contaminated food)
    
public:
    Poison();  // Default constructor
    Poison(string name, int level, int duration, int type);  // Parameterized constructor
    int getLevel() const;  // Getter for poison level
    int getDuration() const;  // Getter for poison duration
    int getType() const;  // Getter for poison type
    string getName() const; // Getter for poison name
    void setLevel(int level);  // Setter for poison level
    void setDuration(int duration);  // Setter for poison duration
    void setType(int type);  // Setter for poison type
    void setName(string name); // Setter for poison name
    void decreaseDuration();  // Decrease poison duration
};

#endif // POISON_H_INCLUDED
