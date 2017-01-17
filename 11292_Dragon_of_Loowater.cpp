#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int m,n;
    while(cin >> m >> n && m){
        vector<int> dragon(m),knight(n);
        for(int i = 0; i < m; i++) cin >> dragon[i];
        for(int i = 0; i < n; i++) cin >> knight[i];
        if(m > n) {cout << "Loowater is doomed!\n";continue;}
        sort(dragon.begin(),dragon.end());
        sort(knight.begin(),knight.end());
        int count = 0;
        int index = 0;
        int gold = 0;
        for(int i = 0; i < m && index < n; i++){
            while(index < n){
                if(knight[index] >= dragon[i]) {
                    count++;
                    gold += knight[index];
                    index++;
                    break;
                }
                index++;
            }
        }
        if(count != m) cout << "Loowater is doomed!\n";
        else cout << gold << endl;
    }
    return 0;
}
