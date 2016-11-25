#include<iostream>
#include<vector>
#include<array>
using namespace std;

bool angle1(array<array<bool,50>,50> pat1, array<array<bool,50>,50> pat2, int dim){
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(pat1[i][j] != pat2[i][j]) return false;
        }
    }
    return true;
}

bool angle2(array<array<bool,50>,50> pat1, array<array<bool,50>,50> pat2, int dim){
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(pat1[i][j] != pat2[j][dim-1-i]) return false;
        }
    }
    return true;
}

bool angle3(array<array<bool,50>,50> pat1, array<array<bool,50>,50> pat2, int dim){
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(pat1[i][j] != pat2[dim-1-j][i]) return false;
        }
    }
    return true;
}

bool angle4(array<array<bool,50>,50> pat1, array<array<bool,50>,50> pat2, int dim){
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(pat1[i][j] != pat2[dim-1-i][dim-1-j]) return false;
        }
    }
    return true;
}

int main()
{
    int dim;
    while(cin >> dim && dim){
        array<array<bool,50>,50> board = {};
        vector<array<array<bool,50>,50>> pat;
        bool check = false;
        for(int i = 1; i <= 2*dim; i++){
            int x,y;
            char s;
            cin >> x >> y >> s;
            if(!check){
                x--;y--;
                if(s=='+') board[y][x] = true;
                else board[y][x] = false;
                for(auto p: pat){
                    check = angle1(board,p,dim)||angle2(board,p,dim)||angle3(board,p,dim)||angle4(board,p,dim);
                    if(check) break;
                }
                if(check) cout << "Player " << (i%2)+1 <<" wins on move " << i <<endl;
                else pat.push_back(board);
            }
        }
        if(!check) cout << "Draw\n";
    }
    return 0;
}
