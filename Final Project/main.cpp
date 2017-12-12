#include "Board.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Game.hpp"

#include <iostream>

int main() {
    
    srand(static_cast<unsigned int>(time(0)));
    
    Game g(3);
    g.play();
    
    return 0;
}
