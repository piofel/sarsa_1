#pragma once

#include "State.hpp"
#include "Action.hpp"
#include "Wind.hpp"
#include "Parameters_environment.hpp"

class Environment
{
    public:
        Environment(const Parameters_environment& p) { wind.set_stochastic_wind(p.stochastic_wind); };
        void initialize();
        void step(const Action& a);
        const State& get_initial_state() const { return initial_state; };
        const State& get_goal_state() const { return goal_state; };
        const State& get_current_state() const { return current_state; };
        Real get_reward() const { return reward; };
        void  set_stochastic_wind(bool stochastic_wind) { wind.set_stochastic_wind(stochastic_wind); };
        Int wind_y(const State& s);
        static constexpr Int num_x_state = 10;
        static constexpr Int num_y_state = 7;
    private:
        const State initial_state {0, 3};
        const State goal_state {7, 3};
        State current_state {0, 3};
        Real reward {-1};
        Wind wind;
};