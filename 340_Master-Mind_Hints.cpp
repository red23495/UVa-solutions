#include<iostream>

using namespace std;

int main(){
    int s, game = 0;
    while(cin >> s && s){
        game++;
        int c[10];
        for(int i = 1; i < 10; i++)
            c[i] = 0;
        int* a = new int[s];
        for(int i = 0; i < s; i++){
            cin >> a[i];
            c[a[i]]++;
        }
        cout << "Game " << game << ":\n";
        while(true){
            int* n = new int[s];
            int cc[10];
            for(int i = 0; i < 10; i++){
                cc[i] = c[i];
            }
            int strong = 0, weak = 0;
            for(int i = 0; i < s; i++){
                int t;
                cin >> t;
                n[i] = t;
            }
            if(!n[0]) break;
            for(int i = 0; i < s; i++){
                if(n[i]==a[i]){
                    strong++;
                    cc[a[i]]--;
                    n[i] = 0;
                }
            }
            for(int i = 0; i < s; i++){
                if(n[i]){
                    if(cc[n[i]] > 0){
                        weak++;
                        cc[n[i]]--;
                    }
                }
            }
            cout << "    (" << strong << "," << weak << ")\n";
            delete[] n;
        }
        delete[] a;
    }
    return 0;
}
