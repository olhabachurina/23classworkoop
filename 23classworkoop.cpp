// 23classworkoop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
class Character {
public:
    virtual void Attack(Character* target) {
        std::cout << "You attack the enemy!" << std::endl;
    }
};

class Player : public Character {
public:
    void Attack(Character* target) override {
        Player* playerPtr = dynamic_cast<Player*>(target);
        if (playerPtr != nullptr) {
            std::cout << "You attack the enemy!" << std::endl;
        }
    }
};

class Enemy : public Character {
public:
    void Attack(Character* target) override {
        Enemy* enemyPtr = dynamic_cast<Enemy*>(target);
        if (enemyPtr != nullptr) {
            std::cout << "The enemy attacks you!" << std::endl;
        }
    }
};

int main() {
    Player player;
    Enemy enemy;

    Character* playerPtr = static_cast<Character*>(&player);
    Character* enemyPtr = static_cast<Character*>(&enemy);

    playerPtr->Attack(enemyPtr); // Вызывает функцию Attack() класса Player
    enemyPtr->Attack(playerPtr); // Вызывает функцию Attack() класса Enemy
    std::cout << "Attacks completed." << std::endl;
    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
