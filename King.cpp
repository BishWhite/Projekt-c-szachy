
#include "King.h"
King::King( int x, int y, int x0, int y0, bool color) : Field(x0, y0) {
    this->x=x;
    this->y=y;
    this->x0=x0;
    this->y0=y0;
    this->color=color;
    this->isMoved = false;
}



King::~King()  {
    //cout<<"King destroyed"<< endl;
}