#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int find(int arr[8], int val){
    for(int i = 0; i < 8; i++){
        if(arr[i] == val) return i;
    }
}

struct x{
    int a;
    int b;
    int c;
};

int main(){
    int n,m;
    while(cin >> n >> m && (n || m)){
        int arr[8] = {0,1,2,3,4,5,6,7};
        vector<x> v(m);
        while(m--){
            cin >> v[m].a >> v[m].b >> v[m].c;
        }
        int count = 0;
        do{
            bool c = true;
            for(int i = 0; i < v.size() && c; i++){
                int a = find(arr,v[i].a), b = find(arr,v[i].b);
                if(v[i].c < 0){
                    if(int(abs(a - b)) < -v[i].c) c = false;
                }
                if(v[i].c > 0){
                    if(int(abs(a - b)) > v[i].c) c = false;
                }
            }
            if(c) count++;
        }while(next_permutation(arr,arr+n));
        cout << count << endl;
    }
}
