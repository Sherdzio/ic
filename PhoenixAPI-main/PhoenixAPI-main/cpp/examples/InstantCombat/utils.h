#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include "player.h"
#pragma once

Player selectMainPlayer(const std::vector<Player>& players);
std::vector<Player> selectTanks(const std::vector<Player>& players);

std::vector<std::string> getAllTitles();
std::vector<int> getPlayerSelections(const std::vector<Player>& players);
void displayPlayerNames(const std::vector<Player>& players);
std::vector<Player> getPlayers();

#endif // UTILS_H
