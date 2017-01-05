#include<iostream>
#include<vector>

using namespace std;

int p[10] = {3,5,7,11,13,17,19,23,29,31};
int n;
bool prime(int n){
    for(int i = 0; i < 10; i++){
        if(n == p[i]) return true;
    }
    return false;
}

vector<int> r;

void ring(int in, int c){
    if(in == n){
        if(!prime(r[0]+r[r.size()-1])) return;
        for(int i = 0; i < n; i++){
            if(i) cout << ' ';
            cout << r[i];
        }
        cout << endl;
        return;
    }
    for(int i = 2; i <= n; i++){
        if(!(c & (1 << i)) && prime(r[in-1]+i)){
            r[in] = i;
            ring(in+1,(c |(1 << i)));
        }
    }
}

int main(){
    int test = 0;
    while(cin >> n){
        if (test) cout << endl;
        cout << "Case "<<++test<<":\n";
        r.resize(n);
        r[0] = 1;
        ring(1,2);
    }
}
