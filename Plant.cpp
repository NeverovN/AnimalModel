//
// Created by cirkul on 27.11.2020.
//

#include "Plant.h"

Plant *Plant::spawn(Playground &pg, int i, int j) {
    Plant *newPlant = new Plant(pg, i, j);
    ++newPlant->home->creatureCount;
    newPlant->home->plant = newPlant;
    newPlant->pg->newCreatures[newPlant] = 1;
    newPlant->pg->allPlants.push_back(newPlant);
    return newPlant;
}

void Plant::aging() {
    this->hp -= 25;
    --this->lifeDuration;
    if (this->hp < 1 || this->lifeDuration == 0)
        this->isAlive = false;
}

void Plant::heal() { this->hp = this->defaultHp; }