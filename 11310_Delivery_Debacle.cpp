#include<bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
	ll mem[41] = {1,1,5};
	for (int i = 3; i <= 40; i++) {
		mem[i] = mem[i - 1] + 4 * mem[i - 2] + 2 * mem[i - 3];
	}
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		cout << mem[n] << endl;
	}
	return 0;
}
