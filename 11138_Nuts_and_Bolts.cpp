#include<bits/stdc++.h>

using namespace std;

int test,nuts,bolts;
vector<vector<int>> v;
int w[1005][1005];

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> nuts >> bolts;
		v.clear();
		v.resize(nuts+bolts+5);
		memset(w,0,sizeof w);
		int source = nuts + bolts + 1;
		int sink = source + 1;
		for (int i = 0; i < nuts; i++) {
			for (int j = 0; j < bolts; j++) {
				int x;
				cin >> x;
				if (x) {
					v[source].push_back(i);
					v[i].push_back(nuts+j);
					v[nuts + j].push_back(i);
					v[nuts + j].push_back(sink);
					w[source][i] = 1;
					w[i][nuts + j] = 1;
					w[nuts + j][sink] = 1;
				}
			}
		}
		//time_t start = clock();
		int maxFlow = 0;
		while (true) {
			queue<int> q;
			q.push(source);
			vector<bool> visited(v.size());
			visited[source] = true;
			vector<int> parent(visited.size());
			parent[source] = -1;
			bool found = false;
			while (!q.empty() && !found) {
				int p = q.front();
				q.pop();
				for (int i = 0; i < v[p].size(); i++) {
					int c = v[p][i];
					if (visited[c] || w[p][c] <= 0) continue;
					parent[c] = p;
					if (c == sink) { found = true; break; }
					visited[c] = true;
					q.push(c);
				}
			}
			if (!found) break;
			int flow = INT_MAX;
			int t = sink;
			while (t != source) {
				int p = parent[t];
				flow = min(flow,w[p][t]);
				t = p;
			}
			maxFlow += flow;
			t = sink;
			while (t != source) {
				int p = parent[t];
				w[p][t] -= flow;
				w[t][p] += flow;
				t = p;
			}
		}
		//time_t stop = clock();
		//cout << stop - start << endl;
		cout << "Case "<< t <<": a maximum of "<< maxFlow <<" nuts and bolts can be fitted together\n";
	}
	return 0;
}
