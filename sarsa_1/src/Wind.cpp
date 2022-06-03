#include "Wind.hpp"

Int Wind::y_component(const State& s)
{
    const Int wym = y_component_mean(s);
    if (stochastic && wym!=0)
    {
        const std::vector<Int> deviaton_range {-1,0,1};
        const Int deviation = deviaton_range[rand_gen.random_number()];
        return wym + deviation;
    }
    else
        return wym;
}

Int Wind::y_component_mean(const State& s) const
{
    const Int x = s.get_x_index();
    if (x>2 && x<9)
        if (x>5 && x<8)
            return 2;
        else
            return 1;
    return 0;
}