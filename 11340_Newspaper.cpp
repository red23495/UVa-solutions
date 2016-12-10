#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int t = 0;
    cin >> t;
    while(t--){
        int k,m;
        cin >> k;
        int c[256] = {};
        for(int i = 0; i < k; i++){
            int cost; unsigned char cc;
            cin >> cc >> cost;
            c[cc] = cost;
        }
        int nl = 0;
        int cost = 0;
        cin >> m;
        while(cin.peek() == 10) cin.ignore();
        while(nl < m){
            unsigned char ch = cin.get();
            if(ch == '\n') nl++;
            else cost += c[ch];
        }
        double r = cost/100.0;
        cout << fixed << setprecision(2) << r << '$' <<endl;
    }
    return 0;
}
