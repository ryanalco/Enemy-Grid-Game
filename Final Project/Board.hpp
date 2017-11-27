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
#include "Player.hpp"
#include <vector>


class Enemy;
class Player;

class Board {
public:
    Board(int enemies);
    virtual ~Board();
    void add_enemy(const Enemy& monster);
    //void add_player();
    void show_grid();
    void create_player();
    void move_enemies();
    //Player* player() const;
    
private:
    char grid[10][10];
    std::vector<Enemy*> enemy_list;
    int enemies;
    Player* guy;
};


Board:: Board(int enemies) {
    this->enemies = enemies;
    guy = nullptr;
}

Board:: ~Board() {
    delete guy;
    for (int i = 0; i < enemies; i++) {
        delete enemy_list[i];
    }
}

void Board:: add_enemy(const Enemy& monster) {
    enemy_list.push_back(monster);
}

/*void Board:: add_player() {
    
}
*/

void Board:: show_grid() {
    
    //create board of x's
    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            grid[r][c] = 'x';
        }
    }
    
    //enemy location
    for (int i = 0; i < enemies; i++) {
        char space = grid[enemy_list[i]->get_row()-1][enemy_list[i]->get_col()-1];
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
    
    //create player position
    char player_spot = grid[guy->get_row()-1][guy->get_col()-1];
    if (!guy->is_alive()) {
        player_spot = '!';
    }
    else {
        player_spot = '@';
    }
    
    //draw grid
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            std::cout<< grid[a][b];
        }
    }
    
}

void Board:: move_enemies() {
    for (int i = 0; i < enemy_list.size(); i++) {
        enemy_list[i]->move();
    }
    for (int i = 0; i < enemy_list.size(); i++) {
        if ((guy->get_col() == enemy_list[i]->get_col()) && (guy->get_row() == enemy_list[i]->get_col())) {
            guy->kill();
        }
    }
}










#endif /* Board_hpp */
