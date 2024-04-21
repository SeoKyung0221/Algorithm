#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, a[404][404], b, c, d, e, f, ret;
vector<int> adj[404], seq;
struct B{
	int y, x, love, emp;
};
vector<B> v;

struct cmp{
	bool operator()(B a, B b){
		if(a.love == b.love){
			if(a.emp == b.emp){
				if(a.y == b.y) return a.x < b.x;
				else return a.y < b.y;
			}else return a.emp > b.emp;
		}else return a.love > b.love;
	} 
};

void solve(int k){
	v.clear();
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] != 0) continue;
			int love = 0, emp = 0;
			for(int h = 0; h < 4; h++){
				int ny = i + dy[h];
				int nx = j + dx[h];
				if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
				if(a[ny][nx] == 0) emp++;
				for(int p : adj[k]){
					if(p == a[ny][nx]) love++;
				}
			}
			v.push_back({i, j, love, emp});
		}
	}
	
	sort(v.begin(), v.end(), cmp());
	a[v[0].y][v[0].x] = k;
}
int main(){
	cin >> n;
	for(int i = 0; i < n * n; i++){
		cin >> b >> c >> d >> e >> f;
		adj[b].push_back(c);
		adj[b].push_back(d);
		adj[b].push_back(e);
		adj[b].push_back(f);
		seq.push_back(b);
	}
	for(int i : seq){
		solve(i);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int love = 0;
			for(int h = 0; h < 4; h++){
				int ny = i + dy[h];
				int nx = j + dx[h];
				if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
				for(int p : adj[a[i][j]]){
					if(p == a[ny][nx]) love++;
				}
			}
			if(love == 1) ret += 1;
			else if(love == 2) ret += 10;
			else if(love == 3) ret += 100;
			else if(love == 4) ret += 1000;
		}
	}
	cout << ret << "\n";
}