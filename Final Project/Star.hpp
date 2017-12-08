//
//  Star.hpp
//  Final Project
//
//  Created by Ryan Alvarez-Cohen on 12/3/17.
//  Copyright © 2017 Ryan Alvarez-Cohen. All rights reserved.
//

#ifndef Star_hpp
#define Star_hpp




class Star {
public:
    Star(int row, int col);
    int get_row() const;
    int get_col() const;
    bool state();
    void achieve();
    
private:
    int row, col;
    bool complete;
    
};

Star:: Star(int row, int col) {
    this->row = row;
    this->col = col;
    complete = false;
}

int Star:: get_row() const {
    return row;
}

int Star:: get_col() const {
    return col;
}

bool Star:: state() {
    if (complete) {
        return true;
    }
    else {
        return false;
    }
}

void Star:: achieve() {
    complete = true;
}




#endif /* Star_hpp */
