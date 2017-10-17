#include<bits/stdc++.h>

using namespace std;

int main(){
	int test;
	cin >> test;
	for(int t = 1; t <= test; t++){
		int n,x;
		cin >> n;
		vector<int> v(101);
		for(int i = 0; i < n*n; i++){
			cin >> x;
			v[x]++;
		}
		int ans = true;
		for(int i = 0; i <= 100 && ans; i++){
			if (v[i] > n) ans = false;
		}
		cout << "Case " << t << ": ";
		if (ans) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}
