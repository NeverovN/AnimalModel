cmake_minimum_required(VERSION 3.17)
project(untitled3)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled3 main.cpp Playground.cpp Playground.h Creature.cpp Creature.h
        Model.cpp Model.h Filereader.cpp Filereader.h Plant.cpp Plant.h Animal.cpp Animal.h
        Herbivorous.cpp Herbivorous.h Predator.cpp Predator.h Tiranosaur.cpp Tiranosaur.h
        Lion.cpp Lion.h Wolf.cpp Wolf.h Cat.cpp Cat.h Ferret.cpp Ferret.h Elephant.cpp Elephant.h
        Giraffi.cpp Giraffi.h Antelope.cpp Antelope.h Sheep.cpp Sheep.h Chiken.cpp Chiken.h Mouse.cpp Mouse.h)