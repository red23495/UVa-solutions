#include<iostream>
#include<map>

using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        map<int,int> m;
        int start = 0, count = 0, max = 0;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(m.find(x) == m.end()){
                m[x] = i;
                count++;
            }
            else if(start <= m[x]){
                start = m[x];
                if(max < count) max = count;
                count = (i-start);
                m[x] = i;
            }
            else{
                m[x] = i;
                count++;
            }
        }
        if(max < count) max = count;
        cout << max << endl;
    }
    return 0;
}
