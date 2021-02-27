//
// Created by cirkul on 23.11.2020.
//

#ifndef UNTITLED3_CREATURE_H
#define UNTITLED3_CREATURE_H

#include "Playground.h"

#include <random>

enum creatureID {
    creature,
    plant,
    animal,
    herbivorous,
    predator,
};

enum creatures {
    tree,
    tiranasaur,
    lion,
    wolf,
    cat,
    ferret,
    elephant,
    giraffi,
    antelope,
    sheep,
    chiken,
    mouse
};

enum sizeOfAnimal {
    noSize, small, middle, big
};


class Creature {
protected:

    Creature(Playground& pg, int i, int j);
    ~Creature();

    Playground* pg;
    Playground::Cell* home;
    bool isAlive = true;
    int lifeDuration;
    int j;
    int i;
    int hp;
    int defaultHp;
    creatureID id;
    creatures name;

    creatureID getID() const { return this->id; }
    creatures getName() const {return this->name; }
    virtual void aging() { --this->lifeDuration; }

    friend class Playground;
    friend  class Herbivorous;
    friend class Predator;
};


#endif //UNTITLED3_CREATURE_H
