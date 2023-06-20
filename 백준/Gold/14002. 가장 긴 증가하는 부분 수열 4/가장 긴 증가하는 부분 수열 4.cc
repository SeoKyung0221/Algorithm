#include<bits/stdc++.h>
using namespace std;
int n, num, lis[1004], len, ret;
pair<int, int> a[1004];
stack<int> st;
int main(){
	cin >> n;
	fill(&lis[0], &lis[0] + 1004, 1004);
	for(int i = 0; i < n; i++){
		cin >> num;
		auto lowerPos = lower_bound(lis, lis+len, num);
		if(*lowerPos == 1004) len++;
		*lowerPos = num;
		int pos = (int)(lowerPos - &lis[0]);
		a[i].first = pos;
		a[i].second = num;
	}
	cout << len << "\n";
	for(int i = n-1; i >= 0; i--){
		if(a[i].first == len-1){
			st.push(a[i].second);
			len--;
		}
	}
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
	
}