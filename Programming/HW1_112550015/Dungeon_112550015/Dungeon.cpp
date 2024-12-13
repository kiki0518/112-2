#include "Dungeon.h"
#include <cctype>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
// #define TEST

Dungeon::Dungeon() : player() {}

void Dungeon::createPlayer() {
    string name;
    char choice;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hi, "<<name<<endl;
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃ Choose your career:  ┃" << endl;
    cout << "┃ 1. Warrior           ┃" << endl;
    cout << "┃ 2. Mage              ┃" << endl;
    cout << "┃ 3. Rogue             ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    cout << "Enter the number corresponding to your choice: ";
    cin >> choice;

    switch (choice) {
        case '1':
            player = Player(name, 120, 85, 50, 100, 100, nullptr, 100);
            cout << "You have chosen to be a warrior!" << endl;
            break;
        case '2':
            player = Player(name, 100, 40, 30, 100, 100, nullptr, 300);
            cout << "You have chosen to be a mage!" << endl;
            break;
        case '3':
            player = Player(name, 110, 60, 70, 100, 100, nullptr, 500);
            cout << "You have chosen to be a rogue!" << endl;
            break;
        default:
            cout << "Invalid choice. I'll choose your career! HaHa!" << endl;
                player = Player(name, 12000, 100, 100, 100, 100, nullptr, 20000);
                break;
    }
    player.setCurrentRoom(rooms[0]);
#ifdef TEST
    cout<<"Test:"<<"run "<<__FUNCTION__<<" successfully"<<endl; //test
#endif
}

void Dungeon::createMap() {
    srand(time(nullptr));
    
    // POISON SETUP
    Poison* venene= new Poison("Venene", 10, 2, 0);
    // get poison by venene by monster "Python" at the endRoom
    
    // FOOD SETUP(increase hunger value)
    Item* cactus = new Item("cactus", 30, 30, 30, 0, 0, false, 0);
    // acquire cactus from the environment(desert)
    // Item* meat = new Item("meat", 100, 100, 100, 100, 100, false, 0);
    // acquire meat from wild animal in forest
    Item* hamburger = new Item("hamburger", 50, 50, 50, 0, 0, false, 30);
    // acquire hamburger from NPC
    
    // MILK SETUP (detoxic)
    Item* milk = new Item("milk", 10, 10, 10, 10, 10, true, 10);
    // acquire milk from NPC

    // WATER SETUP(increase thirst value)
    Item* water = new Item("water", 0, 0, 0, 0, 100, true, 10);
    // acquire water from NPC

    // MONSTER SETUP
    Monster* M1 = new Monster("Dinosaur", 120, 15, 15, nullptr);
    Monster* M2 = new Monster("Python", 150, 60, 20, venene);

    // NPC SETUP
    vector<Item*> commodityList;
    (commodityList).push_back(milk);
    (commodityList).push_back(hamburger);
    (commodityList).push_back(water);
    NPC* merchant = new NPC("merchant", "Hi, do you want to buy something?", commodityList);
    
    // ROOM_OBJECT SETUP
    vector<vector<Object*>>* roomObj = new vector<vector<Object*>>(5);
    for(int i = 0; i < 5; i++)  (*roomObj)[i].clear();
    ((*roomObj)[1]).push_back(cactus);
    ((*roomObj)[2]).push_back(M1);
    ((*roomObj)[3]).push_back(merchant);
    ((*roomObj)[4]).push_back(M2);

    // ROOM SETUP
    Room* startRoom = new Room("StartRoom", false, 0, (*roomObj)[0]);
    rooms.push_back(startRoom);
    Room* desert = new Desert(false, 1, (*roomObj)[1]);
    rooms.push_back(desert);
    Room* forest = new Forest(false, 2, (*roomObj)[2]);
    rooms.push_back(forest);
    Room* swamp = new Swamp(false, 3, (*roomObj)[3]);
    rooms.push_back(swamp);
    Room* endRoom = new Room("EndRoom", true, 4, (*roomObj)[4]);
    rooms.push_back(endRoom);

    // room connection setup
    connectRooms(startRoom, desert);
    connectRooms(desert, forest);
    connectRooms(forest, swamp);
    connectRooms(swamp, endRoom);
#ifdef TEST
    cout<<"Test:"<<"run "<<__FUNCTION__<<" successfully"<<endl; //test
#endif
}

