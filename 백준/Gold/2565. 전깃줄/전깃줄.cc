#include<bits/stdc++.h>
using namespace std;
int n, a, b, lis[104], len;
vector<pair<int,int>> v;

int main(){
	fill(&lis[0], &lis[0] + 104, 504);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++){
		auto lowerPos = lower_bound(lis, lis + len, v[i].second);
		if(*lowerPos == 504) len++;
		*lowerPos = v[i].second;
	}
	cout << n - len << "\n";
}