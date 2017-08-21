#include<bits/stdc++.h>

#define IOBOOST cin.sync_with_stdio(false);cout.sync_with_stdio(false);
#define FOR(I,V,N) for(int I = V; I < N; I++)
#define QI queue<int>

using namespace std;
using vii = vector<vector<int>>;
using vi = vector<int>;

#define MAX_CAPACITY 205
#define ENTRY(I) I
#define EXIT(I) I+100
#define INFINITE 100000
int constexpr SOURCE = 204;
int SINK;
vii v;
int weight[MAX_CAPACITY][MAX_CAPACITY];
enum arr_val{X,Y,PENGUIN,JUMP};
int main(){
    IOBOOST
    int test;
    cin >> test;
    while(test--){
        int ice;double jmp;
        cin >> ice >> jmp;
        int arr[100][4];
        memset(weight,0,sizeof weight);
        FOR(i,0,ice){
            cin >> arr[i][X] >> arr[i][Y] >> arr[i][PENGUIN] >> arr[i][JUMP];
        }
        v.clear();
        v.resize(MAX_CAPACITY);
        FOR(i,0,ice){
            v[ENTRY(i)].push_back(EXIT(i));
            v[EXIT(i)].push_back(ENTRY(i));
            weight[ENTRY(i)][EXIT(i)] = weight[EXIT(i)][ENTRY(i)] = arr[i][JUMP];
        }
        FOR(i,0,ice){
            FOR(j,i+1,ice){
                double x_off = arr[i][X] - arr[j][X];
                double y_off = arr[i][Y] - arr[j][Y];
                //cout << arr[i][X] << ' ' << arr[j][X] << endl;
                //cout << arr[i][Y] << ' ' << arr[j][Y] << endl;
                //cout << x_off << ' ' << y_off << endl;
                double dist = sqrt((x_off*x_off)+(y_off*y_off));
                if(dist <= jmp){
                    //cout <<dist << ' '<< i << ' ' << j << endl;
                    v[EXIT(i)].push_back(ENTRY(j));
                    v[ENTRY(j)].push_back(EXIT(i));
                    weight[EXIT(i)][ENTRY(j)] = INFINITE;
                    v[EXIT(j)].push_back(ENTRY(i));
                    v[ENTRY(i)].push_back(EXIT(j));
                    weight[EXIT(j)][ENTRY(i)] = INFINITE;
                }
            }
        }
        int totalPenguin = 0;
        FOR(i,0,ice){
            if(arr[i][PENGUIN]){
                v[SOURCE].push_back(ENTRY(i));
                v[ENTRY(i)].push_back(SOURCE);
                weight[SOURCE][ENTRY(i)] = arr[i][PENGUIN];
                totalPenguin += arr[i][PENGUIN];
            }
        }
        vi ans;
        FOR(I,0,ice){
            SINK = I;
            int maxFlow = 0;
            int weight_chng [MAX_CAPACITY][MAX_CAPACITY];
            memset(weight_chng,0,sizeof weight_chng);
            while(true){
                QI q;
                q.push(SOURCE);
                vi visited(MAX_CAPACITY),parent(MAX_CAPACITY);
                visited[SOURCE] = 1;
                bool found = false;
                int last_floe;
                while(!q.empty() && !found){
                    int p = q.front();
                    q.pop();
                    FOR(i,0,v[p].size()){
                        int c = v[p][i];
                        if(visited[c] || (weight[p][c]+weight_chng[p][c]) <= 0) continue;
                        parent[c] = p;
                        visited[c] = 1;
                        q.push(c);
                        if(c == ENTRY(SINK)|| c == EXIT(SINK)){last_floe = c;found = true; break;}
                    }
                }
                if(!found) break;
                int e = last_floe;
                int t = INT_MAX;
                //cout << 'h' << endl;
                while(e != SOURCE){
                        //cout << e << ' ';
                    t = min(weight[parent[e]][e]+weight_chng[parent[e]][e],t);
                    e = parent[e];
                }
                //cout << endl;
                maxFlow += t;
                e = last_floe;
                while(e != SOURCE){
                    weight_chng[parent[e]][e] -= t;
                    weight_chng[e][parent[e]] += t;
                    e = parent[e];
                }
            }
            //cout << I << " MAX " << maxFlow << endl;
            if(maxFlow >= totalPenguin) ans.push_back(ENTRY(I));
        }
        if(ans.size()){
            FOR(i,0,ans.size()){
                if(i) cout << ' ';
                cout << ans[i];
            }
            cout << endl;
        }
        else cout << "-1\n";
    }
    return 0;
}
