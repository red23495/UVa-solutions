#include<bits/stdc++.h>

using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int n;
	while (cin >> n && n) {
		int p = log2(n);
		int val = pow(2,p);
		int def = n - val;
		int ans;
		if (def == 0) ans = n;
		else ans = def * 2;
		cout << ans << endl;
	}
	return 0;
}
