//
// Created by cirkul on 27.11.2020.
//

#ifndef UNTITLED3_PLANT_H
#define UNTITLED3_PLANT_H

#include "Creature.h"


class Plant : public Creature { //ready

    Plant(Playground& pg, int i, int j) : Creature(pg, i, j) {
        this->lifeDuration = 3;
        this->id = plant;
        this->name = tree;
    }

    Plant *spawn(Playground& pg, int i, int j);
    void aging() override;
    void heal();

    friend class Playground;
    friend class Animal;
    friend class Model;

};


#endif //UNTITLED3_PLANT_H
