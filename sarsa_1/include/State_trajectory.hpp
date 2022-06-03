#pragma once

#include <vector>

#include "State.hpp"

class State_trajectory
{
    public:
        void append(const State& s);
        bool contains(const State& s) const;
    private:
        std::vector<State> states;
};