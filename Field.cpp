
#include "Field.h"

Field::Field(int x,int y) {
    this->x = x;
    this->y = y;

}
Field::~Field(){
    //cout << "Field destroyed" <<endl;
}
pair<int,int> Field::position(){
    return make_pair(x,y);
}
