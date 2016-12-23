#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        stack<int> st;
        queue<int> qu;
        priority_queue<int> pq;
        int s = 1, q = 2, p = 4;
        int elem = 0;
        while(n--){
            int comm, arg;
            cin >> comm >> arg;
            if(comm == 1){
                if(s)st.push(arg);
                if(q)qu.push(arg);
                if(p)pq.push(arg);
                elem++;
            }
            else if(elem > 0){
                if(s){
                    if(st.top() == arg) st.pop();
                    else s = 0;
                }
                if(q){
                    if(qu.front() == arg) qu.pop();
                    else q = 0;
                }
                if(p){
                    if(pq.top() == arg) pq.pop();
                    else p = 0;
                }
                elem--;
            }
            else{
                s = q = p = 0;
            }
        }
        switch(s|q|p){
        case 1:
            cout << "stack" << endl;
            break;
        case 2:
            cout << "queue" << endl;
            break;
        case 4:
            cout << "priority queue" << endl;
            break;
        case 0:
            cout << "impossible" << endl;
            break;
        default:
            cout << "not sure" << endl;
            break;
        }
    }
    return 0;
}
