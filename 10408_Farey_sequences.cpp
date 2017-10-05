#include<bits/stdc++.h>

using namespace std;

struct record {
	int up, down;
	double val;
};

int gcd(int a, int b) { return ((a%b) == 0) ? b : gcd(b, a%b); }

int main() {
	vector<record> v;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			if (gcd(i, j) == 1) {
				v.push_back({i,j,(double(i)/j)});
			}
		}
	}
	auto x = [](record a, record b) {
		if (a.val < b.val) return true;
		return false;
		};
	sort(v.begin(),v.end(),x);
	int n, m;
	while (cin >> n >> m) {
		int count = 0;
		record ans;
		for(int i = 0; i < v.size(); i++){
			if (v[i].up <= n && v[i].down <= n) {
				count++;
				if (count == m) {
					ans = v[i];
					break;
				}
			}
		}
		cout << ans.up << "/" << ans.down << endl;
	}
	return 0;
}
