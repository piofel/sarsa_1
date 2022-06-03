#include <stdexcept>

#include "Action.hpp"

Action::Action(Int x_action_index, Int y_action_index) : xi(x_action_index), yi(y_action_index)
{
    if (xi<0 || xi>=action_space_dimensions[0])
        throw std::runtime_error("Invalid X action index in Action::Action.");
    if (yi<0 || yi>=action_space_dimensions[1])
        throw std::runtime_error("Invalid Y action index in Action::Action.");
}

const std::vector<Int> Action::axis_actions =  {-1, 0, 1};
const std::vector<Int> Action::action_space_dimensions = {static_cast<Int>(axis_actions.size()), static_cast<Int>(axis_actions.size())};