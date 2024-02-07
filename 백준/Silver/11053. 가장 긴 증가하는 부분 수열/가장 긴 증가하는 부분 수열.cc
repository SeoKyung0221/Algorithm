#include<bits/stdc++.h>
using namespace std;
int n, num, lis[1004], len;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num;
		auto lowerPos = lower_bound(lis, lis + len, num);
		if(*lowerPos == 0) len++;
		*lowerPos = num;
	}
	cout << len << "\n";
}