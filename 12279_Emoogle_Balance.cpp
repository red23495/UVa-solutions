#include<iostream>

using namespace std;

int main()
{
    int n;
    int test = 1;
    while(cin >> n && n){
        int due = 0;
        int paid = 0;
        for(int i = 0; i < n ; i++){
            int x;
            cin >> x;
            if(x) due++;
            else paid++;
        }
        cout << "Case " << test << ": " <<due-paid << endl;
        test++;
    }
    return 0;
}
