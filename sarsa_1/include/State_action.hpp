#pragma once

#include <vector>

#include "State.hpp"
#include "Action.hpp"

class State_action
{
    public:
        State_action(const State& s, const Action& a) { sa = std::vector<Int> {s.get_x_index(), s.get_y_index(), a.get_x_action_index(), a.get_y_action_index()}; }
        const std::vector<Int>& as_vec() const { return sa; };
    private:
        std::vector<Int> sa; // state and action represented as a vector of indices
};