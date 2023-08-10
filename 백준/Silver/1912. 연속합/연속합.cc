#include<bits/stdc++.h>
using namespace std;
int n, num, sum, ret = -1e9;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num;
		sum += num;
		ret = max(ret, sum);
		if(sum < 0) sum = 0;
	}
	cout << ret << '\n';
}