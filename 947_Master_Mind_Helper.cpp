#include<iostream>
#include<string>
using namespace std;

int count;

int main(){
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        string str; int strong,weak;
        count = 0;
        cin >> str >> strong >> weak;
        int size = str.size();
        int* arr = new int[size];
        int* gues = new int[size];
        for(int i = 0; i < size; i++){
            gues[i] = str[i]-'0';
            arr[i] = 1;
        }
        while(true){
            int cc[10],s = 0,w = 0;
            for(int i = 0; i < 10; i++){
                cc[i] = 0;
            }
            int* gg = new int[size];
            for(int i = 0; i < size; i++) gg[i] = gues[i];
            for(int i = 0; i < size; i++){
                cc[arr[i]]++;
            }
            for(int i = 0; i < size; i++){
                if(arr[i] == gg[i]){
                    s++;
                    cc[arr[i]]--;
                    gg[i]=0;
                }
            }
            if(s == strong){
                for(int i = 0; i < size; i++){
                    if(gg[i]){
                        if(cc[gg[i]] > 0){
                            w++;
                            cc[gg[i]]--;
                        }
                    }
                }
            }
            if( strong == s && w == weak) count++;
            int i = size-1;
            while(arr[i] == 9){
                arr[i] = 1;
                --i;
                if(i < 0) break;
            }
            if(i >= 0){
                arr[i]++;
            }
            else break;
        }
        cout << count << endl;
    }
    return 0;
}
