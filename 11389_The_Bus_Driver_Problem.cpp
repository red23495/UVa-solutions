#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,d,r;
    while(cin >> n >> d >> r && n){
        vector<int> mor(n),eve(n);
        for(int i = 0; i < n ; i++) cin >> mor[i];
        for(int i = 0; i < n ; i++) cin >> eve[i];
        sort(mor.begin(),mor.end());
        sort(eve.begin(),eve.end());
        int over = 0;
        for(int i = 0; i < n; i++){
            int l = mor[i]+eve[n-i-1];
            if(l - d > 0) over += (l-d);
        }
        cout << over*r << endl;
    }
    return 0;
}
