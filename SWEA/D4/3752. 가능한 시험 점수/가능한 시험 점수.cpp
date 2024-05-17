#include<bits/stdc++.h>
using namespace std;
int te, n, temp, visited[10004];

int main(){
	cin >> te;
	for(int t = 1; t <= te; t++){
		int ret = 0, mx = 0;
		vector<int> v;
		
		cin >> n;
		
		memset(visited, 0, sizeof(visited));
		visited[0] = 1;
		v.push_back(0);
		
		for(int i = 0; i < n; i++){
			cin >> temp;
			mx += temp;
			int k = v.size();
			for(int j = 0; j < k; j++){
				int p = temp + v[j];
				if(visited[p] == 1) continue;
				v.push_back(p);
				visited[p] = 1;
			}
		}
		for(int i = 0; i <= mx; i++){
			if(visited[i] == 1) ret++; 
		}
		cout << "#" << t << " " << ret << "\n";
	}
}