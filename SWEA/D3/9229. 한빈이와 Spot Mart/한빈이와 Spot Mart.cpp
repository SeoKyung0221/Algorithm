#include<bits/stdc++.h>
using namespace std;
int te, tcnt, n, m, a[1004], ret;

void combi(int start, vector<int> &b){
	if(b.size() == 2){
		int cnt = 0;
		for(int i : b){
			cnt += i;
		}
		if(cnt <= m) ret = max(ret, cnt);
		return;
	}
	for(int i = start + 1; i < n; i++){
		b.push_back(a[i]);
		combi(i, b);
		b.pop_back();
	}
}
int main(){
	cin >> te;
	while(te--){
		tcnt++;
		ret = -1;
		
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		vector<int> b;
		combi(-1, b);
		
		cout << "#" << tcnt << " " << ret << "\n";
	}
}