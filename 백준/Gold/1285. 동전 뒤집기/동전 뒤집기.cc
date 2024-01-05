#include<bits/stdc++.h>
using namespace std;
int n, a[24], ret = 1e9;
string s;

void go(int idx){
	if(idx == n){
		int sum = 0;
		for(int i = 0; i < n; i++){
			int cnt = 0;
			for(int j = 0; j < n; j++){
				if(a[j] & (1 << i)) cnt++;
			}
			sum += min(cnt, n - cnt); 
		}
		ret = min(ret, sum);
		return;
	}
	go(idx + 1);
	a[idx] = ~a[idx];
	go(idx + 1);
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		int value = 1;
		for(int j = 0; j < s.size(); j++){
			if(s[j] == 'T') a[i] |= value;
			value *= 2;
		}
	}
	go(0);
	
	cout << ret << "\n";
	return 0;
}