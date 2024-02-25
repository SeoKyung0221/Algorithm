#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, num, ret;
stack<pair<ll, ll>> stk;

int main(){
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> num;
		int cnt = 1;
		while(stk.size() && stk.top().first <= num){
			ret += stk.top().second;
			if(stk.top().first == num){
				cnt = stk.top().second + 1;
			}else{
				cnt = 1;
			}
			stk.pop();
		}
		if(stk.size()) ret++;
		stk.push({num, cnt});
	}
	cout << ret << "\n";
}