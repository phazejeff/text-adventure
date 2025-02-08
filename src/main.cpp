#include <iostream>
#include <thread>
#include <limits>
#include "player/Player.h"
using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;

int main() {
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    Player player = Player(1);
    Player enemy = Player(1);
    int round = 1;

    while (player.getHealth() > 0) {
        if (enemy.getHealth() <= 0) {
            round++;
            enemy = Player(round);
            cout << endl << "You win the round!" << endl;
            sleep_for(1s);
            cout << "Round " << round << ":" << endl;
            sleep_for(1s);
        }

        cout << "Enemy health: " << enemy.getHealth() << endl;
        cout << "Your health: " << player.getHealth() << endl;

        int decision;
        cout << "What would you like to do? (1: attack, 2: block, 3: heal) ";
        cin >> decision;
        switch (decision) {
            case 1:
                enemy.takeDamage(20);
                cout << endl << "Attacking..." << endl;
                break;
            case 2:
                cout << endl << "Blocking..." << endl;
                break;
            case 3:
                player.heal(10);
                cout << endl << "Healing..." << endl;
                break;
            default:
                cout << endl << "Not a valid option. Skipping turn! Get cooked moron." << endl;
                break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // so it doesnt break when you input a non number

        cout << endl << endl;
    }
    return 0;
} 