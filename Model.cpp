//
// Created by cirkul on 23.11.2020.
//

#include "Model.h"
#include <iostream>


void Model::spawnAllPlants() {
    for (auto item : this->pg->allPlants)
        if (this->pg->newCreatures.find(item) == this->pg->newCreatures.end())
            spawnPlant(*item);
}

void Model::spawnPlant(Plant &plant) {
    std::vector<Playground::Cell *> emptyCells;
    std::multimap<int, Playground::Cell *> cells;
    for (int i = plant.i - 1; i <= plant.i + 1; ++i) {
        for (int j = plant.j - 1; j <= plant.j + 1; ++j) {
            Playground::Cell *curCell = &this->pg->pg[i][j];
            if (i < 0 || j < 0 || i >= this->pg->rows || j >= this->pg->cols)
                continue;
            if (this->pg->newCreatures.find(curCell->plant) != this->pg->newCreatures.end())
                continue;
            if (plant.pg->pg[i][j].creatureCount == MAX_COUNT)
                continue;
            if (i == plant.i && j == plant.j)
                continue;
            if (curCell->plant != nullptr) {
                cells.insert(std::pair<int, Playground::Cell *>(curCell->plant->hp, curCell));
                continue;
            }

            emptyCells.push_back(&this->pg->pg[i][j]);
        }
    }

    if (!emptyCells.empty()) {
        int cell = rand() % emptyCells.size();
        Playground::Cell *randCell = &this->pg->pg[emptyCells[cell]->i][emptyCells[cell]->j];
        plant.spawn(*this->pg, randCell->i, randCell->j);
        return;
    }
    if (!cells.empty()) {
        int count = 0;

        for (auto it = cells.begin(); it->first == cells.begin()->first; ++it) ++count;

        int randCell = rand() % count;
        auto it = cells.begin();

        for (int i = 0; i < randCell; ++i) ++it;

        it->second->plant->heal();
        return;
    }

    plant.heal();
}

void Model::spawnAnimal(Animal &animal) {
    if (!animal.oppToSpawn)
        return;
    for (auto partner : animal.home->animals) {
        if (partner->getID() != animal.getID())
            continue;
        if (partner->sex == animal.sex)
            continue;
        if (animal.home->creatureCount == MAX_COUNT)
            continue;
        if (!partner->oppToSpawn || !partner->isAlive)
            continue;
        animal.spawn(*animal.pg, animal.i, animal.j);
        animal.oppToSpawn = false;
        partner->oppToSpawn = false;
        return;
    }
}

void Model::move() {
    auto stop = this->pg->allAnimals.end();
    for (auto it = this->pg->allAnimals.begin(); it < stop; ++it) {
        if (this->pg->newCreatures.find(*it) != this->pg->newCreatures.end())
            break;
        Animal &animal = **it;
        if (animal.isAlive)
            this->moveAnimal(animal);
    }
}

void Model::moveAnimal(Animal &animal) {
    while (animal.currMovPt) {
        animal.eat();
        this->checkIfAlive(*animal.home);
        animal.starving();
        if (animal.starving())
            this->spawnAnimal(animal);
        animal.move();
        --animal.currMovPt;
    }
}

void Model::uploadTheModel(const char *path){
    Filereader file(path);
    int rows, cols, plantCount, animalCount;
    file.input >> rows;
    file.input >> cols;
    if (rows < 1 || cols < 1)
        throw ModelException(1);
    this->pg = new Playground(rows, cols);
    file.input >> plantCount;

    if (plantCount < 0)
        throw ModelException(2);

    for (int k = 0; k < plantCount; ++k) {
        int i, j;
        file.input >> i >> j;

        if (i < 0 || j < 0 || i >= rows || j >= cols)
            throw ModelException(3);

        this->firstSpawn(i, j);
    }
    file.input >> animalCount;
    if (animalCount < 0)
        throw ModelException(2);
    for (int k = 0; k < animalCount; ++k) {
        int i, j, id;
        file.input >> i >> j >> id;

        if (i < 0 || j < 0 || i >= rows || j >= cols)
            throw ModelException(3);

        if (id < 1 || id > 11)
            throw ModelException(4);

        this->firstSpawn(i, j, id);
    }
}


