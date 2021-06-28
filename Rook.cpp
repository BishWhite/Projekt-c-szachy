
#include "Rook.h"
Rook::Rook( int x, int y, int x0, int y0, bool color) : Field(x0, y0) {
    this->x=x;
    this->y=y;
    this->x0=x0;
    this->y0=y0;
    this->color=color;
    this->name = "R";
}
bool r_move(int x0, int y0, int x, int y, vector<Field>tmp)
{

}
Rook::~Rook()  {
    //cout<<"Rook destroyed"<<endl;
}