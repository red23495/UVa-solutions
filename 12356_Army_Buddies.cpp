#include<iostream>

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int b,s;
    while(cin >> s >> b && s && b){
        int* left = new int[s+1]{};
        int* right = new int[s+1]{};
        for(int i = 1; i < s; i++){
            left[i] = i-1;
            right[i] = i+1;
        }
        left[1] = -1;
        right[s] = -1;
        while(b--){
            int l,r;
            cin >> l >> r;
            right[left[l]] = right[r];
            left[right[r]] = left[l];
            l = left[l];
            r = right[r];
            if(l == -1) cout << '*'; else cout << l;
            cout << ' ';
            if(r == -1) cout << '*'; else cout << r;
            cout << endl;
        }
        cout << '-' << endl;
        //delete[] dead;
    }
}
