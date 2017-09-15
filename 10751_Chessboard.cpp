#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << "0.000\n";
			if (test) cout << endl;
			continue;
		}
		if (n == 2) {
			cout << "4.000\n";
			if (test) cout << endl;
			continue;
		}
		double ans = ((4 * n) - 4) + sqrt(2)*(n - 2)*(n - 2);
		cout << fixed <<setprecision(3) << ans << endl;
		if (test) cout << endl;
	}
	return 0;
}
