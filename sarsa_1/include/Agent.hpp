#pragma once

#include "Tensor.hpp"
#include "Epsilon_greedy_policy.hpp"
#include "State.hpp"
#include "Parameters_agent.hpp"

class Agent // Sarsa agent
{
    public:
        Agent(const Parameters_agent& p);
        ~Agent();
        Action learning_action(const State& s);
        Action exploitation_action(const State& s) const;
        void learning_step(const State& s, const Action& a, Real reward, const State& s_next, const Action& a_next);
    private:
        Tensor<Real>* q; // action value
        Epsilon_greedy_policy* eps_greed_pi;
        Real alpha, gamma;
        bool include_no_move, include_diagonal_move;;
};