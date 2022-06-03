#pragma once

#include <vector>

#include "Numeric_types.hpp"

class Random_generator_non_uniform
{

    public:

        /**
         * @brief Random_generator_non_uniform object produces random integers on the interval [0, n) using non-uniform discrete distribution
         * 
         * @param probability_weights probability of each choice is defined as wi/S, that is the weight wi of the ith choice divided by the sum S of all n weights
         * @param draw_batch_size number of random integers for each draw
         */
        Random_generator_non_uniform(const std::vector<Int>& probability_weights, Int draw_batch_size);

        /**
         * @brief Gets a random number from distribution specified by the constructor
         * 
         * @return Int 
         */
        Int random_number();

        Int get_weight(Int weight_index) const;

        Int get_sum_of_weights() const;

    private:
        
        void draw_from_non_uniform_distribution();
        Int batch_size;
        std::vector<Int> weights;
        std::vector<Int> random_numbers;
        Int weights_sum;

};