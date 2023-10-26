#include<bits/stdc++.h>
using namespace std;
int te, tcnt, k, ret;
string s;

void solve(int idx, int cnt){
	if(cnt == 0){
		ret = max(ret, stoi(s));
		return;
	}
	for(int i = idx; i < s.size() - 1; i++){
		for(int j = i + 1; j < s.size(); j++){
			swap(s[i], s[j]);
			solve(i, cnt-1);
			swap(s[i], s[j]);
		}
	}
	return;
}
int main(){
	cin >> te;
	while(te--){
		tcnt++;
		cin >> s >> k;
		if(s.size() < k) k = s.size();
		ret = 0;
		solve(0, k);
		cout << "#" << tcnt << " " << ret << "\n";
	}
}