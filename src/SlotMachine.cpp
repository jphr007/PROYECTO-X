#include "SlotMachine.hpp"
#include <algorithm>

SlotMachine::SlotMachine() : rng(std::random_device{}()) {
    symbols = {1, 2, 3, 4, 5}; // 1: Cherry, 2: Lemon, 3: Orange, 4: Plum, 5: Bell
    probabilities = {50, 30, 15, 4, 1}; // Probabilities for each symbol
}

std::vector<int> SlotMachine::spin() {
    std::vector<int> result;
    for (int i = 0; i < 3; ++i) {
        std::discrete_distribution<> d(probabilities.begin(), probabilities.end());
        result.push_back(symbols[d(rng)]);
    }
    return result;
}

int SlotMachine::calculateWinnings(const std::vector<int>& result) {
    if (std::all_of(result.begin(), result.end(), [&](int i) { return i == result[0]; })) {
        return result[0] * 10; // All symbols are the same
    } else if (std::count(result.begin(), result.end(), 5) == 2) {
        return 5; // Two Bells
    } else if (std::count(result.begin(), result.end(), 5) == 1) {
        return 2; // One Bell
    }
    return 0;
}