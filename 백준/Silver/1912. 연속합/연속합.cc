#include<bits/stdc++.h>
using namespace std;
int n, a[100004], cnt, ret = -1e9;

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cnt += a[i];
		ret = max(ret, cnt);
		if(cnt < 0) cnt = 0;
	}
	cout << ret << "\n";
}