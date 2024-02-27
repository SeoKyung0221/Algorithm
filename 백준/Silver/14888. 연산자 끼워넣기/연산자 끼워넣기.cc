#include<bits/stdc++.h>
using namespace std;
int n, a[104], b[4], mn = 1e9, mx = -1e9;

void go(int idx, int cnt){
	if(idx == n-1){
		mn = min(mn, cnt);
		mx = max(mx, cnt);
		return;
	}
	for(int i = 0; i < 4; i++){
		if(b[i] == 0) continue;
		b[i]--;
		if(i == 0){
			go(idx + 1, cnt + a[idx + 1]);
		}else if(i == 1){
			go(idx + 1, cnt - a[idx + 1]);
		}else if(i == 2){
			go(idx + 1, cnt * a[idx + 1]);
		}else{
			go(idx + 1, cnt / a[idx + 1]);
		}
		b[i]++;
	}
	return;
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < 4; i++){
		cin >> b[i];
	}
	go(0, a[0]);
	
	cout << mx << "\n" << mn << "\n";
}