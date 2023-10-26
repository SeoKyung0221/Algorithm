#include<bits/stdc++.h>
using namespace std;
int n, col[19], ret;

bool check(int idx){
	for(int i = 0; i < idx; i++){
		if(col[idx] == col[i] || idx - i == abs(col[idx] - col[i])) return false;
	}
	return true;
}
void solve(int idx){
	if(idx == n){
		ret++;
		return;
	}
	for(int j = 0; j < n; j++){
		col[idx] = j;
		if(check(idx)) solve(idx+1);
	}
}
int main(){
	cin >> n;
	solve(0);
	cout << ret << "\n";
	return 0;
}