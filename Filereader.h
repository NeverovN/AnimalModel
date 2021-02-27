//
// Created by cirkul on 24.11.2020.
//

#ifndef UNTITLED3_FILEREADER_H
#define UNTITLED3_FILEREADER_H

#include <fstream>



class Filereader {
    Filereader(const char *path);
    ~Filereader();

    std::ifstream input;

    friend class Model;
};

#endif //UNTITLED3_FILEREADER_H
