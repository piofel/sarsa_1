/**
 * @file main.cpp
 * @author Piotr Felisiak (Piotr.Felisiak@yandex.com)
 * @brief Exercise 6.9 & 6.10 'Windy Gridworld with King's Moves' from Sutton & Barto 'Reinforcement Learning' 2nd Ed.
 * @details Set parameters in Parameters_learning_system.hpp, Parameters_environment.hpp, Parameters_agent.hpp
 * @version 0.9
 * @date 2022-06-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

#include "Parameter_loader.hpp"
#include "Learning_system.hpp"
#include "Graphics.hpp"

int main()
{
    try
    {
        std::ostream& os = std::cout;

        os << "Temporal-Difference Learning\n";
        os << "Exercise 6.9: 'Windy Gridworld with King's Moves' from Sutton & Barto 'Reinforcement Learning' 2nd Ed.\n";
        os << "------------------------------------------------------------------------------------------------------\n";

        Parameter_loader pl;
        Learning_system learning_system {pl.get_parameters_of_learning_system(), pl.get_parameters_of_environment(), pl.get_parameters_of_agent()};
        learning_system.train();
        learning_system.exploit();

        Graphics graphics;
        graphics.draw(std::cout, learning_system.get_environment(), learning_system.get_states());

        // system("pause");  // for Windows

        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        // system("pause");  // for Windows
        return 1;
    }
    catch (...)
    {
        std::cerr << "Unknown error!" << '\n';
        // system("pause");  // for Windows
        return 2;
    }    
}