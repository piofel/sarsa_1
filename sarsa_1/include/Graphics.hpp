#pragma once

#include <vector>
#include <iostream>

#include "Environment.hpp"
#include "State_trajectory.hpp"

class Graphics
{
    public:
        void draw(std::ostream& os, Environment* environment, const State_trajectory& states) const;
    private:
        void draw_hline(std::ostream& os, char c) const;
};