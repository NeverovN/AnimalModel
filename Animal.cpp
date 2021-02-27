//
// Created by cirkul on 27.11.2020.
//

#include "Animal.h"

Animal *Animal::spawn(Playground &pg, int i, int j) { return nullptr; }



void Animal::move() {
    std::vector<Playground::Cell *> cells;
    for (int i = this->i - 1; i <= this->i + 1; ++i) {
        for (int j = this->j - 1; j <= this->j + 1; ++j) {
            if (i < 0 || j < 0 || i >= this->pg->rows || j >= this->pg->cols)
                continue;
            if (this->pg->pg[i][j].creatureCount == MAX_COUNT)
                continue;
            if (i == this->i && j == this->j)
                continue;
            cells.push_back(&this->pg->pg[i][j]);
        }
    }
    if (!cells.empty()) {
        int randCell = rand() % cells.size();

        --this->home->creatureCount;
        ++cells[randCell]->creatureCount;

        auto it = this->home->animals.begin();
        while (*it != this) ++it;
        this->home->animals.erase(it);
        cells[randCell]->animals.push_back(this);

        this->i = cells[randCell]->i;
        this->j = cells[randCell]->j;
        this->home = cells[randCell];
    }
}

bool Animal::starving() const {
    if (this->satietyInd < 0.7* this->maxSatisfaction)
        return false;
    else
        return true;
}

bool Animal::escape() { return false; }

void Animal::checkIfStarve() {
    this->hp = this->defaultHp * ((double)this->satietyInd / (double)this->maxSatisfaction);
    if (this->hp < 1)
        this->isAlive = false;
    this->satietyInd -= this->energyConsumption;
}

void Animal::aging() {
    --this->lifeDuration;
    if (!this->lifeDuration)
        this->isAlive = false;
}




