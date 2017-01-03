#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    int a;
    set<int> p[181],c[181];
    int arr[63] = {};
    for(int i = 1; i <= 20; i++){
        arr[i] = i;
        arr[i*2] = i*2;
        arr[i*3] = i*3;
    }
    arr[61] = 50;
    for(int i = 0; i <= 61; i++){
        for(int j = 0; j <= 61; j++){
            for(int k = 0; k <= 61; k++){
                int l,m = arr[i],n = arr[j], o = arr[k];
                l = ((((0|m) << 8)|n)<<8)|o;
                p[m+n+o].insert(l);
                int a[3] = {m,n,o};
                sort(a,a+3);
                l = ((((0|a[0]) << 8)|a[1])<<8)|a[2];
                c[m+n+o].insert(l);
            }
        }
    }
    while(cin >> a && a > 0){
        if(a > 180 || !c[a].size()) cout << "THE SCORE OF "<<a<<" CANNOT BE MADE WITH THREE DARTS.\n";
        else{
            //for(auto x: c[a]) cout << (x >> 16) << ' ' << ((x << 16) >> 24) << ' ' << ((x << 24) >> 24) << endl;
            cout << "NUMBER OF COMBINATIONS THAT SCORES "<<a<<" IS "<<c[a].size()<<".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES "<<a<<" IS "<<p[a].size()<<".\n";
        }
        cout << "**********************************************************************\n";
    }
    cout << "END OF OUTPUT\n";
}
