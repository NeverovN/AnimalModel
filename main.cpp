#include <iostream>

#include "Model.h"

int main() {
    srand(time(NULL));
    Model a;
    try {
        a.uploadTheModel("input.txt");
    }
    catch (std::ifstream::failure &ex) {
        std::cout << ex.what() << '\n' << ex.code();
    }
    catch (Model::ModelException &ex) {
        std::cout << ex.what() << std::endl;
        std::cout << ex.exceptionDiscription();
    }
    int choise;
    std::cout << "Select managing mode\n\t1. Autorun\n\t2. Manual\n";
    std::cin >> choise;
    switch (choise) {
        case 1:
            a.autorun();
            break;
        case 2:
            a.manualrun();
            break;
        default:
            break;
    }
    return 0;
}