#include<bits/stdc++.h>

using namespace std;

unsigned long long memo[31];
unsigned long long memo2[31];
unsigned long long fact(unsigned long long i){
    if(i == 0) return 1;
    memo[i] = i*fact(i-1);
    return memo[i];
}

unsigned long long derange(unsigned long long i){
    if(i == 0) return 1;
    if(i == 1) return 0;
    if(i == 2) return 1;
    memo2[i] = (i-1)*(derange(i-1)+derange(i-2));
    return memo2[i];
}

int main(){
    memo[0] = memo[1] = 1;
    memo2[0] = memo2[2] = 1;
    fact(30);
    derange(30);
    int n;
    for(int i = 0; i <= 20; i++){
        double p = double(memo[i] - memo2[i])/double(memo[i]);
        cout << i << ' ' << fixed << setprecision(10) << p << endl;
    }
    return 0;
}
