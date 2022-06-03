#include <random>

#include "Random_generator_non_uniform.hpp"

Random_generator_non_uniform::Random_generator_non_uniform(const std::vector<Int>& probability_weights, Int draw_batch_size) :
batch_size(draw_batch_size), weights(probability_weights), weights_sum(0)
{
    random_numbers.reserve(draw_batch_size);
    for (Int w : weights)
        weights_sum += w;
}


Int Random_generator_non_uniform::random_number()
{
    if (random_numbers.empty())
        draw_from_non_uniform_distribution();
    const Int rn = random_numbers.back();
    random_numbers.pop_back();
    return rn;
}

void Random_generator_non_uniform::draw_from_non_uniform_distribution()
{
    std::random_device random_device;
    std::mt19937 generator(random_device());

    std::discrete_distribution<Int> distribution(cbegin(weights), cend(weights));
    
    for (Int i=0;i<batch_size;++i)
        random_numbers.push_back(distribution(generator));
}

Int Random_generator_non_uniform::get_weight(Int weight_index) const
{
    return weights.at(weight_index);
}

Int Random_generator_non_uniform::get_sum_of_weights() const
{
    return weights_sum;
}