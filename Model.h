//
// Created by cirkul on 23.11.2020.
//

#ifndef UNTITLED3_MODEL_H
#define UNTITLED3_MODEL_H
#include "Tiranosaur.h"
#include "Lion.h"
#include "Wolf.h"
#include "Cat.h"
#include "Ferret.h"
#include "Elephant.h"
#include "Giraffi.h"
#include "Antelope.h"
#include "Sheep.h"
#include "Mouse.h"
#include "Chiken.h"
#include "Filereader.h"
#include <chrono>
#include <thread>

class Model {
public:

    ~Model();
    Playground* pg;

    class ModelException : public std::exception {
    public:
        ModelException(int id) {
            this->exCode  = id;
        }
        int exCode;

        const char * what() const noexcept override;
        std::string exceptionDiscription() const;
    };

    void uploadTheModel(const char* path);
    void firstSpawn(int i, int j, int = 0);

    void spawnAllPlants();
    void spawnPlant(Plant& plant);
    void spawnAnimal(Animal& animal);

    void move();
    void moveAnimal(Animal& animal);

    void checkIfAlive(Playground::Cell& cell);
    bool checkIfAlivePlant(Plant* plant);
    bool checkIfAliveAnimal(Animal& animal);

    void damage();
    void giveSpownAndMovPt();

    void autorun();
    void manualrun();

    void printWorld(int day = 1);
    void printWorldToConsole(int day = 1);
    const char* getName(creatures name) const;

    friend class Playground;
};

#endif //UNTITLED3_MODEL_H
