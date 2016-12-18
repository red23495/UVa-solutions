#include<iostream>
#include<bitset>

using namespace std;

int main()
{
    int n,m;
    while(cin >> m >> n && (n || m)){
        bitset<1000001> b;
        bool conflict = false;
        while(m--){
            int start,end;
            cin >> start >> end;
            if(!conflict){
                for(int i = start; i < end; i++){
                    if(b[i]){
                        conflict = true;
                        break;
                    }
                    b[i] = 1;
                }
            }
        }
        while(n--){
            int start,end,period;
            cin >> start >> end>>period;
            if(!conflict){
                bool broken = false;
                for(int j = start; j <= 1000000 && !broken; j+=(period)){
                    for(int i = j; i < j+(end-start) && i < 1000000; i++){
                        if(b[i]){
                            conflict = true;
                            broken = true;
                            break;
                        }
                        else b[i] = 1;
                    }
                }
            }
        }
        if(conflict) cout << "CONFLICT\n";
        else cout << "NO CONFLICT\n";
    }
    return 0;
}
