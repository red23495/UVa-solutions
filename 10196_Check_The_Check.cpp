#include<iostream>
#include<cctype>
using namespace std;

struct pos{
    int x;
    int y;
    char s;
    pos(){x=-1;y=-1;s=0;}
    void set(int a, int b, char c){x=a;y=b;s=c;}
};

class board{
    char a[8][8];
    pos kw,kb;
    bool up(pos);
    bool down(pos);
    bool left(pos);
    bool right(pos);
    bool dig1up(pos);
    bool dig1down(pos);
    bool dig2up(pos);
    bool dig2down(pos);
    bool knights(pos);
    bool pawn(pos);
    bool check(pos);
public:
    board();
    bool empty();
    bool black_check();
    bool white_check();
};

bool board::empty(){
    if(kw.x == -1) return true;
    return false;
}

board::board(){
    kw;kb;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> a[i][j];
            if(a[i][j] == 'k') kb.set(i,j,'k');
            else if(a[i][j] == 'K') kw.set(i,j,'K');
        }
    }
}

bool board::up(pos k){
    for(int i = k.x-1; i >= 0; i--){
        if(a[i][k.y]!='.'){
            if(k.s == 'k'){
                if(a[i][k.y] == 'Q' || a[i][k.y] == 'R')
                    return true;
                else return false;
            }
            if(k.s == 'K'){
                if(a[i][k.y] == 'q' || a[i][k.y] == 'r')
                    return true;
                else return false;
            }
        }
    }
    return false;
}

bool board::down(pos k){
    for(int i = k.x+1; i < 8; i++){
        if(a[i][k.y]!='.'){
            if(k.s == 'k'){
                if(a[i][k.y] == 'Q' || a[i][k.y] == 'R')
                    return true;
                else return false;
            }
            if(k.s == 'K'){
                if(a[i][k.y] == 'q' || a[i][k.y] == 'r')
                    return true;
                else return false;
            }
        }
    }
    return false;
}

bool board::left(pos k){
    for(int i = k.y-1; i >= 0; i--){
        if(a[k.x][i]!='.'){
            if(k.s == 'k'){
                if(a[k.x][i] == 'Q' || a[k.x][i] == 'R')
                    return true;
                else return false;
            }
            if(k.s == 'K'){
                if(a[k.x][i] == 'q' || a[k.x][i] == 'r')
                    return true;
                else return false;
            }
        }
    }
    return false;
}

bool board::right(pos k){
    for(int i = k.y+1; i < 8; i++){
        if(a[k.x][i]!='.'){
            if(k.s == 'k'){
                if(a[k.x][i] == 'Q' || a[k.x][i] == 'R')
                    return true;
                else return false;
            }
            if(k.s == 'K'){
                if(a[k.x][i] == 'q' || a[k.x][i] == 'r')
                    return true;
                else return false;
            }
        }
    }
    return false;
}

bool board::dig1up(pos k){
    for(int i = k.x-1 , j = k.y-1 ; i >= 0 && j >= 0; i--,j--){
        if(a[i][j]!='.'){
            if(k.s == 'k'){
                if(a[i][j] == 'Q' || a[i][j] == 'B')
                    return true;
                else return false;
            }
            if(k.s == 'K'){
                if(a[i][j] == 'q' || a[i][j] == 'b')
                    return true;
                else return false;
            }
        }
    }
    return false;
}

bool board::dig1down(pos k){
    for(int i = k.x+1 , j = k.y+1 ; i < 8 && j < 8; i++,j++){
        if(a[i][j]!='.'){
            if(k.s == 'k'){
                if(a[i][j] == 'Q' || a[i][j] == 'B')
                    return true;
                else return false;
            }
            if(k.s == 'K'){
                if(a[i][j] == 'q' || a[i][j] == 'b')
                    return true;
                else return false;
            }
        }
    }
    return false;
}

bool board::dig2up(pos k){
    for(int i = k.x-1 , j = k.y+1 ; i >= 0 && j < 8; i--,j++){
        if(a[i][j]!='.'){
            if(k.s == 'k'){
                if(a[i][j] == 'Q' || a[i][j] == 'B')
                    return true;
                else return false;
            }
            if(k.s == 'K'){
                if(a[i][j] == 'q' || a[i][j] == 'b')
                    return true;
                else return false;
            }
        }
    }
    return false;
}

