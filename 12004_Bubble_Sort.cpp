#include<bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		ull n;
		cin >> n;
		ull x = (n - 1)*(n - 1) + (n - 1);
		int div = 4;
		if (!(x & 3)) div = 1;
		else if (!(x & 1)) div = 2;
		cout << "Case " << t << ": ";
		if (div == 1) cout << x / 4 << endl;
		else if (div == 2) cout << x / 2 << "/2\n";
		else cout << x << "/4\n";
	}
	return 0;
}
