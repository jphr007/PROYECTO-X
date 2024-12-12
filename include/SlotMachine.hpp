#ifndef SLOTMACHINE_HPP
#define SLOTMACHINE_HPP

#include <vector>
#include <random>

class SlotMachine {
public:
    SlotMachine();
    std::vector<int> spin();
    int calculateWinnings(const std::vector<int>& result);

private:
    std::mt19937 rng;
    std::vector<int> symbols;
    std::vector<int> probabilities;
};

#endif // SLOTMACHINE_HPP