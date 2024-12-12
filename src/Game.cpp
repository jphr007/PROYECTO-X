#include "Game.hpp"
#include <iostream>
#include <string>

Game::Game() : balance(100) {}

void Game::play() {
    std::string input;
    while (balance > 0) {
        std::cout << "Your balance: $" << balance << std::endl;
        std::cout << "Press 'p' to play or 'q' to quit: ";
        std::cin >> input;

        if (input == "q") break;
        if (input != "p") continue;

        balance -= 1; // Cost to play
        auto result = machine.spin();
        int winnings = machine.calculateWinnings(result);
        balance += winnings;

        displayResult(result, winnings);
    }

    std::cout << "Game over. Final balance: $" << balance << std::endl;
}

void Game::displayResult(const std::vector<int>& result, int winnings) {
    std::string symbols[] = {"🍒", "🍋", "🍊", "🍇", "🔔"};
    std::cout << "Result: ";
    for (int symbol : result) {
        std::cout << symbols[symbol - 1] << " ";
    }
    std::cout << std::endl;

    if (winnings > 0) {
        std::cout << "You won $" << winnings << "!" << std::endl;
    } else {
        std::cout << "No win this time." << std::endl;
    }
}