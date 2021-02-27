//
// Created by cirkul on 27.11.2020.
//

#ifndef UNTITLED3_GIRAFFI_H
#define UNTITLED3_GIRAFFI_H

#include "Herbivorous.h"

class Giraffi : public Herbivorous {
    Giraffi(Playground& pg, int i, int j) : Herbivorous(pg, i, j) {
        this->name = giraffi;
        this->size = big;
        this->defaultHp = 200;
        this->hp = this->defaultHp;
        this->maxSatisfaction = 200;
        this->satietyInd = this->maxSatisfaction;
        this->energyConsumption = 70;
        this->lifeDuration = 4;
        this->movPt = 4;
        this->currMovPt = this->movPt;
    }

    Animal * spawn(Playground &pg, int i, int j) override;

    friend class Model;
};


#endif //UNTITLED3_GIRAFFI_H
