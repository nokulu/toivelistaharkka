#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip> 
#include "menu.hpp"
#include "game.hpp"

int main() {
    std::string filename = "pelit.txt"; 
    WishList wishList(filename);
    Menu menu;

    int choice;
    do {
        menu.display();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string name;
            double price;
            std::cout << "Anna pelin nimi: ";
            std::cin.ignore(); 
            std::getline(std::cin, name);
            std::cout << "Anna pelin hinta Euroissa: ";
            std::cin >> price;
            wishList.addGame(Game(name, price));
            break;
        }
        case 2:
            wishList.showGames();
            break;
        case 3:
            wishList.showPatchNotes();
            break;
        case 4: {
            std::string name;
            std::cout << "Anna pelin koko nimi jonka haluat poistaa: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            wishList.removeGame(name);
            break;
        }
        case 5:
            std::cout << "Poistutaan..." << std::endl;
            break;
        default:
            std::cout << "Invalidi valinta. Uudestaan uudestaan!" << std::endl;
        }
    } while (choice != 5);

    return 0;
}