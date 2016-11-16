#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int r,c;
    while(cin >> r >> c && (r || c)){
        if(c == 1 || r == 1) cout << (c*r);
        else if(c == 2 || r == 2){
            auto x = (r != 2)?r:c;
            switch(x%4){
            case 0:
                cout << x;
                break;
            case 1:
                cout << (x/4)*4+2;
                break;
            default:
                cout << (x/4)*4+4;
                break;
            }
        }
        else cout << int(ceil((double)(r*c)/2));
        cout << " knights may be placed on a "<<r<<" row "<<c<<" column board." << endl;
    }
    return 0;
}
