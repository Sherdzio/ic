#include <iostream>
#include "Api.h"
#include "scene.h"
#include "bot.h"
#include "player.h"
#include "utils.h"

int select_port();

void run_bot(int port);

int main() {
    std::vector<Player> players = getPlayers();
    Player mainPlayer = selectMainPlayer(players);
    std::vector<Player> tanks = selectTanks(players);

    std::cout << "Main player: " << mainPlayer.name << " (move_to_point: " << mainPlayer.move_to_point << ")" << std::endl;
    std::cout << "Tanks: ";
    for (const auto& tank : tanks) {
        std::cout << tank.name << " (move_to_point: " << tank.move_to_point << "), ";
    }
    std::cout << std::endl;

    int port = select_port();
    run_bot(port);

    return 0;
}

int select_port() {
    std::vector<int> available_ports = Phoenix::find_ports();
    int selected_port = -1;

    if (available_ports.empty()) {
        std::cerr << "Nie znaleziono ¿adnych dostêpnych portów." << std::endl;
        return -1;
    }

    std::cout << "Dostêpne porty: ";
    for (const auto& port : available_ports) {
        std::cout << port << " ";
    }
    std::cout << std::endl;

    while (selected_port == -1) {
        std::cout << "WprowadŸ wybrany port: ";
        std::cin >> selected_port;

        if (std::find(available_ports.begin(), available_ports.end(), selected_port) == available_ports.end()) {
            std::cerr << "Nieprawid³owy port. Spróbuj ponownie." << std::endl;
            selected_port = -1;
        }
    }

    return selected_port;
}

void run_bot(int port) {
    if (port == -1) {
        std::cerr << "Nie mo¿na uruchomiæ bota bez wybranego portu." << std::endl;
        return;
    }

    try {
        Phoenix::Api api(port);
        Scene scene;
        Bot bot(&api, &scene);

        // Tutaj mo¿esz dodaæ logikê bota
    }
    catch (const std::exception& e) {
        std::cerr << "Wyst¹pi³ b³¹d: " << e.what() << std::endl;
    }
}
