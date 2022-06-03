#include "Greedy_policy.hpp"
#include "State_action.hpp"

Action Greedy_policy::choose_action(const Tensor<Real>* action_value, const State& s, bool include_no_move_action, bool include_diagonal_actions)
{
    Real optimal_value = -1e9;
    Action optimal_action {0, 0};
    const Int x_act_sp_dim = Action::get_action_space_dimensions()[0];
    const Int y_act_sp_dim = Action::get_action_space_dimensions()[1];
    for (int i=0; i<x_act_sp_dim; ++i)
        for (int j=0; j<y_act_sp_dim; ++j)
        {
            const Action a {i, j};
            if (include_diagonal_actions || !a.is_diagonal_action())  // diagonal moves test
                if (include_no_move_action || !a.is_no_move_action()) // no move action test
                {
                    const State_action sa {s, a};
                    const Real q_sa = action_value->get_value(sa.as_vec());
                    if (q_sa > optimal_value)
                    {
                        optimal_value = q_sa;
                        optimal_action = a;
                    }
                }
        }
    return optimal_action;
}