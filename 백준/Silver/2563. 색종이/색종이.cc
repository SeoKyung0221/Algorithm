#include<bits/stdc++.h>
using namespace std;
int m[104][104], n, a, b, ret;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		for(int i = a; i < 10 + a; i++){
			for(int j = b; j < 10 + b; j++){
				m[i][j]++;
			}
		}
	}
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			if(m[i][j] != 0){
				ret++;
			}
		}
	}
	cout << ret << "\n";
}