void Model::firstSpawn(int i, int j, int id) {
    switch (id) {
        case tree: {
            if (this->pg->pg[i][j].plant != nullptr || this->pg->pg[i][j].creatureCount == MAX_COUNT)
                throw ModelException(5);

            this->pg->pg[i][j].plant = new Plant(*pg, i, j);
            Plant *newPlant = this->pg->pg[i][j].plant;
            ++this->pg->pg[i][j].creatureCount;
            this->pg->allPlants.push_back(newPlant);
            break;
        }
        case tiranasaur: {
            if (this->pg->pg[i][j].creatureCount == MAX_COUNT)
                throw ModelException(5);

            Tiranosaur *newAnimal = new Tiranosaur(*pg, i, j);
            this->pg->pg[i][j].animals.push_back(newAnimal);
            ++this->pg->pg[i][j].creatureCount;
            this->pg->allAnimals.push_back(newAnimal);
            break;
        }
        case lion: {
            if (this->pg->pg[i][j].creatureCount == MAX_COUNT)
                throw ModelException(5);

            Lion *newAnimal = new Lion(*pg, i, j);
            this->pg->pg[i][j].animals.push_back(newAnimal);
            ++this->pg->pg[i][j].creatureCount;
            this->pg->allAnimals.push_back(newAnimal);
            break;
        }
        case wolf: {
            if (this->pg->pg[i][j].creatureCount == MAX_COUNT)
                throw ModelException(5);

            Wolf *newAnimal = new Wolf(*pg, i, j);
            this->pg->pg[i][j].animals.push_back(newAnimal);
            ++this->pg->pg[i][j].creatureCount;
            this->pg->newCreatures[newAnimal] = 1;
            this->pg->allAnimals.push_back(newAnimal);
            break;
        }
        case cat: {
            if (this->pg->pg[i][j].creatureCount == MAX_COUNT)
                throw ModelException(5);

            Cat *newAnimal = new Cat(*pg, i, j);
            this->pg->pg[i][j].animals.push_back(newAnimal);
            ++this->pg->pg[i][j].creatureCount;
            this->pg->allAnimals.push_back(newAnimal);
            break;
        }
        case ferret: {
            if (this->pg->pg[i][j].creatureCount == MAX_COUNT)
                throw ModelException(5);

            Ferret *newAnimal = new Ferret(*pg, i, j);
            this->pg->pg[i][j].animals.push_back(newAnimal);
            ++this->pg->pg[i][j].creatureCount;
            this->pg->newCreatures[newAnimal] = 1;
            this->pg->allAnimals.push_back(newAnimal);
            break;
        }
        case elephant: {
            if (this->pg->pg[i][j].creatureCount == MAX_COUNT)
                throw ModelException(5);

            Elephant *newAnimal = new Elephant(*pg, i, j);
            this->pg->pg[i][j].animals.push_back(newAnimal);
            ++this->pg->pg[i][j].creatureCount;
            this->pg->allAnimals.push_back(newAnimal);
            break;
        }
        case giraffi: {
            if (this->pg->pg[i][j].creatureCount == MAX_COUNT)
                throw ModelException(5);

            Giraffi *newAnimal = new Giraffi(*pg, i, j);
            this->pg->pg[i][j].animals.push_back(newAnimal);
            ++this->pg->pg[i][j].creatureCount;
            this->pg->allAnimals.push_back(newAnimal);
            break;
        }
        case antelope: {
            if (this->pg->pg[i][j].creatureCount == MAX_COUNT)
                throw ModelException(5);

            Antelope *newAnimal = new Antelope(*pg, i, j);
            this->pg->pg[i][j].animals.push_back(newAnimal);
            ++this->pg->pg[i][j].creatureCount;
            this->pg->allAnimals.push_back(newAnimal);
            break;
        }
        case sheep: {
            if (this->pg->pg[i][j].creatureCount == MAX_COUNT)
                throw ModelException(5);

            Sheep *newAnimal = new Sheep(*pg, i, j);
            this->pg->pg[i][j].animals.push_back(newAnimal);
            ++this->pg->pg[i][j].creatureCount;
            this->pg->allAnimals.push_back(newAnimal);
            break;
        }
        case chiken: {
            if (this->pg->pg[i][j].creatureCount == MAX_COUNT)
                throw ModelException(5);

            Chiken *newAnimal = new Chiken(*pg, i, j);
            this->pg->pg[i][j].animals.push_back(newAnimal);
            ++this->pg->pg[i][j].creatureCount;
            this->pg->allAnimals.push_back(newAnimal);
            break;
        }
        case mouse: {
            if (this->pg->pg[i][j].creatureCount == MAX_COUNT)
                throw ModelException(5);

            Mouse *newAnimal = new Mouse(*pg, i, j);
            this->pg->pg[i][j].animals.push_back(newAnimal);
            ++this->pg->pg[i][j].creatureCount;
            this->pg->newCreatures[newAnimal] = 1;
            this->pg->allAnimals.push_back(newAnimal);
            break;
        }
        default:
            break;
    }
}

