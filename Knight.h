

#ifndef ULTIMATETERMINALCHESS_KNIGHT_H
#define ULTIMATETERMINALCHESS_KNIGHT_H
#include <iostream>
#include <vector>
#include "Field.h"

using namespace std;

class Knight: public Field {
    int x=0; int y=0;
    int x0=0; int y0=0;


public:
    bool color;
    string name = "N";
    Knight( int x, int y, int x0, int y0, bool color);
    ~Knight();
};


#endif //ULTIMATETERMINALCHESS_KNIGHT_H
