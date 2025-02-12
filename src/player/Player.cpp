#include "Player.h"

Player::Player(int healthLevel) {
    this->healthLevel = healthLevel;
    this->currentHealth = this->baseHealth * this->healthLevel;
}

int Player::getBaseHealth() {
    return this->baseHealth * this->healthLevel;
}

int Player::getHealth() {
    return currentHealth;
}

void Player::takeDamage(int dmg) {
    this->currentHealth -= dmg;
    if (this->currentHealth < 0) {
        this->currentHealth = 0;
    }
}

void Player::heal(int amount) {
    this->currentHealth += amount;
    /*
    if (this->currentHealth > this->getBaseHealth()) {
        this->currentHealth = this->getBaseHealth();
    }
    */
}

void Player::block() {
    isBlocking = true;
}