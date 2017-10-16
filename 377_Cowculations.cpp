#include<bits/stdc++.h>

using namespace std;

int cow_to_int(string s){
	int base = pow(4, s.length()-1);
	int ret = 0;
	for(int i = 0; i < s.length(); i++){
		int t = 0;
		switch (s[i]) {
		case 'V':
			t = 0;
			break;
		case 'U':
			t = 1;
			break;
		case 'C':
			t = 2;
			break;
		case 'D':
			t = 3;
			break;
		}
		ret += (t*base);
		base /= 4;
	}
	return ret;
}

int main(){
	int test;
	cin >> test;
	cout << "COWCULATIONS OUTPUT\n";
	while(test--){
		string s1, s2;
		cin >> s1 >> s2;
		int n1 = cow_to_int(s1);
		int n2 = cow_to_int(s2);
		//cout << n1 << ' ' << n2 << endl;
		for(int i = 0; i < 3; i++){
			char c;
			cin >> c;
			switch (c) {
			case 'A':
				n2 += n1; break;
			case 'L':
				n2 *= 4; break;
			case 'R':
				n2 /= 4; break;
			}
		}
		string ans;
		cin >> ans;
		if (cow_to_int(ans) == n2) cout << "YES\n";
		else cout << "NO\n";
	}
	cout << "END OF OUTPUT\n";
	return 0;
}
