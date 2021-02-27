//
// Created by cirkul on 27.11.2020.
//

#ifndef UNTITLED3_SHEEP_H
#define UNTITLED3_SHEEP_H

#include "Herbivorous.h"

class Sheep : public Herbivorous {
    Sheep(Playground& pg, int i, int j) : Herbivorous(pg, i, j) {
        this->name = sheep;
        this->size = middle;
        this->escChance = 10;
        this->defaultHp = 100;
        this->hp = this->defaultHp;
        this->maxSatisfaction = 100;
        this->satietyInd = this->maxSatisfaction;
        this->energyConsumption = 50;
        this->lifeDuration = 4;
        this->movPt = 3;
        this->currMovPt = this->movPt;
    }

    Animal * spawn(Playground &pg, int i, int j) override;

    friend class Model;
};

#endif //UNTITLED3_SHEEP_H
