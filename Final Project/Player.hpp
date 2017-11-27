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
    row = 5;
    col = 5;
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


#endif /* Player_hpp */
