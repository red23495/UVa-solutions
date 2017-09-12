#include<bits/stdc++.h>

using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1;
        while(cin.peek() == '\n') cin.ignore();
        string s;
        stringstream ss;
        double time = 0;
        while(getline(cin,s) && s.length()){
            ss.str(s);
            ss.clear();
            ss >> x1 >> y1 >> x2 >> y2;
            double dist = sqrt(pow(x2-x1,2.0)+pow(y2-y1,2.0))/1000.0;
            time += dist*6.0;
        }
        //cout << time << endl;
        int hour = time/60;
        int minute = round(time - hour*60);
        if(minute == 60) {hour++; minute = 0;}
        cout << hour << ":" << setw(2) << setfill('0') << minute << endl;
        if(test) cout << endl;
    }
    return 0;
}
