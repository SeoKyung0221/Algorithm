#include<bits/stdc++.h>
using namespace std;
int n, a[1004], b[1004], ret = -1;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		b[i] = a[n-1-i];
	}
	for(int i = 0; i < n; i++){
		int lis1[1004], lis2[1004], len1 = 0, len2 = 0;
		fill(lis1, lis1+1004, 0);
		fill(lis2, lis2+1004, 0);
		for(int j = 0; j <= i; j++){
			auto pos = lower_bound(lis1, lis1 + len1, a[j]);
			if(*pos == 0) len1++;
			*pos = a[j]; 
		}
		for(int j = 0; j <= n-1-i; j++){
			auto pos = lower_bound(lis2, lis2 + len2, b[j]);
			if(*pos == 0) len2++;
			*pos = b[j];
		}
		ret = max(ret, len1 + len2 - 1);
	}
	cout << ret << "\n";
}