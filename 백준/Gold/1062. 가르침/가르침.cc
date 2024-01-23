#include<bits/stdc++.h>
using namespace std;
int n, k, a[54], ret;
string s;

int count(int mask){
	int ret = 0;
	for(int i = 0; i < n; i++){
		if(mask && (mask & a[i]) == a[i]) ret++; 
	}
	return ret;
}
int go(int idx, int cnt, int mask){
	if(cnt < 0) return 0;
	if(idx == 26) return count(mask);
	int ret = go(idx + 1, cnt - 1, mask | (1 << idx));
	if('a' + idx != 'a' && 'a' + idx != 'n' && 'a' + idx != 't' && 'a' + idx != 'i' && 'a' + idx != 'c'){
		ret = max(ret, go(idx + 1, cnt, mask));
	}
	return ret;
}
int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(char str : s){
			a[i] |= (1 << (str - 'a'));
		}
	}
	
	cout << go(0, k, 0) << "\n";
}