#include<iostream>
using namespace std;

int main()
{
    int init,f,s,t;
    while(cin >> init >> f >> s >> t && (init || f || s|| t)){
        int count = 80;
        int te = init - f;
        if(te < 0) te = 40+te;
        count+=te;
        count+=40;
        te = s - f;
        if(te < 0) te = 40+te;
        count+=te;
        te = s - t;
        if(te < 0) te = 40+te;
        count+= te;
        cout << count*9 << endl;
    }
    return 0;
}
