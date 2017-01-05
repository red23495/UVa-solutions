#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int d;
        cin >> d;
        vector<vector<int>> v(d,vector<int>(d));
        vector<int> perm(d);
        for(int i =0; i < d; i++){
            for(int j = 0; j < d; j++){
                cin >> v[i][j];
            }
            perm[i] = i;
        }
        int min = numeric_limits<int>::max();
        do{
            int x = 0;
            for(int i = 0; i < d; i++){
                x += v[i][perm[i]];
            }
            if(x < min) min = x;
        }while(next_permutation(perm.begin(),perm.end()));
        cout << min << endl;
    }
    return 0;
}
