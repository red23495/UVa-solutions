#include<iostream>
#include<set>

using namespace std;

int main(){
    int m,n;
    while(cin >> m >> n && (m || n)){
        set<int> s;
        for(int i = 0; i < m+n; i++){
            int x;
            cin >> x;
            s.insert(x);
        }
        cout << m+n - s.size() << endl;
    }
    return 0;
}
