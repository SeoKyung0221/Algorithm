#include<bits/stdc++.h>
using namespace std;
int t, w, a[1004], dp[1004][32][2];

int go(int idx, int move, int flag){
	if(idx == t){
		return 0;
	}
	if(move > w) return -1e9;
	
	int &ret = dp[idx][move][flag];
	if(ret != -1) return ret;
	
	int _flag = (flag == 1) ? 2 : 1;
	
	if(a[idx] == _flag){
		ret = max(go(idx + 1, move + 1, !flag), go(idx + 1, move, flag)) + 1;
	}else{
		ret = max(go(idx + 1, move + 1, !flag), go(idx + 1, move, flag));
	}
	return ret;
}
int main(){
	memset(dp, -1, sizeof(dp));
	cin >> t >> w;
	for(int i = 0; i < t; i++){
		cin >> a[i];
	}
	cout << max(go(0, 0, 0), go(0, 1, 1)) << "\n";
}