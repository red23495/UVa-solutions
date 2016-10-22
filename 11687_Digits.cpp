#include<iostream>
#include<string>
#include<cstdint>

using namespace std;

int main(){
    string str;
    while(cin >> str && str != "END"){
        int32_t init = str.size();
        int32_t past ;
        if(init == 1) past = str[0] - '0';
        else past = 1;
        int run = 1;
        while(true){
            if(init == past) break;
            past = init;
            int i;
            for(i = 1; init / 10 != 0; i++,init/=10){}
            init = i;
            run++;
        }
        cout << run << endl;
    }
    return 0;
}
