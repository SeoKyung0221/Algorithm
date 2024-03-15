#include<bits/stdc++.h>
using namespace std;
int n, a[21][21], ret = 1e9;

int solve(vector<int> &start, vector<int> &link){
	int ans1 = 0, ans2 = 0;
	
	for(int i = 0; i < n / 2; i++){
		for(int j = 0; j < n / 2; j++){
			if(i == j) continue;
			ans1 += a[start[i]][start[j]];
			ans2 += a[link[i]][link[j]];
		}
	}
	return abs(ans1 - ans2);
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i < (1 << n) - 1; i++){
		if(__builtin_popcount(i) != n / 2) continue; 
		vector<int> start, link;
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				start.push_back(j + 1);
			}else link.push_back(j + 1);
		}
		ret = min(ret, solve(start, link));
	}
	cout << ret << "\n";
}