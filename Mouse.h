//
// Created by cirkul on 27.11.2020.
//

#ifndef UNTITLED3_MOUSE_H
#define UNTITLED3_MOUSE_H

#include "Herbivorous.h"

class Mouse : public Herbivorous {
    Mouse(Playground& pg, int i, int j) : Herbivorous(pg, i, j) {
        this->name = mouse;
        this->size = small;
        this->escChance = 25;
        this->defaultHp = 40;
        this->hp = this->defaultHp;
        this->maxSatisfaction = 60;
        this->satietyInd = this->maxSatisfaction;
        this->lifeDuration = 5;
        this->movPt = 3;
        this->currMovPt = this->movPt;
    }

    Animal * spawn(Playground &pg, int i, int j) override;

    friend class Model;
};


#endif //UNTITLED3_MOUSE_H
