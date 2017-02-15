#include<bits/stdc++.h>
using namespace std;

int m,n,p,turn,ans;
vector<vector<int>> v;
vector<int> cur,low;
vector<bool> visited;
stack<int> s;

void scc(int p){
	if(ans > 1) return;
	cur[p]=low[p]=++turn;
	s.push(p);
	visited[p]=true;
	for(auto x: v[p]){
		if(!cur[x]) scc(x);
		if(visited[x]) low[p]=min(low[p],low[x]);
	}
	if(ans > 1) return;
	if(cur[p]==low[p]){
		while(true){
			int x = s.top();
			s.pop();
			visited[x]=false;
			if(x==p)break;
		}
		ans++;
	}
}

int main(){
	while(cin >> n >> m && n){
		v.clear();
		v.resize(n);
		while(m--){
			int x,y;
			cin >> x >> y >> p;
			x--;y--;
			v[x].push_back(y);
			if(p == 2)v[y].push_back(x);
		}
		cur.clear();
		cur.resize(n);
		low.clear();
		low.resize(n);
		visited.clear();
		visited.resize(n);
		ans = 0; turn = 0;
		while(!s.empty()) s.pop();
		for(int i = 0; i < n && ans < 2; i++){
			if(!cur[i]) scc(i);
		}
		if(ans==1)
		cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}
