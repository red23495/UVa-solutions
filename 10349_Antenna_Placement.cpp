#include<bits/stdc++.h>

using namespace std;

char grid[40][10];
vector<vector<int>> v;
int w[402][402];
int constexpr SOURCE = 400, SINK = 401;
int test, n, m, poi;
int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cin >> test;
	while (test--) {
		cin >> m >> n;
		v.clear();
		v.resize(402);
		memset(w, 0, sizeof w);
		poi = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
				if (grid[i][j] == '*') poi++;
			}
		}
		int arrX[4] = { +1,-1,0,0 }, arrY[4] = { 0,0,+1,-1 };
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == '*') {
					for (int k = 0; k < 4; k++) {
						int x = arrX[k] + i, y = arrY[k] + j;
						if (x < 0 || x >= m || y < 0 || y >= n) continue;
						if (grid[x][y] == '*') {
							v[i*n + j].push_back(x*n + y);
							//cout << i*n + j << ' ' << x*n + y << endl;
							if((i+j)&1)w[i*n + j][x*n + y] = 1;
						}
					}
					if ((i + j) & 1) {
						v[SOURCE].push_back(i*n + j);
						//cout << i*n + j << " odd\n";
						w[SOURCE][i*n + j] = 1;
					}
					else {
						v[i*n+j].push_back(SINK);
						//cout << i*n + j << " even\n";
						w[i*n + j][SINK] = 1;
					}
				}
			}
		}
		int maxFlow = 0;
		while (true) {
			queue<int> q;
			q.push(SOURCE);
			vector<bool> visited(402);
			visited[SOURCE] = true;
			vector<int> parent(402,-1);
			bool found = false;
			while (!q.empty() && !found) {
				int p = q.front();
				q.pop();
				for (int i = 0; i < v[p].size(); i++) {
					int c = v[p][i];
					if (visited[c] || w[p][c] <= 0) continue;
					parent[c] = p;
					if (c == SINK) { found = true; break; }
					visited[c] = true;
					q.push(c);
				}
			}
			if (!found) break;
			int t = SINK;
			int flow = INT_MAX;
			while (t != SOURCE) {
				//cout << t << ' ';
				int p = parent[t];
				flow = min(w[p][t],flow);
				t = p;
			}
			//cout << endl;
			maxFlow += flow;
			t = SINK;
			while (t != SOURCE) {
				int p = parent[t];
				w[p][t] -= flow;
				w[t][p] += flow;
				t = p;
			}
		}
		//cout << poi << ' ' << maxFlow << endl;
		cout << poi - maxFlow << endl;
	}
	return 0;
}
