#include<bits/stdc++.h>
using namespace std;
int n, m, num, a[44], dp[44];

int go(int cnt){
	if(cnt >= n-1) return 1;
	
	int &ret = dp[cnt];
	if(ret != 0) return ret;
	
	if(a[cnt]) ret += go(cnt+1);
	else if(a[cnt+1]) ret += go(cnt+1);
	else ret += go(cnt+1) + go(cnt+2);
	
	return ret;
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> num;
		a[num-1] = 1;
	}
	cout << go(0) << "\n";
}