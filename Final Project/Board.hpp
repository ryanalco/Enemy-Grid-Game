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
#include <cstdlib>
#include <string>
#include "Enemy.hpp"
#include "Player.hpp"
#include "Additions.hpp"


class Enemy;
class Player;

class Board {
public:
    Board(int enemies);
    virtual ~Board();
    void add_enemy(int e_row, int e_col);
    void add_player();
    void show_grid();
    Player* create_player();
    void move_enemies();
    int enemies_at(int row, int col) const;
    //Player* player() const;
    
private:
    char grid[10][10];
    Enemy* enemy_list[10];
    int enemies;
    int count = 0;
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

void Board:: add_enemy(int e_row, int e_col) {
   //{
    Enemy* monster = new Enemy(e_row, e_col);
    //std:: cout << enemy_list[0];
    enemy_list[count] = monster;
    count++;
    //}
   // catch (std::exception& e) {
     //   throw;

}

Player* Board:: create_player() {
    return guy;
}

void Board:: add_player() {
    try {
        guy = new Player(this);
    }
    catch(std::exception& e) {
        guy = nullptr;
        throw;
    }
}


void Board:: show_grid() {
    
    //create board of x's
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            grid[a][b] = 'x';
        }
    }
    
    //enemy location
    for (int i = 0; i < enemies; i++) {
        char& space = grid[enemy_list[i]->get_row()-1][enemy_list[i]->get_col()-1];
        switch(space) {
            case 'x': space = '*';
                break;
            case '*': space = '2';
                break;
            case '1': space = '3';
                break;
            case '2': space = '4';
                break;
            case '3': space = '5';
                break;
            case '4': space = '6';
                break;
            case '5': space = '7';
                break;
            case '6': space = '8';
                break;
            case '7': space = '9';
                break;
        }
    }
    
    //create player position
    char& player_spot = grid[guy->get_row()-1][guy->get_col()-1];
    if (guy->is_alive()) {
        player_spot = '@';
    }
    else {
        player_spot = '!';
    }
    
    clearScreen();
    //draw grid
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            std::cout<< grid[a][b];
        }
        std:: cout << endl;
    }
    
}

void Board:: move_enemies() {
    for (int i = 0; i < enemies; i++) {
        enemy_list[i]->move();
    }
    for (int i = 0; i < enemies; i++) {
        if ((guy->get_col() == enemy_list[i]->get_col()) && (guy->get_row() == enemy_list[i]->get_col())) {
            guy->kill();
        }
    }
}

int Board:: enemies_at(int row, int col) const {
    int count = 0;
    for (int i = 0; i < enemies; i++) {
        if ((enemy_list[i]->get_row() == row) && (enemy_list[i]->get_col() == col)) {
            count++;
        }
    }
    return count;
}










#endif /* Board_hpp */
