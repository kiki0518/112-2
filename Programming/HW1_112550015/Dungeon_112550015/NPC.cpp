#include "NPC.h"

NPC::NPC() : GameCharacter(), script(""), commodity({}) {}

NPC::NPC(string name, string script, vector<Item*> commodity) : GameCharacter(name, "NPC", 0, 0, 0), script(script), commodity(commodity) {}

void NPC::listCommodity() {
    cout << "Commodities available:" << endl;
    int index = 1;
    for (auto& item : commodity) {
        cout << index++<<". " <<item->getName() << endl;
    }
}


bool NPC::triggerEvent(Object* obj) {
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃ As you journey through the dungeon, you stumble upon a mysterious   ┃" << endl;
    cout << "┃ figure standing in the shadows. As you approach, you realize it's   ┃" << endl;
    cout << "┃ a traveling merchant!                                               ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        
    cout<<this->getScript()<<endl;
    if(commodity.empty()) {
        cout << "No Commodity!" << endl;
        return false;
    }

    listCommodity();
    cout << "Would you like to buy something? (Y/N): ";
    char choice;
    cin >> choice;
    
    if (choice == 'Y' || choice == 'y') {
        int index;
        cout << "Enter the number corresponding to the item you want to buy: ";
        cin >> index;
        
        if (index >= 1 && index <= commodity.size()) {
            Player* player = dynamic_cast<Player*>(obj);
            if (player) {
                Item* item = commodity[index - 1];
                
                if (player->getMoney() >= item->getMoney()) {
                    player->setMoney(player->getMoney() - item->getMoney());
                    player->addItem(*item);
                    commodity.erase(commodity.begin()+(index - 1));
                    cout << "You have bought " << item->getName() << "." << endl;
                } else {
                    cout << "You don't have enough money to buy this item." << endl;
                }
            }
        } else {
            cout << "Invalid item index." << endl;
        }
    }
    return false;
}

void NPC::setScript(string script) {
    this->script = script;
}

void NPC::setCommodity(vector<Item*> commodity) {
    this->commodity = commodity;
}

string NPC::getScript() {
    return this->script;
}

vector<Item*> NPC::getCommodity() {
    return this->commodity;
}
