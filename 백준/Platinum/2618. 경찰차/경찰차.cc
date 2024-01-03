#include<bits/stdc++.h>
using namespace std;
int n, w, p, q, dp[1004][1004];
pair<int, int> a[1004];

int go(int one, int two){
	if(one == w + 2 || two == w + 2){
		return 0;
	}
	int &ret = dp[one][two];
	if(ret != 0) return ret;
	
	int next = max(one, two) + 1;

	int p = go(next, two) + (abs(a[next].first - a[one].first) + abs(a[next].second - a[one].second));
	int q = go(one, next) + (abs(a[next].first - a[two].first) + abs(a[next].second - a[two].second));

	ret = min(p, q);
	return ret;
}
int main(){
	cin >> n >> w;
	a[1] = make_pair(1, 1);
	a[2] = make_pair(n, n);
	for(int i = 3; i <= w + 2; i++){
		cin >> p >> q;
		a[i] = make_pair(p, q);
	}
	cout << go(1, 2) << "\n";
	
	int one = 1;
	int two = 2;
	for(int i = 3; i <= w + 2; i++){
		if(dp[one][i] + (abs(a[i].first - a[two].first) + abs(a[i].second - a[two].second)) > dp[i][two] + (abs(a[i].first - a[one].first) + abs(a[i].second - a[one].second))){
			cout << "1\n";
			one = i; 
		}else{
			cout << "2\n";
			two = i;
		}
	}
	return 0;
}