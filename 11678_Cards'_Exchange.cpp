#include<iostream>
#include<stack>

using namespace std;

int main(){
    int n1,n2;
    while(cin >> n1 >> n2 && n1 && n2){
        stack<int> p1,p2;
        int last = 0;
        for(int i = 0; i < n1; i++){
            int x;
            cin >> x;
            if(x == last) continue;
            p1.push(x);
            last = x;
        }
        last = 0;
        for(int i = 0; i < n2; i++){
            int x;
            cin >> x;
            if(x == last) continue;
            p2.push(x);
            last = x;
        }
        int i1{0}, i2{0};
        while(p1.size() && p2.size()){
            if(p1.top() > p2.top()){
                i1++;
                p1.pop();
            }
            else if(p1.top() < p2.top()){
                i2++;
                p2.pop();
            }
            else{
                p1.pop();p2.pop();
            }
        }
        while(p1.size()){
                p1.pop();
                i1++;
            }
        while(p2.size()){
                p2.pop();
                i2++;
            }
        cout << ((i1 < i2)? i1 : i2) << endl;;
    }
    return 0;
}
