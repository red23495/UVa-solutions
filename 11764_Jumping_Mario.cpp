#include<iostream>

using namespace std;

int main(){
    int test;
    cin >> test;
    for(int i = 1; i <= test; i++){
        int no;
        cin >> no;
        int cur,last;
        int hi = 0;
        int lo = 0;
        cin >> last;
        for(int i = 1; i < no ; i++){
            cin >> cur;
            if((cur - last) > 0) hi++;
            else if((cur - last) < 0) lo++;
            last = cur;
        }
        cout << "Case " << i << ": " << hi << ' ' << lo << endl;
    }
    return 0;
}
