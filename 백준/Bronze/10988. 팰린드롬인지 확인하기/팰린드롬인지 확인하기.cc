#include<bits/stdc++.h>
using namespace std;
string s;

int main(){
	cin >> s;
	string s2;
	s2 = s;
	reverse(s2.begin(), s2.end());
	if(s == s2) cout << "1\n";
	else cout << "0\n";
}