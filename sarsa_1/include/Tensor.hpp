#pragma once

#include <iostream>
#include <vector>

#include "Numeric_types.hpp"

template <typename T>
class Tensor
{
    public:
        Tensor(const std::vector<Int>& tensor_dimensions, const T& init_val);
        void set_all(const T& value);
        T get_value(const std::vector<Int>& indices) const;
        void set_value(const std::vector<Int>& indices, const T& value);
        void add_to_element(const std::vector<Int>& indices, const T& value);
        void set_index_check(const bool check);
        Int number_of_elements() const;
        std::vector<Int> get_dimensions() const;
        Int get_rank() const;
    private:
        Int get_flat_index(const std::vector<Int>& indices) const;
        std::vector<Int> dimensions;
        std::vector<T> values;
        bool icheck;
};

template <typename T>
Tensor<T>::Tensor(const std::vector<Int>& tensor_dimensions, const T& init_val)
{
    dimensions = tensor_dimensions;
    set_all(init_val);
    icheck = false;
}

template <typename T>
void Tensor<T>::set_all(const T& value)
{
    Int n = 1;
    for (Int d : dimensions)
        n *= d;
    for (Int i=0; i<n; ++i)
        values.push_back(value);
}

template <typename T>
Int Tensor<T>::get_flat_index(const std::vector<Int>& indices) const
{
    if (icheck)
    {
        bool indices_fault = false;

        if (indices.size() != get_rank())
        {
            std::cerr << "Number of indices (" << indices.size() << ") not equal to the rank of the tensor (" << get_rank() << ")!\n";
            indices_fault = true;
        }

        for (UInt i=0; i<indices.size(); ++i)
        {
            if (indices.at(i)>=dimensions.at(i))
            {
                std::cerr << "Incorrect index " << indices.at(i) << " along axis " << i << " where max. index is " << dimensions.at(i) - 1 << ".\n";
                indices_fault = true;
            }
            if (indices.at(i)<0)
            {
                std::cerr << "Incorrect index " << indices.at(i) << " along axis " << i << " where min. index is 0.\n";
                indices_fault = true;
            }
        }

        if (indices_fault)
            throw std::runtime_error("Incorrect index error at Tensor::get_flat_index!");
    }

    Int index=0;
    Int n=1;
    for (UInt i=0; i<indices.size(); ++i)
    {
        index += indices.at(i) * n;
        n *= dimensions.at(i);
    }
    return index;
}

template <typename T>
T Tensor<T>::get_value(const std::vector<Int>& indices) const
{
    const Int idx = get_flat_index(indices);
    return values.at(idx);
}

template <typename T>
void Tensor<T>::set_value(const std::vector<Int>& indices, const T& value)
{
    const Int idx = get_flat_index(indices);
    values.at(idx)=value;
}

template <typename T>
void Tensor<T>::add_to_element(const std::vector<Int>& indices, const T& value)
{
    const Int idx = get_flat_index(indices);
    values.at(idx) += value;
}

template <typename T>
void Tensor<T>::set_index_check(const bool check)
{
    icheck = check;
}

template <typename T>
Int Tensor<T>::number_of_elements() const
{
    return values.size();
}

template <typename T>
std::vector<Int> Tensor<T>::get_dimensions() const
{
    return dimensions;
}

template <typename T>
Int Tensor<T>::get_rank() const
{
    return dimensions.size();
}