void Dungeon::handleMovement() {
    Room* curRoom = player.getCurrentRoom();

    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃ Where do you want to go?  ┃" << endl;
    if (curRoom->getUpRoom() != nullptr) {
        cout << "┃ W. Go up                  ┃" << endl;
    }
    if (curRoom->getDownRoom() != nullptr) {
        cout << "┃ S. Go down                ┃" << endl;
    }
    if (curRoom->getLeftRoom() != nullptr) {
        cout << "┃ A. Go left                ┃" << endl;
    }
    if (curRoom->getRightRoom() != nullptr) {
        cout << "┃ D. Go right               ┃" << endl;
    }
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    cout << "Enter W, A, S, D to choose a direction: ";
    char choice;
    cin >> choice;
    choice = tolower(choice);

    switch (choice) {
        case 'w':
            if (curRoom->getUpRoom() != nullptr)   {
                if(player.changeRoom(curRoom->getUpRoom())==false)   return;
                cout << "┌───────────────────────────────────────────────────────────┐" << endl;
                cout << "│ You traverse through the mysterious pathways of the       │" << endl;
                cout << "│ dungeon and ascend upwards.                               │" << endl;
                cout << "└───────────────────────────────────────────────────────────┘" << endl;
            } else {
                cout << "Invalid choice! Please choose a valid direction." << endl;
            }
            break;
        case 's':
            if (curRoom->getDownRoom() != nullptr) {
                if(player.changeRoom(curRoom->getDownRoom())==false)   return;
                cout << "┌───────────────────────────────────────────────────────────┐" << endl;
                cout << "│ You delve deeper into the depths of the dungeon,          │" << endl;
                cout << "│ descending into the unknown.                              │" << endl;
                cout << "└───────────────────────────────────────────────────────────┘" << endl;
            } else {
                cout << "Invalid choice! Please choose a valid direction." << endl;
            }
            break;
        case 'a':
            if (curRoom->getLeftRoom() != nullptr) {
                if(player.changeRoom(curRoom->getLeftRoom())==false)   return;
                cout << "┌───────────────────────────────────────────────────────────┐" << endl;
                cout << "│ You venture into the shadowy corridors, moving leftward   │" << endl;
                cout << "│ with caution.                                             │" << endl;
                cout << "└───────────────────────────────────────────────────────────┘" << endl;
            } else {
                cout << "Invalid choice! Please choose a valid direction." << endl;
            }
            break;
        case 'd':
            if (curRoom->getRightRoom() != nullptr) {
                if(player.changeRoom(curRoom->getRightRoom())==false)   return;
                cout << "┌───────────────────────────────────────────────────────────┐" << endl;
                cout << "│ You tread carefully, exploring the passageways to the     │" << endl;
                cout << "│ right.                                                    │" << endl;
                cout << "└───────────────────────────────────────────────────────────┘" << endl;
            
            } else {
                cout << "Invalid choice! Please choose a valid direction." << endl;
            }
            break;
        default:
            cout << "Invalid choice! Please choose a valid direction." << endl;
            break;
    }
}

void Dungeon::connectRooms(Room* room1, Room* room2) {
    int direction;
    bool connected = false;

    while (!connected) {
        direction = rand() % 4; 
        // Randomly choose a direction (0: up, 1: down, 2: left, 3: right)
        switch (direction) {
            case 0:
                if (room1->getUpRoom() == nullptr && room2->getDownRoom() == nullptr) {
                    room1->setUpRoom(room2);
                    room2->setDownRoom(room1);
                    connected = true;
                }
                break;
            case 1:
                if (room1->getDownRoom() == nullptr && room2->getUpRoom() == nullptr) {
                    room1->setDownRoom(room2);
                    room2->setUpRoom(room1);
                    connected = true;
                }
                break;
            case 2:
                if (room1->getLeftRoom() == nullptr && room2->getRightRoom() == nullptr) {
                    room1->setLeftRoom(room2);
                    room2->setRightRoom(room1);
                    connected = true;
                }
                break;
            case 3:
                if (room1->getRightRoom() == nullptr && room2->getLeftRoom() == nullptr) {
                    room1->setRightRoom(room2);
                    room2->setLeftRoom(room1);
                    connected = true;
                }
                break;
        }
    }
}

void Dungeon::handleEvent(Object* obj) {
    obj->triggerEvent(&(this->player));
}

void Dungeon::startGame() {
   cout<<"  ____    _    __  __ _____   ____ _____  _    ____ _____ "<<endl;
   cout<<" / ___|  / \\  |  \\/  | ____| / ___|_   _|/ \\  |  _ \\_   _|"<<endl;
   cout<<"| |  _  / _ \\ | |\\/| |  _|   \\___ \\ | | / _ \\ | |_) || |  "<<endl;
   cout<<"| |_| |/ ___ \\| |  | | |___   ___) || |/ ___ \\|  _ < | |  "<<endl;
   cout<<" \\____/_/   \\_\\_|  |_|_____| |____/ |_/_/   \\_\\_| \\_\\|_|  "<<endl;
                                                           
                                                           
    createMap();

    createPlayer();
#ifdef TEST
    cout<<"Test:"<<"run "<<__FUNCTION__<<" successfully"<<endl; //test
#endif
}

