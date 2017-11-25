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
    void update_location(/* some type of input */);
    int get_location();
    
private:
    int x_location, y_location;
};

Player:: Player () {
    x_location = 5;
    y_location = 5;
}

int Player:: get_location() {
    return std:: array[x_location][y_location];
}




#endif /* Player_hpp */
