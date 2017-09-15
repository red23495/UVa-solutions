#include<bits/stdc++.h>

using namespace std;

int main() {
	int total, trade, butt;
	while (cin >> total >> trade) {
		butt = total;
		while (true) {
			int temp = butt / trade;
			if (!temp) break;
			total += temp;
			butt = (butt%trade) + temp;
		}
		cout << total << endl;
	}
	return 0;
}
