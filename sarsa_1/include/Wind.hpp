#pragma once

#include "State.hpp"
#include "Random_generator_non_uniform.hpp"

class Wind
{
    public:
        Wind() : stochastic(false) {};
        Int y_component(const State& s);
        void  set_stochastic_wind(bool stochastic_wind) { stochastic = stochastic_wind; };
    private:
        Int y_component_mean(const State& s) const;
        bool stochastic;
        Random_generator_non_uniform rand_gen { std::vector<Int> {1,1,1}, 512};
};