#include<iostream>

using namespace std;

int main(){
    int test;
    cin >> test;
    cout << "Lumberjacks:\n";
    for(int i = 0; i < test; i++){
        int arr[10];
        for(int i = 0; i < 10; i++)
            cin >> arr[i];
        bool check = false;
        bool less;
        bool sort = true;
        for(int i = 1; i < 10 && sort; i++){
            if(!check){
                if((arr[i] - arr[i-1]) > 0){
                    less = true;
                    check = true;
                }
                else if((arr[i] - arr[i-1]) < 0){
                    less = false;
                    check = true;
                }
            }else if(less){
                if((arr[i] - arr[i-1]) < 0){
                    sort = false;
                }
            }else{
                if((arr[i] - arr[i-1]) > 0){
                    sort = false;
            }
        }
    }
        if(sort) cout << "Ordered";
        else cout << "Unordered";
        cout << endl;
    }
    return 0;
}
