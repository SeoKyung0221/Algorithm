#include<bits/stdc++.h>
using namespace std;
int num, a[10][10], ret;

int main(){
	memset(a, -1, sizeof(a));
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			cin >> num;
			a[i][j] = num;
			ret = max(ret, num);
		}
	}
	
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			if(a[i][j] == ret){
				cout << ret << "\n";
				cout << i << " " << j << "\n";
				break;
			}
		}
	}
	
	return 0;
}