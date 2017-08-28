#include<bits/stdc++.h>

using namespace std;

int camp,night;
int v[605];

int check(int r){
    int cnt = 0, sum = 0;
    for(int i = 0; i < camp; i++){
        if(v[i] > r) return 0;
        if(sum + v[i] <= r){
            sum += v[i];
        }else{
            sum = v[i];
            cnt++;
        }
    }
    if(sum) cnt++;
    return cnt <= night;
}

int main(){
    while(cin >> camp >> night){
        camp++,night++;
        for(int i = 0; i < camp; i++)
            cin >> v[i];
        int l = 0, r = 1000000,ans;
        while(l <= r){
            int mid = (l+r)/2;
            if(check(mid))
                r = mid-1;
            else l = mid+1;
        }
        cout << r+1 << endl;
    }
    return 0;
}
