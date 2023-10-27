#include<bits/stdc++.h>
using namespace std;
int te, tcnt, n, k, a[24], ret;

void solve(int sum, int here){
	if(here == n) return;
	
	if(sum + a[here] == k){
		ret++;
		solve(sum, here + 1);
		return;
	}else if(sum + a[here] > k){
		return;
	}else{
		solve(sum, here + 1);
		solve(sum + a[here], here + 1);
	}
	return;
}
int main(){
	cin >> te;
	while(te--){
		tcnt++;
		fill(a, a + 24, 0);
		ret = 0;
		
		cin >> n >> k;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n);
		solve(0, 0);
		cout << "#" << tcnt << " " << ret << "\n";
	}
}