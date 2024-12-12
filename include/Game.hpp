#ifndef GAME_HPP
#define GAME_HPP

#include "SlotMachine.hpp"

class Game {
public:
    Game();
    void play();

private:
    SlotMachine machine;
    int balance;
    void displayResult(const std::vector<int>& result, int winnings);
};

#endif // GAME_HPP