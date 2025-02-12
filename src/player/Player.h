#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
        int baseHealth = 100;
        int healthLevel;
        int currentHealth;


    public:
        Player(int healthLevel);
        int getBaseHealth();
        int getHealth();
        void takeDamage(int dmg);
        void heal(int amount);
        bool isBlocking;
        void block();
        int strength;
};

#endif