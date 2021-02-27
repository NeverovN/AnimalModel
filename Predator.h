//
// Created by cirkul on 27.11.2020.
//

#ifndef UNTITLED3_PREDATOR_H
#define UNTITLED3_PREDATOR_H

#include "Animal.h"

class Predator : public Animal {
protected:
    Predator(Playground& pg, int i, int j) : Animal(pg, i, j) { this->id = predator; }

    Animal * spawn(Playground &pg, int i, int j) override;

    void eat() override;

    friend class Playground;
    friend class Model;
};


#endif //UNTITLED3_PREDATOR_H
