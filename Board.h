
#ifndef ULTIMATETERMINALCHESS_BOARD_H
#define ULTIMATETERMINALCHESS_BOARD_H
#include <iostream>
#include <vector>
#include "Field.h"

using namespace std;

class Board {
public:
     Board();
    ~Board();
    vector<vector<Field>>fields; // klasa pole - poli
    void print();
    bool check(int whoseTurn, int x_w, int y_w, int x_b, int y_b);
    int turn(string move); // tu będzie parametr jaki ruch
    int turnBack(int prev_x, int prev_y, int curr_x, int curr_y,string t);
    bool checkmate= false;

};
#endif //ULTIMATETERMINALCHESS_BOARD_H
