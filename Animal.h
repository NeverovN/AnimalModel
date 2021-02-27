//
// Created by cirkul on 27.11.2020.
//

#ifndef UNTITLED3_ANIMAL_H
#define UNTITLED3_ANIMAL_H

#include "Plant.h"


class Animal : public Creature {
protected:

    Animal(Playground& pg, int i, int j) : Creature(pg, i, j) {
        this->id = animal;
        this->sex = rand() % 2;
        this->movPt = 3;
        this->currMovPt = this->movPt;
        this->oppToSpawn = true;
        this->size = noSize;
        this->maxSatisfaction = 200;
        this->energyConsumption = 100;
        this->satietyInd = this->maxSatisfaction;
    }

    sizeOfAnimal size;
    bool sex; // male == true
    bool oppToSpawn;
    int movPt; //количество очков передвижения
    int currMovPt;
    int satietyInd;
    int energyConsumption;
    int maxSatisfaction;

    virtual Animal* spawn(Playground& pg, int i, int j);
    void move(); //ready
    virtual void eat() {};

    bool starving() const;

    virtual bool escape();

    void checkIfStarve(); //ready
    void aging() override;

    //friend class Playground;
    friend class Model;
    friend class Predator;
};


#endif //UNTITLED3_ANIMAL_H
