#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, num, lis[1000004], len;
pair<int ,int> a[1000004];
stack<int> stk;

int main(){
	fill(lis, lis + 1000004, INF);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num;
		auto lowerPos = lower_bound(lis, lis + len, num);
		int _pos = lower_bound(lis, lis + len, num) - lis;
		if(*lowerPos == INF) len++;
		*lowerPos = num;
		a[i].first = _pos;
		a[i].second = num;
	}
	cout << len << "\n";
	for(int i = n - 1; i >= 0; i--){
		if(a[i].first == len - 1){
			stk.push(a[i].second);
			len--;
		}
	}
	while(stk.size()){
		cout << stk.top() << " ";
		stk.pop();
	}
}