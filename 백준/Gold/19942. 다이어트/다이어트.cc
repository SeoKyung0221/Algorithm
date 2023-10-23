#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, mp, mf, ms, mv, ret = INF;
struct A{
	int p, f, s, v, c;
};

A a[16];
map<int, vector<vector<int>>> mpp;
 
int main(){
	cin >> n >> mp >> mf >> ms >> mv;
	for(int i = 0; i < n; i++){
		cin >> a[i].p >> a[i].f >> a[i].s >> a[i].v >> a[i].c;
	}
	for(int i = 0; i < (1 << n); i++){
		int cp = 0, cf = 0, cs = 0, cv = 0, cc = 0;
		vector<int> v;
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				v.push_back(j+1);
				cp += a[j].p;
				cf += a[j].f;
				cs += a[j].s;
				cv += a[j].v;
				cc += a[j].c;
			}
		}
		if(cp >= mp && cf >= mf && cs >= ms && cv >= mv){
			if(ret >= cc){
				ret = cc;
				mpp[ret].push_back(v);
			}
		}
	}
	if(ret == INF) cout << -1 << "\n";
	else{
		sort(mpp[ret].begin(), mpp[ret].end());
		cout << ret << "\n";
		for(int i : mpp[ret][0]){
			cout << i << " ";
		}
	}
}