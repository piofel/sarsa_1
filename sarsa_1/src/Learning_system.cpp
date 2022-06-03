#include "Learning_system.hpp"

Learning_system::Learning_system(const Parameters_learning_system& pls, const Parameters_environment& pe, const Parameters_agent& pa) :
num_learning_steps(pls.number_of_learning_steps), num_exploit_steps(pls.number_of_exploitation_steps)
{
    environment = new Environment {pe};
    agent = new Agent {pa};
}

Learning_system::~Learning_system()
{
    delete agent;
    delete environment;
}

void Learning_system::train()
{
    Int t = 0;
    Int episode_counter = 0;
    while (t < num_learning_steps)
    {
        environment->initialize();
        State s = environment->get_current_state();
        Action a = agent->learning_action(s);
        while (s != environment->get_goal_state())
        {
            environment->step(a);
            const Real r = environment->get_reward();
            const State s_next = environment->get_current_state();
            const Action a_next = agent->learning_action(s_next);
            agent->learning_step(s, a, r, s_next, a_next);
            s = s_next;
            a = a_next;
            ++t;
        }
        ++episode_counter;
    }
    std::cout << "Learning finished after " << episode_counter << " episodes " << " and " << t << " time steps.\n";
}

void Learning_system::exploit()
{
    environment->initialize();
    environment->set_stochastic_wind(false);
    for (int t=0; t<num_exploit_steps; ++t)
    {
        State s = environment->get_current_state();
        states.append(s);
        if (s == environment->get_goal_state())
            std::cout << "Goal met at " << t << " time step.\n";

        Action a  = agent->exploitation_action(s);
        environment->step(a);
    }
}