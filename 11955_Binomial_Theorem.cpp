#include<bits/stdc++.h>

using namespace std;

long long memo[55][55];

long long nCr(int n, int r) {
	if (r == 0 || n == r) return memo[n][r] = 1;
	if (memo[n][r]) return memo[n][r];
	return memo[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main() {
	int test;
	cin >> test;
	/*for (int i = 0; i <= 55; i++) {
		memo[i][0] = 1;
		memo[i][i] = 1;
	}
	for (int k = 1; k < 55; k++) {
		for (int n = k + 1; n <= 55; n++) {
			memo[n][k] = memo[n - 1][k - 1] + memo[n - 1][k];
		}
	}*/
	while (cin.peek() == 10) cin.ignore();
	for (int t = 1; t <= test; t++) {
		string v1, v2, s;
		int n;
		/*
		while (cin.peek() == '\n') cin.ignore();
		while (cin.peek() == '(') cin.ignore();
		getline(cin, v1, '+');
		getline(cin, v2, ')');
		while (cin.peek() == '^') cin.ignore();
		cin >> degree;
		*/
		getline(cin, s);
		int in = 1;
		while (true) {
			v1.push_back(s[in]);
			if (s[++in] == '+') break;
		}
		in++;
		while (true) {
			v2.push_back(s[in]);
			if (s[++in] == ')') break;
		}
		in += 2;
		string temp;
		while (true) {
			temp.push_back(s[in]);
			if (++in == s.length()) {
				n = atoi(temp.c_str());
				break;
			}
		}
		cout << "Case " << t << ": ";
		for (int k = 0, p1 = n, p2 = 0; k <= n; k++,p1--,p2++) {
			if (k) cout << '+';
			if (nCr(n,k) != 1) cout << nCr(n,k);
			if (p1 != 0) {
				if (nCr(n,k) != 1) cout << '*';
				cout << v1;
				if (p1 != 1) cout << '^' << p1;
			}
			if (p2 != 0) {
				if (p1 != 0) cout << '*';
				cout << v2;
				if (p2 != 1) cout << '^' << p2;
			}
		}
		cout << endl;
	}
	return 0;
}
