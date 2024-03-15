#include<bits/stdc++.h>
using namespace std;
int n, l, a[104][104], ret;

void solve(){
	for(int i = 0; i < n; i++){
		int cnt = 1;
		int j;
		for(j = 0; j < n - 1; j++){
			if(a[i][j] == a[i][j + 1]) cnt++;
			else if(a[i][j] == a[i][j + 1] - 1 && cnt >= l){
				cnt = 1;
			}else if(a[i][j] == a[i][j + 1] + 1 && cnt >= 0){
				cnt = -l + 1;
			}else break;
		}
		if(j == n - 1 && cnt >= 0) ret++;
	}
	
	for(int j = 0; j < n; j++){
		int cnt = 1;
		int i;
		for(i = 0; i < n - 1; i++){
			if(a[i][j] == a[i + 1][j]) cnt++;
			else if(a[i][j] == a[i + 1][j] - 1 && cnt >= l){
				cnt = 1;
			}else if(a[i][j] == a[i + 1][j] + 1 && cnt >= 0){
				cnt = -l + 1;
			}else break;
		}
		if(i == n - 1 && cnt >= 0) ret++;
	}
	return;
}
int main(){
	cin >> n >> l;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	solve();
	
	cout << ret << "\n";
}