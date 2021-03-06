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
class Money;
class Trap;


#include <iostream>
#include <cstdlib>
#include <string>
#include "Enemy.hpp"
#include "Player.hpp"
#include "Money.hpp"
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
    void create_money(int s_row, int s_col);
    int num_monies() const;
    void kill_money(int s_row, int s_col);
    void check_monies();
    bool find_monies(int t_row, int t_col);
    void create_trap(int t_row, int t_col);
    void check_traps();
    bool make_money();
    void lose_money();
    
private:
    char grid[10][10];
    Enemy* enemy_list[10];
    int enemies;
    int money_num;
    int count = 0;
    int num = 0;
    Player* guy;
    Money* money_list[4];
    Trap* trap_list[10];
    int t_num = 0;
    bool get_money;
};


Board:: Board(int enemies) {
    this->enemies = enemies;
    guy = nullptr;
    money_num = 4;
    get_money = false;
}


//virtual board destructor for RAII purposes
Board:: ~Board() {
    delete guy;
    guy = nullptr;
    for (int i = 0; i < enemies; i++) {
        delete enemy_list[i];
        enemy_list[i] = nullptr;
    }
    for (int i = 0; i < 4; i++) {
        delete money_list[i];
        money_list[i] = nullptr;
    }
    for (int i = 0; i < t_num; i++) {
        delete trap_list[i];
        trap_list[i] = nullptr;
    }
}

//adds an enemy into the enemy list
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

//returns the player object after it has been added
Player* Board:: create_player() {
    return guy;
}

//makes a new player at the beginning of game
void Board:: add_player() {
    try {
        guy = new Player(this);
    }
    catch(std::exception& e) {
        guy = nullptr;
        throw;
    }
}

//adds a new star to the star list
void Board:: create_money(int s_row, int s_col) {
    try {
        Money* money = new Money(s_row, s_col);
        money_list[num] = money;
        num++;
    }
    catch(std::exception& e) {
        throw;
    }
}

//removes a money after it has been achieved by the player
void Board:: kill_money(int s_row, int s_col) {
    for (int i = 0; i < 4; i++) {
        if ((money_list[i]->get_row() == s_row) && (money_list[i]->get_col() == s_col)) {
            money_list[i]->achieve();
        }
    }
    money_num--;
    std:: cout << "You got some money! \n";
}

//creates the grid at the beginning of each turn
void Board:: show_grid() {
    
    //create board of x's
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            grid[a][b] = 'x';
        }
    }
    
    //create stars position
    for (int i = 0; i < 4; i++) {
        char& money_spot = grid[money_list[i]->get_row()-1][money_list[i]->get_col()-1];
        if (money_list[i]->state() == false) {
            money_spot = '$';
        }
        else money_spot = 'x';
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

//each enemy in the list randomly moves in a direction
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

//determines if player has gotten a money at end of each turn
void Board:: check_monies() {
    for (int i = 0; i < 4; i++) {
        if (((guy->get_col() == money_list[i]->get_col()) && (guy->get_row() == money_list[i]->get_row())) && (money_list[i]->state() == false)) {
            kill_money(money_list[i]->get_row(), money_list[i]->get_col());
            get_money = true;
        }
    }
}

//returns the number of monies remaining
int Board:: num_monies() const {
    return money_num;
}

//adds a new trap to the list
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

//returns if a player found a money
bool Board:: find_monies(int t_row, int t_col) {
    for (int i = 0; i < 4; i++) {
        if ((money_list[i]->get_row() == t_row) && (money_list[i]->get_col() == t_col)) {
            return true;
        }
    }
    return false;
}

//returns if a player fell into a trap
void Board:: check_traps() {
    for (int i = 0; i < t_num; i++) {
        if ((guy->get_col() == trap_list[i]->get_col()) && (guy->get_row() == trap_list[i]->get_row())) {
            guy->kill();
        }
    }
}

// T/F depending on if player gets a money
bool Board:: make_money() {
    if (get_money) {
        return true;
    }
    else {
        return false;
    }
}

void Board:: lose_money() {
    get_money = false;
}




#endif /* Board_hpp */
