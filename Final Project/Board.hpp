//
//  Board.hpp
//  Final Project
//
//  Created by Ryan Alvarez-Cohen on 11/15/17.
//  Copyright © 2017 Ryan Alvarez-Cohen. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

class Enemy;
class Player;
class Star;
class Trap;


#include <iostream>
#include <cstdlib>
#include <string>
#include "Enemy.hpp"
#include "Player.hpp"
#include "Star.hpp"
#include "Trap.hpp"
#include "Additions.hpp"




class Board {
public:
    Board(int enemies);
    virtual ~Board();
    void add_enemy(int e_row, int e_col);
    void add_player();
    void show_grid();
    Player* create_player();
    void move_enemies();
    void create_star(int s_row, int s_col);
    int num_stars() const;
    void kill_star(int s_row, int s_col);
    void check_stars();
    bool find_stars(int t_row, int t_col);
    void create_trap(int t_row, int t_col);
    void check_traps();
    
private:
    char grid[10][10];
    Enemy* enemy_list[10];
    int enemies;
    int star_num;
    int count = 0;
    int num = 0;
    Player* guy;
    Star* star_list[4];
    Trap* trap_list[10];
    int t_num = 0;
};


Board:: Board(int enemies) {
    this->enemies = enemies;
    guy = nullptr;
    star_num = 4;
}

Board:: ~Board() {
    delete guy;
    for (int i = 0; i < enemies; i++) {
        delete enemy_list[i];
    }
    for (int i = 0; i < 4; i++) {
        delete star_list[i];
    }
    for (int i = 0; i < t_num; i++) {
        delete trap_list[i];
    }
}

void Board:: add_enemy(int e_row, int e_col) {
    try {
        Enemy* monster = new Enemy(e_row, e_col);
        enemy_list[count] = monster;
        count++;
    }
    catch (std:: exception& e) {
        throw;
    }
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


void Board:: create_star(int s_row, int s_col) {
    try {
        Star* star = new Star(s_row, s_col);
        star_list[num] = star;
        num++;
    }
    catch(std::exception& e) {
        throw;
    }
}


void Board:: kill_star(int s_row, int s_col) {
    for (int i = 0; i < 4; i++) {
        if ((star_list[i]->get_row() == s_row) && (star_list[i]->get_col() == s_col)) {
            star_list[i]->achieve();
        }
    }
    star_num--;
    std:: cout << "You got some money! \n";
}


void Board:: show_grid() {
    
    //create board of x's
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            grid[a][b] = 'x';
        }
    }
    
    //create stars position
    for (int i = 0; i < 4; i++) {
        char& star_spot = grid[star_list[i]->get_row()-1][star_list[i]->get_col()-1];
        if (star_list[i]->state() == false) {
            star_spot = '$';
        }
        else star_spot = 'x';
    }
    
    //enemy location
    for (int i = 0; i < enemies; i++) {
        char& space = grid[enemy_list[i]->get_row()-1][enemy_list[i]->get_col()-1];
        switch(space) {
            case 'x': space = '!';
                break;
            case '!': space = '2';
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
            case '$': space = '$';
                break;
        }
    }

    //create traps position
    for (int i = 0; i < t_num; i++) {
        char& trap_spot = grid[trap_list[i]->get_row()-1][trap_list[i]->get_col()-1];
        trap_spot = '*';
    }
    //create player position
    char& player_spot = grid[guy->get_row()-1][guy->get_col()-1];
    //std:: cout << guy->get_row()-1 << guy->get_col()-1 << endl;
    if (guy->is_alive()) {
        player_spot = '@';
    }
    else {
        player_spot = '#';
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
        if ((guy->get_col() == enemy_list[i]->get_col()) && (guy->get_row() == enemy_list[i]->get_row())) {
            guy->kill();
        }
    }
}


void Board:: check_stars() {
    for (int i = 0; i < 4; i++) {
        if (((guy->get_col() == star_list[i]->get_col()) && (guy->get_row() == star_list[i]->get_row())) && (star_list[i]->state() == false)) {
            kill_star(star_list[i]->get_row(), star_list[i]->get_col());
        }
    }
}


int Board:: num_stars() const {
    return star_num;
}


void Board:: create_trap(int t_row, int t_col) {
    try {
        Trap* trap = new Trap(t_row, t_col);
        trap_list[t_num] = trap;
        t_num++;
    }
    catch(std::exception& e) {
        throw;
    }
}

bool Board:: find_stars(int t_row, int t_col) {
    for (int i = 0; i < 4; i++) {
        if ((star_list[i]->get_row() == t_row) && (star_list[i]->get_col() == t_col)) {
            return true;
        }
    }
    return false;
}


void Board:: check_traps() {
    for (int i = 0; i < t_num; i++) {
        if ((guy->get_col() == trap_list[i]->get_col()) && (guy->get_row() == trap_list[i]->get_row())) {
            guy->kill();
        }
    }
}






#endif /* Board_hpp */
