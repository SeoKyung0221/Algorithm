#include<bits/stdc++.h>
using namespace std;
int n, num, lis[1004], len;
pair<int, int> a[1004];
stack<int> stk;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num;
		auto lowerPos = lower_bound(lis, lis + len, num);
		int pos = lowerPos - lis;
		if(*lowerPos == 0) len++;
		*lowerPos = num;
		a[i].first = pos;
		a[i].second = num;
	}
	cout << len << "\n";
	for(int i = n - 1; i >= 0; i--){
		if(a[i].first == len - 1){
			len--;
			stk.push(a[i].second);
		}
	}
	while(stk.size()){
		cout << stk.top() << " ";
		stk.pop();
	}
}