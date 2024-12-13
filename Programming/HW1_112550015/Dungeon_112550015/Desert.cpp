#include "Desert.h"

Desert::Desert() {}

Desert::Desert(bool isExit, int index, vector<Object*> objects) : Room("Desert",isExit, index, objects){}

bool Desert::environmentEvent(Object* obj) {
    Player* player = dynamic_cast<Player*>(obj);
    if(!player) return false;
    
    player->setThirst(player->getThirst() - 5);
    return player->checkIsDead();
}

bool Desert::findRestArea(Object *obj) {
    Player* player = dynamic_cast<Player*>(obj);
    if(!player) return false;
    player->setThirst(player->getThirst()+10);

    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃                                                        ┃" << endl;
    cout << "┃ As you journey through the desert, you stumble upon    ┃" << endl;
    cout << "┃ an oasis.                                              ┃" << endl;
    cout << "┃ The sight of water fills you with relief, and you      ┃" << endl;
    cout << "┃ drink deeply.                                          ┃" << endl;
    cout << "┃ You feel refreshed and revitalized, ready to continue  ┃" << endl;
    cout << "┃ your journey.                                          ┃" << endl;
    cout << "┃                                                        ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    char choice;
    cout << "Press any key to continue: ";
    cin >> choice;
    return false;
}
bool Desert::triggerEvent(Object* obj) {
    Player* player = dynamic_cast<Player*>(obj);
    if(!player) return false;
    player->setHunger(player->getHunger() - 10);
    player->setThirst(player->getThirst() - 20);


    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⣄⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⠂⣠⠾⠛⠋⠛⠛⢷⣄⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠴⢤⡀⠀⡀⠀⠀⠀⠉⠛⠀⠰⠻⣷⡆⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⠀⠈⠁⠈⢉⣀⣀⠀⠀⠀⠀⠀⡆⢻⡇⣀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠆⠀⢠⠟⠉⠙⣷⠀⠀⠀⠛⠀⢸⡇⠟⠀" << endl;
    cout << "⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠴⠀⠀⠀⠀⠀⣠⣿⠶⠀⠀⠀⢰⣿⡇⠀⠀" << endl;
    cout << "⠀⢸⣿⣿⣶⣶⣦⣾⣥⣤⣭⣤⣤⣤⣤⣤⣶⣶⣿⠿⠃⠀⠀⢸⣠⣾⡿⠒⠃⠀" << endl;
    cout << "⠀⠉⠉⠉⠙⠛⠛⠛⠛⠛⠿⠿⠛⠛⠛⠛⠉⠉⣀⣀⣤⣴⣾⣿⡿⠟⢁⠀⠀⠀" << endl;
    cout << "⠀⢀⣿⣿⣿⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣾⣿⣿⣿⣿⠿⠛⠋⠁⠀⠀⠸⠀⠀⠀" << endl;
    cout << "⠀⠈⢉⣉⣭⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⢿⡿⠿⠿⠿⠿⣿⣷⣶⣤⡃⠀⠀⠀" << endl;
    cout << "⠀⠘⣿⣿⣿⣿⣿⡿⠿⠿⠟⠉⠁⠤⠄⠀⠀⠁⠀⠀⠀⠘⠆⠈⠙⣿⣧⢰⡄⠀" << endl;
    cout << "⠀⠀⠸⠛⠋⠉⣀⠐⠓⠀⠀⠀⠀⠀⠀⠀⠴⢦⠄⠓⠀⠀⠀⠀⠀⣸⡏⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡤⠑⢦⣼⣧⣴⠿⡀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠦⠀⠉⠁⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;

    
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃                                                        ┃" << endl;
    cout << "┃ As you traverse the desert, a fierce sandstorm engulfs ┃" << endl;
    cout << "┃ you.                                                   ┃" << endl;
    cout << "┃ The biting winds and abrasive sand grains take their   ┃" << endl;
    cout << "┃ toll on you.                                           ┃" << endl;
    cout << "┃ Despite the adversity, you press on, determined to     ┃" << endl;
    cout << "┃ weather the storm.                                     ┃" << endl;
    cout << "┃ The sandstorm rages on, obscuring your vision and      ┃" << endl;
    cout << "┃ making progress difficult.                             ┃" << endl;
    cout << "┃                                                        ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    player->handleStatus();
    cout << "╔═════════════════════════════╗" << endl;
    cout << "║ What do you want to do ?    ║" << endl;
    cout << "║ A. Seek shelter             ║" << endl;
    cout << "║ B. Continue journey         ║" << endl;
    cout << "╚═════════════════════════════╝" << endl;
    cout << "Enter A or B to choose an action: ";
    char choice;
    cin >> choice;

    if (choice == 'A' || choice == 'a') {
        cout << "┌─────────────────────────────────────────────────────────────────────┐" << endl;
        cout << "│ You chose to seek shelter from the sandstorm, finding refuge        │" << endl;
        cout << "│ in a nearby cave.                                                   │" << endl;
        cout << "│ The cave offers temporary protection from the raging storm,         │" << endl;
        cout << "│ allowing you to recuperate.                                         │" << endl;
        cout << "└─────────────────────────────────────────────────────────────────────┘" << endl;
        player->increaseStates(0, 10, 10, -30, -30, nullptr, 0);
    } else {
        cout << "┌─────────────────────────────────────────────────────────────┐" << endl;
        cout << "│ The sandstorm proves too much to handle, overwhelming you   │" << endl;
        cout << "│ with its force.                                             │" << endl;
        cout << "│ Your efforts to withstand the storm are in vain, and you    │" << endl;
        cout << "│ succumb to its fury.                                        │" << endl;
        cout << "└─────────────────────────────────────────────────────────────┘" << endl;

        player->setCurrentHealth(0); // Player dies due to the desert sandstorm
        return true;
    }
    cout << "Press any key to continue: ";
    cin >> choice;

    while (bool sandstorm = rand() % 2) {   
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┃ The sandstorm continues to rage outside, with no signs of    ┃" << endl;
        cout << "┃ abating. Visibility remains poor, and the howling winds echo ┃" << endl;
        cout << "┃ through the cave.                                            ┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        player->handleStatus();
        
        cout << "╔═════════════════════════════╗" << endl;
        cout << "║ What do you want to do ?    ║" << endl;
        cout << "║ A. Stay in shelter          ║" << endl;
        cout << "║ B. Continue journey         ║" << endl;
        cout << "╚═════════════════════════════╝" << endl;
        cout << "Enter A or B to choose an action: ";
        cin >> choice;

        if (choice == 'A' || choice == 'a') {
            cout << "┌───────────────────────────────────────────────────────────┐" << endl;
            cout << "│ You hunker down in the shelter, waiting for the sandstorm │" << endl;
            cout << "│ to pass.                                                  │" << endl;
            cout << "└───────────────────────────────────────────────────────────┘" << endl;
            player->increaseStates(0, 10, 10, -30, -30, nullptr, 0);
            cout << "Press any key to continue: ";
            cin >> choice;
        } else {
            cout << "┌─────────────────────────────────────────────────────────────┐" << endl;
            cout << "│ The sandstorm proves too much to handle, overwhelming you   │" << endl;
            cout << "│ with its force.                                             │" << endl;
            cout << "│ Your efforts to withstand the storm are in vain, and you    │" << endl;
            cout << "│ succumb to its fury.                                        │" << endl;
            cout << "└─────────────────────────────────────────────────────────────┘" << endl;
            player->setCurrentHealth(0); 
            return true;
        }
    }
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃ After a while, the sandstorm begins to subside, ┃" << endl;
    cout << "┃ and the desert returns to relative calm.        ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    cout << "Press any key to continue: ";
    cin >> choice;
    return player->checkIsDead();
}
