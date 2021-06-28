
#ifndef ULTIMATETERMINALCHESS_EMPTY_H
#define ULTIMATETERMINALCHESS_EMPTY_H

#include <iostream>
#include <vector>
#include "Field.h"


class Empty : public Field {
    int x=0; int y=0;
    int x0=0;int y0=0;
public:
    bool color;
    string name = "E";
    Empty( int x, int y, int x0, int y0, bool color);
};


#endif //ULTIMATETERMINALCHESS_EMPTY_H
