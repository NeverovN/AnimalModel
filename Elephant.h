//
// Created by cirkul on 27.11.2020.
//

#ifndef UNTITLED3_ELEPHANT_H
#define UNTITLED3_ELEPHANT_H

#include "Herbivorous.h"

class Elephant : public Herbivorous {
    Elephant(Playground& pg, int i, int j) : Herbivorous(pg, i, j) {
        this->name = elephant;
        this->size = big;
        this->defaultHp = 250;
        this->hp= this->defaultHp;
        this->maxSatisfaction = 250;
        this->satietyInd = this->maxSatisfaction;
        this->energyConsumption = 100;
        this->lifeDuration = 5;
        this->movPt = 4;
        this->currMovPt = this->movPt;
    }

    Animal * spawn(Playground &pg, int i, int j) override;

    friend class Model;
};


#endif //UNTITLED3_ELEPHANT_H
