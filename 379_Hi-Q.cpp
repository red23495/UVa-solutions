#include<iostream>

using namespace std;

void parser(int index, int& r , int &c){
    if(index < 4) {r = 0; c = 1+index;}
    else if(index >3 && index <7) {r = 1; c = ((index-1)%3)+2;}
    else if(index > 6 && index < 14) {r = 2; c = index - 7;}
    else if(index > 13 && index < 21) {r = 3; c = index - 14;}
    else if(index > 20 && index < 28) {r = 4; c = index - 21;}
    else if(index > 27 && index < 31) {r = 5; c = index - 26;}
    else{ r = 6; c = index - 29;}
}

bool check(int (&table)[7][7], int r, int c){
    if(r<5){
        if(table[r+1][c] == 1 && table[r+2][c] == 1){
            table[r+1][c] = 0; table[r+2][c] = 0;
            table[r][c] = 1;
            return true;
        }
    }
    if(c < 5){
        if(table[r][c+1] == 1 && table[r][c+2] == 1){
            table[r][c+1] = 0; table[r][c+2] = 0;
            table[r][c] = 1;
            return true;
        }
    }
    if(c > 1){
        if(table[r][c-1] == 1 && table[r][c-2] == 1){
            table[r][c-1] = 0; table[r][c-2] = 0;
            table[r][c] = 1;
            return true;
        }
    }
    if(r>1){
        if(table[r-1][c] == 1 && table[r-2][c] == 1){
            table[r-1][c] = 0; table[r-2][c] = 0;
            table[r][c] = 1;
            return true;
        }
    }
    return false;
}

int main()
{
    int test;
    cout << "HI Q OUTPUT\n";
    cin >> test;
    while(test--){
        int table[7][7] =
        { {-1,-1, 0, 0, 0,-1,-1},
          {-1,-1, 0, 0, 0,-1,-1},
          { 0, 0, 0, 0, 0, 0, 0},
          { 0, 0, 0, 0, 0, 0, 0},
          { 0, 0, 0, 0, 0, 0, 0},
          {-1,-1, 0, 0, 0,-1,-1},
          {-1,-1, 0, 0, 0,-1,-1} };
        int in;
        while (cin >> in && in) {
            int r,c;
            parser(in,r,c);
            table[r][c] = 1;
        }
        int start = 33;
        while(start){
            int r,c;
            parser(start,r,c);
            if(table[r][c] == 0){
                if(check(table,r,c)){
                    start = 33; continue;
                }
            }
            start--;
        }
        int c = 0, sum = 0;
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 7; j++){
                if(table[i][j] != -1){
                    c++;
                    if(table[i][j] == 1) sum+=c;
                }
            }
        }
        cout << sum << endl;
    }
    cout << "END OF OUTPUT\n";
    return 0;
}
