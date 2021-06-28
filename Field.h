

#ifndef ULTIMATETERMINALCHESS_FIELD_H

#define ULTIMATETERMINALCHESS_FIELD_H
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Field {
    int x, y;


public:
    Field(int x,int y);
     virtual ~Field();
    virtual pair<int,int>position();

    string name="E";
    bool color;
};


#endif //ULTIMATETERMINALCHESS_FIELD_H
