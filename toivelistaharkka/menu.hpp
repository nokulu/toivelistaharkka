#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip> // For std::fixed and std::setprecision


class Menu {
public:
    void display() const {
        std::cout << "\nMenu:\n";
        std::cout << "1. Addaa peli\n";
        std::cout << "2. Lista peleista\n";
        std::cout << "3. Patch notes\n";
        std::cout << "4. Poista peli\n";
        std::cout << "5. Exit\n";
        std::cout << "Kirjoita valintasi: ";
    }
};
 