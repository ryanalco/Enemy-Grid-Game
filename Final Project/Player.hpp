//
//  Player.hpp
//  Final Project
//
//  Created by Ryan Alvarez-Cohen on 11/15/17.
//  Copyright © 2017 Ryan Alvarez-Cohen. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp
#include <iostream>
#include <stdio.h>

class Player{
public:
    Player();
    bool is_alive();
    void kill();
    void move(int x);
    int get_row() const;
    int get_col() const;
    
private:
    bool alive;
    int row, col;
};

Player:: Player () {
    alive = true;
    row = 4;
    col = 4;
}

bool Player:: is_alive() {
    if (alive) {
        return true;
    }
    else {
        return false;
    }
}

int Player:: get_row() const {
    return row;
}

int Player:: get_col() const {
    return col;
}

void Player:: kill() {
    alive = false;
}

void Player:: move(int x) {
    //up
    if (x == 0) {
        if (row == 0) {
            return;
        }
        else {
            row -= 1;
        }
    }
    //down
    else if (x == 1) {
        if (row == 9) {
            return;
        }
        else {
            row += 1;
        }
    }
    //move left
    else if (x == 2) {
        if (col == 0) {
            return;
        }
        else {
            col -= 1;
        }
    }
    //move right
    else if (x == 3) {
        if (col == 9) {
            return;
        }
        else {
            col += 1;
        }
    }
}


#endif /* Player_hpp */
