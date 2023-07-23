#include<bits/stdc++.h>
using namespace std;
int n, m, ret, a[104];
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	} 
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			for(int k = j+1; k < n; k++){
				int cnt = a[i] + a[j] + a[k];
				if(cnt <= m){
					ret = max(ret, cnt);
				}
			}
		}
	}
	cout << ret << "\n";
}