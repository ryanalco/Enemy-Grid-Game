#include "Board.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Game.hpp"

#include <iostream>

int main() {
    
    srand(static_cast<unsigned int>(time(0)));
    
    Game test(3);
    test.play();
    
    return 0;
}
