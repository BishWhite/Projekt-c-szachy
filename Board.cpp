#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;
#include <typeinfo>
#include "Board.h"
#include "Pawn.h"
#include "Queen.h"
#include "King.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Empty.h"

#include "colors.h"

int x_white = 3;
int y_white = 0;
int x_black = 3;
int y_black = 7;

Board::Board(){

    for( int i= 0 ; i< 8; i++){
        vector<Field> tmp;
        bool color = ( i >= 4 )? true : false;//czarny true bialy false
        for( int j= 0 ; j< 8; j++){
           if(i==1 || i==6) {
               tmp.push_back(Pawn(j, i, j, i, color));
               tmp[j].name = "P";
               tmp[j].color = color;
           }
           else if((i == 0 || i == 7) && (j == 0 || j == 7) ){
               tmp.push_back(Rook(j, i, j, i, color));
               tmp[j].name = "R";
               tmp[j].color = color;
           }
           else if((i==0 || i==7) && (j==1 || j==6)){
               tmp.push_back(Knight(j, i, j, i, color));
               tmp[j].name = "N";
               tmp[j].color = color;
           }
           else if((i==0 || i==7)&&(j==2 || j==5)){
               tmp.push_back(Bishop(j, i, j, i, color));
               tmp[j].name = "B";
               tmp[j].color = color;
           }
           else if((i==0 && j==3)||(i==7 && j==3)){
               tmp.push_back(Queen(j, i, j, i, color));
               tmp[j].name = "K";
               tmp[j].color = color;
           }
           else if((i==0 && j==4)||(i==7 && j==4)){
               tmp.push_back(King(j, i, j, i, color));
               tmp[j].name = "Q";
               tmp[j].color = color;
           }
           else{
               tmp.push_back( Empty(j, i, j, i, color) );
               tmp[j].name = "E";
               tmp[j].color = color;
           }

        }
        fields.push_back(tmp);
    }
}


