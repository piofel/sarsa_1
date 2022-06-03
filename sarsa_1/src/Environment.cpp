#include <stdexcept>

#include "Environment.hpp"

void Environment::initialize()
{
    current_state = initial_state;
    reward = -1;
}

/**
 * @brief Updates state and reward
 * 
 * @param a action
 */
void Environment::step(const Action& a)
{
    Int x_cand = current_state.get_x_position() + a.get_x_action();  // candidate to next position along the X axis
    Int y_cand = current_state.get_y_position() + a.get_y_action() + wind_y(current_state);  // candidate to next position along the Y axis

    if (x_cand < 0)
        x_cand = 0;
    else if (x_cand >= num_x_state)
        x_cand = num_x_state - 1;
    if (y_cand < 0)
        y_cand = 0;
    else if (y_cand >= num_y_state)
        y_cand = num_y_state - 1;

    current_state.set_x_index(x_cand);
    current_state.set_y_index(y_cand);

    if (current_state == goal_state)
        reward = 0;
}

Int Environment::wind_y(const State& s)
{
    return wind.y_component(s);
}