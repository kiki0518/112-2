#include "Player.h"
#include <iomanip>

Player::Player() : GameCharacter(), hunger(0), thirst(0), money(0), currentRoom(nullptr), previousRoom(nullptr), poison(nullptr), inventory({}) {}

Player::Player(string name, int maxHealth, int attack, int defense, int hunger, int thirst, Poison* poison, int money)
    : GameCharacter(name, "Player", maxHealth, attack, defense), hunger(hunger), thirst(thirst), money(money), currentRoom(nullptr), previousRoom(nullptr), poison(poison), inventory({}) {}

void Player::addItem(Item item) {
    cout << "Do you want to equip it? (Y/N): ";
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        equipItem(item);
    } else {
        cout << "You decided not to equip " << item.getName() << ", but you added it to your inventory." << endl;
        this->inventory.push_back(item);
    }
}

void Player::equipItem(Item item) {
    if(item.getIsDetoxic()) this->setPoison(nullptr);
    increaseStates(item.getHealth(), item.getAttack(), item.getDefense(), item.getHunger(), item.getThirst(), nullptr, 0);
}

void Player::openBackpack() {
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠉⠉⠉⠉⠉⠉⠉⠉⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⣾⠀⣿⣿⡿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⢿⣿⣿⠀⢷⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⢰⡏⠀⣿⣿⠀⣴⣶⣶⣶⣶⣶⣶⣶⣶⣶⣦⠀⣿⣿⡀⢸⡆⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⢸⡇⠀⣿⣿⣆⠘⠻⠇⢠⣤⣤⡄⠸⠟⠋⣠⣿⣿⡇⢸⡇⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⢸⣇⠀⣿⣿⣿⣿⣶⣆⣈⣉⣉⣁⣰⣶⣿⣿⣿⣿⣿⠃⢸⡇⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠈⣿⣀⣉⣉⠉⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠉⣉⣉⣀⣿⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⢀⡴⠀⣉⣉⠉⠉⠉⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠉⠉⠉⣉⣉⠀⢦⡀⠀⠀" << endl;
    cout << "⠀⠀⠈⣀⠀⣿⣿⠀⣿⣿⠀⠛⠛⠉⠉⠉⠉⠛⠛⠀⣿⣿⠀⣿⣿⠀⣀⠁⠀⠀" << endl;
    cout << "⠀⠀⢸⡇⢀⣿⣿⠀⣿⣿⠀⣿⣿⣿⣿⣿⣿⣿⣿⠀⣿⣿⠀⣿⣿⡀⢸⡇⠀⠀" << endl;
    cout << "⠀⠀⢸⡇⢸⣿⠀⣤⡤⢤⣄⠘⠻⠿⠿⠿⠿⠟⠃⣠⡤⢤⣤⠀⣿⡇⢸⡇⠀⠀" << endl;
    cout << "⠀⠀⢠⡄⢸⣿⠀⠛⠃⠘⠋⢸⣶⣶⣆⣰⣶⣶⡇⠙⠃⠘⠛⠀⣿⡇⢠⡄⠀⠀" << endl;
    cout << "⠀⠀⢠⡄⠸⣿⣿⠀⠷⠞⠀⠛⠛⠿⠿⠿⠿⠛⠛⠀⠳⠾⠀⣿⣿⠇⢠⡄⠀⠀" << endl;
    cout << "⠀⠀⠘⠗⠀⣿⣿⠀⣶⣶⠀⣿⣷⣶⣶⣶⣶⣾⣿⠀⣶⣶⠀⣿⣿⠀⠺⠃⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠉⠉⠀⠉⠉⠀⠉⠉⠉⠉⠉⠉⠉⠀⠉⠉⠀⠉⠉⠀⠀⠀⠀⠀" << endl;

    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃    Backpack, backpack~     ┃" << endl;
    cout << "┃    Backpack, backpack~     ┃" << endl;
    cout << "┃                            ┃" << endl;
    if (inventory.empty()) {
        cout << "┃    You have nothing.       ┃" << endl;
        cout << "┃    Sad as fuck.            ┃" << endl;
    }
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    if (inventory.empty()) {
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡭⠥⠐⠒⠒⠒⠒⠂⠤⢤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
        cout << "⠀⠀⠀⠀⠀⢀⣤⠖⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠲⣤⡀⠀⠀⠀⠀⠀" << endl;
        cout << "⠀⠀⠀⢀⡴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢦⡀⠀⠀⠀" << endl;
        cout << "⠀⠀⢠⠟⠀⠀⠀⠀⠀⣠⣤⣤⡀⠀⠀⠀⠀⠀⣤⣤⣄⠀⠀⠀⠀⠈⠻⡄⠀⠀" << endl;
        cout << "⠀⣠⠋⠀⠀⠀⠀⠀⠀⣿⣿⣿⣧⠀⠀⠀⠀⣼⣿⣿⣿⠀⠀⠀⠀⠀⠀⠹⣄⠀" << endl;
        cout << "⠀⡏⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⡟⠀⠀⠀⠀⢻⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⢹⠀" << endl;
        cout << "⢰⠀⠀⠀⠀⠀⠀⠀⠀⠙⠛⠛⠀⠀⠀⠀⠀⠀⠛⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⡆" << endl;
        cout << "⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣤⣤⣤⣤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇" << endl;
        cout << "⠸⠀⠀⠀⠀⠀⠀⠀⣠⣴⡿⠟⠛⠋⠉⠉⠙⠛⠻⢷⣦⣄⠀⠀⠀⠀⠀⠀⠀⠇" << endl;
        cout << "⠀⣇⠀⠀⠀⠀⢀⣼⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣷⡀⠀⠀⠀⠀⣸⠀" << endl;
        cout << "⠀⠘⣆⠀⠒⠲⣾⡃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢘⡷⠖⠒⠀⣰⠃⠀" << endl;
        cout << "⠀⠀⠘⣦⡀⠀⠈⠳⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠺⠁⠀⠀⣴⠃⠀⠀" << endl;
        cout << "⠀⠀⠀⠈⠳⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠁⠀⠀⠀" << endl;
        cout << "⠀⠀⠀⠀⠀⠈⠛⠦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠴⠛⠁⠀⠀⠀⠀⠀" << endl;
        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠓⠒⠠⠤⠤⠤⠤⠄⠒⠚⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl; 
        return;
    } else {
        cout << "> Items:" << endl;
        int index = 1;
        for (auto& item : inventory) {
            cout << index << ". " << item.getName() << endl;
            ++index;
        }
    }

    cout << "Do you want to equip any item? (Y/N): ";
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        cout << "Enter the number corresponding to the item you want to equip: ";
        int choice;
        cin >> choice;
        if (choice >= 1 && choice <= inventory.size()) {
            equipItem(inventory[choice - 1]);
            inventory.erase(inventory.begin() + choice - 1);
        } else {
            cout << "Invalid item number." << endl;
        }
    }
}

