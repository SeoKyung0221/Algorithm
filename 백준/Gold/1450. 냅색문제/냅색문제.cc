#include<bits/stdc++.h>
using namespace std;
int n, c, a[34], ret;
vector<int> v;
vector<int> vv;

void go(int here, int n, vector<int> &v, int sum){
	if(sum > c){
		return;
	}
	if(here > n){
		v.push_back(sum);
		return;
	}
	go(here + 1, n, v, sum + a[here]);
	go(here + 1, n, v, sum);
}
int main(){
	cin >> n >> c;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	go(0, n / 2 - 1, v, 0);
	go(n / 2, n - 1, vv, 0);
	sort(v.begin(), v.end());
	sort(vv.begin(), vv.end());
	for(int b : v){
		ret += upper_bound(vv.begin(), vv.end(), c - b) - vv.begin();
	}
	cout << ret << "\n";
}