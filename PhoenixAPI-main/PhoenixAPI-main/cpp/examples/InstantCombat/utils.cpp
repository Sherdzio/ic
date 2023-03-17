#include "utils.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

Player selectMainPlayer(std::vector<Player>& players) {
    displayPlayerNames(players);
    int mainPlayerIndex;

    std::cout << "Wybierz numer g³ównego gracza z listy: ";
    std::cin >> mainPlayerIndex;
    while (mainPlayerIndex < 1 || mainPlayerIndex > static_cast<int>(players.size())) {
        std::cout << "Nieprawid³owy wybór. Spróbuj ponownie: ";
        std::cin >> mainPlayerIndex;
    }

    players[mainPlayerIndex - 1].move_to_point = false;
    return players[mainPlayerIndex - 1];
}

std::vector<Player> selectTanks(const std::vector<Player>& players) {
    std::vector<Player> tanks;
    for (const auto& player : players) {
        if (player.move_to_point) {
            tanks.push_back(player);
        }
    }
    return tanks;
}

std::vector<std::string> getAllTitles() {
    std::vector<std::string> titles = { "Tank 1", "Tank 2", "Tank 3", "Tank 4", "Tank 5" };
    return titles;
}

std::vector<int> getPlayerSelections(const std::vector<Player>& players) {
    std::vector<int> selections;
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);

    int selection;
    while (iss >> selection) {
        if (selection >= 1 && selection <= static_cast<int>(players.size())) {
            selections.push_back(selection - 1);
        }
        else {
            std::cout << "Invalid selection: " << selection << std::endl;
        }
    }

    return selections;
}

void displayPlayerNames(const std::vector<Player>& players) {
    for (std::size_t i = 0; i < players.size(); ++i) {
        std::cout << (i + 1) << ": " << players[i].name << std::endl;
    }
}

std::vector<Player> getPlayers() {
    std::vector<std::string> titles = getAllTitles();
    std::vector<Player> players(titles.size());

    for (std::size_t i = 0; i < titles.size(); ++i) {
        players[i].name = titles[i];
        players[i].hp = 100;
        players[i].move_to_point = true;
    }

    return players;
}
