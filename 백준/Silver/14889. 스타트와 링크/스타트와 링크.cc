#include<bits/stdc++.h>
using namespace std;
int n, a[24][24], ret = 1e9;

int go(vector<int> &start, vector<int> &link){
	int s1 = 0, s2 = 0;
	for(int i = 0; i < n / 2; i++){
		for(int j = 0; j < n / 2; j++){
			if(i == j) continue;
			s1 += a[start[i]][start[j]];
			s2 += a[link[i]][link[j]];
		}
	}
	return abs(s1 - s2);
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < (1 << n); i++){
		vector<int> start, link;
		if(__builtin_popcount(i) != n / 2) continue;
		for(int j = 0; j < n; j++){
			if(i & (1 << j)) start.push_back(j + 1);
			else link.push_back(j + 1);
		}
		ret = min(ret, go(start, link));
	}
	cout << ret << "\n";
}