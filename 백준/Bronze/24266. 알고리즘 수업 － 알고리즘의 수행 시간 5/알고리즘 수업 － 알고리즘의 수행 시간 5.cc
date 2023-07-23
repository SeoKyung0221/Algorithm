#include<bits/stdc++.h>
using namespace std;
long long n, ret;

int main(){
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				ret++;
			}
		}
	}
	cout << ret << "\n" << 3 << "\n";
}