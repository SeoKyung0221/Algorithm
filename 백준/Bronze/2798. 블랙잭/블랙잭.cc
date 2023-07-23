#include<bits/stdc++.h>
using namespace std;
int n, m, ret, a[104];
vector<int> b;

void combi(int start, vector<int> b){
	if(b.size() == 3){
		int cnt = 0;
		for(int i : b){
			cnt += i;
		}
		if(cnt <= m){
			ret = max(ret, cnt);
		}
		return;
	}
	for(int i = start+1; i < n; i++){
		b.push_back(a[i]);
		combi(i, b);
		b.pop_back();
	}
	return;
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	} 
	combi(-1, b);
	
	cout << ret << "\n";
}