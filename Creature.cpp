//
// Created by cirkul on 23.11.2020.
//

#include "Creature.h"

Creature::Creature(Playground &pg, int i, int j) {
    this->i = i;
    this->j = j;
    this->defaultHp = 100;
    this->hp = this->defaultHp;
    this->lifeDuration = 4;
    this->id = creature;
    this->pg = &pg;
    this->home = &this->pg->pg[i][j];
}

Creature::~Creature() {
    delete pg;
    delete home;
}