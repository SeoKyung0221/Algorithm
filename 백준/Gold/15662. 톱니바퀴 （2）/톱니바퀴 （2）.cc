#include<bits/stdc++.h>
using namespace std;
int t, k, a, b, ret;
string s[1004];

void rotate_(int pos, int flag){
	if(flag == 0) rotate(s[pos].begin(), s[pos].begin() + 1, s[pos].end());
	else rotate(s[pos].rbegin(), s[pos].rbegin() + 1, s[pos].rend());
}
int findL(int pos){
	for(int i = pos; i >= 1; i--){
		if(s[i][6] == s[i-1][2]){
			return i;
		}
	}
	return 0;
}
int findR(int pos){
	for(int i = pos; i <= t-2; i++){
		if(s[i][2] == s[i+1][6]){
			return i;
		}
	}
	return t-1;
}

int main(){
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> s[i];
	}
	cin >> k;
	for(int i = 0; i < k; i++){
		cin >> a >> b;
		a--;
		b = (b == -1) ? 0 : 1;
		int l = findL(a);
		int r = findR(a);
		
		int cnt = 0;
		for(int j = a; j >= l; j--){
			if(cnt % 2 == 0) rotate_(j, b);
			else rotate_(j, !b);
			cnt++;
		}
		cnt = 1;
		for(int j = a+1; j <= r; j++){
			if(cnt % 2 == 0) rotate_(j, b);
			else rotate_(j, !b);
			cnt++;
		}
	}
	for(int i = 0; i < t; i++){
		if(s[i][0] == '1') ret++;
	}
	cout << ret << "\n";
}