#include<iostream>
#include<bitset>
#include<iomanip>
using namespace std;

int main(){
    int n;
    bool beg = false;
    while(cin >> n && n){
        if(beg) cout << endl;
        else beg = true;
        bool shown = false;
        for(int i = 1234; i <= 98765/n ; i++){
            int c = i;
            int x = n*i;
            //cout << i << ' ' << x << endl;
            bitset<10> b;
            int p1 = c, p2 = x;
            for(int i = 0; i < 5; i++){
                int l = c%10;
                int m = x%10;
                b[l]=true;b[m]=true;
                c /=10;
                x /=10;
            }
            if(b.count() == 10){
                shown = true;
                cout << p2 << " / " << setw(5) << setfill('0') <<p1 << " = " << n << endl;
                //i = ((i/10000)+1)*10000;
            }
        }
        if(!shown)cout << "There are no solutions for "<<n<<".\n";
    }
    return 0;
}
