#include<iostream>
#include<vector>

using namespace std;

int main()
{
    long long n,m,c,count;
    count = 0;
    while(cin >> n >> m >> c && (n || m || c)){
        count++;
        vector<long long> power(n);
        vector<bool> state(n,false);
        for(auto& c: power) cin >> c;
        long long high = 0;
        long long p = 0;
        for(long long i = 0; i < m ; i++){
            long long s;
            cin >> s;
            if(p > c) continue;
            if(state[s-1]){
                state[s-1] = false;
                p -= power[s-1];
            }
            else {
                state[s-1] = true;
                p += power[s-1];
            }
            if(high < p) high = p;
        }
        cout << "Sequence "<< count << endl;
        if(p > c) cout << "Fuse was blown.\n";
        else{
            cout << "Fuse was not blown.\nMaximal power consumption was "<<high<<" amperes.\n";
        }
        cout << endl;
    }
    return 0;
}
