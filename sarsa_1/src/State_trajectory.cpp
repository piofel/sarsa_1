#include "State_trajectory.hpp"

void State_trajectory::append(const State& s)
{
    states.push_back(s);
}

bool State_trajectory::contains(const State& s) const
{
    for (UInt i=0; i<states.size(); ++i)
    {
        State e  = states[i];
        if (e == s)
            return true;
    }
    return false;
}