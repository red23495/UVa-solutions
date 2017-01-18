#include<iostream>

using namespace std;

int main(){
    unsigned int n,l,u;
    while(cin >> n >> l >> u){
        bool uedge = true, ledge = true;
        unsigned int ans = 0;
        for(int i = 31; i >= 0; i--){
            int x = (1<<i);
            int a = (l&x), b = (u&x);
            int m = (n&x);
            if(uedge && ledge){
                if(a == b) ans |= a;
                else{
                    if(m == b){
                        uedge = false;
                    }else{
                        ledge = false;
                        ans |= x;
                    }
                }
            }else if(uedge){
                if(b && m) uedge = false;
                else if(b) ans |= x;
            }
            else if(ledge){
                if(a) ans |= x;
                else{
                    if(!m){
                        ledge = false;
                        ans |= x;
                    }
                }
            }else{
                if(!m) ans |= x;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
