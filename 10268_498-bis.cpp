#include<bits/stdc++.h>

using namespace std;
using ll = long long;

long long Pow(long long x, long long y) {
	if (y == 0)
		return 1;
	if (y & 1)
		return x*Pow(x*x, y / 2);
	else
		return Pow(x*x, y / 2);
}

int main() {
	ll x;
	vector<ll> coffs;
	while (cin >> x) {
		while (cin.peek() == 10) cin.ignore();
		string s;
		getline(cin,s);
		stringstream ss(s);
		coffs.clear();
		ll temp;
		while (ss >> temp) coffs.push_back(temp);
		ll n = coffs.size() - 1;
		ll X = pow(x,n-1);
		ll sum = 0;
		for (int i = 0; i < coffs.size() - 1; i++) {
			//cout << coffs[i] << ' ' << n << ' ' << X << endl;
			sum += Pow(x, n - i - 1)*coffs[i] * (n - i);
		}
		cout << sum << endl;
	}
	return 0;
}
