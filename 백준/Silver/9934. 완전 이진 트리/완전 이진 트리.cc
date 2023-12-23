#include<bits/stdc++.h>
using namespace std;
int k, a[1030];
vector<int> adj[11];

void go(int s, int e, int level){
	if(s > e) return;
	if(s == e){
		adj[level].push_back(a[e]);
		return;
	}
	int mid = (s + e) / 2;
	adj[level].push_back(a[mid]);
	go(s, mid - 1, level + 1);
	go(mid + 1, e, level + 1);
	return;
}
int main(){
	cin >> k;
	int n = (int)pow(2, k) - 1;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	go(0, n-1, 0);
	for(auto i : adj){
		for(int j : i){
			cout << j << " ";
		}
		cout << "\n";
	}
}
