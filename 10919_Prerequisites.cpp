#include<iostream>
#include<vector>
using namespace std;

int main(){
    int course , cat;
    while(cin >> course && course){
        cin >> cat;
        vector<int> list(course);
        for(int i = 0; i < course;i++){
            cin >> list[i];
        }
        bool eligable = true;
        for(int i = 0; i < cat ; i++){
            int given,required;
            cin >> given >> required;
            vector<int> g(given);
            for(int i = 0; i < given; i++){
                cin >> g[i];
            }
            if(eligable){
                int sum = 0;
                for(int i = 0; i < given; i++){
                    for(int j = 0; j < course; j++){
                        if(g[i] == list[j]){
                            sum++;
                            break;
                        }
                    }
                }
                if(sum < required) eligable = false;
            }
        }
        if(eligable) cout << "yes";
        else cout << "no";
        cout << endl;
    }
    return 0;
}
