#ifndef ULTIMATETERMINALCHESS_PAWN_H
#define ULTIMATETERMINALCHESS_PAWN_H
#include <iostream>
#include <vector>
#include "Field.h"

using namespace std;

class Pawn: public Field {
    int x=0; int y=0;
    int x0=0; int y0=0;

    public:
    bool isMoved = false;
    bool color;
    string name = "P" ;
    Pawn( int x, int y, int x0, int y0, bool color);
    ~Pawn();
};


#endif //ULTIMATETERMINALCHESS_PAWN_H
