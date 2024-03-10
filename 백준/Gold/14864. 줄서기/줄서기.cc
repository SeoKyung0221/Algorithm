#include<bits/stdc++.h>
using namespace std;
int n, m, x, y, a[100004];
map<int, int> mp;

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		a[x]++; a[y]--;
	}
	for(int i = 1; i <= n; i++){
		a[i] += i;
		mp[a[i]]++;
	}
	int flag = 0;
	for(int i = 1; i <= n; i++){
		if(mp[a[i]] >= 2) flag = 1;
	}
	if(flag) cout << -1 << "\n";
	else{
		for(int i = 1; i <= n; i++){
			cout << a[i] << " ";
		}
	}
}