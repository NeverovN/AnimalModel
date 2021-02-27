//
// Created by cirkul on 23.11.2020.
//

#ifndef UNTITLED3_PLAYGROUND_H
#define UNTITLED3_PLAYGROUND_H

#include <map>
#include <vector>


const int MAX_COUNT = 4;

class Creature;
class Animal;
class Plant;

class Playground {
public:
    Playground (int rows, int cols);

    class Cell {
    public:
        Cell();
        ~Cell();
        int i;
        int j;
        int creatureCount;
        Plant *plant;
        std::vector<Animal *> animals;
    };

    std::vector<std::vector<Cell>> pg;
    int rows;
    int cols;
    std::map<Creature *, int> newCreatures;
    std::vector<Animal *> allAnimals;
    std::vector<Plant*> allPlants;

    friend class Creature;
    friend class Animal;
    friend class Plant;
};




#endif //UNTITLED3_PLAYGROUND_H
