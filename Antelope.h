//
// Created by cirkul on 27.11.2020.
//

#ifndef UNTITLED3_ANTELOPE_H
#define UNTITLED3_ANTELOPE_H

#include "Herbivorous.h"

class Antelope : public Herbivorous {
    Antelope(Playground& pg, int i, int j) : Herbivorous(pg, i, j) {
        this->name = antelope;
        this->size = middle;
        this->escChance = 40;
        this->defaultHp = 140;
        this->hp = this->defaultHp;
        this->maxSatisfaction = 150;
        this->satietyInd = this->maxSatisfaction;
        this->energyConsumption = 70;
        this->lifeDuration = 4;
        this->movPt = 4;
        this->currMovPt = this->movPt;
    }

    Animal * spawn(Playground &pg, int i, int j) override;

    friend class Model;
};


#endif //UNTITLED3_ANTELOPE_H
