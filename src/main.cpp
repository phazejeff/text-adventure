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
    int strength = 0;
    int enemyStrength = 0;
    int gold = 0;

    // Next round and randomly gain gold
    while (player.getHealth() > 0) {
        if (enemy.getHealth() <= 0) {
            round++;
            enemy = Player(round);
            enemyStrength += 5;
            cout << endl << "You win the round and received..." << endl;
            sleep_for(1s);
            int rngGold = (rand() % 200) + 1;
            cout << rngGold << " GOLD!" << endl;
            gold += rngGold;
            sleep_for(1s);

    // SHOPPING
    cout << "You encounter a strange hobo who offers you an assortment of strange items." << endl;
    int shopDecision = 0; // Initialize shopDecision
    while (shopDecision != 3) {
    cout << endl << endl << endl;
    cout << "What's shakin' bacon?" << " You have " << gold << " GOLD! (1: BUY, 2: STEAL, 3: LEAVE): ";
    cin >> shopDecision;
    switch (shopDecision) {
        case 1: {
            cout << "Whatcha need, pumpkin seed? (1: HP UP(-50 GOLD), 2: STR UP(-25 GOLD), 3: EXIT): ";
            int buyDecision = 0; // Initialize buyDecision
            while (buyDecision != 3) {
                cin >> buyDecision;
                switch (buyDecision) {
                    case 1:
                        if (gold >= 50) {
                            player.heal(100);
                            cout << endl << "You gained +100 HP!" << endl;
                            gold -= 50;
                            buyDecision = 3;
                            break;
                        }
                        else {
                            cout << endl << "Sorry you don't have enough GOLD..." << endl;
                            buyDecision = 3;
                            break;
                        }
                    case 2:
                        if (gold >= 25) {
                            strength += 10;
                            cout << endl << "Your strength improved by +10!" << endl;
                            gold -= 25;
                            buyDecision = 3;
                            break;
                        }
                        else {
                            cout << endl << "Sorry you don't have enough GOLD..." << endl;
                            buyDecision = 3;
                            break;
                        }
                    case 3:
                        break;
                    default:
                        cout << endl << "Not a valid option" << endl;
                        buyDecision = 3;
                        break;
                }
                //sleep_for(1s);

            }
            break;
        }
        case 2: {
            int rngSteal = (rand() % 100) + 1;
            if (rngSteal <= 50) {
                sleep_for(1s);
                cout << endl << "Aww shucks, not again..." << endl;
                strength += 20;
                player.heal(50);
                cout << endl << "You gain +20 strength and gain +50 HP!" << endl;
                sleep_for(1s);
            } else {
                sleep_for(1s);
                cout << endl << "Hey stop that, buddy! Get Outta here!" << endl;
                player.takeDamage(50);
                cout << endl << "The kind shopkeeper hobo kicks you and you lose 50 HP!" << endl;
            }
            break;
        }
        case 3:
            cout << endl << "Later Alligator!" << endl;
            break;
        default:
            cout << endl << "Not a valid option" << endl;
            break;
    }
    //sleep_for(1s);
}

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
                if (!enemy.isBlocking) {
                    enemy.takeDamage(20 + strength);
                    cout << endl << "Attacking...you deal damage!" << endl;
                } else {
                    enemy.takeDamage((10 + strength) / 2);
                    cout << endl << "Attacking...the enemy blocked and you deal less damage!" << endl;
                    enemy.isBlocking = false;
                }
                break;
            case 2:
                cout << endl << "Blocking..." << endl;
                player.isBlocking = true;
                break;
            case 3:
                player.heal(10);
                cout << endl << "Healing..." << endl;
                break;
            default:
                cout << endl << "Not a valid option. Skipping turn! Get cooked moron." << endl;
                break;
        }
        sleep_for(1s);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // so it doesn't break when you input a non-number

        cout << endl << endl;

        cout << "Enemy health: " << enemy.getHealth() << endl;
        cout << "Your health: " << player.getHealth() << endl;
        sleep_for(1s);

        cout << endl << endl;

        // Enemy turn
        if (enemy.getHealth() > 0) {
            enemy.isBlocking = false;
            int rngNum = (rand() % 3) + 1;

            // Debuug random number generated
            //cout << rngNum << endl << endl;
            cout << "ENEMY TURN!" << endl << endl;

            switch (rngNum) {
                case 1:
                    if (!player.isBlocking) {
                        player.takeDamage(20 + enemyStrength);
                        cout << endl << "Enemy Attacking...You take damage!" << endl;
                    } else {
                        player.takeDamage((10 + enemyStrength) / 2);
                        cout << endl << "Enemy Attacking...You blocked and took damage!" << endl;
                        player.isBlocking = false;
                    }
                    break;
                case 2:
                    cout << endl << "Enemy Blocking..." << endl;
                    enemy.isBlocking = true;
                    break;
                case 3:
                    enemy.heal(10);
                    cout << endl << "Enemy Healing...Enemy healed for 10 HP!" << endl;
                    break;
                default:
                    cout << endl << "Not a valid option. Skipping turn! Get cooked moron." << endl;
                    break;
            }

            sleep_for(1s);

            cout << endl << endl;
        }
    }
    return 0;
}