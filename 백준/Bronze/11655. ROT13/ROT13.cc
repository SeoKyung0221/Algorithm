#include<bits/stdc++.h>
using namespace std;
string s, ret;

int main(){
	getline(cin, s);
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= 'a' && s[i] <= 'z') ret += ((s[i] + 13 + - 'a') % 26) + 'a';
		else if(s[i] >= 'A' && s[i] <= 'Z') ret += ((s[i] + 13 + - 'A') % 26) + 'A';
		else ret += s[i];
	}
	cout << ret << '\n';
}