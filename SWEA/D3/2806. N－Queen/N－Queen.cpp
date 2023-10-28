#include<bits/stdc++.h>
using namespace std;
int te, tcnt, n, col[14], ret;

bool check(int here){
	for(int i = 0; i < here; i++){
		if(col[i] == col[here] || here - i == abs(col[i] - col[here])) return false;
	}
	return true;
}
void solve(int here){
	if(here == n){
		ret++;
		return;
	}
	for(int i = 0; i < n; i++){
		col[here] = i;
		if(check(here)) solve(here + 1);
	}
}
int main(){
	cin >> te;
	while(te--){
		tcnt++;
		ret = 0;
		fill(col, col + 14, 0);
		cin >> n;
		
		solve(0);
		cout << "#" << tcnt << " " << ret << "\n";
	}
}