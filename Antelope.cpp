//
// Created by cirkul on 27.11.2020.
//

#include "Antelope.h"

Animal *Antelope::spawn(Playground &pg, int i, int j) {
    Antelope *newAnimal = new Antelope(pg, i, j);
    ++newAnimal->home->creatureCount;
    newAnimal->pg->newCreatures[newAnimal] = 1;
    newAnimal->pg->allAnimals.push_back(newAnimal);
    newAnimal->home->animals.push_back(newAnimal);
    return newAnimal;
}