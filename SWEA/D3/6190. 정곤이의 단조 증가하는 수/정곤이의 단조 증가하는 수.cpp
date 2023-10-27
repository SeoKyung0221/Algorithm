#include<bits/stdc++.h>
using namespace std;
int te, tcnt, n, a[1004], ret;

bool check(int k){
	string s = to_string(k);
	char b = s[0];
	for(int i = 1; i < s.size(); i++){
		if(b <= s[i]){
			b = s[i];
		}else return false;
	}
	return true;
}
int main(){
	cin >> te;
	while(te--){
		tcnt++;
		fill(a, a + 1004, 0);
		ret = - 1;
		
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		
		for(int i = 0; i < n-1; i++){
			for(int j = i + 1; j < n; j++){
				if(check(a[i] * a[j])){
					ret = max(ret, a[i] * a[j]);
				}
			}
		}
		cout << "#" << tcnt << " " << ret << "\n";
	}
}