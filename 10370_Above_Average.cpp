#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int test;
	cin >> test;
	while (test--)
	{
		int a; double total{};
		cin >> a;
		vector<int> v(a);
		for (int i = 0; i < a; i++) {
			cin >> v[i]; total += v[i];
		}
		total /= a;
		int count = 0;
		for (auto x : v) if (x > total) count++;
		cout << fixed << setprecision(3) << ((double)count / a)*100.00 << "%\n";
	}
	return 0;
}
