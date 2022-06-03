#pragma once

#include "Numeric_types.hpp"

class State
{
    public:
        State(Int x_pos, Int y_pos) : xi(x_pos), yi(y_pos) {};
        bool operator==(const State& rhs) {return xi==rhs.xi && yi==rhs.yi; };
        bool operator!=(const State& rhs) {return xi!=rhs.xi || yi!=rhs.yi; };
        Int get_x_index() const { return xi; };
        Int get_y_index() const { return yi; };
        Int get_x_position() const { return xi; };
        Int get_y_position() const { return yi; };
        void set_x_index(Int x_position) { xi = x_position; };
        void set_y_index(Int y_position) { yi = y_position; };
    private:
        Int xi, yi;
};