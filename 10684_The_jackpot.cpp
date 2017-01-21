#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        int m = -1000,x,s=0;
        for(int i = 0; i < n; i++){
            cin >> x;
            s += x;
            m = max(m,s);
            if(s < 0) s = 0;
        }
        if(m > 0) cout << "The maximum winning streak is "<<m<<".\n";
        else cout << "Losing streak.\n";
    }
    return 0;
}
