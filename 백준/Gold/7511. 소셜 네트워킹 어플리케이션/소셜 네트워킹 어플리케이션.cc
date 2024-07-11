#include<bits/stdc++.h>
using namespace std;
int te, n, m, k, a, b, parent[1000004];

int Find(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	
	if(x == y) return;
	
	if(x < y) parent[y] = x;
	else parent[x] = y;
	
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> te;
	for(int t = 1; t <= te; t++){
		cin >> n >> k;
		for(int i = 0; i < n; i++){
			parent[i] = i;
		}
		
		for(int i = 0; i < k; i++){
			cin >> a >> b;
			Union(a, b);
		}
		
		cout << "Scenario " << t << ":\n";
		cin >> m;
		for(int i = 0; i < m; i++){
			cin >> a >> b;
			if(Find(a) == Find(b)) cout << "1\n";
			else cout << "0\n";
		}
		cout << "\n";
	}
}