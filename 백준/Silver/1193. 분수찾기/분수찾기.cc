#include<bits/stdc++.h>
using namespace std;
int x, ret;

int main(){
	cin >> x;
	int i = 1;
	while(x > i * (i+1) / 2){
		i++;
	}
	i -= 1;
	int k = i + 1;
	int cnt = x - (i * (i+1) / 2) - 1;
	if(k % 2 != 0){
		cout << k-cnt << "/" << 1+cnt << "\n";
	}else{
		cout << 1+cnt << "/" << k-cnt << "\n";
	}
	return 0;
}