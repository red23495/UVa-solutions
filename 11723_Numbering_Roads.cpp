#include<bits/stdc++.h>

using namespace std;

int main() {
	int x, y;
	int test = 1;
	while (cin >> x >> y && x){
		int ans = x / y;
		if (x%y == 0) ans--;
		cout << "Case " << test++ << ": ";
		if (ans <= 26) cout << ans << endl;
		else cout << "impossible\n";
	}
}
