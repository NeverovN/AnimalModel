//
// Created by cirkul on 23.11.2020.
//

#include "Playground.h"

Playground::Playground(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    this->pg.resize(this->rows, std::vector<Cell>(this->cols));
    for (std::size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j) {
            this->pg[i][j].i = i;
            this->pg[i][j].j = j;
        }

}

Playground::Cell::Cell() {
    this->creatureCount = 0;
    this->plant = nullptr;
}

Playground::Cell::~Cell() {
    delete this->plant;
}
