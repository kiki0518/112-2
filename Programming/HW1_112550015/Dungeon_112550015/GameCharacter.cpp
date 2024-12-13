#include "GameCharacter.h"

GameCharacter::GameCharacter() : Object(), maxHealth(0), currentHealth(0), attack(0), defense(0) {}

GameCharacter::GameCharacter(string name, string tag, int maxHealth, int attack, int defense) : Object(name, tag), maxHealth(maxHealth), currentHealth(maxHealth), attack(attack), defense(defense) {}

bool GameCharacter::checkIsDead() {
    return (this->currentHealth <= 0);
}

void GameCharacter::takeDamage(int damage) {
    this->setCurrentHealth(max(0, this->getCurrentHealth()-damage)); 
}

void GameCharacter::setMaxHealth(int maxHealth) {
    this->maxHealth = maxHealth;
}

void GameCharacter::setCurrentHealth(int currentHealth) {
    this->currentHealth = min(maxHealth, currentHealth);
}

void GameCharacter::setAttack(int attack) {
    this->attack = attack;
}

void GameCharacter::setDefense(int defense) {
    this->defense = defense;
}

int GameCharacter::getMaxHealth() {
    return this->maxHealth;
}

int GameCharacter::getCurrentHealth() {
    return this->currentHealth;
}

int GameCharacter::getAttack() {
    return this->attack;
}

int GameCharacter::getDefense() {
    return this->defense;
}
