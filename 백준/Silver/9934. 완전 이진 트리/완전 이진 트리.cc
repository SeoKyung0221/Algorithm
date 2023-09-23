#include<bits/stdc++.h>
using namespace std;
int k, a[1030];
vector<int> adj[11];

void solve(int s, int e, int level){
	if(s > e) return;
	if(s == e){
		adj[level].push_back(a[s]);
		return;
	}
	int mid = (s + e) / 2;
	adj[level].push_back(a[mid]);
	solve(s, mid-1, level+1);
	solve(mid+1, e, level+1);
	return;
}
int main(){
	cin >> k;
	int n = (int)pow(2, k) - 1;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	solve(0, n-1, 0);
	
	for(int i = 0; i < k; i++){
		for(int j : adj[i]){
			cout << j << " ";
		}
		cout << "\n";
	}
}