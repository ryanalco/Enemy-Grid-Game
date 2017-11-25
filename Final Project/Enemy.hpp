//
//  Enemy.hpp
//  Final Project
//
//  Created by Ryan Alvarez-Cohen on 11/19/17.
//  Copyright © 2017 Ryan Alvarez-Cohen. All rights reserved.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>


class Enemy {
public:
    Enemy(int row, int col);
    int get_row() const;
    int get_col() const;
    
private:
    int row;
    int col;
    
};

Enemy:: Enemy(int row, int col) {
    this->row = row;
    this->col = col;
}

int Enemy:: get_col() const {
    return this->col;
}

int Enemy:: get_row() const {
    return this->row;
}



#endif /* Enemy_hpp */
