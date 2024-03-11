#include<bits/stdc++.h>
using namespace std;
int te, n, a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string max_ret, min_dp[104];

bool check(string a, string b){
	if(a.size() == b.size()) return a > b;
	else return a.size() > b.size();
}
void max_go(int n){
	int temp = n;
	if(n & 1){
		max_ret += "7";
		temp -= 3;
	}
	while(temp){
		max_ret += "1";
		temp -= 2;
	}
	return;
}

string min_go(int n){
	if(n == 0 && n != 1) return "";
	
	string &ret = min_dp[n];
	if(ret != "1111111111111111111111111111111111111111111111111112") return ret;
	
	for(int i = 0; i <= 9; i++){
		if(i == 0 && n - a[i] == 0) continue;
		if(n - a[i] >= 0 && n - a[i] != 1 && check(ret, min_go(n - a[i]) + to_string(i))) ret = min_go(n - a[i]) + to_string(i);
	}
	return ret;
}
int main(){
	cin >> te;
	while(te--){
		cin >> n;
		max_ret = "";
		fill(min_dp, min_dp + 104, "1111111111111111111111111111111111111111111111111112");
		
		max_go(n);
		cout << min_go(n) << " " << max_ret << "\n";
	}
}