#include<bits/stdc++.h>
using namespace std;
int te, n, a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string max_ret, dp[104];
const string INF = "1111111111111111111111111111111111111111111111111112";

void make_max(int k){
	if(k & 1){
		max_ret += "7";
		k -= 3;
	}
	while(k){
		max_ret += "1";
		k -= 2;
	}
	return;
}

bool check(string a, string b){
	if(a.size() == b.size()) return a > b;
	else return a.size() > b.size();
}
string go(int idx){
	if(idx == 0 && idx != 1) return "";
	
	string &ret = dp[idx];
	if(ret != INF) return ret;
	
	for(int i = 0; i <= 9; i++){
		if(idx - a[i] == 0 && i == 0) continue;
		if(idx - a[i] == 1) continue;
		if(idx - a[i] >= 0 && check(ret, go(idx - a[i]) + to_string(i))) ret = go(idx - a[i]) + to_string(i);
	}
	return ret;
}
int main(){
	cin >> te;
	while(te--){
		cin >> n;
		max_ret = "";
		fill(dp, dp + 104, INF);
		
		make_max(n);
		cout << go(n) << " " << max_ret << "\n";
	}
}