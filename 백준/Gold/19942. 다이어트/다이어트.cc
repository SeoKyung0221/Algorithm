#include<bits/stdc++.h>
using namespace std;
int n, mp, mf, ms, mv, ret = 1e9;
struct A{
	int p = 0;
	int f = 0;
	int s = 0;
	int v = 0;
	int c = 0;
};
A a[16];
map<int, vector<vector<int>>> ma;
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
				v.push_back(j + 1);
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
				ma[ret].push_back(v);
			}
		}
	}
	sort(ma[ret].begin(), ma[ret].end());
	if(ret == 1e9) cout << "-1\n";
	else{
		cout << ret << "\n";
		for(int i : ma[ret][0]){
			cout << i << " ";
		}
	}
}