void Model::checkIfAlive(Playground::Cell &cell) {
    if (cell.plant != nullptr && !cell.plant->isAlive) {
        --cell.creatureCount;
        auto it = cell.plant->pg->allPlants.begin();
        while (*it != cell.plant) ++it;
        cell.plant->pg->allPlants.erase(it);
        cell.plant = nullptr;
    }
    for (auto it = cell.animals.begin(); it < cell.animals.end(); ++it) {
        Animal &animal = **it;
        if (!animal.isAlive) {
            auto itAll = animal.pg->allAnimals.begin();
            while (*itAll != &animal) ++itAll;
            animal.pg->allAnimals.erase(itAll);
            cell.animals.erase(it);
            --cell.creatureCount;
        }
    }
}

void Model::damage() {
    auto itAnimal = this->pg->allAnimals.begin();
    while (!this->pg->allAnimals.empty()) {
        Animal &animal = **itAnimal;
        if (this->pg->newCreatures.find(&animal) != this->pg->newCreatures.end()) break;

        animal.aging();
        animal.checkIfStarve();
        if (this->checkIfAliveAnimal(animal)) ++itAnimal;
        if (itAnimal == this->pg->allAnimals.end()) break;
    }
    auto itPlant = this->pg->allPlants.begin();
    while (!this->pg->allPlants.empty()) {
        Plant &plant = **itPlant;
        if (this->pg->newCreatures.find(&plant) != this->pg->newCreatures.end()) break;

        plant.aging();
        if (this->checkIfAlivePlant(&plant))
            ++itPlant;
        if (itPlant == this->pg->allPlants.end())
            break;
    }
}

bool Model::checkIfAliveAnimal(Animal &animal) {
    if (animal.isAlive)
        return true;
    auto itCell = animal.home->animals.begin();
    auto itAll = animal.pg->allAnimals.begin();
    while (*itCell != &animal) ++itCell;
    while (*itAll != &animal) ++itAll;
    animal.pg->allAnimals.erase(itAll);
    animal.home->animals.erase(itCell);
    --animal.home->creatureCount;
    return false;
}

void Model::giveSpownAndMovPt() {
    for (auto animal : this->pg->allAnimals)
        if (this->pg->newCreatures.find(animal) == this->pg->newCreatures.end()) {
            animal->currMovPt = animal->movPt;
            animal->oppToSpawn = true;
        }
}

void Model::manualrun() {
    char cont[50];
    int day = 0;
    this->printWorldToConsole(++day);
    while (!this->pg->allAnimals.empty()) {
        std::cout << "Input anyting to continue\n";
        std::cin >> cont;
        this->spawnAllPlants();
        this->move();
        this->damage();
        this->giveSpownAndMovPt();
        this->pg->newCreatures.clear();
        this->printWorldToConsole(++day);
    }
}

void Model::autorun() {
    int day = 0;
    while (!this->pg->allAnimals.empty()) {
        this->printWorld(++day);
        this->spawnAllPlants();
        this->move();
        this->damage();
        this->giveSpownAndMovPt();
        this->pg->newCreatures.clear();
    }
}

bool Model::checkIfAlivePlant(Plant *plant) {
    if (plant->isAlive)
        return true;
    --plant->home->creatureCount;
    plant->home->plant = nullptr;
    auto it = this->pg->allPlants.begin();
    while (*it != plant) ++it;
    this->pg->allPlants.erase(it);
    plant = nullptr;
    return false;
}

Model::~Model() {
    delete pg;
}

void Model::printWorld(int day) {
    bool flag = true;

    if (day == 1) {
        std::fstream clear_file("output.txt", std::ios::out);
        clear_file.close();
    }

    std::ofstream output("output.txt", std::ios::binary | std::ios::app);
    output << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tDAY " << day << "\n\n\n";
    for (auto it = this->pg->pg.begin(); it < this->pg->pg.end(); ++it)
        output << "_______________";
    output << "________ ";
    output << std::endl;
    for (auto it1 = this->pg->pg.begin(); it1 < this->pg->pg.end(); ++it1) {
        for (auto it2 = it1->begin(); it2 < it1->end(); ++it2) {
            if (flag) {
                if (it2->plant != nullptr)
                    output << "P:" << it2->plant->hp << '\t';
                else
                    output << "P:NUL" << '\t';
                if (it2->animals.size() > 0) {
                    output << this->getName(it2->animals[0]->getName()) << ":";
                    if (it2->animals[0]->hp < 100 && it2->animals[0]->getName() != chiken)
                        output << ' ';
                    output << it2->animals[0]->hp;
                } else
                    output << "B:NUL";
                output << " | ";
            } else {
                if (it2->animals.size() == 3) {
                    output << this->getName(it2->animals[1]->getName()) << ":";
                    if (it2->animals[1]->hp < 100 && it2->animals[1]->getName() != chiken)
                        output << ' ';
                    output << it2->animals[1]->hp << '\t';
                    output << this->getName(it2->animals[2]->getName()) << ":";
                    if (it2->animals[2]->hp < 100 && it2->animals[2]->getName() != chiken)
                        output << ' ';
                    output << it2->animals[2]->hp;
                } else if (it2->animals.size() == 2) {
                    output << this->getName(it2->animals[1]->getName()) << ":";
                    if (it2->animals[1]->hp < 100 && it2->animals[1]->getName() != chiken)
                        output << ' ';
                    output << it2->animals[1]->hp << '\t';
                    output << "B:NUL";
                } else {
                    output << "B:NUL" << '\t';
                    output << "B:NUL";
                }
                output << " | ";
            }
        }
        if (flag) {
            output << std::endl;
            it1 = prev(it1);
            flag = false;
        } else {
            for (auto it = this->pg->pg.begin(); it < this->pg->pg.end(); ++it)
                output << "_______________";
            output << "________| ";
            output << std::endl;
            flag = true;
        }
    }
    output << "\n\n";
    output.close();
}

