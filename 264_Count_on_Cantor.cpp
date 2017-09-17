#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int offset = n,diagon;
		for (diagon = 1; offset > diagon; diagon++)
			offset -= diagon;
		int p1, p2;
		p1 = diagon - offset + 1;
		p2 = offset;
		if (!(diagon & 1)) swap(p1,p2);
		cout << "TERM "<<n<<" IS "<<p1<<"/"<<p2<< endl;
	}
	return 0;
}
