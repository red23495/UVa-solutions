#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

struct p{
    int x; int y;
};

bool up(char (&arr)[8][8], int row, int column, char suit){
    if(arr[row][column] != '-') return false;
    for(int i = row+1; i < 8; i++){
        if(arr[i][column] == '-') return false;
        else if(arr[i][column] == suit){
            if(i - row > 1) return true;
            else return false;
        }
    }
    return false;
}

bool down(char (&arr)[8][8], int row, int column, char suit){
    if(arr[row][column] != '-') return false;
    for(int i = row-1; i >= 0; i--){
        if(arr[i][column] == '-') return false;
        else if(arr[i][column] == suit){
            if(row - i > 1) return true;
            else return false;
        }
    }
    return false;
}

bool left(char (&arr)[8][8], int row, int column, char suit){
    if(arr[row][column] != '-') return false;
    for(int i = column-1; i >= 0; i--){
        if(arr[row][i] == '-') return false;
        else if(arr[row][i] == suit){
            if(column - i > 1) return true;
            else return false;
        }
    }
    return false;
}

bool right(char (&arr)[8][8], int row, int column, char suit){
    if(arr[row][column] != '-') return false;
    for(int i = column+1; i < 8; i++){
        if(arr[row][i] == '-') return false;
        else if(arr[row][i] == suit){
            if(i - column > 1) return true;
            else return false;
        }
    }
    return false;
}

bool upperLeft(char (&arr)[8][8], int row, int column, char suit){
    if(arr[row][column] != '-') return false;
    for(int i = row+1, j = column - 1; i < 8 && j >= 0; i++, j--){
        if(arr[i][j] == '-') return false;
        else if(arr[i][j] == suit){
            if(i - row > 1) return true;
            else return false;
        }
    }
    return false;
}

bool lowerLeft(char (&arr)[8][8], int row, int column, char suit){
    if(arr[row][column] != '-') return false;
    for(int i = row-1, j = column + 1; j < 8 && i >= 0; j++, i--){
        if(arr[i][j] == '-') return false;
        else if(arr[i][j] == suit){
            if(row - i > 1) return true;
            else return false;
        }
    }
    return false;
}

bool upperRight(char (&arr)[8][8], int row, int column, char suit){
    if(arr[row][column] != '-') return false;
    for(int i = row+1, j = column + 1; i < 8 && j < 8; i++, j++){
        if(arr[i][j] == '-') return false;
        else if(arr[i][j] == suit){
            if(i - row > 1) return true;
            else return false;
        }
    }
    return false;
}

bool lowerRight(char (&arr)[8][8], int row, int column, char suit){
    if(arr[row][column] != '-') return false;
    for(int i = row-1, j = column - 1; i >= 0 && j >= 0; i--, j--){
        if(arr[i][j] == '-') return false;
        else if(arr[i][j] == suit){
            if(row - i > 1) return true;
            else return false;
        }
    }
    return false;
}

void legal(char (&arr)[8][8], vector<p> &v, char suit)
{
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(up(arr,i,j,suit)||down(arr,i,j,suit)||left(arr,i,j,suit)||
               right(arr,i,j,suit)||upperLeft(arr,i,j,suit)||upperRight(arr,i,j,suit)||
               lowerLeft(arr,i,j,suit)||lowerRight(arr,i,j,suit)) v.push_back({i,j});
        }
    }
}

bool play(char (&arr)[8][8], int row, int column,char suit){
    bool check = false;
    char oppos = (suit == 'W')? 'B':'W';
    if(up(arr,row,column,suit)){
        check = true;
        for(int i = row+1; i < 8; i++){
            if(arr[i][column] == oppos) arr[i][column] = suit;
            else break;
        }
    }
    if(down(arr,row,column,suit)){
        check = true;
        for(int i = row-1; i >= 0; i--){
            if(arr[i][column] == oppos) arr[i][column] = suit;
            else break;
        }
    }
    if(left(arr,row,column,suit)){
        check = true;
        for(int i = column-1; i >= 0; i--){
            if(arr[row][i] == oppos) arr[row][i] = suit;
            else break;
        }
    }
    if(right(arr,row,column,suit)){
        check = true;
        for(int i = column+1; i < 8; i++){
            if(arr[row][i] == oppos) arr[row][i] = suit;
            else break;
        }
    }
    if(upperLeft(arr,row,column,suit)){
        check = true;
        for(int i = row+1, j = column - 1; i < 8 && j >= 0; i++, j--){
            if(arr[i][j] == oppos) arr[i][j] = suit;
            else break;
        }
    }
    if(lowerLeft(arr,row,column,suit)){
        check = true;
        for(int i = row-1, j = column + 1; i >= 0 && j < 8; j++, i--){
            if(arr[i][j] == oppos) arr[i][j] = suit;
            else break;
        }
    }
    if(upperRight(arr,row,column,suit)){
        check = true;
        for(int i = row+1, j = column + 1; i < 8 && j < 8; i++, j++){
            if(arr[i][j] == oppos) arr[i][j] = suit;
            else break;
        }
    }
    if(lowerRight(arr,row,column,suit)){
        check = true;
        for(int i = row-1, j = column - 1; i >= 0 && j >= 0; i--, j--){
            if(arr[i][j] == oppos) arr[i][j] = suit;
            else break;
        }
    }
    if(check) arr[row][column] = suit;
    return check;
}

int main(){
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        if(i)cout << endl;
        char table[8][8];
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                cin >> table[i][j];
            }
        }
        char command,suit;
        cin >> suit;
        while(cin >> command){
            if (command == 'L'){
                vector<p> v;
                legal(table,v,suit);
                if(!v.size()) cout << "No legal move.\n";
                else{
                    for(int i = 0; i < v.size(); i++){
                        if(i) cout << ' ';
                        cout << '(' << v[i].x+1 << ',' << v[i].y+1 << ')';
                    }
                    cout << endl;
                }
            }
            else if(command == 'M'){
                char i,j;
                cin >> i >> j;
                i-='0'+1; j-='0'+1;
                if(!play(table,i,j,suit)){
                    suit = (suit == 'W')? 'B':'W';
                    play(table,i,j,suit);
                }
                int b = 0,w = 0;
                for(int i = 0; i < 8; i++){
                    for(int j = 0; j < 8; j++){
                        if(table[i][j] == 'W') w++;
                        else if(table[i][j] == 'B') b++;
                    }
                }
                suit = (suit == 'W')? 'B':'W';
                cout << "Black - " << setw(2) << b << " White - " << setw(2) << w << endl;
            }
            else if(command == 'Q'){
                for(int i = 0; i < 8; i++){
                    for(int j = 0; j < 8; j++){
                        cout << table[i][j];
                    }
                    cout << endl;
                }
                break;
            }
        }
    }
    return 0;
}
