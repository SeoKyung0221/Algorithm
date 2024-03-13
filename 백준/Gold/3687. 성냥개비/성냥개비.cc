#include<bits/stdc++.h>
using namespace std;
int te, n, a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string max_ret, dp[104];
const string INF = "1111111111111111111111111111111111111111111111111112";

void make_max(int n){
	if(n & 1){
		max_ret += "7";
		n -= 3;
	}
	while(n){
		max_ret += "1";
		n -= 2;
	}
	return;
}

bool check(string a, string b){
	if(a.size() == b.size()) return a > b;
	else return a.size() > b.size();
}
string make_min(int idx){
	if(idx == 0) return "";
	
	string &ret = dp[idx];
	if(ret != INF) return ret;
	
	for(int i = 0; i <= 9; i++){
		if(idx - a[i] == 0 && i == 0) continue;
		if(idx - a[i] >= 0 && idx - a[i] != 1){
			if(check(ret, make_min(idx - a[i]) + to_string(i))){
				ret = make_min(idx - a[i]) + to_string(i);
			}
		}
	}
	return ret;
}
int main(){
	cin >> te;
	while(te--){
		max_ret = "";
		fill(dp, dp + 104, INF);
		
		cin >> n;
		
		make_max(n);
		
		cout << make_min(n) << " " << max_ret << "\n";
	}
}