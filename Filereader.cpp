//
// Created by cirkul on 24.11.2020.
//

#include "Filereader.h"

Filereader::Filereader(const char * path) {
    this->input.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    this->input.open(path);
}

Filereader::~Filereader() {
    this->input.close();
}