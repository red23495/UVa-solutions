#include<bits/stdc++.h>

using namespace std;

int main() {
	vector<int> digits(1);
	long double sum = 1.0;
	int it = 1;
	while (sum <= (1 << 22)) {
		long double val = log2l(it);
		sum += val;
		digits.push_back(sum);
		//cout << digits[it] << endl;
		it++;
		//cout <<it << ' ' <<digits[it-1] << endl;
	}
	int n;
	while (cin >> n && n) {
		int val = (n - 1960) / 10;
		val += 2;
		val = (1 << val);
		//cout << val << endl;
		int ans = 0;
		for (int i = 1; i < digits.size(); i++) {
			//cout << i << ' ' << digits[i] << endl;
			if (digits[i] > val) break;
			ans = i;
		}
		cout << ans << endl;
	}
	return 0;
}
