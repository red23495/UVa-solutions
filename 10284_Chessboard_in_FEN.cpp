#include<iostream>
#include<string>
#include<cctype>
#include<cmath>
using namespace std;
class board{
    char a[8][8];
    void board_check();
    void check_horizontal(int x, int y);
    void check_vertical(int x, int y);
    void check_diagonal(int x, int y);
    void check_knight(int x, int y);
    void check_black_pawn(int x, int y);
    void check_white_pawn(int x, int y);
    void check_king(int x,int y);
public:
    board(string& s);
    int free_space();
};

board::board(string& s){
    int x = 0, y = 0;
    for(char c: s){
        if(isdigit(c)){
            for(int i = 0; i < c - '0'; i++){
                a[x][y++] = 0;
            }
        }
        else if(c == '/'){
            x++;y=0;
        }
        else a[x][y++] = c;
    }
    board_check();
}

void board::board_check(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            switch(a[i][j]){
                case 'Q':
                case 'q':
                    check_horizontal(i,j);
                    check_vertical(i,j);
                    check_diagonal(i,j);
                    break;
                case 'R':
                case 'r':
                    check_horizontal(i,j);
                    check_vertical(i,j);
                    break;
                case 'B':
                case 'b':
                    check_diagonal(i,j);
                    break;
                case 'N':
                case 'n':
                    check_knight(i,j);
                    break;
                case 'K':
                case 'k':
                    check_king(i,j);
                    break;
                case 'P':
                    check_white_pawn(i,j);
                    break;
                case 'p':
                    check_black_pawn(i,j);
                    break;
            }
        }
    }
}

void board::check_horizontal(int x, int y){
    for(int i = y+1; i < 8; i++){
        if(a[x][i] == 0) a[x][i] = 1;
        else if(a[x][i] != 1) break;
    }
    for(int i = y-1; i >= 0; i--){
        if(a[x][i] == 0) a[x][i] = 1;
        else if(a[x][i] != 1) break;
    }
}

void board::check_vertical(int x, int y){
    for(int i = x+1; i < 8; i++){
        if(a[i][y] == 0) a[i][y] = 1;
        else if(a[i][y] != 1) break;
    }
    for(int i = x-1; i >= 0; i--){
        if(a[i][y] == 0) a[i][y] = 1;
        else if(a[i][y] != 1) break;
    }
}

void board::check_diagonal(int x, int y){
    for(int i = x+1, j = y+1; i < 8 && j < 8; i++, j++){
        if(a[i][j] == 0) a[i][j] = 1;
        else if(a[i][j] != 1) break;
    }
    for(int i = x-1, j = y-1; i >= 0 && j >= 0; i--, j--){
        if(a[i][j] == 0) a[i][j] = 1;
        else if(a[i][j] != 1) break;
    }
    for(int i = x+1, j = y-1; i < 8 && j >= 0; i++, j--){
        if(a[i][j] == 0) a[i][j] = 1;
        else if(a[i][j] != 1) break;
    }
    for(int i = x-1, j = y+1; i >= 0 && j < 8; i--, j++){
        if(a[i][j] == 0) a[i][j] = 1;
        else if(a[i][j] != 1) break;
    }
}

void board::check_king(int x, int y){
    for(int i = x-1; i <x+2; i++){
        for(int j = y-1; j < y+2; j++){
            if(i >= 0 && j >= 0 && i < 8 && j < 8){
                if(a[i][j] == 0) a[i][j] = 1;
            }
        }
    }
}

void board::check_knight(int x, int y){
    if(x+2 < 8){
        if(y+1 < 8)
            if(a[x+2][y+1]==0) if(a[x+2][y+1] == 0)a[x+2][y+1] = 1;
        if(y-1 >= 0)
            if(a[x+2][y-1]==0) if(a[x+2][y-1] == 0)a[x+2][y-1] = 1;
    }
    if(x-2 >= 0){
        if(y+1 < 8)
            if(a[x-2][y+1]==0) if(a[x-2][y+1] == 0)a[x-2][y+1] = 1;
        if(y-1 >= 0)
            if(a[x-2][y-1]==0) if(a[x-2][y-1] == 0)a[x-2][y-1] = 1;
    }
    if(y+2 < 8){
        if(x+1 < 8)
            if(a[x+1][y+2]==0) if( a[x+1][y+2]== 0)a[x+1][y+2] = 1;
        if(x-1 >= 0)
            if(a[x-1][y+2]==0) if( a[x-1][y+2]== 0)a[x-1][y+2] = 1;
    }
    if(y-2 >= 0){
        if(x+1 < 8)
            if(a[x+1][y-2]==0) if(a[x+1][y-2] == 0)a[x+1][y-2] = 1;
        if(x-1 >= 0)
            if(a[x-1][y-2]==0) if(a[x-1][y-2] == 0)a[x-1][y-2] = 1;
    }
}

void board::check_black_pawn(int x, int y){
    if(x+1 < 8){
        if(y-1 >= 0){
            if(a[x+1][y-1] == 0)a[x+1][y-1] = 1;
        }
        if(y+1 < 8){
            if(a[x+1][y+1] == 0)a[x+1][y+1] = 1;
        }
    }
}

void board::check_white_pawn(int x, int y){
    if(x-1 >= 0){
        if(y-1 >= 0){
            if(a[x-1][y-1] == 0)a[x-1][y-1] = 1;
        }
        if(y+1 < 8){
            if(a[x-1][y+1] == 0)a[x-1][y+1] = 1;
        }
    }
}

int board::free_space(){
    int c = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(a[i][j] == 0) c++;
        }
    }
    return c;
}

int main(){
    string str;
    while(cin >> str){
        board b(str);
        int c = b.free_space() ;
        cout << c << endl;
    }
    return 0;
}