bool Dungeon::chooseAction(vector<Object*> objects) {
    
    cout << "╔═════════════════════════════╗" << endl;
    cout << "║ What do you want to do ?    ║" << endl;
    cout << "║ A. Move                     ║" << endl;
    cout << "║ B. Check Status             ║" << endl;
    cout << "║ C. Open Backpack            ║" << endl;
    cout << "║ D. Explore                  ║" << endl;
    cout << "╚═════════════════════════════╝" << endl;
    cout << "Enter A, B, C or D to choose an action: ";
    char choice;
    cin >> choice;
    choice = tolower(choice);
    bool ret = false;
    switch (choice) {
        case 'a':
            this->handleMovement();
            ret = true;
            break;
        case 'b':
            handleEvent(&(this->player));
            break;
        case 'c':
            this->player.openBackpack();
            break;
        case '#':
            cout<<"Goodbye"<<endl;
            this->player.setCurrentHealth(0);
            return false;
        case 'd':
            if(objects.empty()) {
                cout << "┌───────────────────────────────────────────────────────────┐" << endl;
                cout << "│ There's nothing of interest here.                         │" << endl;
                cout << "└───────────────────────────────────────────────────────────┘" << endl;
            } else {
                Object* selectedObject = objects[0];
                if(selectedObject->triggerEvent(&(this->player)))
                    this->player.getCurrentRoom()->popObject(selectedObject);
                ret = true;
            }
    }
    cout << "Press any key to continue: ";
    cin >> choice;
    return ret;
}

bool Dungeon::checkGameLogic() {
    if(player.checkIsDead()) {
        cout <<  "  ____    _    __  __ _____    _____     _______ ____  "<< endl;
        cout <<  " / ___|  / \\  |  \\/  | ____|  / _ \\ \\   / / ____|  _ \\ "<< endl;
        cout <<  "| |  _  / _ \\ | |\\/| |  _|   | | | \\ \\ / /|  _| | |_) |"<< endl;
        cout <<  "| |_| |/ ___ \\| |  | | |___  | |_| |\\ V / | |___|  _ < "<< endl;
        cout <<  " \\____/_/   \\_\\_|  |_|_____|  \\___/  \\_/  |_____|_| \\_\\"<< endl;
                                                                                             
        return true;
    }
    if(player.getCurrentRoom()->getIsExit() 
    && player.getCurrentRoom()->getObjects().empty()) {
        cout <<" __   _____  _   _  __        _____ _   _ "<< endl;
        cout <<" \\ \\ / / _ \\| | | | \\ \\      / /_ _| \\ | |"<< endl;
        cout <<"  \\ V / | | | | | |  \\ \\ /\\ / / | ||  \\| |"<< endl;
        cout <<"   | || |_| | |_| |   \\ V  V /  | || |\\  |"<< endl;
        cout <<"   |_| \\___/ \\___/     \\_/\\_/  |___|_| \\_|"<< endl;
        return true;
    }
    return false; 
}

bool Dungeon::handleEnvironment(Room* curRoom, bool statusUpdate) {
    // if player is dead -> return true
    
    if(statusUpdate) {
        if(player.increaseStates(0,0,0,-2,-2,nullptr,0))    return true;
        // player decrease hunger and thirst value after every action
        
        if(curRoom->environmentEvent(&player))    return true;
        // environment could affect player's status after every action
    }

    // in desert, forest and swamp
    // player can find area to rest
    // (oasis, lake, and spring)
    if(!(rand() % 5) && !curRoom->getRestAreaFound()) {
        curRoom->findRestArea(&player);
        curRoom->setRestAreaFound(true);
    }

    // in desert, forest and swamp
    // player might encounter some trigger events
    // (sandstorm, wildlife animal, and inhale posion gas)
    if(!(rand() % 3) && !curRoom->getBeTriggered()) {
        if(curRoom->triggerEvent(&player))  return true;
        curRoom->setBeTriggered(true);
    }
    return false;
}

void Dungeon::runDungeon() {
    startGame();

    while(checkGameLogic()==false) {
        bool statUpdate = chooseAction(this->player.getCurrentRoom()->getObjects());
        if(checkGameLogic() == true)    break;
        if(handleEnvironment(this->player.getCurrentRoom(), statUpdate))  continue;
        // if player is dead -> continue
        this->player.handleStatus();    // handle status decrease cause by hunger, thirst and poison

    }
}
