#include "Swamp.h"

Swamp::Swamp() {
    // Initialize the poison instance with default values
    poison = new Poison("Toxic gas", 5, 3, 1); // Example poison with name, level, duration, and type
}


Swamp::Swamp(bool isExit, int index, vector<Object*> objects) : Room("Swamp", isExit, index, objects){
    // Initialize the poison instance with default values
    poison = new Poison("Toxic gas", 5, 3, 1); // Example poison with name, level, duration, and type
}

bool Swamp::environmentEvent(Object* obj) {
    Player* player = dynamic_cast<Player*>(obj);
    if(!player) return false;

    player->setCurrentHealth(player->getCurrentHealth() - 5);

    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃ As you traverse through the murky swamp, the thick mud makes   ┃" << endl;
    cout << "┃ every step arduous.                                            ┃" << endl;
    cout << "┃ Your energy is drained as you struggle to navigate the         ┃" << endl;
    cout << "┃ treacherous terrain.                                           ┃" << endl;
    cout << "┃ Your health decreases due to the exertion required to move     ┃" << endl;
    cout << "┃ forward.                                                       ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    char choice;
    cout << "Press any key to continue: ";
    cin >> choice;
    return player->checkIsDead();
}


bool Swamp::triggerEvent(Object *obj) {
    Player* player = dynamic_cast<Player*>(obj);
    if(!player) return false;
    player->setPoison(poison); 
    player->setCurrentHealth(player->getCurrentHealth() * 0.7);
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃ As you explore deeper into the swamp, you suddenly inhale ┃" << endl;
    cout << "┃ a noxious gas.                                            ┃" << endl;
    cout << "┃ Your head spins, and your vision blurs as the toxic       ┃" << endl;
    cout << "┃ fumes take effect.                                        ┃" << endl;
    cout << "┃ You are poisoned and feel your health deteriorating       ┃" << endl;
    cout << "┃ rapidly.                                                  ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    char choice;
    cout << "Press any key to continue: ";
    cin >> choice;
    return player->checkIsDead();
}

bool Swamp::findRestArea(Object *obj) {
    Player* player = dynamic_cast<Player*>(obj);
    if(!player) return false;
    player->setThirst(player->getThirst() + 10);
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃ As you wander through the dense foliage, you stumble upon a     ┃" << endl;
    cout << "┃ hidden spring.                                                  ┃" << endl;
    cout << "┃ Crystal-clear water flows from a moss-covered rock, offering a  ┃" << endl;
    cout << "┃ refreshing respite.                                             ┃" << endl;
    cout << "┃ You drink deeply from the cool, clean water, replenishing your  ┃" << endl;
    cout << "┃ thirst.                                                         ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    char choice;
    cout << "Press any key to continue: ";
    cin >> choice;
    return false;
}