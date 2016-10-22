#include<iostream>
#include<vector>
using namespace std;

int main(){
    int height, length;
    while(cin >> height >> length && height && length){
        vector<int> list(length);
        for(int i = 0; i < length; i++){
            cin >> list[i];
            list[i] = height - list[i];
        }
        int sum = list[list.size()-1];
        for(int i = list.size()-2; i >= 0; i--){
            if(list[i] > list[i+1])
                sum += list[i] - list[i+1];
        }
        cout << sum << endl;
    }
    return 0;
}
