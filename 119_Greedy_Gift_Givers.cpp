#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main()
{
    int n;
    int count = 0;
    while(cin >> n){
        if (count) cout << endl;
        count++;
        unordered_map<string,int> rec;
        string pep[10];
        for(int i = 0; i < n; i++){
            string name;
            cin >> name;
            pep[i] = name;
            rec.insert(pair<string,int>{name,0});
        }
        for(int i = 0; i < n; i++){
            string str;
            int money, person;
            cin >> str >> money >> person;
            if(person == 0){
                continue;
            }
            rec[str] -= (money - money%person);
            int div = money/person;
            for(int i = 0; i < person; i++){
                string p;
                cin >> p;
                rec[p] += div;
            }
        }
        for(int i = 0; i < n ; i++)
            cout << pep[i] << ' ' << rec[pep[i]] << endl;
    }
    return 0;
}
