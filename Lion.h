//
// Created by cirkul on 27.11.2020.
//

#ifndef UNTITLED3_LION_H
#define UNTITLED3_LION_H

#include "Predator.h"

class Lion : public Predator {
    Lion(Playground& pg, int i, int j) : Predator (pg, i, j) {
        this->name = lion;
        this->size = middle;
        this->defaultHp = 250;
        this->hp = this->defaultHp;
        this->lifeDuration = 4;
        this->energyConsumption = 120;
    }

    Animal * spawn(Playground &pg, int i, int j) override;

    friend class Model;
};


#endif //UNTITLED3_LION_H
