#include <stdexcept>
#include <iostream>

#include "Epsilon_greedy_policy.hpp"

Epsilon_greedy_policy::Epsilon_greedy_policy(const std::vector<Int>& action_space_dimensions, Int epsilon)
{
    const Int num_actions = action_space_dimensions[0];
    std::vector<Int> weights;
    for (int i=0; i<num_actions; ++i)
        weights.push_back(epsilon);

    const Int remaining_weights = 100 - (num_actions-1)*epsilon;
    if (remaining_weights < epsilon)
        throw std::runtime_error("Epsilon too large in Epsilon_greedy_policy::Epsilon_greedy_policy.");

    for (int i=0; i<num_actions; ++i)
    {
        std::vector<Int> weights_i = weights;
        weights_i[i] = remaining_weights;
        Random_generator_non_uniform g {weights_i, random_actions_batch_size};
        action_generators.push_back(g);
    }
}

Action Epsilon_greedy_policy::choose_action(const Action& greedy_action, bool include_no_move_action, bool include_diagonal_actions)
{
    Action a = draw_action_candidate(greedy_action);
    while (a.is_diagonal_action() || a.is_no_move_action()) // while diagonal action or no move action
    {
        if (include_no_move_action)
            break;
        if (!a.is_no_move_action() && include_diagonal_actions)
            break;
        a = draw_action_candidate(greedy_action);
    }
    return a;
}

Action Epsilon_greedy_policy::draw_action_candidate(const Action& greedy_action)
{
    const Int x_act_index = action_generators[greedy_action.get_x_action_index()].random_number();
    const Int y_act_index = action_generators[greedy_action.get_y_action_index()].random_number();
    return Action {x_act_index, y_act_index};
}