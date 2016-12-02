#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

unordered_map<char,char> weak = {{'S','R'},{'R','P'},{'P','S'}};

using vc = vector<char>;
using vvc = vector<vc>;

char war(vvc &m, int r, int c){
    char s = weak[m[r][c]];
    if(r > 0 &&  m[r-1][c] == s) return s;
    if(r < m.size()-1 &&  m[r+1][c] == s) return s;
    if(c > 0 &&  m[r][c-1] == s) return s;
    if(c < m[r].size()-1 &&  m[r][c+1] == s) return s;
    return m[r][c];
}

int main()
{
    int test;
    cin >> test;
    while(test--){
        int r, c , d;
        cin >> r >> c >> d;
        vvc v(r,vc(c));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> v[i][j];
            }
        }
        while(d--){
            vvc temp(r,vc(c,0));
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    temp[i][j] = war(v,i,j);
                }
            }
            v = temp;
        }
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cout << v[i][j];
            }
            cout << endl;
        }
        if(test) cout << endl;
    }
    return 0;
}
