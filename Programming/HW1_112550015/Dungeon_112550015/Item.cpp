#include "Item.h"

Item::Item() : Object(), health(0), attack(0), defense(0), hunger(0), thirst(0), isDetoxic(false), money(0) {}

Item::Item(string name, int health, int attack, int defense, int hunger, int thirst, bool isDetoxic, int money)
    : Object(name, "Item"), health(health), attack(attack), defense(defense), hunger(hunger), thirst(thirst), isDetoxic(isDetoxic), money(money) {}

bool Item::triggerEvent(Object* obj) {
    Player* player = dynamic_cast<Player*>(obj);

    cout << "⠀⠀⠀⢠⡄⢠⣤⣤⠀⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⠀⣤⣤⡄⢠⡄⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⢸⡇⢸⣿⣿⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⣿⣿⡇⢸⡇⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⣿⡇⢸⣿⣿⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⣿⣿⡇⢸⣿⠀⠀⠀" << endl;
    cout << "⠀⠀⢀⣿⡇⢸⣿⣿⠀⣿⣿⣿⠟⠛⠛⠛⠛⠻⣿⣿⣿⠀⣿⣿⡇⢸⣿⡀⠀⠀" << endl;
    cout << "⠀⠀⢈⡉⢁⣀⣉⣉⣀⣉⣉⣉⠀⣴⠖⠲⣦⠀⣉⣉⣉⣀⣉⣉⣀⡈⢉⡁⠀⠀" << endl;
    cout << "⠀⠀⢸⡇⢸⣿⣿⣿⣿⣿⣿⣿⠀⣿⡄⢠⣿⠀⣿⣿⣿⣿⣿⣿⣿⡇⢸⡇⠀⠀" << endl;
    cout << "⠀⠀⢸⡇⢸⣿⣿⣿⣿⣿⣿⣿⠀⣿⣧⣼⣿⠀⣿⣿⣿⣿⣿⣿⣿⡇⢸⡇⠀⠀" << endl;
    cout << "⠀⠀⢸⡇⢸⣿⣿⣿⣿⣿⣿⣿⣀⣉⣉⣉⣉⣀⣿⣿⣿⣿⣿⣿⣿⡇⢸⡇⠀⠀" << endl;
    cout << "⠀⠀⠘⠇⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠸⠃⠀⠀" << endl;
    cout << "⠀⠀⢰⣄⠈⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠁⣠⡆⠀⠀" << endl;
    cout << "⠀⠀⠘⠛⠃⠈⠙⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠋⠁⠘⠛⠃⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;

    cout << "You found a chest! Do you want to open it? (Y/N): ";
    
    
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        cout << "⠀⠀⠀⠀⠀⠀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
        cout << "⠀⠀⠀⠀⠀⠺⠿⠿⠿⠿⢿⣿⣿⣶⣶⣶⣶⣤⣤⣤⣤⣄⣀⣀⡀⠀⠀⠀⠀⠀" << endl;
        cout << "⠀⠀⠀⠀⠀⢾⣷⡆⢰⣶⣦⣤⣤⣤⣤⣉⣉⣉⣉⠙⠛⠛⠛⠛⢠⣿⣷⠀⠀⠀" << endl;
        cout << "⠀⠀⠀⠀⠀⠘⣿⡇⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠈⣿⣿⠀⠀⠀" << endl;
        cout << "⠀⠀⠀⠀⠀⠀⠸⠇⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠸⣿⠀⠀⠀" << endl;
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠿⠿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠻⠀⠀⠀" << endl;
        cout << "⠀⠀⠀⠀⠀⢀⡄⢰⣶⣶⣶⣶⣤⣤⣤⣤⣈⣉⣉⣉⡙⠛⠛⠛⠛⠷⠀⠀⠀⠀" << endl;
        cout << "⠀⠀⠀⠀⠾⠿⡇⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠗⢀⠀⠀⠀⠀" << endl;
        cout << "⠀⠀⠀⣶⣶⣶⣤⣤⣤⣤⣈⣉⣉⣉⡙⠛⠛⠛⠛⠿⠿⠿⠛⣁⣴⣿⠀⠀⠀⠀" << endl;
        cout << "⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣟⠉⣿⣿⣿⣿⣿⣿⣶⣶⡆⢸⣿⣿⣿⠀⠀⠀⠀" << endl;
        cout << "⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣼⣿⣿⣿⣿⣿⣿⣿⣿⡇⢸⣿⣿⣿⠀⠀⠀⠀" << endl;
        cout << "⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢸⣿⣿⣿⠀⠀⠀⠀" << endl;
        cout << "⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢸⣿⣿⡿⠀⠀⠀⠀" << endl;
        cout << "⠀⠀⠀⠉⠉⠉⠙⠛⠛⠛⠻⠿⠿⠿⠿⣿⣿⣿⣿⣿⣿⡇⢸⠟⠁⠀⠀⠀⠀⠀" << endl;
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠁⠀⠀⠀⠀⠀⠀" << endl;
 
        cout << "You opened the chest and found: " << this->getName() << endl;
        cout << "Do you want to collect it? (Y/N): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y') {
            cout << "You collected " << this->getName() << " and added it to your inventory." << endl;                
            player->addItem(*this);
            return true;
        }
        else {
            cout << "┌──────────────────────────────────────────────┐" << endl;
            cout << "│ You chose not to collect the item.           │" << endl;
            cout << "└──────────────────────────────────────────────┘" << endl;
        }
    } else {
        cout << "┌──────────────────────────────────────────────┐" << endl;
        cout << "│ You chose not to open the chest.             │" << endl;
        cout << "└──────────────────────────────────────────────┘" << endl;
            
    }
    return false;
}


int Item::getHealth() {
    return this->health;
}

int Item::getAttack() {
    return this->attack;
}

int Item::getDefense() {
    return this->defense;
}

int Item::getHunger() {
    return this->hunger;
}

int Item::getThirst() {
    return this->thirst;
}

bool Item::getIsDetoxic() {
    return this->isDetoxic;
}

int Item::getMoney() {
    return this->money;
}

void Item::setHealth(int health) {
    this->health = health;
}

void Item::setAttack(int attack) {
    this->attack = attack;
}

void Item::setDefense(int defense) {
    this->defense = defense;
}

void Item::setHunger(int hunger) {
    this->hunger = hunger;
}

void Item::setThirst(int thirst) {
    this->thirst = thirst;
}

void Item::setIsDetoxic(bool isDetoxic) {
    this->isDetoxic = isDetoxic;
}

void Item::setMoney(int money) {
    this->money = money;
}
