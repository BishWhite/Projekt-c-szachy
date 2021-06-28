#include <iostream>
#include "Board.h"
#include <cstdlib>
using namespace std;
int n=0;
void getinput(Board *b){
    string move = "";

    if(n%2==0)
        cout<<"White turn:"<<endl;
    else
        cout<<"Black turn:"<<endl;


    cin>>move;

    getchar();
    //b->turn(move);
    //cout<<  b->turn(move);
    n += (  b->turn(move) == 0 )? 1 : 0;


    system("clear");
    b->print();
    if(!b->checkmate){
        getinput(b);
    }

}
int main() {
    Board *board = new Board();
    board->print();
    getinput(board);

    return 0;
}
