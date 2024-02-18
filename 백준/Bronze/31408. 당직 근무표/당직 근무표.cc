#include<bits/stdc++.h>
using namespace std;
int n, num, a[100004], mx, cnt, _num;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num;
		a[num]++;
		mx = max(mx, a[num]);
		if(mx == a[num]) _num = num;
	}
	for(int i = 0; i < 100004; i++){
		if(i != _num) cnt += a[i];
	}
	if(cnt < mx - 1) cout << "NO\n";
	else cout << "YES\n";
	return 0;
}