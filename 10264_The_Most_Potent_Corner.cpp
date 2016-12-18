#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int dim;
    while(cin >> dim){
        vector<int> weight(1 << dim);
        for(int i = 0; i < weight.size(); i++){
            cin >> weight[i];
        }
        vector<int> potency(1 << dim,0);
        for(int i = 0; i < weight.size(); i++){
            for(int j = 0; j < dim; j++){
                potency[i]+=weight[i^(1<<j)];
            }
        }
        int maxp = 0;
        for(int i = 0; i < weight.size(); i++){
            for(int j = 0; j < dim; j++){
                maxp = max(maxp,potency[i]+potency[i^(1 << j)]);
            }
        }
        cout << maxp << endl;
    }
    return 0;
}
