#include<bits/stdc++.h>
using namespace std;
int n, m, a[2004], dp[2004][2004], p, q;

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
	for(int i = 0; i < n - 1; i++){
		if(a[i] == a[i+1]) dp[i][i+1] = 1;
	}
	for(int s = 2; s <= n - 1; s++){
		for(int i = 0; i + s < n; i++){
			if(a[i] == a[i + s] && dp[i + 1][i + s - 1]) dp[i][i+s] = 1;
		}
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> p >> q;
		p--; q--;
		cout << dp[p][q] << "\n";
	}
}