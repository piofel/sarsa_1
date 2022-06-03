#pragma once

#include "Parameters_learning_system.hpp"
#include "Parameters_environment.hpp"
#include "Parameters_agent.hpp"

class Parameter_loader
{
    public:
        Parameters_learning_system get_parameters_of_learning_system() const;
        Parameters_environment get_parameters_of_environment() const;
        Parameters_agent get_parameters_of_agent() const;
};