bool board::dig2down(pos k){
    for(int i = k.x+1 , j = k.y-1 ; i < 8 && j >= 0; i++,j--){
        if(a[i][j]!='.'){
            if(k.s == 'k'){
                if(a[i][j] == 'Q' || a[i][j] == 'B')
                    return true;
                else return false;
            }
            if(k.s == 'K'){
                if(a[i][j] == 'q' || a[i][j] == 'b')
                    return true;
                else return false;
            }
        }
    }
    return false;
}

bool board::knights(pos k){
    if(k.y != 0){
        if(k.x+2 < 8){
            if(k.s == 'k'){
                if(a[k.x+2][k.y-1] == 'N') return true;
            }
            else if(k.s == 'K'){
                if(a[k.x+2][k.y-1] == 'n') return true;
            }
        }
        if(k.x-2 >= 0){
            if(k.s == 'k'){
                if(a[k.x-2][k.y-1] == 'N') return true;
            }
            else if(k.s == 'K'){
                if(a[k.x-2][k.y-1] == 'n') return true;
            }
        }
        if(k.y != 1){
            if(k.x+1 < 8){
                if(k.s == 'k'){
                    if(a[k.x+1][k.y-2] == 'N') return true;
                }
                else if(k.s == 'K'){
                    if(a[k.x+1][k.y-2] == 'n') return true;
                }
            }
            if(k.x-1 >= 0){
                if(k.s == 'k'){
                    if(a[k.x-1][k.y-2] == 'N') return true;
                }
                else if(k.s == 'K'){
                    if(a[k.x-1][k.y-2] == 'n') return true;
                }
            }
        }
    }
    if(k.y != 7){
        if(k.x+2 < 8){
            if(k.s == 'k'){
                if(a[k.x+2][k.y+1] == 'N') return true;
            }
            else if(k.s == 'K'){
                if(a[k.x+2][k.y+1] == 'n') return true;
            }
        }
        if(k.x-2 >= 0){
            if(k.s == 'k'){
                if(a[k.x-2][k.y+1] == 'N') return true;
            }
            else if(k.s == 'K'){
                if(a[k.x-2][k.y+1] == 'n') return true;
            }
        }
        if(k.y != 6){
            if(k.x+1 < 8){
                if(k.s == 'k'){
                    if(a[k.x+1][k.y+2] == 'N') return true;
                }
                else if(k.s == 'K'){
                    if(a[k.x+1][k.y+2] == 'n') return true;
                }
            }
            if(k.x-1 >= 0){
                if(k.s == 'k'){
                    if(a[k.x-1][k.y+2] == 'N') return true;
                }
                else if(k.s == 'K'){
                    if(a[k.x-1][k.y+2] == 'n') return true;
                }
            }
        }
    }
    return false;
}

bool board::pawn(pos k){
    if(k.y != 0){
        if(k.s == 'k'){
            if(a[k.x+1][k.y-1] == 'P') return true;
        }
        else{
            if(a[k.x-1][k.y-1] == 'p') return true;
        }
    }
    if(k.y != 7){
        if(k.s == 'k'){
            if(a[k.x+1][k.y+1] == 'P') return true;
        }
        else{
            if(a[k.x-1][k.y+1] == 'p') return true;
        }
    }
    return false;
}

bool board::check(pos k){
    return (up(k)||down(k)||left(k)||right(k)||dig1up(k)||dig1down(k)||dig2up(k)||dig2down(k)||knights(k)||pawn(k));
}

bool board::black_check(){
    return check(kb);
}

bool board::white_check(){
    return check(kw);
}

int main(){
    unsigned long long test = 0;
    while(++test){
        board b;
        if(b.empty()) break;
        cout <<"Game #" << test <<": ";
        if(b.black_check()) cout << "black";
        else if(b.white_check()) cout << "white";
        else cout << "no";
        cout << " king is in check.\n";
    }
    return 0;
}