const char *Model::getName(creatures name) const {
    switch (name) {
        case tiranasaur: {
            return "T";
        }
        case lion: {
            return "L";
        }
        case wolf: {
            return "W";
        }
        case cat: {
            return "C";
        }
        case ferret: {
            return "F";
        }
        case elephant: {
            return "E";
        }
        case giraffi: {
            return "G";
        }
        case antelope: {
            return "A";
        }
        case sheep: {
            return "S";
        }
        case chiken: {
            return "Ch";
        }
        case mouse: {
            return "M";
        }
        default:
            return "";

    }
}

void Model::printWorldToConsole(int day) {
    bool flag = true;

    std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tDAY " << day << "\n\n\n";
    for (auto it = this->pg->pg.begin(); it < this->pg->pg.end(); ++it)
        std::cout << "_______________";
    std::cout << "________ ";
    std::cout << std::endl;
    for (auto it1 = this->pg->pg.begin(); it1 < this->pg->pg.end(); ++it1) {
        for (auto it2 = it1->begin(); it2 < it1->end(); ++it2) {
            if (flag) {
                if (it2->plant != nullptr)
                    std::cout << "P:" << it2->plant->hp << '\t';
                else
                    std::cout << "P:NUL" << '\t';
                if (it2->animals.size() > 0) {
                    std::cout << this->getName(it2->animals[0]->getName()) << ":";
                    if (it2->animals[0]->hp < 100 && it2->animals[0]->getName() != chiken)
                        std::cout << ' ';
                    std::cout << it2->animals[0]->hp;
                } else
                    std::cout << "B:NUL";
                std::cout << " | ";
            } else {
                if (it2->animals.size() == 3) {
                    std::cout << this->getName(it2->animals[1]->getName()) << ":";
                    if (it2->animals[1]->hp < 100 && it2->animals[1]->getName() != chiken)
                        std::cout << ' ';
                    std::cout << it2->animals[1]->hp << '\t';
                    std::cout << this->getName(it2->animals[2]->getName()) << ":";
                    if (it2->animals[2]->hp < 100 && it2->animals[2]->getName() != chiken)
                        std::cout << ' ';
                    std::cout << it2->animals[2]->hp;
                } else if (it2->animals.size() == 2) {
                    std::cout << this->getName(it2->animals[1]->getName()) << ":";
                    if (it2->animals[1]->hp < 100 && it2->animals[1]->getName() != chiken)
                        std::cout << ' ';
                    std::cout << it2->animals[1]->hp << '\t';
                    std::cout << "B:NUL";
                } else {
                    std::cout << "B:NUL" << '\t';
                    std::cout << "B:NUL";
                }
                std::cout << " | ";
            }
        }
        if (flag) {
            std::cout << std::endl;
            it1 = prev(it1);
            flag = false;
        } else {
            std::cout << std::endl;
            for (auto it = this->pg->pg.begin(); it < this->pg->pg.end(); ++it)
                std::cout << "_______________";
            std::cout << "________| ";
            std::cout << std::endl;
            flag = true;
        }
    }
}

std::string Model::ModelException::exceptionDiscription() const {
    switch (this->exCode) {
        case 1:
            return "code: " + std::to_string(this->exCode) + "\nIncorrect playground size";
        case 2:
            return "code: " + std::to_string(this->exCode) + "\nIncorrect creature count";
        case 3:
            return "code: " + std::to_string(this->exCode) + "\nIncorrect creature position (out of range)";
        case 4:
            return "code: " + std::to_string(this->exCode) + "\nUncnown animal type";
        case 5:
            return "code: " + std::to_string(this->exCode) + "\nSpawn error. The cell is already full";
        default:
            return "Unknown error";
    }
}

const char *Model::ModelException::what() const noexcept {
    return "Exception of Model class. Use exceptionDiscription(); to get more informarion";
}
