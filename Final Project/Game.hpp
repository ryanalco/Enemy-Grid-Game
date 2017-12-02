//
//  Game.hpp
//  Final Project
//
//  Created by Ryan Alvarez-Cohen on 11/19/17.
//  Copyright © 2017 Ryan Alvarez-Cohen. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Board.hpp"
#include "AddOns.hpp"

class Board;


class Game {
public:
    Game(int level);
    virtual ~Game();
    void play();
private:
    Board* board;
    int enemies;
};


Game:: Game(int level) {
    
    //board = new Board(enemies);
    
    int row_player = 1 + rand() % 10;
    int col_player = 1 + rand() % 10;
    
    if (level == 1) {
        enemies = 5;
        //board = new Board(enemies);
        try {
            board = new Board(enemies);
        }
        catch(std::exception & e) {
            board = nullptr;
            throw;
        }
        while (enemies > 0) {
            int row_enemy = 1 + rand() % 10;
            int col_enemy = 1 + rand() % 10;
            if (row_enemy == row_player && col_enemy == col_player) {
                continue;
            }
            //Enemy* monster = new Enemy(row_enemy, col_enemy);
            board->add_enemy(row_enemy, col_enemy);
            enemies--;
        }
    }
    else if (level == 2) {
        enemies = 7;
        try {
            board = new Board(enemies);
        }
        catch(std::exception & e) {
            board = nullptr;
            throw;
        }
        while (enemies > 0) {
            int row_enemy = 1 + rand() % 10;
            int col_enemy = 1 + rand() % 10;
            if (row_enemy == row_player && col_enemy == col_player) {
                continue;
            }
            //Enemy* monster = new Enemy(row_enemy, col_enemy);
            board->add_enemy(row_enemy, col_enemy);
            enemies--;
        }
    }
    else if (level == 3) {
        enemies = 10;
        try {
            board = new Board(enemies);
        }
        catch(std::exception & e) {
            board = nullptr;
            throw;
        }
        while (enemies > 0) {
            int row_enemy = 1 + rand() % 10;
            int col_enemy = 1 + rand() % 10;
            if (row_enemy == row_player && col_enemy == col_player) {
                continue;
            }
            //Enemy* monster = new Enemy(row_enemy, col_enemy);
            board->add_enemy(row_enemy, col_enemy);
            enemies--;
        }
    }
    else {
        std::cout << "error";
    }
    /*
    try {
        board = new Board(enemies);
    }
    catch(std::exception & e) {
        board = nullptr;
        throw;
    }
    */
    board->add_player();
}

Game:: ~Game() {
    delete board;
}

void Game:: play() {
    Player* p = board->create_player();
    while (p->is_alive()) {
        board->show_grid();
        std::cout << "Use arrow keys to move\n";
        char response;
        response = getCharacter(); //this is from the Additions.hpp
        if (isblank(response)) {
            return;
            //change this?
        }
        else {
            switch (response) {
                case 'u':
                case 'd':
                case 'l':
                case 'r':
                    p->move(decodeDirection(response));
                    break;
            }
        }
        
        
    }
}





#endif /* Game_hpp */
