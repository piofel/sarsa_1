#include <algorithm>

#include "Graphics.hpp"

void Graphics::draw(std::ostream& os, Environment* environment, const State_trajectory& states) const
{
    draw_hline(os, '=');

    for (int j=0; j<Environment::num_y_state; ++j)
    {
        os << '|';
        for (int i=0; i<Environment::num_x_state; ++i)
        {
            State s {i, Environment::num_y_state-1-j};
            if (s == environment->get_initial_state())
                os << 'S';
            else if (s == environment->get_goal_state())
                os << 'G';
            else if (states.contains(s))
                os << '#';
            else
                os << '-';                
        }
        os << "|\n";
    }

    draw_hline(os, '^');

    os << '|';
    for (int i=0; i<Environment::num_x_state; ++i)
    {
        State s {i, 0};
        os << environment->wind_y(s);
    }
    os << "|\n";

    draw_hline(os, '=');
}

void Graphics::draw_hline(std::ostream& os, char c) const
{
    for (int i=0; i<Environment::num_x_state + 2; ++i) os << c;
    os << '\n';
}