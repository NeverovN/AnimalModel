//
// Created by cirkul on 27.11.2020.
//

#ifndef UNTITLED3_WOLF_H
#define UNTITLED3_WOLF_H

#include "Predator.h"

class Wolf : public Predator {
    Wolf(Playground& pg, int i, int j) : Predator (pg, i, j) {
        this->name = wolf;
        this->size = middle;
        this->defaultHp = 150;
        this->hp = this->defaultHp;
        this->lifeDuration = 4;
        this->maxSatisfaction = 150;
        this->satietyInd = this->maxSatisfaction;
        this->movPt = 5;
        this->currMovPt = this->movPt;
        this->energyConsumption = 50;
    }

    Animal * spawn(Playground &pg, int i, int j) override;

    friend class Model;
};

#endif //UNTITLED3_WOLF_H
