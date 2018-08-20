#include<iostream>
#include<string>
#include<cstdint>
#include<limits>
using namespace std;

int main()
{
    int32_t length;
    while(cin >> length && length){
        cin.ignore();
        string road;
        getline(cin,road);
        int distance = 0;
        char cur ;
        bool start = true;
        int32_t mini = 20000000;
        for(auto c: road){
            if(c == '.') {
                distance++;
                continue;
            }
            if(c == 'Z') {
                mini = 0;
                break;
            }
            distance++;
            if(start){
                cur = c;
                start = false;
                distance = 0;
            }
            else if(cur == c){
                distance = 0;
            }
            else{
                cur = c;
                if(mini > distance) mini = distance;
                distance = 0;
            }
        }
        cout << mini << endl;
    }
    return 0;
}
