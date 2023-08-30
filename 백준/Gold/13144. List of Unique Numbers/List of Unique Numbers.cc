#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s, e, n, a[100004], cnt[100004], ret;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	while(e < n){
		if(cnt[a[e]] != 0){
			ret += e - s;
			cnt[a[s]]--;
			s++;
		}else{
			cnt[a[e]]++;
			e++;
		}
	}
	ret += ll((e - s) * (e - s + 1) / 2);
	cout << ret << "\n";
}