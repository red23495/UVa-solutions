#include<iostream>
#include<vector>
using namespace std;

int n;

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int test = 1;
	while (cin >> n && n) {
		vector<int> v(n);
		int total = 0;
		for (auto &x : v) { cin >> x; total += x; }
		total /= n;
		int ans = 0;
		for (auto& x : v) if (x > total) ans += (x - total);
		cout << "Set #" << test++ << "\nThe minimum number of moves is " << ans << ".\n\n";
	}
	return 0;
}
