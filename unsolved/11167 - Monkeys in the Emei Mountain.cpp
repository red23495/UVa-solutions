#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#include<algorithm>
#include<queue>
#include<limits>
using namespace std;

using ii = pair<int, int>;
vector<vector<int>> node;
#define GRAPH_SIZE 450
#define MONKEY(I) I
#define TIME(I) 100+I
#define TIME2ID(I) I-100
#define SOURCE 448
#define SINK 449
int weight[GRAPH_SIZE][GRAPH_SIZE];
int n, m;
map<int, int> checkpoint_id;
vector<int> checkpoint;
struct record { int v, a, b; };
vector<record> records;
int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int test = 1;
	while (cin >> n >> m && n) {
		int totalFlow = 0;
		node.clear();
		node.resize(GRAPH_SIZE);
		memset(weight,0,sizeof weight);
		checkpoint.clear();
		checkpoint_id.clear();
		records.clear();
		for (int i = 0; i < n; i++) {
			int v, a, b;
			cin >> v >> a >> b;
			totalFlow += v;
			checkpoint.push_back(a);
			checkpoint.push_back(b);
			records.push_back({v,a,b});
		}
		sort(checkpoint.begin(),checkpoint.end());
		checkpoint.resize(distance(checkpoint.begin(),unique(checkpoint.begin(),checkpoint.end())));
		for (int i = 0; i < checkpoint.size(); i++) checkpoint_id[checkpoint[i]] = i;
		for (int i = 0; i < records.size(); i++) {
			//cout << records[i].v << ' ' << records[i].a << ' ' << records[i].b << endl;
			int a = records[i].a;
			//cout << a << endl;
			node[SOURCE].push_back(MONKEY(i));
			//node[MONKEY(i)].push_back(SOURCE);
			weight[SOURCE][MONKEY(i)] = records[i].v;
			while (a < records[i].b) {
				int x = checkpoint_id[a];
				int w = checkpoint[x + 1] - a;
				node[MONKEY(i)].push_back(TIME(x));
				node[TIME(x)].push_back(MONKEY(i));
				weight[MONKEY(i)][TIME(x)] = w;
				//weight[TIME(x)][MONKEY(i)]= 0;
				a = checkpoint[x + 1];
			}
		}
		for (int i = 0; i < checkpoint.size() - 1; i++) {
			int w = checkpoint[i + 1] - checkpoint[i];
			node[TIME(i)].push_back(SINK);
			weight[TIME(i)][SINK] = m*w;
		}
		/*for (int i = 0; i < node.size(); i++) {
			cout << i << ':';
			for (int j = 0; j < node[i].size(); j++) {
				cout << node[i][j] << ' ';
			}
			cout << endl;
		}*/
		int maxFlow = 0;
		while (true) {
			int is_found = false;
			queue<int> q;
			q.push(SOURCE);
			vector<bool> visited(GRAPH_SIZE);
			visited[SOURCE] = true;
			vector<int> parent(GRAPH_SIZE);
			while (!is_found && !q.empty()) {
				int x = q.front();
				q.pop();
				for (int i = 0; i < node[x].size(); i++) {
					if (!visited[node[x][i]] && weight[x][node[x][i]] > 0) {
						parent[node[x][i]] = x;
						if (node[x][i] == SINK) { is_found = true; break; }
						q.push(node[x][i]);
						visited[node[x][i]] = true;
					}
				}
			}
			if (!is_found) break;
			int t = INT_MAX;
			int p = SINK;
			while (p != SOURCE) {
				t = min(weight[parent[p]][p], t);
				p = parent[p];
			}
			//cout << t << endl;
			p = SINK;
			maxFlow += t;
			while (p != SOURCE) {
				weight[parent[p]][p] -= t;
				weight[p][parent[p]] += t;
				p = parent[p];
			}
		}
        /*for(int i = 0; i < checkpoint.size(); i++){
            for(int j = 0; j < n; j++){
                cout << weight[TIME(i)][MONKEY(j)] << ' ';
            }
            cout << endl;
        }*/
		cout << "Case " << test++ << ": ";
		if (totalFlow != maxFlow) cout << "No\n";
		else {
			cout << "Yes\n";
			int track[50005];
			memset(track,0,sizeof track);
			for (int i = 0; i < n; i++) {
				vector<int> v;
				for (int j = 0; j < node[MONKEY(i)].size(); j++) {
					int w = weight[node[MONKEY(i)][j]][MONKEY(i)];
					//cout << w << endl;
					if (w > 0) {
						int a = checkpoint[TIME2ID(node[MONKEY(i)][j])];
						while (track[a] >= m) a++;
						v.push_back(a);
						for (int x = 0; x < w; x++) track[a + x]++;
						v.push_back(a + w);
					}
				}
				//sort(v.begin(),v.end());
				//cout << v.size() << endl;
				for(auto x: v) cout << x << ' '; cout << endl;
				//for (auto x : v) cout << x << ' '; cout << endl;
				vector<int> ans;
				if(v.size())ans.push_back(v[0]);
				if(v.size())ans.push_back(v[1]);
				for (int j = 1; j < v.size()/2 && v.size(); j++) {
                    if(ans[ans.size()-1] == v[2*j]){
                        ans[ans.size()-1] = v[2*j+1];
                    }
                    else{
                        ans.push_back(v[2*j]);
                        ans.push_back(v[2*j+1]);
                    }
				}
				//if(v.size())ans.push_back(v[v.size()-1]);
				cout << (ans.size() / 2);
				for (int j = 0; j < ans.size(); j += 2) {
					cout << " (" << ans[j] << ',' << ans[j + 1] << ')';
				}
				cout << endl;
			}
		}
	}
	return 0;
}
