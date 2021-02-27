//
// Created by cirkul on 27.11.2020.
//

#ifndef UNTITLED3_HERBIVOROUS_H
#define UNTITLED3_HERBIVOROUS_H

#include "Animal.h"

class Herbivorous : public Animal {
protected:

    Herbivorous(Playground& pg, int i, int j) : Animal(pg, i, j) {
        this->id = herbivorous;
        this->escChance = 0;
    }

    int escChance;

    Animal * spawn(Playground& pg, int i, int j) override;

    bool escape() override;

    void eat() override;

    friend class Playground;
    friend class Predator;
};


#endif //UNTITLED3_HERBIVOROUS_H
