#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

class table{
    int row;
    int column;
    vector<vector<char>> v;
    void large(int& x1, int& x2){if(x1>x2){int t = x1; x1 = x2; x2 = t;}}
    void fill(int x, int y, char cc, char lc);
public:
    table(int,int);
    void clear();
    void point(int,int,char);
    void hline(int,int,int,char);
    void vline(int,int,int,char);
    void rect(int,int,int,int,char);
    void fill(int x,int y,char c);
    void print();
};

table::table(int r, int c){
    row = r;
    column = c;
    v = vector<vector<char>>(r,vector<char>(c,'O'));
}

void table::clear(){
    for(auto &c: v){
        for(auto &d: c){
            d = 'O';
        }
    }
}

void table::point(int x, int y, char c){
    v[y][x] = c;
}

void table::hline(int x1, int x2, int y, char c){
    large(x1,x2);
    for(int i = x1; i <= x2; i++){
        v[y][i] = c;
    }
}

void table::vline(int x, int y1, int y2, char c){
    large(y1,y2);
    for(int i = y1; i <= y2; i++){
        v[i][x] = c;
    }
}

void table::rect(int x1,int x2, int y1, int y2, char c){
    for(int i = y1; i <= y2; i++){
        for(int j = x1; j <= x2; j++){
            v[i][j] = c;
        }
    }
}

void table::fill(int x, int y, char c){
    if(c == v[y][x]) return;
    char lc = v[y][x];
    fill(x,y,c,lc);
}

void table::fill(int x, int y,char cc, char lc){
    if(v[y][x] != lc) return;
    else v[y][x] = cc;
    if(x > 0 ) fill(x-1,y,cc,lc);
    if(x < column-1) fill(x+1,y,cc,lc);
    if(y > 0 ) fill(x,y-1,cc,lc);
    if(y < row-1) fill(x,y+1,cc,lc);
}

void table::print(){
    for(auto &c: v){
        for(auto &d: c){
            cout << d;
        }
        cout << endl;
    }
}

int main()
{
    string s;
    table* b = nullptr;
    while(getline(cin,s,'\n') && s[0] != 'X'){
        stringstream ss(s);
        char comm;
        ss >> comm;
        int x,y,x1,x2,y1,y2;char c;
        switch(comm){
        case 'I':
            int row,column;
            ss >> column >> row;
            if(b != nullptr) delete b;
            b = new table(row,column);
            break;
        case 'C':
            b->clear();
            break;
        case 'L':
            ss >> x >> y >> c;
            x--;y--;
            b->point(x,y,c);
            break;
        case 'V':
            ss >> x >> y1 >> y2 >> c;
            x--;y1--;y2--;
            b->vline(x,y1,y2,c);
            break;
        case 'H':
            ss >> x1 >> x2 >> y >> c;
            x1--;x2--;y--;
            b->hline(x1,x2,y,c);
            break;
        case 'K':
            ss >> x1 >> y1 >> x2 >> y2 >> c;
            x1--;y1--;x2--;y2--;
            b->rect(x1,x2,y1,y2,c);
            break;
        case 'F':
            ss >> x >> y >> c;
            x--;y--;
            b->fill(x,y,c);
            break;
        case 'S':
            string n;
            ss >> n;
            cout << n << endl;
            b->print();
            break;
        }
    }
    if(b != nullptr) delete b;
    return 0;
}
