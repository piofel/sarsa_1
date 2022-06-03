#pragma once

#include "Tensor.hpp"
#include "Action.hpp"
#include "State.hpp"

class Greedy_policy
{
    public:
        static Action choose_action(const Tensor<Real>* action_value, const State& s, bool include_no_move_action, bool include_diagonal_actions);
};