Board::~Board(){
    cout << "Board destroyed" <<endl;
}
int Board::turnBack(int prev_x, int prev_y, int curr_x, int curr_y,string t) {
    if(fields[curr_y][curr_x].color){
        if(check(1, x_white, y_white, x_black, y_black))
        {
            cout<<RED<<"Wrong format"<<RESET<<endl;
            fields[prev_y][prev_x].name=fields[curr_y][curr_x].name;
            fields[curr_y][curr_x].name = t;
            fields[curr_y][curr_x].color = !fields[curr_y][curr_x].color;

            return 1;
        }
        return 0;
    }
    else{
        if(check(0, x_white, y_white, x_black, y_black))
        {
            cout<<RED<<"Wrong format"<<RESET<<endl;
            fields[prev_y][prev_x].name=fields[curr_y][curr_x].name;
            fields[curr_y][curr_x].name = t;
            fields[curr_y][curr_x].color = !fields[curr_y][curr_x].color;
            return 1;
        }
        return 0;
    }

}
bool Board::check(int whoseTurn, int x_w,int y_w,int x_b, int y_b) {
    if (whoseTurn==0) {
        int tmpy = y_w;
        int tmpx = x_w;
        int i = 1;
        //do gory
        while (tmpy - i >= 0) {
            if (!fields[tmpy - i][tmpx].color && fields[tmpy -i][tmpx].name!="E")
                break;
            if ((fields[tmpy - i][tmpx].name == "Q" && fields[tmpy - i][tmpx].color) ||
                (fields[tmpy - i][tmpx].name == "R" && fields[tmpy - i][tmpx].color))
                return true;
            i++;

        }
        //w dol
        i = 1;
        while (tmpy + i <= 7) {
            if (!fields[tmpy + i][tmpx].color && fields[tmpy + i][tmpx].name!="E")
                break;
            if ((fields[tmpy + i][tmpx].name == "Q" && fields[tmpy + i][tmpx].color) ||
                (fields[tmpy + i][tmpx].name == "R" && fields[tmpy + i][tmpx].color))
                return true;
            i++;

        }
        //z prawej
        i = 1;
        while (tmpx + i <= 7) {
            if (!fields[tmpy][tmpx + i].color && fields[tmpy][tmpx + i].name!="E")
                break;
            if ((fields[tmpy][tmpx + i].name == "Q" && fields[tmpy][tmpx + i].color) ||
                (fields[tmpy][tmpx + i].name == "R" && fields[tmpy][tmpx + i].color))
                return true;
            i++;

        }
        //z lewej
        i = 1;
        while (tmpx - i >= 0) {
            if (!fields[tmpy][tmpx - i].color && fields[tmpy][tmpx - i].name!="E")
                break;
            if ((fields[tmpy][tmpx - i].name == "Q" && fields[tmpy][tmpx - i].color) ||
                (fields[tmpy][tmpx - i].name == "R" && fields[tmpy][tmpx - i].color))
                return true;
            i++;
        }
        //konie
        if (tmpy - 1 >= 0 && tmpx - 2 >= 0 && fields[tmpy - 1][tmpx - 2].color && fields[tmpy - 1][tmpx - 2].name == "N")
            return true;
        if (tmpy - 2 >= 0 && tmpx - 1 >= 0 && fields[tmpy - 2][tmpx - 1].color && fields[tmpy - 2][tmpx - 1].name == "N")
            return true;
        if (tmpy - 2 >= 0 && tmpx + 1 <= 7 && fields[tmpy - 2][tmpx + 1].color && fields[tmpy - 2][tmpx + 1].name == "N")
            return true;
        if (tmpy - 1 >= 0 && tmpx + 2 <= 7 && fields[tmpy - 1][tmpx + 2].color && fields[tmpy - 1][tmpx + 2].name == "N")
            return true;
        if (tmpy + 1 <= 7 && tmpx + 2 <= 7 && fields[tmpy + 1][tmpx + 2].color && fields[tmpy + 1][tmpx + 2].name == "N")
            return true;
        if (tmpy + 2 <= 7 && tmpx + 1 <= 7 && fields[tmpy + 2][tmpx + 1].color && fields[tmpy + 2][tmpx + 1].name == "N")
            return true;
        if (tmpy + 2 <= 7 && tmpx - 1 >= 0 && fields[tmpy + 2][tmpx - 1].color && fields[tmpy + 2][tmpx - 1].name == "N")
            return true;
        if (tmpy + 1 <= 7 && tmpx - 2 >= 0 && fields[tmpy + 1][tmpx - 2].color && fields[tmpy + 1][tmpx - 2].name == "N")
            return true;
        //pionki
        if (tmpx - 1 >= 0 && tmpy + 1 <= 7 && fields[tmpy + 1][tmpx - 1].name == "P" && fields[tmpy + 1][tmpx - 1].color)
            return true;
        if (tmpx + 1 <= 7 && tmpy + 1 <= 7 && fields[tmpy + 1][tmpx + 1].name == "P" && fields[tmpy + 1][tmpx + 1].color)
            return true;
        //prawo gora
        i = 1;
        while (tmpy - i >= 0 && tmpx + i <= 7) {
            if (!fields[tmpy - i][tmpx + i].color && fields[tmpy - i][tmpx + i].name!="E")
                break;
            if ((fields[tmpy - i][tmpx + i].name == "Q" && fields[tmpy - i][tmpx + i].color) ||
                (fields[tmpy - i][tmpx + i].name == "B" && fields[tmpy - i][tmpx + i].color))
                return true;
            i++;
        }

        //lewo gora
        i = 1;
        while (tmpy - i >= 0 && tmpx - i >= 0) {
            if (!fields[tmpy - i][tmpx - i].color && fields[tmpy - i][tmpx - i].name!="E")
                break;
            if ((fields[tmpy - i][tmpx - i].name == "Q" && fields[tmpy - i][tmpx - i].color) ||
                (fields[tmpy - i][tmpx - i].name == "B" && fields[tmpy - i][tmpx - i].color))
                return true;
            i++;
        }
        //lewo dol
        i = 1;
        while (tmpy + i <= 7 && tmpx - i >= 0) {
            if (!fields[tmpy + i][tmpx - i].color && fields[tmpy + i][tmpx - i].name!="E")
                break;
            if ((fields[tmpy + i][tmpx - i].name == "Q" && fields[tmpy + i][tmpx - i].color) ||
                (fields[tmpy + i][tmpx - i].name == "B" && fields[tmpy + i][tmpx - i].color))
                return true;
            i++;
        }
        //prawo dol
        i = 1;
        while (tmpy + i <= 7 && tmpx + i <= 7) {
            if (!fields[tmpy + i][tmpx + i].color && fields[tmpy + i][tmpx + i].name!="E")
                break;
            if ((fields[tmpy + i][tmpx + i].name == "Q" && fields[tmpy + i][tmpx + i].color) ||
                (fields[tmpy + i][tmpx + i].name == "B" && fields[tmpy + i][tmpx + i].color))
                return true;
            i++;
        }
        //krol przeciwny
        if (abs(x_w - x_b) <= 1 && abs(y_w - y_b) <= 1)
            return true;

        return false;
    } else {
        int tmpy = y_b;
        int tmpx = x_b;
        int i = 1;
        //do gory
        while (tmpy - i >= 0) {
            if (fields[tmpy - i][tmpx].color && fields[tmpy - i][tmpx].name!="E")
                break;
            if ((fields[tmpy - i][tmpx].name == "Q" && !fields[tmpy - i][tmpx].color) ||
                (fields[tmpy - i][tmpx].name == "R" && !fields[tmpy - i][tmpx].color))
                return true;
            i++;
        }
        //w dol
        i = 1;
        while (tmpy + i <= 7) {
            if (fields[tmpy + i][tmpx].color && fields[tmpy + i][tmpx].name!="E")
                break;
            if ((fields[tmpy + i][tmpx].name == "Q" && !fields[tmpy + i][tmpx].color) ||
                (fields[tmpy + i][tmpx].name == "R" && !fields[tmpy + i][tmpx].color))
                return true;
            i++;
        }
        //z prawej
        i = 1;
        while (tmpx + i <= 7) {
            if (fields[tmpy][tmpx + i].color && fields[tmpy][tmpx + i].name!="E")
                break;
            if ((fields[tmpy][tmpx + i].name == "Q" && !fields[tmpy][tmpx + i].color) ||
                (fields[tmpy][tmpx + i].name == "R" && !fields[tmpy][tmpx + i].color))
                return true;
            i++;
        }
        //z lewej
        i = 1;
        while (tmpx - i >= 0) {
            if (fields[tmpy][tmpx - i].color && fields[tmpy][tmpx - i].name!="E")
                break;
            if ((fields[tmpy][tmpx - i].name == "Q" && !fields[tmpy][tmpx - i].color) ||
                (fields[tmpy][tmpx - i].name == "R" && !fields[tmpy][tmpx - i].color))
                return true;
            i++;
        }
        //konie
        if (tmpy - 1 >= 0 && tmpx - 2 >= 0 && !fields[tmpy - 1][tmpx - 2].color && fields[tmpy - 1][tmpx - 2].name == "N")
            return true;
        if (tmpy - 2 >= 0 && tmpx - 1 >= 0 && !fields[tmpy - 2][tmpx - 1].color && fields[tmpy - 2][tmpx - 1].name == "N")
            return true;
        if (tmpy - 2 >= 0 && tmpx + 1 <= 7 && !fields[tmpy - 2][tmpx + 1].color && fields[tmpy - 2][tmpx + 1].name == "N")
            return true;
        if (tmpy - 1 >= 0 && tmpx + 2 <= 7 && !fields[tmpy - 1][tmpx + 2].color && fields[tmpy - 1][tmpx + 2].name == "N")
            return true;
        if (tmpy + 1 <= 7 && tmpx + 2 <= 7 && !fields[tmpy + 1][tmpx + 2].color && fields[tmpy + 1][tmpx + 2].name == "N")
            return true;
        if (tmpy + 2 <= 7 && tmpx + 1 <= 7 && !fields[tmpy + 2][tmpx + 1].color && fields[tmpy + 2][tmpx + 1].name == "N")
            return true;
        if (tmpy + 2 <= 7 && tmpx - 1 >= 0 && !fields[tmpy + 2][tmpx - 1].color && fields[tmpy + 2][tmpx - 1].name == "N")
            return true;
        if (tmpy + 1 <= 7 && tmpx - 2 >= 0 && !fields[tmpy + 1][tmpx - 2].color && fields[tmpy + 1][tmpx - 2].name == "N")
            return true;
        //pionki
        if (tmpx - 1 >= 0 && tmpy - 1 >= 0 && fields[tmpy - 1][tmpx - 1].name == "P" && !fields[tmpy - 1][tmpx - 1].color)
            return true;
        if (tmpx + 1 <= 7 && tmpy - 1 >= 0 && fields[tmpy - 1][tmpx + 1].name == "P" && !fields[tmpy - 1][tmpx + 1].color)
            return true;
        //prawo gora
        i = 1;
        while (tmpy - i >= 0 && tmpx + i <= 7) {
            if (fields[tmpy - i][tmpx + i].color && fields[tmpy - i][tmpx + i].name!="E")
                break;
            if ((fields[tmpy - i][tmpx + i].name == "Q" && !fields[tmpy - i][tmpx + i].color) ||
                (fields[tmpy - i][tmpx + i].name == "B" && !fields[tmpy - i][tmpx + i].color))
                return true;
            i++;
        }
        //lewo gora
        i = 1;
        while (tmpy - i >= 0 && tmpx - i >= 0) {
            if (fields[tmpy - i][tmpx - i].color && fields[tmpy - i][tmpx - i].name!="E")
                break;
            if ((fields[tmpy - i][tmpx - i].name == "Q" && !fields[tmpy - i][tmpx - i].color) ||
                (fields[tmpy - i][tmpx - i].name == "B" && !fields[tmpy - i][tmpx - i].color))
                return true;
            i++;
        }
        //lewo dol
        i = 1;
        while (tmpy + i <= 7 && tmpx - i >= 0) {
            if (fields[tmpy + i][tmpx - i].color && fields[tmpy + i][tmpx - i].name!="E")
                break;
            if ((fields[tmpy + i][tmpx - i].name == "Q" && !fields[tmpy + i][tmpx - i].color) ||
                (fields[tmpy + i][tmpx - i].name == "B" && !fields[tmpy + i][tmpx - i].color))
                return true;
            i++;
        }
        //prawo dol
        i = 1;
        while (tmpy + i <= 7 && tmpx + i <= 7) {
            if (fields[tmpy + i][tmpx + i].color && fields[tmpy + i][tmpx + i].name!="E")
                break;
            if ((fields[tmpy + i][tmpx + i].name == "Q" && !fields[tmpy + i][tmpx + i].color) ||
                (fields[tmpy + i][tmpx + i].name == "B" && !fields[tmpy + i][tmpx + i].color))
                return true;
            i++;
        }
        //krol przeciwny
        if (abs(x_w - x_b) <= 1 && abs(y_w - y_b) <= 1)
            return true;
        return false;
    }
}
int Board::turn(string move) {
    //K i L sprawdzenie czy pozycja ma szach
    //if(move=="L"){cout<< check(0,x_white,y_white,x_black,y_black)<<endl;}
    //else if(move=="K"){cout<< check(1,x_white,y_white,x_black,y_black)<<endl;}
    if ( move.find("-") == string::npos ) { cout << "Wrong Format" <<endl;return 1; }
    else if ( move.length() != 5 ) { cout << "Wrong Format" <<endl;return 1; }
    else {
        string what = move.substr(0, move.find("-"));
        string where = move.substr(move.find("-") + 1, move.length());
        cout << what << "    |   " << where << endl;

        string sWhatY = &what[1];
        int whatY = stoi(sWhatY) - 1;
        int whatX = 7-(int(what[0]) - int('a'));

        cout << "[ Chosen Piece ]: " << fields[whatY][whatX].name << endl;

        string sWhereY = &where[1];
        int whereY = stoi(sWhereY) - 1;
        int whereX = 7-(int(where[0]) - int('a'));

        if (whereX > 7 || whereX < 0 || whereY > 7 || whereY < 0) {
            cout << RED << "Wrong format." << RESET << endl;
            return 1;
        } else if (fields[whatY][whatX].name == "R") {
            if(whatX==whereX && whatY!=whereY)
            {
                int tmp_x = whatX;
                int tmp_y = whatY;
                int dY = (whatY > whereY) ? -1 : 1;
                tmp_y += dY;
                while(tmp_y!=whereY)
                {
                    if (fields[tmp_y][tmp_x].name != "E") {
                        cout << RED << "ERROR" << RESET << endl;
                        return 1;}
                    tmp_y += dY;
                }
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                    return 1;}
                string tmp_name = fields[whereY][whereX].name;
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
                return turnBack(whatX,whatY,whereX,whereY,tmp_name);



            }
            else if(whatX!=whereX && whatY==whereY)
            {
                int tmp_x = whatX;
                int tmp_y = whatY;
                int dX = (whatX > whereX) ? -1 : 1;
                tmp_x += dX;
                while(tmp_x!=whereX)
                {
                    if (fields[tmp_y][tmp_x].name != "E") {
                        cout << RED << "ERROR" << RESET << endl;
                        return 1;}
                    tmp_x += dX;
                }
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                    return 1; }
                string tmp_name = fields[whereY][whereX].name;
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
                return turnBack(whatX,whatY,whereX,whereY,tmp_name);

            }
            else
            {
                cout << RED << "Wrong format" << RESET << endl;
                return 1;}


        } else if (fields[whatY][whatX].name == "N") {

            if(whereX-whatX==1 && whereY-whatY==2)
            {
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                return 1;}
                string tmp_name = fields[whereY][whereX].name;
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
                return turnBack(whatX,whatY,whereX,whereY,tmp_name);
            }
            else if(whereX-whatX==1 && whereY-whatY==-2)
            {
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                    return 1;}
                string tmp_name = fields[whereY][whereX].name;
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
                return turnBack(whatX,whatY,whereX,whereY,tmp_name);
            }
            else if(whereX-whatX==-1 && whereY-whatY==2)
            {
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                    return 1;}
                string tmp_name = fields[whereY][whereX].name;
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
                return turnBack(whatX,whatY,whereX,whereY,tmp_name);
            }
            else if(whereX-whatX==-1 && whereY-whatY==-2)
            {
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                    return 1;}
                string tmp_name = fields[whereY][whereX].name;
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
                return turnBack(whatX,whatY,whereX,whereY,tmp_name);
            }
            else if(whereX-whatX==2 && whereY-whatY==1)
            {
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                    return 1;}
                string tmp_name = fields[whereY][whereX].name;
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
                return turnBack(whatX,whatY,whereX,whereY,tmp_name);
            }
            else if(whereX-whatX==2 && whereY-whatY==-1)
            {
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                    return 1;}
                string tmp_name = fields[whereY][whereX].name;
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
                return turnBack(whatX,whatY,whereX,whereY,tmp_name);
            }
            else if(whereX-whatX==-2 && whereY-whatY==1)
            {
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                    return 1;}
                string tmp_name = fields[whereY][whereX].name;
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
                return turnBack(whatX,whatY,whereX,whereY,tmp_name);
            }
            else if(whereX-whatX==-2 && whereY-whatY==-1)
            {
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                    return 1;}
                string tmp_name = fields[whereY][whereX].name;
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
                return turnBack(whatX,whatY,whereX,whereY,tmp_name);
            }
            else{
                cout << RED << "Wrong format" << RESET << endl;
                return 1;}


        } else if (fields[whatY][whatX].name == "B") {

            int tmp_x = whatX;
            int tmp_y = whatY;
            if (abs(whereX - whatX) != abs(whereY - whatY)) {
                cout << RED << "Wrong format" << RESET << endl;
                return 1; }
            else {

                int dX = (whatX > whereX) ? -1 : 1;
                int dY = (whatY > whereY) ? -1 : 1;
                tmp_x += dX;
                tmp_y += dY;
                while (tmp_x != whereX && tmp_y != whereY) {
                    if (fields[tmp_y][tmp_x].name != "E") {
                        cout << RED << "ERROR" << RESET << endl;
                        return 1;}
                    tmp_x += dX;
                    tmp_y += dY;}
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                    return 1;}

                string tmp_name = fields[whereY][whereX].name;
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
                return turnBack(whatX,whatY,whereX,whereY,tmp_name);

                }
    }

        else if (fields[ whatY ][ whatX ].name == "Q") {
            if(whatX==whereX && whatY!=whereY)
            {
                int tmp_x = whatX;
                int tmp_y = whatY;
                int dY = (whatY > whereY) ? -1 : 1;
                tmp_y += dY;
                while(tmp_y!=whereY)
                {
                    if (fields[tmp_y][tmp_x].name != "E") {
                        cout << RED << "ERROR" << RESET << endl;
                        return 1;}
                    tmp_y += dY;
                }
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                    return 1;}
                string tmp_name = fields[whereY][whereX].name;
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
                return turnBack(whatX,whatY,whereX,whereY,tmp_name);

            }
            else if(whatX!=whereX && whatY==whereY)
            {
                int tmp_x = whatX;
                int tmp_y = whatY;
                int dX = (whatX > whereX) ? -1 : 1;
                tmp_x += dX;
                while(tmp_x!=whereX)
                {
                    if (fields[tmp_y][tmp_x].name != "E") {
                        cout << RED << "ERROR" << RESET << endl;
                        return 1;}
                    tmp_x += dX;
                }
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                    return 1;}
                string tmp_name = fields[whereY][whereX].name;
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
                return turnBack(whatX,whatY,whereX,whereY,tmp_name);
            }
            else if(abs(whereX - whatX) == abs(whereY - whatY))
            {
                int tmp_x = whatX;
                int tmp_y = whatY;
                int dX = (whatX > whereX) ? -1 : 1;
                int dY = (whatY > whereY) ? -1 : 1;
                tmp_x += dX;
                tmp_y += dY;
                while (tmp_x != whereX && tmp_y != whereY) {
                    if (fields[tmp_y][tmp_x].name != "E") {
                        cout << RED << "ERROR" << RESET << endl;
                        return 1;}
                    tmp_x += dX;
                    tmp_y += dY;}
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                    return 1;}

                string tmp_name = fields[whereY][whereX].name;
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
                return turnBack(whatX,whatY,whereX,whereY,tmp_name);

            }
            else{
                cout << RED << "Wrong format" << RESET << endl;
                return 1;}



        } else if (fields[ whatY ][ whatX ].name == "K") {

            if((abs(whereY-whatY)==1 && whatX==whereX)|| (whatY==whereY && abs(whereX-whatX)==1)|| (abs(whereY-whatY)==1 && abs(whereX-whatX)==1)){
                if(fields[whereY][whereX].name!= "E" && fields[whereY][whereX].color!=fields[whatY][whatX].color){


                    string tmp_name= fields[whereY][whereX].name;
                    fields[whereY][whereX] = fields[whatY][whatX];
                    fields[whatY][whatX].name = "E";
                    if(fields[whereY][whereX].color){
                        x_black = whereX;
                        y_black = whereY;
                        if(turnBack(whatX,whatY,whereX,whereY,tmp_name)){
                            x_black = whatX;
                            y_black = whatY;
                            return 1;
                        }
                    }
                    else {
                        x_white = whereX;
                        y_white = whereY;
                        if(turnBack(whatX,whatY,whereX,whereY,tmp_name)){
                            x_white = whatX;
                            y_white = whatY;
                            return 1;
                        }
                    }


                    return 0;

                }
                else if(fields[whereY][whereX].name == "E"){
                    string tmp_name= fields[whereY][whereX].name;
                    fields[whereY][whereX] = fields[whatY][whatX];
                    fields[whatY][whatX].name = "E";

                    if(fields[whereY][whereX].color){
                        x_black = whereX;
                        y_black = whereY;
                        if(turnBack(whatX,whatY,whereX,whereY,tmp_name)){
                            x_black = whatX;
                            y_black = whatY;
                            return 1;
                        }
                    }
                    else {
                        x_white = whereX;
                        y_white = whereY;
                        if(turnBack(whatX,whatY,whereX,whereY,tmp_name)){
                            x_white = whatX;
                            y_white = whatY;
                            return 1;
                        }
                    }
                    return 0;

                }
                else {
                    cout << RED << "Wrong format" << RESET << endl;
                    return 1;
                }
            }

            else {
                cout << RED << "Wrong format" << RESET << endl;
                return 1;
            }




        } else if (fields[ whatY ][ whatX ].name == "P") {


                //czarny
                if(fields[whatY][whatX].color){

                    if(whereX==whatX){
                        if(whereY-whatY==-1 && fields[whereY][whereX].name=="E"){
                            fields[whereY][whereX] = fields[whatY][whatX];
                            fields[whatY][whatX].name = "E";
                            return turnBack(whatX,whatY,whereX,whereY,"E");

                        }
                        else if(whereY-whatY==-2 && fields[whereY][whereX].name=="E"  && fields[whereY+1][whereX].name=="E" && whereY==4){
                            fields[whereY][whereX] = fields[whatY][whatX];
                            fields[whatY][whatX].name = "E";
                            return turnBack(whatX,whatY,whereX,whereY,"E");
                        }
                        else {
                            cout << RED << "Wrong format" << RESET << endl;
                            return 1;
                        }

                    }
                    else if(whereX-whatX==1 && whereY-whatY==-1){
                        if(fields[whereY][whereX].name!= "E" && fields[whereY][whereX].color!=fields[whatY][whatX].color){
                            string tmp_name= fields[whereY][whereX].name;
                            fields[whereY][whereX] = fields[whatY][whatX];
                            fields[whatY][whatX].name = "E";
                            return turnBack(whatX,whatY,whereX,whereY,tmp_name);

                        }
                        else {
                            cout << RED << "Wrong format" << RESET << endl;
                            return 1;
                        }
                    }
                    else if(whereX-whatX==-1 && whereY-whatY==-1){
                        if(fields[whereY][whereX].name!= "E" && fields[whereY][whereX].color!=fields[whatY][whatX].color){
                            string tmp_name= fields[whereY][whereX].name;
                            fields[whereY][whereX] = fields[whatY][whatX];
                            fields[whatY][whatX].name = "E";
                            return turnBack(whatX,whatY,whereX,whereY,tmp_name);
                        }
                        else {
                            cout << RED << "Wrong format" << RESET << endl;
                            return 1;
                        }
                    }

                }
                if(!fields[whatY][whatX].color){

                    if(whereX==whatX){

                        if(whereY-whatY==1 && fields[whereY][whereX].name=="E"){

                            fields[whereY][whereX] = fields[whatY][whatX];
                            fields[whatY][whatX].name = "E";
                            return turnBack(whatX,whatY,whereX,whereY,"E");


                        }
                        else if(whereY-whatY==2 && fields[whereY][whereX].name=="E"  && fields[whereY-1][whereX].name=="E" && whereY==3){

                            fields[whereY][whereX] = fields[whatY][whatX];
                            fields[whatY][whatX].name = "E";
                            return turnBack(whatX,whatY,whereX,whereY,"E");
                        }
                        else {
                            cout << RED << "Wrong format" << RESET << endl;
                            return 1;
                        }

                    }
                    else if(whereX-whatX==1 && whereY-whatY==1){
                        if(fields[whereY][whereX].name!= "E" && fields[whereY][whereX].color!=fields[whatY][whatX].color){
                            string tmp_name= fields[whereY][whereX].name;
                            fields[whereY][whereX] = fields[whatY][whatX];
                            fields[whatY][whatX].name = "E";
                            return turnBack(whatX,whatY,whereX,whereY,tmp_name);
                        }
                        else {
                            cout << RED << "Wrong format" << RESET << endl;
                            return 1;
                        }
                    }
                    else if(whereX-whatX==-1 && whereY-whatY==1){
                        if(fields[whereY][whereX].name!= "E" && fields[whereY][whereX].color!=fields[whatY][whatX].color){
                            string tmp_name= fields[whereY][whereX].name;
                            fields[whereY][whereX] = fields[whatY][whatX];
                            fields[whatY][whatX].name = "E";
                            return turnBack(whatX,whatY,whereX,whereY,tmp_name);
                        }
                        else {
                            cout << RED << "Wrong format" << RESET << endl;
                            return 1;
                        }
                    }


                }
                else {
                    cout << RED << "Wrong format" << RESET << endl;
                    return 1;
                }


                 // Podmianka pól
                    //swap(fields[ whereY ][ whereX ],fields[ whatY ][ whatX ]);



        }
        else { cout << "No piece there" <<endl;
        return 1;}

    }


}
void Board::print() {
    cout <<BOLDMAGENTA <<  "    | H | G | F | E | D | C | B | A |" << RESET;
    int a = 0;
    for( vector<Field>row : fields ) {

        for ( Field f : row )
        {
            if(a % 8 == 0) cout <<endl<<BOLDMAGENTA<< "-----------------------------------------" <<RESET<<endl;
            if ( a % 8 == 0) cout << "| "<< a/8+1 << " | ";
            if (f.name != "E"){
                if (f.color == true) cout << RED;
                else if (f.color != true) cout << GREEN;
            }
            if (f.name == "E") cout << "E";
            else cout << f.name;
            cout << RESET;
            if( a % 8 != 7) cout << " | " ;
            if ( a % 8 == 7) cout << " | "<< a/8+1 << " | ";
            a++;
        }

    }
    cout <<endl<< BOLDMAGENTA << "-----------------------------------------"<< RESET <<endl;
    cout <<BOLDMAGENTA <<  "    | H | G | F | E | D | C | B | A |" << RESET <<endl;
}
