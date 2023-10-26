#include<bits/stdc++.h>
using namespace std;
int te, tcnt, n, a[54][54], ret;

int main(){
	cin >> te;
	while(te--){
		memset(a, 0, sizeof(a));
		ret = 0;
		tcnt++;
		cin >> n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%1d", &a[i][j]);
			}
		}
		for(int i = 0; i < n / 2; i++){
			for(int j = n / 2 - i; j <= n / 2 + i; j++){
				ret += a[i][j];
			}
		}
		for(int i = 0; i < n / 2; i++){
			for(int j = n / 2 - i; j <= n / 2 + i; j++){
				ret += a[n-1 - i][j];
			}
		}
		for(int i = 0; i < n; i++){
			ret += a[n / 2][i];
		}
		cout << "#" << tcnt << " " << ret << "\n";
	}
}