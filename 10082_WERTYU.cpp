#include<iostream>
#include<string>
using namespace std;

int arr[128] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,59,0,0,0,0,77,48,44,46,57,96,49,50,51,52,53,54,55,56,0,76,0,45,0,0,0,0,86,88,83,87,68,70,71,85,72,74,75,78,66,73,79,0,69,65,82,89,67,81,90,84,0,80,61,91,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	arr[' '] = ' ';
	arr['\\'] = ']';
	string s;
	while (getline(cin,s)) {
		string ans;
		for (int i = 0; i < s.length(); i++) ans.push_back(arr[s[i]]);
		cout << ans << endl;
	}
}
