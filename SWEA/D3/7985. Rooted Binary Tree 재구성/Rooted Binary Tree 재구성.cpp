#include<bits/stdc++.h>
using namespace std;
int te, tcnt, k, a[1030];
vector<int> adj[14];

void go(int s, int e, int level){
	if(s > e) return;
	
	if(s == e){
		adj[level].push_back(a[s]);
		return;
	}
	int mid = (s + e) / 2;
	adj[level].push_back(a[mid]);
	go(s, mid-1, level + 1);
	go(mid + 1, e, level + 1);
}
int main(){
	cin >> te;
	while(te--){
		tcnt++;
		fill(a, a + 1030, 0);
		for(int i = 0; i < 14; i++){
			adj[i].clear();
		}
		
		cin >> k;
		int n = (int)pow(2, k) - 1;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		go(0, n, 0);
		cout << "#" << tcnt << " ";
		for(int i = 0; i < k; i++){
			for(int j : adj[i]){
				cout << j << " ";
			}
			cout << "\n";
		}
	}	
}