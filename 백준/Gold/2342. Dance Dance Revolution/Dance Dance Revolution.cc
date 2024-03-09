#include<bits/stdc++.h>
using namespace std;
int num, dp[100004][5][5];
vector<int> v;

int move(int a, int b){
	
	if(a == 0) return 2;
	else if(a == b) return 1;
	else if(abs(a - b) == 2) return 4;
	else return 3;
}
int go(int idx, int left, int right){
	if(idx == v.size()) return 0;
	
	int &ret = dp[idx][left][right];
	if(ret != 1e9) return ret;
	
	ret = min(ret, go(idx + 1, v[idx], right) + move(left, v[idx]));
	ret = min(ret, go(idx + 1, left, v[idx]) + move(right, v[idx]));
	
	return ret; 
}
int main(){
	while(true){
		cin >> num;
		if(num == 0) break;
		v.push_back(num);
	}
	fill(&dp[0][0][0], &dp[0][0][0] + 100004 * 5 * 5, 1e9);
	cout << go(0, 0, 0) << "\n";
}