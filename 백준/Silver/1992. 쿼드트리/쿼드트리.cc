#include<bits/stdc++.h>
using namespace std;
int n;
char a[68][68];

string go(int y, int x, int n){
	if(n == 1) return string(1, a[y][x]);
	string ret = "";
	for(int i = y; i < y + n; i++){
		for(int j = x; j < x + n; j++){
			if(a[y][x] != a[i][j]){
				ret += "(";
				ret += go(y, x, n / 2);
				ret += go(y, x + n/2, n/2);
				ret += go(y + n/2, x, n/2);
				ret += go(y + n/2, x + n/2, n/2);
				ret += ")";
				return ret;
			}
		}
	}
	return string(1, a[y][x]);
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf(" %1c", &a[i][j]);
		}
	}
	cout << go(0, 0, n) << "\n";
}