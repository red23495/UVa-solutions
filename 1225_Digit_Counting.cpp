#include<bits/stdc++.h>

using namespace std;

int arr[10001][10];

int main() {
	for (int i = 1; i <= 10000; i++) {
		string s = to_string(i);
		for (int j = 0; j < 10; j++) {
			arr[i][j] = arr[i - 1][j];
		}
		for (char c : s) {
			arr[i][c - '0']++;
		}
	}
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		for (int i = 0; i < 10; i++) {
			if (i) cout << ' ';
			cout << arr[n][i];
		}
		cout << endl;
	}
	return 0;
}
