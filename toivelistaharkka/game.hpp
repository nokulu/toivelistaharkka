#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip> 



class Game {
public:
    std::string name;
    double price; 

    Game(const std::string& n, double p) : name(n), price(p) {}
};