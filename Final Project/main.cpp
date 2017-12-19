#include "Board.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Game.hpp"

#include <iostream>

int main() {
    
    srand(static_cast<unsigned int>(time(0)));
    
    //Currently game is set to the medium level (2). Easy level is number 1 and hard level is number 3. Level is determined by the parameter inputted into Game g.
    Game g(2);
    g.play();
    
    return 0;
}
