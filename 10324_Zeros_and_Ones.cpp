#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str;
    int test = 0;
    while(cin >> str){
        test++;
        int c;
        cin >> c;
        cout << "Case " << test <<":\n";
        for(int i = 0; i < c; i++){
            int x,y;
            cin >> x >> y;
            if(x > y) {
                int temp = x;
                x = y;
                y = temp;
            }
            char check = str[x];
            bool same = true;
            for(int i = x+1; i <= y; i++) if(check != str[i]){ same = false; break;}
            if(same) cout << "Yes";
            else cout << "No";
            cout << endl;
        }
    }
    return 0;
}
