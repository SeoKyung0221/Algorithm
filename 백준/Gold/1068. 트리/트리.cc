#include<bits/stdc++.h>
using namespace std;
int n, num, root;
vector<int> adj[54];

int dfs(int here){
	int ret = 0;
	int child = 0;
	for(int i : adj[here]){
		if(i == num) continue;
		ret += dfs(i);
		child++;
	}
	if(child == 0) return 1;
	return ret;
}
int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> num;
		if(num == -1) root = i;
		else adj[num].push_back(i);
	}
	
	cin >> num;
	if(num == root) cout << 0 << "\n";
	else cout << dfs(root) << "\n";
}