//
// Created by cirkul on 27.11.2020.
//

#ifndef UNTITLED3_TIRANOSAUR_H
#define UNTITLED3_TIRANOSAUR_H

#include "Predator.h"

class Tiranosaur : public Predator {
    Tiranosaur(Playground& pg, int i, int j) : Predator (pg, i, j) {
        this->name = tiranasaur;
        this->size = big;
        this->maxSatisfaction = 300;
        this->satietyInd = this->maxSatisfaction;
        this->defaultHp = 300;
        this->hp = this->defaultHp;
        this->lifeDuration = 5;
        this->movPt = 4;
        this->currMovPt = this->movPt;
        this->energyConsumption = 140;
    }

    Animal * spawn(Playground &pg, int i, int j) override;

    friend class Model;
};


#endif //UNTITLED3_TIRANOSAUR_H
