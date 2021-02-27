//
// Created by cirkul on 27.11.2020.
//

#ifndef UNTITLED3_CHIKEN_H
#define UNTITLED3_CHIKEN_H

#include "Herbivorous.h"

class Chiken : public Herbivorous {
    Chiken(Playground& pg, int i, int j) : Herbivorous(pg, i, j) {
        this->name = chiken;
        this->size = small;
        this->escChance = 10;
        this->defaultHp = 60;
        this->hp = this->defaultHp;
        this->maxSatisfaction = 100;
        this->satietyInd = this->maxSatisfaction;
        this->lifeDuration = 4;
        this->movPt = 3;
        this->currMovPt = this->movPt;
    }

    Animal * spawn(Playground &pg, int i, int j) override;

    friend class Model;
};


#endif //UNTITLED3_CHIKEN_H
