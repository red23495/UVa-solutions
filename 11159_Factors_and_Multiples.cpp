#include<bits/stdc++.h>

using namespace std;

int test, n, m;
int vleft[105], vright[105];
vector<vector<int>> v;
int match[210];
vector<int> visited;

int aug(int l) {
	if (visited[l]) return 0;
	visited[l] = 1;
	for (int i = 0; i < v[l].size(); i++) {
		int r = v[l][i];
		if (match[r] == -1 || aug(match[r])) {
			match[r] = l; return 1;
		}
	}
	return 0;
}

int main() {
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> vleft[i];
		cin >> m;
		for (int i = 0; i < m; i++) cin >> vright[i];
		v.clear();
		v.resize(n + m + 5);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vleft[i]) {
					if (!(vright[j] % vleft[i]))
						v[i].push_back(n+j);
				}
				else{
					if (!vright[j]) v[i].push_back(n + j);
				}
			}
		}
		int MCBP = 0;
		memset(match, -1, sizeof match);
		for (int i = 0; i < n; i++) {
			visited.clear();
			visited.resize(v.size());
			MCBP += aug(i);
		}
		cout << "Case " << t << ": " << MCBP << endl;
	}
	return 0;
}
