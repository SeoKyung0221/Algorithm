#include<bits/stdc++.h>
using namespace std;
int n, k, a[11], ret;

int main(){
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(int i = n - 1; i >= 0; i--){
		ret += k / a[i];
		k %= a[i];
	}
	cout << ret << "\n";
}