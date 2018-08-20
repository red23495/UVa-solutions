#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,q;
    while(cin >> n >> q){
        vector<int> l[1000001];
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            l[x].push_back(i);
        }
        while(q--){
            int a,b;
            cin >> a >> b;
            if(a <= l[b].size())cout << l[b][a-1] << endl;
            else cout << "0\n";
        }
    }
    return 0;
}
