#include "Agent.hpp"
#include "Environment.hpp"
#include "Greedy_policy.hpp"
#include "State_action.hpp"

Agent::Agent(const Parameters_agent& p) :
alpha(p.learning_rate), gamma(p.discount_rate), include_no_move(p.include_no_move_action), include_diagonal_move(p.include_diagonal_actions)
{
    std::vector<Int> action_space_dimensions = Action::get_action_space_dimensions();

    const Int nax = action_space_dimensions[0];
    const Int nay = action_space_dimensions[1];
    q = new Tensor<Real>  { std::vector<Int> {Environment::num_x_state, Environment::num_y_state, nax, nay}, 0.0};

    eps_greed_pi = new Epsilon_greedy_policy {action_space_dimensions, p.exploration_coefficient};
}

Agent::~Agent()
{
     delete q;
     delete eps_greed_pi;
}

Action Agent::learning_action(const State& s)
{
    Action greedy_action = Greedy_policy::choose_action(q, s, include_no_move, include_diagonal_move);
    return eps_greed_pi->choose_action(greedy_action, include_no_move, include_diagonal_move);
}

Action Agent::exploitation_action(const State& s) const
{
    return Greedy_policy::choose_action(q, s, include_no_move, include_diagonal_move);
}

void Agent::learning_step(const State& s, const Action& a, Real reward, const State& s_next, const Action& a_next)
{
    const State_action sa {s, a};
    const State_action sa_next {s_next, a_next};
    const Real q_sa = q->get_value(sa.as_vec());
    const Real q_sa_next = q->get_value(sa_next.as_vec());
    const Real dq = alpha * (reward + gamma*q_sa_next - q_sa);
    q->add_to_element(sa.as_vec(), dq);
}