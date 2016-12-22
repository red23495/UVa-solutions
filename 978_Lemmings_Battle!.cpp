#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int battlefield,g,b;
        cin >> battlefield >> g >> b;
        multiset<int,greater<int>> green,blue;
        for(int i = 0; i < g; i++){
            int x;
            cin >> x;
            green.insert(x);
        }
        for(int i = 0; i < b; i++){
            int x;
            cin >> x;
            blue.insert(x);
        }
        while(!green.empty() && !blue.empty()){
            vector<int> G,B;
            int i = 0;
            int b = (green.size() < blue.size())? green.size():blue.size();
            b = min(b,battlefield);
            while(i < b){
                int x = *green.begin();
                int y = *blue.begin();
                green.erase(green.begin());
                blue.erase(blue.begin());
                if(x-y > 0) G.push_back(x-y);
                else if(y-x > 0) B.push_back(y-x);
                i++;
            }
            for(auto x: G) green.insert(x);
            for(auto x: B) blue.insert(x);
        }
        if(green.empty() && blue.empty()) cout << "green and blue died\n";
        else if(blue.empty()){
            cout << "green wins\n";
            while(!green.empty()) {
                cout << *green.begin() << endl;
                green.erase(green.begin());
            }
        }
        else {
            cout << "blue wins\n";
            while(!blue.empty()) {
                cout << *blue.begin() << endl;
                blue.erase(blue.begin());
            }
        }
        if(test) cout << endl;
    }
    return 0;
}
