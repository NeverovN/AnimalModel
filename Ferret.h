//
// Created by cirkul on 27.11.2020.
//

#ifndef UNTITLED3_FERRET_H
#define UNTITLED3_FERRET_H

#include "Predator.h"

class Ferret : public Predator {
    Ferret(Playground& pg, int i, int j) : Predator (pg, i, j) {
        this->name = ferret;
        this->size = small;
        this->defaultHp = 70;
        this->hp = this->defaultHp;
        this->lifeDuration = 3;
        this->maxSatisfaction = 70;
        this->satietyInd = this->maxSatisfaction;
        this->energyConsumption = 50;
        this->movPt = 7;
        this->currMovPt = this->movPt;
    }

    Animal * spawn(Playground &pg, int i, int j) override;

    friend class Model;
};


#endif //UNTITLED3_FERRET_H
