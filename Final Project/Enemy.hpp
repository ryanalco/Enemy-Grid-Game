//
//  Enemy.hpp
//  Final Project
//
//  Created by Ryan Alvarez-Cohen on 11/19/17.
//  Copyright © 2017 Ryan Alvarez-Cohen. All rights reserved.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <cstdlib>
#include "Additions.hpp"



class Enemy {
public:
    Enemy(int row, int col);
    int get_row() const;
    int get_col() const;
    void move();
    
private:
    int row;
    int col;
    
};

Enemy:: Enemy(int row, int col) {
    this->row = row;
    this->col = col;
}

int Enemy:: get_col() const {
    return col;
}

int Enemy:: get_row() const {
    return row;
}

void Enemy:: move() {
    switch (rand() % 4) {
        //move up
        case 0:
            if (row == 0) {
                return;
            }
            else {
                row -= 1;
                std::cout<< "move up\n";
                break;
            }
            
        //move left
        case 1:
            if (col == 0) {
                return;
            }
            else {
                col -= 1;
                std::cout<< "move left\n";
                break;
            }
            
        //move right
        case 2:
            if (col == 9) {
                return;
            }
            else {
                col += 1;
                std::cout<< "move right\n";
                break;
            }
            
        //move down
        case 3:
            if (row == 9) {
                return;
            }
            else {
                row += 1;
                std::cout<< "move down\n";
                break;
            }
            
    }
}



#endif /* Enemy_hpp */
