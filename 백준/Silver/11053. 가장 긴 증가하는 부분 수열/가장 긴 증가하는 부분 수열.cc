#include<bits/stdc++.h>
using namespace std;
int n, num, lis[1004], len, ret;

int main(){
	cin >> n;
	fill(&lis[0], &lis[0] + 1004, 1004);
	for(int i = 0; i < n; i++){
		cin >> num;
		auto lowerPos = lower_bound(lis, lis+len, num);
		if(*lowerPos == 1004) len++;
		*lowerPos = num;
	}
	cout << len << "\n";
}