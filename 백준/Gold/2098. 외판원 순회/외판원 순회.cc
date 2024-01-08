#include<bits/stdc++.h>
using namespace std;
int n, a[18][18], dp[18][1 << 17];

int go(int idx, int visited){
	if(visited == (1 << n) - 1){
		return a[idx][0] == 0 ? 1e9 : a[idx][0];
	}
	int &ret = dp[idx][visited];
	if(ret != -1) return ret;
	
	ret = 1e9;
	for(int i = 0; i < n; i++){
		if(visited & (1 << i)) continue;
		if(a[idx][i] == 0) continue;
		ret = min(ret , go(i, visited | (1 << i)) + a[idx][i]);
	}
	return ret;
}
int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	cout << go(0, 1) << "\n";
}