#include "Monster.h"

Monster::Monster() : GameCharacter(){}

Monster::Monster(string name, int maxHealth, int attack, int defense, Poison* poison) : GameCharacter(name, "Monster", maxHealth, attack, defense), poison(poison){}

bool Monster::triggerEvent(Object* object) {
    Player* player = dynamic_cast<Player*>(object);

    if (player) {
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┃ As you journey through the dungeon, you come face to face with a   ┃" << endl;
        cout << "┃ fearsome creature!                                                 ┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        if(getName()=="Python") {
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⠖⣲⢾⣭⠽⠏⠉⠑⠒⢦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡴⡟⠁⠀⣼⡧⠊⠁⣠⠔⠒⠒⠒⠢⡝⢷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⢾⡕⢹⠇⠀⠐⠋⠀⢠⣾⠵⠒⠋⠉⠉⠉⠻⣌⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⢞⣱⠈⢧⣸⡄⠀⠀⠀⠀⠉⠀⠀⣀⣤⠤⣄⡀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⠟⣿⡀⠀⠉⠓⠀⣀⣤⣬⡆⢰⣯⣥⣤⣤⣤⣙⣦⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠫⢧⣄⠘⣿⡄⠀⢴⡺⠗⠊⣹⠟⠀⠀⠀⠀⠀⠀⠀⠉⠁⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣻⣇⠀⠈⠉⠉⠉⡴⠋⠑⢦⡴⣣⠶⠒⠉⠉⠑⠲⢤⡀⠀⠀⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠏⡇⠈⢧⡀⠀⢀⡾⣄⣀⡴⠋⠚⠉⠉⠓⠶⠒⠒⠉⠙⠃⠀⣼⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠓⠒⠒⠛⠁⡞⢀⡤⠾⣦⣤⠤⠤⢤⡤⠤⠤⣄⣴⠶⣤⡼⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠳⣄⡀⠀⢸⠁⢸⣱⡀⡠⠙⡧⠤⠄⠀⠤⣴⠳⣄⢀⣎⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⢻⣀⠤⠝⠁⢸⣴⠛⢻⡏⢷⡤⠙⢦⠀⠀⣤⠊⢤⡾⢻⣟⢛⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⢠⣤⡀⠀⠀⢸⣿⣠⠚⣻⣻⣷⡶⠾⣀⢀⠿⣶⣼⣟⣿⡛⣄⡟⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣮⣇⣉⠟⠂⢸⣽⡷⡄⠀⣈⡻⠿⠚⠍⠩⠇⠽⢿⣁⠀⢡⢼⣥⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣌⠁⠀⠀⠀⠉⢻⣷⠤⣀⣀⣀⣀⣰⣦⣂⣀⣀⣀⡤⣾⡟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⢲⠒⠚⢛⡟⠀⢹⣷⢶⠓⣿⣷⣾⣷⣿⣿⡒⣿⣾⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⣳⡤⠋⠀⠀⠀⢻⡼⣆⣿⣿⣯⣭⣿⣿⣷⢧⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⡤⡶⠖⠒⣲⠎⣿⣸⣿⣿⡧⣿⣿⣿⡃⣿⠳⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣞⠢⡔⠁⠀⣸⣯⠙⠙⢳⡘⣏⡟⣽⠇⠀⠈⠑⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⣝⠫⣭⡿⣍⠉⠉⢙⣇⡟⣩⡥⠄⠀⢀⣤⠌⠳⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⣌⠀⠙⠯⣲⣎⣸⣻⡏⢀⡠⠞⠉⠀⠀⠀⠈⠳⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠓⢤⡀⠈⡆⢀⠇⠹⡍⠀⠀⠀⠀⢀⡰⠆⠀⠈⠳⣄⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⢸⣋⠹⡶⣆⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢦⡉⠉⠀⠀⠘⢦⣀⣠⠞⠁⠀⠀⠀⠀⠀⠘⢧⡀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⣿⣄⡝⠆⣨⠟⢳⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⣜⣿⣛⡟⠻⣄⠀⠀⠀⠀⠀⣠⠄⠀⠀⠙⣄⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠈⠹⣷⣼⠉⠣⣔⠉⢻⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢭⡁⠀⠈⢳⡀⣠⠴⠋⠀⠀⠀⠀⠀⠈⢧⡀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠈⠻⣤⡏⠀⡱⣄⢠⠟⠳⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢟⠿⠟⠙⢦⠀⠀⠀⠀⠀⢀⣠⠄⠀⢻⡄⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠘⢿⣾⡁⣨⠓⢄⡘⠋⣙⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⡴⣖⡶⠳⣄⣀⡤⠞⠋⠀⠀⠀⠀⢻⡄⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠙⠿⣧⣀⡆⣽⠋⠉⠉⠳⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢯⣀⣀⣙⣧⡀⠀⠀⠀⠀⠀⠀⠀⢳⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⢷⣯⡀⢀⣤⠀⠈⢷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⡳⠟⠉⢳⡀⢀⣀⠠⠀⠀⠀⠈⡇"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢳⡀⠙⢣⠀⠈⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣤⣄⣀⡻⡍⠁⠀⠀⠀⠀⠀⢷"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣷⠶⠭⠇⠀⢸⣤⣤⣄⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣯⠷⠛⠁⢹⡄⠀⠀⠀⠀⠀⢸"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⢀⣠⡴⢶⣞⣋⢩⡇⠀⡠⢴⠀⠘⡆⠹⡒⢦⡍⠉⢩⣭⣿⣒⠒⠦⣤⣤⣄⡀⠀⠀⢸⠀⠀⠀⠀⢻⡤⠒⠂⠀⠀⢸"<<endl;
            cout<<"⠀⠀⠀⠀⣠⡶⢛⣽⣤⣤⠈⠱⣽⢸⠀⠚⠒⠺⠀⠀⢧⠀⠑⠋⠀⠀⠀⢹⣄⠔⠋⠀⠐⡖⠚⢯⡝⢲⡟⡾⡆⠀⠀⠀⢷⠀⠀⠀⠀⢸"<<endl;
            cout<<"⠀⢀⣴⠟⠁⠞⠛⠉⠓⢾⠀⠀⠀⠸⡄⠀⢀⣴⡛⢆⠘⢷⡀⠀⠀⠀⠀⠀⠃⠀⠀⠀⠀⠷⠒⠋⢀⡾⠿⣄⣈⢢⣄⠀⢸⠀⠤⠖⠀⢸"<<endl;
            cout<<"⢠⡟⠁⠀⠀⠀⣀⣀⣀⣦⠀⠀⠀⠀⣷⡀⠈⠁⠈⢹⣄⠀⠙⢶⡶⠶⠤⢤⣀⣀⠀⠀⠀⠀⣠⠖⣋⣤⠀⠀⠈⠉⠁⠀⠘⡇⠀⠀⠀⡏"<<endl;
            cout<<"⣿⠀⠀⠀⠀⡼⢃⡠⠾⠛⢲⣮⣍⣁⣬⣷⣄⡀⠤⠾⠭⠷⠄⠀⠙⠳⢦⣄⣀⡠⠽⢿⠚⠉⢰⡏⠁⠻⡀⠀⠀⠀⠀⠀⢠⠇⠀⠀⢸⠃"<<endl;
            cout<<"⢿⠀⠀⠀⠀⡟⠋⠀⠀⡴⠋⢉⡿⠀⠀⢠⠾⠿⣿⡍⠉⠉⡯⠭⠽⣽⠉⠀⡴⠖⠚⠙⡇⠀⠀⠳⣄⠀⠻⣄⠀⠀⠀⠀⡼⠒⠒⣰⠏⠀"<<endl;
            cout<<"⠘⢧⠀⠀⠀⠀⠀⠀⠀⡇⢀⠞⠀⠀⠀⡞⠀⣰⠏⠀⠀⢸⡅⠀⣰⠏⠀⠀⢹⡀⠀⠀⡇⠀⠀⠀⠀⠙⠓⠾⠆⠀⠀⣼⠃⢀⣼⠃⠀⠀"<<endl;
            cout<<"⠀⠈⠳⡀⠀⠀⠀⠀⠀⢷⡟⠀⠀⠀⠀⣇⣰⠏⠀⠀⠀⠀⡇⠀⡇⠀⠀⠀⠀⠳⡀⢸⠁⠀⠀⠀⠀⠀⠀⠀⠀⢠⠞⠓⣤⠟⠁⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠈⠲⣄⡀⠀⠀⠈⠀⠀⠀⠀⠀⠘⠛⠀⠀⠀⠀⠀⠹⣾⠀⠀⠀⠀⠀⠀⠙⢾⠀⠀⠀⠀⠀⠀⠀⣀⠔⣫⡴⠞⠃⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠉⠓⠦⢄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⡾⠿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠛⠒⠒⠶⠤⠤⠤⠤⣤⣤⣤⣤⣤⣤⣤⠤⠤⠤⠤⠴⠶⠒⠒⠛⢉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<<endl;
            cout << " _______          _________          _______  _       " << endl;
            cout << "(  ____ )|\\     /|\\__   __/|\\     /|(  ___  )( (    /|" << endl;
            cout << "| (    )|( \\   / )   ) (   | )   ( || (   ) ||  \\  ( |" << endl;
            cout << "| (____)| \\ (_) /    | |   | (___) || |   | ||   \\ | |" << endl;
            cout << "|  _____)  \\   /     | |   |  ___  || |   | || (\\ \\) |" << endl;
            cout << "| (         ) (      | |   | (   ) || |   | || | \\   |" << endl;
            cout << "| )         | |      | |   | )   ( || (___) || )  \\  |" << endl;
            cout << "|/          \\_/      )_(   |/     \\|(_______)|/    )_)" << endl;
            cout << "                                                      " << endl;
        } else if(getName()=="Dinosaur") {
            cout << "⠀⠀⣶⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠈⠿⣿⣿⣿⣿⣷⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⢈⣻⣿⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⣤⣤⣴⣿⣿⣿⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠙⠛⠛⠛⠛⢻⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠠⠐⠤⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠉⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣤⣄⡀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠿⠟⠻⢿⣿⣿⣟⠛⠛⠛⠛⠛⠛⠻⠶⣤⡀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⣿⣷⠀⠀⠀⠙⠿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠉⠓" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢙⣿⡇⠀⠀⠀⠀⢸⣿⡃⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⣀⣤⣤⣶⣿⣿⠀⠀⠀⢀⣠⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠉⠉⠋⠉⠀⠀⠀⠐⠺⠿⠿⠟⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "DINOSAUR"<<endl;
        }
        char choice;
        cout << "Press any key to continue: ";
        cin >> choice;
        while (true) {
            cout << "Do you want to attack (A) or retreat (R)? (A/R): ";
            cin >> choice;
            
            if (choice == 'A' || choice == 'a') {
                cout << "You attack the monster!" << endl;
                this->takeDamage(player->getAttack()-this->getDefense()*0.5);
                if (this->checkIsDead()) {
                    cout << "You defeated the monster!" << endl;
                    player->increaseStates(this->getAttack(), 10, 10, 10, 10, nullptr, 100);
                    return true;
                }
                
                cout << "The monster attacks you!" << endl;
                player->takeDamage(this->getAttack()-player->getDefense()*0.5);
                if(poison!=nullptr && player->getPoison()==nullptr) {
                    player->setPoison(poison);
                }
                if (player->checkIsDead()) {
                    cout << "You were defeated by the monster." << endl;
                    return true;
                }

            } else if (choice == 'R' || choice == 'r') {
                cout << "You retreat from the combat." << endl;
                player->changeRoom(player->getPreviousRoom());
                return false;

            } else {
                cout << "Invalid choice. Please enter A to attack or R to retreat." << endl;
            }
        }
    } else {
        cout << "Error: Object is not a Player." << endl;
        return false;
    }
}

Poison* Monster::getPoison() {
    return poison;
}

void Monster::setPoison(Poison* newPoison) {
    poison = newPoison;
}