#include<bits/stdc++.h>
using namespace std;
int n, a, b, c, dp[1004][1004], visited[54];
struct A{
	int x;
	int y;
	int z;
};
vector<A> v;

int solve(int STR, int INT){
	int &ret = dp[STR][INT];
	if(ret != -1) return ret;
	
	ret = 0;
	int point = 0;
	vector<int> vv;
	for(int i = 0; i < n; i++){
		if(v[i].x <= STR || v[i].y <= INT){
			ret++;
			if(visited[i] != 1){
				point += v[i].z;
				visited[i] = 1;
				vv.push_back(i);
			}
		}
	}
	for(int i = 0; i <= point; i++){
		int STR_N = min(1000, STR+i);
		int INT_N = min(1000, INT+point - i);
		ret = max(ret, solve(STR_N, INT_N));
	}
	for(int i : vv){
		visited[i] = 0;
	}
	return ret;
}
int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> b >> c;
		v.push_back({a, b, c});
	}
	cout << solve(1, 1) << "\n";
}