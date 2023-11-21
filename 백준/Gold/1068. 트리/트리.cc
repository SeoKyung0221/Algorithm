#include<bits/stdc++.h>
using namespace std;
int n, num, k, root, ret;
vector<int> adj[54];

void go(int here){
	int flag = 0;
	for(int i : adj[here]){
		if(i == k) continue;
		flag = 1;
		go(i);
	}
	if(flag == 0) ret++;
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num;
		if(num == -1) root = i;
		else{
			adj[num].push_back(i);
		}
	}
	cin >> k;
	if(k == root){
		cout << 0 << "\n";
		return 0;
	}
	go(root);
	cout << ret << "\n";
}