#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        auto comp = [](char c1, char c2){
                        if(toupper(c1) < toupper(c2)) return true;
                        else if(toupper(c1) == toupper(c2) && c1 < c2) return true;
                        else return false;};
        sort(s.begin(),s.end(),comp);
        do{
            cout << s << endl;
        }while(next_permutation(s.begin(),s.end(),comp));
    }
    return 0;
}
