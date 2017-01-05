#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    int test = 0;
    int tower,build;
    while(cin >> tower >> build && (tower||build)){
        cout << "Case Number  "<<++test<< endl;
        vector<int> v(tower+1);
        map<int,int> m;
        for(int i = 0; i < tower; i++) cin >> v[i];
        int q;
        cin >> q;
        while(q--){
            int x;
            cin >> x;
            int mm = 0;
            while(x--){
                int n;
                cin >> n;
                mm |= (1 << (n-1));
            }
            int pop;
            cin >> pop;
            m[mm] = pop;
        }
        int max = 0;
        int maxcomb;
        for(int i = 1; i < (1 << tower); i++){
            if(__builtin_popcount(i) == build){
                int total = 0;
                for(int j = 0; j < tower; j++){
                    if(i & (1<<j)) total+= v[j];
                }
                for(auto x: m){
                    int t = __builtin_popcount(x.first & i);
                    if(t > 1){
                        if(t & 1) total+= x.second;
                        else total-=x.second;
                    }
                }
                if(total > max){
                    max = total;
                    maxcomb = i;
                }
            }
        }
        auto lambda = [tower](int x, int y){
            for(int i = 0; i < tower; i++){
                int a = (1<<i);
                if(x&a && !(y&a)) return true;
                else if(y&a && !(x&a)) return false;
            }
            return true;
        };
        cout << "Number of Customers: " <<max << endl;
        cout << "Locations recommended:";
        for(int i = 0; i < tower; i++){
            if(maxcomb & (1<<i)) cout << ' ' << i+1;
        }
        cout << endl << endl;
    }
}
