#include<iostream>
#include<string>

using namespace std;

struct link{
    string url;
    int precedence;
};

int main(){
    int test;
    cin >> test;
    for(int i = 1; i <= test; i++){
        link list[10];
        int high = -1;
        for(int i = 0; i < 10; i++) {
            cin >> list[i].url >> list[i].precedence;
            if(list[i].precedence > high) high = list[i].precedence;
        }
        cout << "Case #" << i << ":\n";
        for(int i = 0; i < 10; i++){
            if(list[i].precedence == high) cout << list[i].url << endl;
        }
    }
    return 0;
}
