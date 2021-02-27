//
// Created by cirkul on 27.11.2020.
//

#include "Herbivorous.h"

Animal *Herbivorous::spawn(Playground &pg, int i, int j) {
    Herbivorous *newAnimal = new Herbivorous(pg, i, j);
    ++newAnimal->home->creatureCount;
    newAnimal->pg->newCreatures[newAnimal] = 1;
    newAnimal->pg->allAnimals.push_back(newAnimal);
    newAnimal->home->animals.push_back(newAnimal);
    return newAnimal;
}

void Herbivorous::eat() {
    if (this->satietyInd == this->maxSatisfaction)
        return;
    Plant *food = this->home->plant;
    if (food == nullptr || !food->isAlive)
        return;
    if (this->satietyInd == this->maxSatisfaction)
        return;
    if (food->hp > this->maxSatisfaction - this->satietyInd) {
        food->hp -= this->maxSatisfaction - this->satietyInd;
        this->satietyInd = maxSatisfaction;
    } else {
        this->satietyInd += food->hp;
        food->isAlive = false;
    }
}

bool Herbivorous::escape() { return rand() % 100 + 1 < this->escChance; }

