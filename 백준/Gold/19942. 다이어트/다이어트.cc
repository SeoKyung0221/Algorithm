#include<bits/stdc++.h>
using namespace std;
int n, mp, mf, ms, mv, ret = 1e9;
struct A{
	int p, f, s, v, c;
};
A a[20];
map<int, vector<vector<int>>> sto;
int main(){
	cin >> n >> mp >> mf >> ms >> mv;
	for(int i = 0; i < n; i++){
		cin >> a[i].p >> a[i].f >> a[i].s >> a[i].v >> a[i].c;
	}
	for(int i = 0; i < (1 << n); i++){
		vector<int> v;
		int cp = 0, cf = 0, cs = 0, cv = 0, cc = 0;
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
				sto[ret].push_back(v);
			}
		}
	}
	if(ret == 1e9) cout << "-1";
	else{
		cout << ret << "\n";
		sort(sto[ret].begin(), sto[ret].end());
		for(int i : sto[ret][0]){
			cout << i << " ";
		}
	}
}