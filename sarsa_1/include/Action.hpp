#pragma once

#include <vector>

#include "Numeric_types.hpp"

class Action
{
    public:
        Action(Int x_action_index, Int y_action_index);
        Int get_x_action_index() const { return xi; };
        Int get_y_action_index() const { return yi; };
        Int get_x_action() const { return axis_actions[xi]; };
        Int get_y_action() const { return axis_actions[yi]; };
        static const std::vector<Int>& get_action_space_dimensions() { return action_space_dimensions; };
        bool is_no_move_action() const { return get_x_action()==0 && get_y_action()==0; };
        bool is_diagonal_action() const { return get_x_action()==get_y_action() || get_x_action()==-get_y_action(); };
    private:
        Int xi, yi; // action indices
        static const std::vector<Int> axis_actions;
        static const std::vector<Int> action_space_dimensions;
};