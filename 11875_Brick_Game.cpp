#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	int arr[50];
	for (int t = 1; t <= test; t++) {
		int n;
		cin >> n;
		int center = n / 2;
		for (int i = 0; i < n; i++) cin >> arr[i];
		cout << "Case " << t << ": " << arr[center] << endl;
	}
	return 0;
}
