#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
        int baseHealth = 100;
        int level;
        int currentHealth;
        int strength;
        bool isBlocking = false;
        bool isEnemy;

    public:
        Player(int level, bool isEnemy);
        int getBaseHealth();
        int getHealth();
        int getStrength();
        bool getIsEnemy();
        bool getIsBlocking();
        void addStrength(int amount);
        void startBlocking();
        void stopBlocking();
        void takeDamage(Player attacker);
        void takeDamage(int dmg);
        void heal(int amount);
};

#endif