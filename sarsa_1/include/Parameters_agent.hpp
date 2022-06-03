#pragma once

#include "Numeric_types.hpp"

struct Parameters_agent
{
    static constexpr bool include_no_move_action = false;
    static constexpr bool include_diagonal_actions = true;  // King's moves
    static constexpr Real learning_rate = 0.5;
    static constexpr Real discount_rate = 1;
    static constexpr Int exploration_coefficient = 10;  // in percent
};