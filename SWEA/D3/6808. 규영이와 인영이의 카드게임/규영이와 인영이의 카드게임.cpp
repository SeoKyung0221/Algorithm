#include<bits/stdc++.h>
using namespace std;
int te, tcnt, num, a[19], check[10], ret;
vector<int> v;
vector<int> vv;

void solve(int idx, int k, int y){
	if(idx == 9){
		if(k > y) ret++;
		return;
	}
	for(int i = 0; i < 9; i++){
		if(!check[i]){
			check[i] = 1;
			if(v[idx] > vv[i]) solve(idx + 1, k + v[idx] + vv[i], y);
			else solve(idx + 1, k, y + v[idx] + vv[i]);
			check[i] = 0;
		}
	}
}
int main(){
	cin >> te;
	while(te--){
		tcnt++;
		fill(a, a + 19, 0);
		ret = 0;
		v.clear();
		vv.clear();
		
		for(int i = 0; i < 9; i++){
			cin >> num;
			v.push_back(num);
			a[num]++;
		}
		for(int i = 1; i <= 18; i++){
			if(a[i] == 0) vv.push_back(i);
		}
		solve(0, 0, 0);
		
		cout << "#" << tcnt << " " << ret << " " << 362880 - ret << "\n";
	}
}