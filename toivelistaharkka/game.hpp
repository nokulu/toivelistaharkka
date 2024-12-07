#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip> // For std::fixed and std::setprecision



class Game {
public:
    std::string name;
    double price; // Price in euros

    Game(const std::string& n, double p) : name(n), price(p) {}
};

class WishList {
private:
    std::vector<Game> games;
    std::string filename;

public:
    WishList(const std::string& fname) : filename(fname) {
        games = readDataFromFile(filename);
    }

    void addGame(const Game& game) {
        games.push_back(game);
        saveDataToFile();
    }

    void showGames() const {
        if (games.empty()) {
            std::cout << "Ei peleja toiveissa.\n";
            return;
        }
        for (const auto& game : games) {
            std::cout << "Nimi: " << game.name << ", Hinta: €" << std::fixed << std::setprecision(2) << game.price << std::endl;
        }
    }

    void removeGame(const std::string& name) {
        auto it = std::remove_if(games.begin(), games.end(), [&](const Game& game) {
            return game.name == name;
            });
        if (it != games.end()) {
            games.erase(it, games.end());
            saveDataToFile();
            std::cout << "Peli poistettu onnistuneesti.\n";
        }
        else {
            std::cout << "Peli ei loytynyt.\n";
        }
    }

    void showPatchNotes() const {
        std::cout << "Patch notes: \n";
        std::cout << "Version 1.0: Initial release.\n";
        std::cout << "Version 1.1: squashed cats. \n";
        std::cout << "Version 1.2: petted bugs. \n";
        std::cout << "Version 1.3: Wait what?? \n";
    }

private:
    void saveDataToFile() const {
        std::ofstream outFile(filename);
        for (const auto& game : games) {
            outFile << game.name << "," << game.price << std::endl;
        }
    }

    std::vector<Game> readDataFromFile(const std::string& filename) {
        std::vector<Game> games;
        std::ifstream inFile(filename);
        std::string line;
        while (std::getline(inFile, line)) {
            size_t commaPos = line.find(',');
            if (commaPos != std::string::npos) {
                std::string name = line.substr(0, commaPos);
                double price = std::stod(line.substr(commaPos + 1)); //stringistä doublle
                games.emplace_back(name, price);
            }
        }
        return games;
    }
};

