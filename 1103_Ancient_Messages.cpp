#include<bits/stdc++.h>

using namespace std;

vector<vector<char>> v,slate;

string hex2bin(char c){
    if(c == '0') return "0000";
    if(c == '1') return "0001";
    if(c == '2') return "0010";
    if(c == '3') return "0011";
    if(c == '4') return "0100";
    if(c == '5') return "0101";
    if(c == '6') return "0110";
    if(c == '7') return "0111";
    if(c == '8') return "1000";
    if(c == '9') return "1001";
    if(c == 'a') return "1010";
    if(c == 'b') return "1011";
    if(c == 'c') return "1100";
    if(c == 'd') return "1101";
    if(c == 'e') return "1110";
    if(c == 'f') return "1111";
}

int h,w,test;
vector<char> ans;

char name(int hole){
    switch(hole){
        case 1: return 'A';
        case 3: return 'J';
        case 5: return 'D';
        case 4: return 'S';
        case 0: return 'W';
        case 2: return 'K';
    }
}

void segmentize(int r, int c){
    if(v[r][c] != '1') return;
    slate[r+1][c+1] = '1';
    v[r][c] = '.';
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            int x = r+i; int y = c + j;
            if(x >= 0 && x < h && y >= 0 && y < 4*w && v[x][y] == '1' && (x == r || y == c)){
                segmentize(x,y);
            }
        }
    }
    //if(r > 0 && v[r-1][c] == '1') segmentize(r-1,c);
    //if(r < h-1 && v[r+1][c] == '1') segmentize(r+1,c);
    //if(c > 0 && v[r][c-1] == '1') segmentize(r,c-1);
    //if(c > 4*w-1 && v[r][c+1] == '1') segmentize(r,c+1);
    //if(r > 0 && c > 0 && v[r-1][c-1] == '1') segmentize(r-1,c-1);
    //if(r < h-1 && c < 4*w-1 && v[r+1][c+1] == '1') segmentize(r+1,c+1);
    //if(r > 0 && c < 4*w-1 && v[r-1][c+1] == '1') segmentize(r-1,c+1);
    //if(r < h-1 && c > 0 && v[r+1][c-1] == '1') segmentize(r+1,c-1);
}

void remove_background(int r, int c){
    //if(slate[r][c] != '0') return;
    slate[r][c] = '.';
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            int x = r+i; int y = c + j;
            if(x >= 0 && x < h+4 && y >= 0 && y < 4*w+4 && slate[x][y] == '0'){
                remove_background(x,y);
            }
        }
    }
    //if(r > 0 && slate[r-1][c] == '0') remove_background(r-1,c);
    //if(r < h+1 && slate[r+1][c] == '0') remove_background(r+1,c);
    //if(c > 0 && slate[r][c-1] == '0') remove_background(r,c-1);
    //if(c > 4*w+1 && slate[r][c+1] == '0') remove_background(r,c+1);
    //if(r > 0 && c > 0 && slate[r-1][c-1] == '0') remove_background(r-1,c-1);
    //if(r < h+1 && c < 4*w+1 && slate[r+1][c+1] == '0') remove_background(r+1,c+1);
    //if(r > 0 && c < 4*w+1 && slate[r-1][c+1] == '0') remove_background(r-1,c+1);
    //if(r < h+1 && c > 0 && slate[r+1][c-1] == '0') remove_background(r+1,c-1);
}

int main(){
    while(cin >> h >> w && h){
        v.assign(h,vector<char>(4*w));
        for(int i = 0; i < h; i++){
            for(int j = 0; j < 4*w; j+=4){
                char c;
                cin >> c;
                string s = hex2bin(c);
                for(int k = 0; k < 4; k++) v[i][j+k] = s[k];
            }
        }
        /*for(auto x: v){
            for(auto y: x){
                cout << y ;
            }
            cout << endl;
        }*/
        ans.clear();
        for(int i = 0; i < h; i++){
            for(int j = 0; j < 4*w; j++){
                if(v[i][j] == '1'){
                    slate.clear();
                    slate.resize(h+4,vector<char>(4*w+4,'0'));
                    segmentize(i,j);
                    remove_background(h+3,4*w+3);
                    int count = 0;
                    for(int a = 0; a < h+4; a++){
                        for(int b = 0; b < 4*w+4; b++){
                            if(slate[a][b] == '0'){
                                remove_background(a,b);
                                count++;
                            }
                        }
                    }
                    ans.push_back(name(count));
                }
            }
        }
        sort(ans.begin(),ans.end());
        cout << "Case " << ++test << ": ";
        for(auto x: ans) cout << x;
        cout << endl;
    }
}
