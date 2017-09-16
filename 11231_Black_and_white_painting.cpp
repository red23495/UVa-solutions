#include<bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
int main() {
	int a, b, c;
	while (cin >> a >> b >> c && a) {
		a -= 7; b -= 7;
		int area = a*b;
		int ans = area / 2;
		if (c && ans * 2 != area) ans++;
		cout << ans << endl;
	}
	return 0;
}
