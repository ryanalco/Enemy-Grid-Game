//
//  Additions.hpp
//  Final Project
//
//  Created by Ryan Alvarez-Cohen on 11/28/17.
//  Copyright © 2017 Ryan Alvarez-Cohen. All rights reserved.
//


#ifndef AddOns_hpp
#define AddOns_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

int decodeDirection(char dir);
bool directionToDeltas(int dir, int& rowDelta, int& colDelta);
void clearScreen();
bool destroyOneSnake(int r, int c);
int numberOfSnakesAt(int r, int c);

const char ARROW_LEFT  = 'l';
const char ARROW_RIGHT = 'r';
const char ARROW_UP    = 'u';
const char ARROW_DOWN  = 'd';

const int UP    = 0;
const int DOWN  = 1;
const int LEFT  = 2;
const int RIGHT = 3;


char getCharacter();

#endif /* AddOns_hpp */
