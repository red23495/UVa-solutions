#include<iostream>
#include<array>
#include<limits>
using namespace std;

long long s,d,t;

void backtrack(int i, array<long long,12> l){
    if(i > 4 && (l[i-1]+l[i-2]+l[i-3]+l[i-4]+l[i-5]) >= 0) return;
    if(i == 12) {
        long long s = 0;
        for(long long x: l) s+= x;
        if(s > t) t = s;
        return;
    }
    auto x  = l;
    auto y  = l;
    x[i] = s;
    y[i] = -d;
    backtrack(i+1,x);
    backtrack(i+1,y);
}

int main(){
    while(cin >> s >> d){
        t = numeric_limits<long long>::min();
        backtrack(0,array<long long,12>());
        if(t >= 0)cout << t << endl;
        else cout << "Deficit\n";
    }
}
