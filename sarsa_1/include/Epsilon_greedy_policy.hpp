#pragma once

#include "Action.hpp"
#include "Random_generator_non_uniform.hpp"

class Epsilon_greedy_policy
{
    public:
        Epsilon_greedy_policy(const std::vector<Int>& action_space_dimensions, Int epsilon); // epsilon in percent
        Action choose_action(const Action& greedy_action, bool include_no_move_action, bool include_diagonal_actions);
    private:
        Action draw_action_candidate(const Action& greedy_action);
        static constexpr Int random_actions_batch_size = 1024;
        std::vector<Random_generator_non_uniform> action_generators;
};