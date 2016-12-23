#include<iostream>
#include<set>

using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        multiset<int> m;
        long long total = 0;
        while(n--){
            int x;
            cin >> x;
            while(x--){
                int y;
                cin >> y;
                m.insert(y);
            }
            int l = *m.begin();
            int h = *(--m.end());
            m.erase(m.begin());m.erase(--m.end());
            total += (h-l);
        }
        cout << total << endl;
    }
    return 0;
}
