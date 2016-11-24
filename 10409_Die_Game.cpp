#include<iostream>
#include<string>

using namespace std;

int main()
{
    int c;
    while(cin >> c && c){
        int top = 1, bottom = 6, north = 2, south = 5, east = 4, west = 3;
        for(int i = 0; i < c; i++){
            string str;
            int t = top;
            cin >> str;
            switch(str[0]){
            case 'n':
                top = south;
                south = bottom;
                bottom = north;
                north = t;
                break;
            case 's':
                top = north;
                north = bottom;
                bottom = south;
                south = t;
                break;
            case 'e':
                top = west;
                west = bottom;
                bottom = east;
                east = t;
                break;
            case 'w':
                top = east;
                east = bottom;
                bottom = west;
                west = t;
                break;
            }
        }
        cout << top << endl;
    }
    return 0;
}
