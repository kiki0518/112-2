#include "Forest.h"

Forest::Forest() {}

Forest::Forest(bool isExit, int index, vector<Object*> objects) : Room("Forest", isExit, index, objects){}

bool Forest::environmentEvent(Object* obj) {
    Player* player = dynamic_cast<Player*>(obj);
    if(!player) return false;
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃ As you journey through the forest, your stomach  ┃" << endl;
    cout << "┃ grumbles with hunger.                            ┃" << endl;
    cout << "┃ The dense foliage and limited food sources       ┃" << endl;
    cout << "┃ contribute to your growing hunger.               ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    char choice;
    cout << "Press any key to continue: ";
    cin >> choice;
    player->setHunger(player->getHunger() - 5);
    return player->checkIsDead();
}

bool Forest::findRestArea(Object *obj) {
    Player* player = dynamic_cast<Player*>(obj);
    if(!player) return false;
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃ As you explore the forest, you stumble upon a   ┃" << endl;
    cout << "┃ serene lake nestled among the trees.            ┃" << endl;
    cout << "┃ The clear waters beckon you, offering relief    ┃" << endl;
    cout << "┃ from your parched throat.                       ┃" << endl;
    cout << "┃ You quench your thirst and feel rejuvenated by  ┃" << endl;
    cout << "┃ the refreshing water.                           ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    char choice;
    cout << "Press any key to continue: ";
    cin >> choice;
    player->setThirst(player->getThirst() + 10);
    return true;
}

bool Forest::triggerEvent(Object *obj) {
    Player* player = dynamic_cast<Player*>(obj);
    if(!player) return false;

    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃ As you move through the forest, you suddenly find yourself      ┃" << endl;
    cout << "┃ face to face with a fearsome tiger!                             ┃" << endl;
    cout << "┃ You must act quickly to avoid danger and ensure your survival.  ┃" << endl;
    cout << "┃ Your health decreases as you struggle to fend off the ferocious ┃" << endl;
    cout << "┃ beast.                                                          ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    
    player->setCurrentHealth(player->getCurrentHealth() * 0.5);
        
    cout << "╔═════════════════════════════╗" << endl;
    cout << "║ What do you want to do ?    ║" << endl;
    cout << "║ A. Run                      ║" << endl;
    cout << "║ B. Stay                     ║" << endl;
    cout << "╚═════════════════════════════╝" << endl;
    cout << "Enter A or B to choose an action: ";
    char choice;
    cin >> choice;

    if (choice == 'A' || choice == 'a') {

        cout << "┌─────────────────────────────────────────────────────────────────┐" << endl;
        cout << "│ You quickly turn on your heels and sprint away from the tiger,  │" << endl;
        cout << "│ your heart pounding in your chest. You manage to put enough     │" << endl;
        cout << "│ distance between yourself and the beast to escape its reach.    │" << endl;
        cout << "│ Breathing heavily, you stop to catch your breath, grateful for  │" << endl;
        cout << "│ another chance at survival.                                     │" << endl;
        cout << "└─────────────────────────────────────────────────────────────────┘" << endl;
            
        player->increaseStates(0, 0, 0, -30, -30, nullptr, 100);

    
    } else {
       
        cout << "┌───────────────────────────────────────────────────────────┐" << endl;
        cout << "│ You chose to stay and confront the tiger head-on.         │" << endl;
        cout << "│               *             *             *               │" << endl;
        double survivalChance = ((double) rand() / RAND_MAX);

        if (survivalChance < player->getDefense() / 100.0) {
            cout << "│ You bravely fought off the tiger, managing to fend it off │" << endl;
            cout << "│ and survive the encounter.                                │" << endl;
            cout << "│ You emerge victorious but severely injured from the fight.│" << endl;
            cout << "└───────────────────────────────────────────────────────────┘" << endl;
            player->increaseStates(0, 10, 10, -50, -50, nullptr, 100);
            player->setCurrentHealth(player->getCurrentHealth() * 0.1 + 1);
            cout << "┌───────────────────────────────────────────────────────────┐" << endl;
            cout << "│ After defeating the tiger, you find that it left behind   │" << endl;
            cout << "│ some meat. You carefully harvest it, knowing it will      │" << endl;
            cout << "│ provide sustenance on your journey.                       │" << endl;
            cout << "└───────────────────────────────────────────────────────────┘" << endl;
            Item meat("meat", 100, 100, 100, 100, 100, false, 0);
            // acquire meat from wild animal in forest
            player->addItem(meat);
        } else {
            cout << "│ Despite your efforts, the tiger overwhelms you in battle. │" << endl;
            cout << "│ You were unable to defeat the tiger, and it mauls you to  │" << endl;
            cout << "│ death.                                                    │" << endl;
            cout << "└───────────────────────────────────────────────────────────┘" << endl;
            player->setCurrentHealth(0); // Player dies due to the wildlife encounter
            return true;
        }
    }
    cout << "Press any key to continue: ";
    cin >> choice;
    return player->checkIsDead();
}

