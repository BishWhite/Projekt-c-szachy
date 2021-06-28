#ifndef ULTIMATETERMINALCHESS_QUEEN_H
#define ULTIMATETERMINALCHESS_QUEEN_H
#include <iostream>
#include <vector>
#include "Field.h"

using namespace std;

class Queen: public Field {


    int x=0; int y=0;
    int x0=0; int y0=0;


public:
    bool color;
    string name = "Q";
    Queen( int x, int y, int x0, int y0, bool color);
    ~Queen();
};



#endif //ULTIMATETERMINALCHESS_QUEEN_H
