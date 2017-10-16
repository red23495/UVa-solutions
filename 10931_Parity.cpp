#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(cin >> n && n){
		bitset<32> b(n);
		cout << "The parity of ";
		int i = 31;
		while (!b[i]) i--;
		while (i >= 0) cout << b[i--];
		cout << " is " << b.count() << " (mod 2).\n";
	}
	return 0;
}
