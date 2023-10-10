#include<bits/stdc++.h>
using namespace std;
int n, a[2004], m, s, e, dp[2004][2004];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		dp[i][i] = 1;
	}
	for(int i = 0; i < n-1; i++){
		if(a[i] == a[i+1]) dp[i][i+1] = 1;
	}
	for(int _size = 2; _size <= n-1; _size++){
		for(int i = 0; i + _size < n; i++){
			if(a[i] == a[i + _size] && dp[i+1][i+ _size - 1]) dp[i][i + _size] = 1;
		}
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> s >> e;
		s--; e--;
		cout << dp[s][e] << "\n";
	}
}