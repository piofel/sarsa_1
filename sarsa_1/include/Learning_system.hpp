#pragma once

#include "Environment.hpp"
#include "Agent.hpp"
#include "State_trajectory.hpp"
#include "Parameters_learning_system.hpp"

class Learning_system
{
    public:
        Learning_system(const Parameters_learning_system& pls, const Parameters_environment& pe, const Parameters_agent& pa);
        ~Learning_system();
        void train();
        void exploit();
        Environment* get_environment() const { return environment; };
        const State_trajectory& get_states() const {return states; };
    private:
        Environment* environment;
        Agent* agent;
        State_trajectory states;
        Int num_learning_steps, num_exploit_steps;
};