#include<bits/stdc++.h>

using namespace std;

vector<vector<char>> v;
int row,col,com;
enum dir {NORTH,EAST,SOUTH,WEST};

void turn_right(dir& d){ d = (d == WEST)?NORTH:dir(d+1);}
void turn_left(dir& d){ d = (d == NORTH)?WEST:dir(d-1);}

void move_front(int& cx, int& cy, dir d){
    bool movable = true;
    switch(d){
    case NORTH:
        if(v[cx-1][cy] == '#') movable = false;
        break;
    case SOUTH:
        if(v[cx+1][cy] == '#') movable = false;
        break;
    case EAST:
        if(v[cx][cy+1] == '#') movable = false;
        break;
    case WEST:
        if(v[cx][cy-1] == '#') movable = false;
        break;
    }
    if(movable){
        switch(d){
        case NORTH:
            cx--; return;
        case SOUTH:
            cx++; return;
        case EAST:
            cy++; return;
        case WEST:
            cy--; return;
        }
    }
}



int main(){
    while(cin >> row >> col >> com && row){
        v.clear();
        v.resize(row+2,vector<char>(col+2,'#'));
        int c_row , c_col;
        dir d;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cin >> v[i+1][j+1];
                if(v[i+1][j+1] != '.' && v[i+1][j+1] != '*' && v[i+1][j+1] != '#'){
                    switch(v[i+1][j+1]){
                    case 'N':
                        d = NORTH;
                        break;
                    case 'S':
                        d = SOUTH;
                        break;
                    case 'L':
                        d = EAST;
                        break;
                    case 'O':
                        d = WEST;
                        break;
                    }
                    c_row = i+1;
                    c_col = j+1;
                }
            }
        }
        int sticker = 0;
        while(com--){
            char c;
            cin >> c;
            switch(c){
            case 'E':
                turn_left(d);
                break;
            case 'D':
                turn_right(d);
                break;
            case 'F':
                move_front(c_row,c_col,d);
                if(v[c_row][c_col] == '*'){
                    sticker++;
                    v[c_row][c_col] = '.';
                }
                break;
            }
        }
        cout << sticker << endl;
    }
    return 0;
}
