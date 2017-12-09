//
//  Player.hpp
//  Final Project
//
//  Created by Ryan Alvarez-Cohen on 11/15/17.
//  Copyright © 2017 Ryan Alvarez-Cohen. All rights reserved.
//

class Board;

#ifndef Player_hpp
#define Player_hpp
#include <iostream>
//#include <stdio.h>
#include "AddOns.hpp"
#include "Board.hpp"



class Player{
public:
    Player(Board* board);
    bool is_alive();
    void kill();
    void move(int x);
    int get_row() const;
    int get_col() const;
    
private:
    bool alive;
    int row, col;
    const int UP    = 0;
    const int DOWN  = 1;
    const int LEFT  = 2;
    const int RIGHT = 3;
    Board* board;

};

Player:: Player (Board* board) {
    if (board == nullptr)
    {
        cout << "The player must be in board" << endl;
        exit(1);
    }
    this->board = board;
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
    //std:: cout << "You died\n";
}

void Player:: move(int dir) {
    //up
    
    if (dir == UP) {
        if (row == 1) {
            return;
        }
        else {
            row -= 1;
        }
    }
    //down
    else if (dir == DOWN) {
        if (row == 10) {
            return;
        }
        else {
            row += 1;
        }
    }
    //move left
    else if (dir == LEFT) {
        if (col == 1) {
            return;
        }
        else {
            col -= 1;
        }
    }
    //move right
    else if (dir == RIGHT) {
        if (col == 10) {
            return;
        }
        else {
            col += 1;
        }
    }
    /*
    if (board->enemies_at(row, col) != 0) {
        this->kill();
    }
    
    
    if (board->star_at(row, col)) {
        board->kill_star();
        std:: cout << "You got a star!\n";
    }
    */
}


#endif /* Player_hpp */
