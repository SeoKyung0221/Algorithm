#include<bits/stdc++.h>
using namespace std;
int te, n;
char a[6] = {'(', ')', '{', '}', '[', ']'};
string dp[1004];
map<char, char> mp;

bool check(string a, string b){
	if(a == "" && b == "") return false;
	if(a == "") return true;
	if(a.size() == b.size()) return b < a;
	else return b.size() < a.size();
}
int main(){
	cin >> te;
	for(int i = 0; i < 6; i++){
		mp[i + '1'] = a[i]; 
	}
	dp[1] = "12";
	dp[2] = "34";
	dp[3] = "56";
	for(int i = 1; i <= 1000; i++){
		if(i % 2 == 0 && check(dp[i], '1' + dp[i / 2] + '2')) dp[i] = '1' + dp[i / 2] + '2';
		if(i % 3 == 0 && check(dp[i], '3' + dp[i / 3] + '4')) dp[i] = '3' + dp[i / 3] + '4';
		if(i % 5 == 0 && check(dp[i], '5' + dp[i / 5] + '6')) dp[i] = '5' + dp[i / 5] + '6';
		for(int j = 1; j <= i; j++){
			if(check(dp[i], dp[j] + dp[i - j])) dp[i] = dp[j] + dp[i-j];
		}
	}
	while(te--){
		cin >> n;
		for(char a : dp[n]) cout << mp[a];
		cout << "\n";
	}
}