

#ifndef ULTIMATETERMINALCHESS_KING_H
#define ULTIMATETERMINALCHESS_KING_H
#include <iostream>
#include <vector>
#include "Field.h"

using namespace std;

class King: public Field {
    int x=0; int y=0;
    int x0=0;int y0=0;


public:

    bool isMoved = false;
    bool color;
    string name = "K";
    King( int x, int y, int x0, int y0, bool color);
    ~King();

};


#endif //ULTIMATETERMINALCHESS_KING_H
