#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        vector<string> name(n);
        while(cin.peek() == 10) cin.ignore();
        for(int i = 0; i < n; i++){
            getline(cin,name[i],'\n');
        }
        while(cin.peek() == 10) cin.ignore();
        string str;
        vector<vector<int>> b;
        while(getline(cin,str,'\n') && str != ""){
            stringstream ss(str);
            vector<int> t(n);
            for(int i = 0; i < n; i++){
                ss >> t[i];
                t[i]--;
            }
            b.push_back(t);
        }
        vector<bool> dead(n,false);
        int live = n;
        while(true){
            vector<int> count(n,0);
            for(auto &c: b){
                for(int i = 0; i < n;i++){
                    if(!dead[c[i]]){
                        count[c[i]]++;
                        break;
                    }
                }
            }
            for(int i = 0; i < n; i++){
                if(count[i] == 0) dead[i] = true;
            }
            int hi = 0, lo = n;
            for(int i = 0; i < n; i++){
                if(count[i]){
                    if(count[i] > count[hi]) hi = i;
                }
            }
            lo = hi;
            for(int i = 0; i < n; i++){
                if(count[i]){
                    if(count[i] < count[lo]) lo = i;
                }
            }
            if(count[hi] == count[lo]){
                for(int i = 0; i < n; i++){
                    if(count[i]) cout << name[i] << endl;
                }
                break;
            }
            else if(count[hi]*2 > b.size()){
                cout << name[hi]<<endl;break;
            }
            else {
                for(int i = lo; i < n; i++){
                    if(count[i] == count[lo]) dead[i] = true;
                }
            }
        }
        if(test) cout << endl;
    }
    return 0;
}
