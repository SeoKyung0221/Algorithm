#include<bits/stdc++.h>
using namespace std;
int n, a[3], dp[64][64][64];

int go(int s1, int s2, int s3){
	if(s1 <= 0 && s2 <= 0 && s3 <= 0) return 0;
	
	if(s1 <= 0) s1 = 0;
	if(s2 <= 0) s2 = 0;
	if(s3 <= 0) s3 = 0;
	
	int &ret = dp[s1][s2][s3];
	if(ret != 1e9) return ret;
	
	ret = min(ret, go(s1 - 9, s2 - 3, s3 - 1) + 1);
	ret = min(ret, go(s1 - 9, s2 - 1, s3 - 3) + 1);
	ret = min(ret, go(s1 - 3, s2 - 9, s3 - 1) + 1);
	ret = min(ret, go(s1 - 1, s2 - 9, s3 - 3) + 1);
	ret = min(ret, go(s1 - 3, s2 - 1, s3 - 9) + 1);
	ret = min(ret, go(s1 - 1, s2 - 3, s3 - 9) + 1);
	
	return ret;
}
int main(){
	fill(&dp[0][0][0], &dp[0][0][0] + 64 * 64 * 64, 1e9);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << go(a[0], a[1], a[2]) << "\n";
}