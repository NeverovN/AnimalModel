//
// Created by cirkul on 27.11.2020.
//

#include "Predator.h"

void Predator::eat() {
    for (auto victim : this->home->animals) {
        if (!victim->isAlive)
            continue;
        if (this->satietyInd == this->maxSatisfaction)
            return;
        if (victim->id == predator || victim->escape() || victim->size > this->size)
            continue;
        if (victim->hp > this->maxSatisfaction - this->satietyInd)
            this->satietyInd = maxSatisfaction;
        else
            this->satietyInd += victim->hp;
        victim->isAlive = false;
    }
}

Animal *Predator::spawn(Playground &pg, int i, int j) {
    Predator *newAnimal = new Predator(pg, i, j);
    ++newAnimal->home->creatureCount;
    newAnimal->pg->newCreatures[newAnimal] = 1;
    newAnimal->pg->allAnimals.push_back(newAnimal);
    newAnimal->home->animals.push_back(newAnimal);
    return newAnimal;
}