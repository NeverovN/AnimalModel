//
// Created by cirkul on 27.11.2020.
//

#ifndef UNTITLED3_CAT_H
#define UNTITLED3_CAT_H

#include "Predator.h"

class Cat : public Predator {
    Cat(Playground& pg, int i, int j) : Predator (pg, i, j) {
        this->name = cat;
        this->size = small;
        this->lifeDuration = 5;
        this->maxSatisfaction = 120;
        this->satietyInd = this->maxSatisfaction;
        this->energyConsumption = 50;
        this->movPt = 5;
        this->currMovPt = this->movPt;
    }

    Animal * spawn(Playground &pg, int i, int j) override;

    friend class Model;
};


#endif //UNTITLED3_CAT_H
