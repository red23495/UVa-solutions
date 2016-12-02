#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int h , m;
        char c;
        cin >> h >> c >> m;
        int h1,h2,m1,m2;
        h1 = h/10; m1 = m/10;
        h2 = h%10; m2 = m%10;
        int rh,rm;
        if(h == 0){
            if(m==0) {rh = 0; rm = 1;}
            else if(m < 9) {rh = 0; rm = m+1;}
            else if(m < 55){rh = 0; rm = ((m/11)+1)*11;}
            else {rh = 1; rm = 1;}
        }
        else if(h < 10){
            int nm = m1*10+h2;
            if(h == 9 && m == 59){rh = 10; rm = 1;}
            else if(nm > m) {rh = h; rm = nm;}
            else if(nm+10 < 60){rh = h; rm = nm+10;}
            else {rh = h+1; rm = h+1;}
        }
        else{
            int nm = (h2*10)+h1;
            if(h == 23 && m >= 32) {rh = 0; rm = 0;}
            else if(nm > m && nm < 60){rh = h; rm = nm;}
            else if(h < 15 || h > 18){
                rh = h+1;
                int nh1,nh2;
                nh1 = rh/10;
                nh2 = rh%10;
                rm = (nh2*10)+nh1;
            }
            else{rh = 20; rm = 2;}
        }
        cout << setw(2) << setfill('0') << rh << ':' << setw(2) << setfill('0') << rm << endl;
    }
    return 0;
}
