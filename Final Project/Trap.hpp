//
//  Trap.hpp
//  Final Project
//
//  Created by Ryan Alvarez-Cohen on 12/9/17.
//  Copyright © 2017 Ryan Alvarez-Cohen. All rights reserved.
//

#ifndef Trap_hpp
#define Trap_hpp

#include <stdio.h>


class Trap {
public:
    Trap(int t_row, int t_col);
    int get_row() const;
    int get_col() const;
private:
    int t_row, t_col;
};


Trap:: Trap(int t_row, int t_col) {
    this->t_row = t_row;
    this->t_col = t_col;
}


int Trap:: get_row() const {
    return t_row;
}

int Trap:: get_col() const {
    return t_col;
}







#endif /* Trap_hpp */
