#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(int level, bool isEnemy) {
    this->level = level;
    this->currentHealth = getBaseHealth();
    this->strength = 5 * (level - 1);
    this->isEnemy = isEnemy;
}

int Player::getBaseHealth() {
    return this->baseHealth * this->level;
}

int Player::getHealth() {
    return this->currentHealth;
}

bool Player::getIsBlocking() {
    return this->isBlocking;
}

bool Player::getIsEnemy() {
    return this->isEnemy;
}

int Player::getStrength() {
    return this->strength;
}

void Player::addStrength(int amount) {
    if (this->getIsEnemy()) {
        cout << endl << "Enemy strength improved by +" << amount << "!" << endl;
    } else {
        cout << endl << "Strength improved by +" << amount << "!" << endl;
    }
    this->strength += amount;
}

void Player::startBlocking() {
    if (this->getIsEnemy()) {
        cout << endl << "Enemy Blocking..." << endl;
    } else {
        cout << endl << "Blocking..." << endl;
    }
    this->isBlocking = true;
}

void Player::stopBlocking() {
    this->isBlocking = false;
}

void Player::takeDamage(Player attacker) {
    if (this->getIsBlocking()) {
        this->currentHealth -= (10 + attacker.getStrength()) / 2;
        this->stopBlocking();

        if (attacker.getIsEnemy()) {
            cout << endl << "Enemy Attacking...You blocked and took damage!" << endl;
        } else {
            cout << endl << "Attacking...the enemy blocked and you deal less damage!" << endl;
        }

    } else {
        this->currentHealth -= 20 + attacker.getStrength();

        if (attacker.getIsEnemy()) {
            cout << endl << "Enemy Attacking...You take damage!" << endl;
        } else {
            cout << endl << "Attacking...you deal damage!" << endl;
        }
    }

    if (this->currentHealth < 0) {
        this->currentHealth = 0;
    }
}

void Player::takeDamage(int dmg) {
    this->currentHealth -= dmg;
}

void Player::heal(int amount) {
    if (this->getIsEnemy()) {
        cout << endl << "Enemy Healing...Enemy gained " << amount << " HP!" << endl;
    } else {
        cout << endl << "Healing... You gained " << amount << " HP!" << endl;
    }
    this->currentHealth += amount;
}