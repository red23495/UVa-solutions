#include<iostream>
#include<vector>

using namespace std;
struct stone{
    int d;
    char s;
};
int main(){
    int test;
    cin >> test;
    for(int t = 1; t <= test; t++){
        int n,l;
        cin >> n >> l;
        int _max = 0;
        vector<stone> v(n+2);
        v[0] = stone{0,'B'};
        for(int i = 1; i <= n; i++){
            char a,b;int d;
            cin >> a >> b >> d;
            v[i] = stone{d,a};
        }
        v[n+1] = {l,'B'};
        for(int i = 0; i < n+1;i++){
            if(v[i+1].s == 'S'){
                int end;
                int m = v[i+1].d - v[i].d;
                if(m > _max) _max = m;
                m = v[i+2].d - v[i].d;
                if(m > _max) _max = m;
                for(int j = i+1; j < n+1 && v[j].s == 'S'; j+=2){
                    int x ;
                    if(v[j+1].s == 'B') {
                        x = v[j+1].d - v[j].d;
                        if(x > _max) _max = x;
                        break;
                    }
                    x = v[j+2].d - v[j].d;
                    if(x > _max) _max = x;
                }
                for(int j = i+2; j < n+1 && v[j].s == 'S'; j+=2){
                    int x ;
                    if(v[j+1].s == 'B') {
                        x = v[j+1].d - v[j].d;
                        if(x > _max) _max = x;
                        end = j+1;
                        break;
                    }
                    x = v[j+2].d - v[j].d;
                    if(x > _max) _max = x;
                    end = j+2;
                }
            }else{
                int m = v[i+1].d - v[i].d;
                if(m > _max) _max = m;
            }
        }
        cout << "Case " << t << ": " << _max << endl;
    }
    return 0;
}
