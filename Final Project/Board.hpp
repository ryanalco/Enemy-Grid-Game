//
//  Board.hpp
//  Final Project
//
//  Created by Ryan Alvarez-Cohen on 11/15/17.
//  Copyright © 2017 Ryan Alvarez-Cohen. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <iostream>
#include <stdio.h>
#include "Enemy.hpp"
#include <vector>

class Enemy;

class Board {
public:
    Board(int enemies);
    void add_enemy(Enemy monster);
    void add_player(int r, int c);
    void show_grid();
    
private:
    char grid[10][10];
    std::vector<Enemy> enemy_list;
    int enemies;
    
};


Board:: Board(int enemies) {
    this->enemies = enemies;
}

void Board:: add_player(int r, int c) {
    
}

void Board:: add_enemy(Enemy monster) {
    enemy_list.push_back(monster);
}

void Board:: show_grid() {
    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            grid[r][c] = 'x';
        }
    }
    
    for (int i = 0; i < enemies; i++) {
        char space = grid[enemy_list[i].get_row()][enemy_list[i].get_col()];
        switch(space) {
            case 'x': space = '*';
                break;
            case '*': space = 1;
                break;
            case '1': space = 2;
                break;
            case '2': space = 3;
                break;
            case '3': space = 4;
                break;
            case '4': space = 5;
                break;
            case '5': space = 6;
                break;
            case '6': space = 7;
                break;
            case '7': space = 8;
                break;
        }
    }
}










#endif /* Board_hpp */