bool Player::increaseStates(int health, int attack, int defense, int hunger, int thirst, Poison* poison, int money){
    this->setCurrentHealth(min(this->getCurrentHealth() + health, this->getMaxHealth()));
    this->setAttack(this->getAttack() + attack);
    this->setDefense(this->getDefense() + defense);
    this->setHunger(max(this->getHunger() + hunger, 0));
    this->setThirst(max(this->getThirst() + thirst, 0));
    if(this->getPoison()==nullptr) {
        this->setPoison(poison);
    }
    this->setMoney(this->getMoney() + money);
    return this->checkIsDead();
}

bool Player::changeRoom(Room* room) {
    bool hasMonster = false;
    vector<Object*> objectList = currentRoom->getObjects();
    for (Object* obj : objectList) {
        if (obj->getTag() == "Monster") {
            hasMonster = true;
            break;
        }
    }

    // If there's a monster, the player can only go back to the previous room
    if (hasMonster && room!=this->previousRoom) {
        cout << "┌─────────────────────────────────────────────────────┐" << endl;
        cout << "│ There's a monster in the room! You can't proceed.   │" << endl;
        cout << "└─────────────────────────────────────────────────────┘" << endl;
        return false; // Player can't change rooms
    }

    // If no monster, change the current room and update previous room
    this->previousRoom = this->currentRoom;
    this->currentRoom = room;
    return true;
}

bool Player::handleStatus() {
    int decrease = 0;
    if(hunger == 0)  decrease += 5;
    if(thirst == 0)  {
        decrease += 5;
        // debuff of thirst == 0
        setAttack(max(0, getAttack() - 3));
        setDefense(max(0, getDefense() - 3));
    }

    if(poison != nullptr) {  
        decrease += poison->getLevel();
        poison->decreaseDuration();
        if(poison->getDuration() == 0) {
            free(poison);
            poison = nullptr;
        }
    }
    this->setCurrentHealth(this->getCurrentHealth() - decrease);
    return (this->checkIsDead());
}

bool Player::triggerEvent(Object *obj) {

    cout << "┏━━━                                             ━━━┓" << endl;
    cout << "┃ Status:                                           ┃" << endl;
    cout << "  " << getName() << endl;
    cout << "  > Health: " << getCurrentHealth() << "/" << getMaxHealth() << endl;
    cout << "  > Attack: "<< getAttack()<< endl;
    cout << "  > Defense: " << getDefense() << endl;
    cout << "  > Hunger: " << getHunger() << endl;
    cout << "  > Thirst: " << getThirst() << endl;

    if (getPoison() != nullptr) {
        cout << "  Poisoned with: " << getPoison()->getName() << endl;
    }

    if (inventory.empty()) {
        cout << "  Items:                                              " << endl;
        cout << "  - None                                              " << endl;
    } else {
        cout << " > Items:                                             " << endl;
        for (auto& item : inventory) {
            cout << "  - " << item.getName() << endl;
        }
    }
    cout << "┃                                                   ┃" << endl;
    cout << "┗━━━                                             ━━━┛" << endl;

    return false;
}

void Player::setHunger(int hunger) {
    this->hunger = max(hunger,0);
}

void Player::setThirst(int thirst) {
    this->thirst = max(thirst,0);
}

void Player::setMoney(int money) {
    this->money = money;
}

void Player::setPoison(Poison* poison) {
    this->poison = poison;
}

void Player::setCurrentRoom(Room* room) {
    this->currentRoom = room;
}

void Player::setPreviousRoom(Room* room) {
    this->previousRoom = room;
}

void Player::setInventory(vector<Item> inventory) {
    this->inventory = inventory;
}

int Player::getHunger() const {
    return this->hunger;
}

int Player::getThirst() const {
    return this->thirst;
}

Poison* Player::getPoison() const {
    return this->poison;
}

Room* Player::getCurrentRoom() {
    return this->currentRoom;
}

Room* Player::getPreviousRoom() {
    return this->previousRoom;
}

vector<Item> Player::getInventory() {
    return this->inventory;
}

int Player::getMoney() const {
    return money;
}
