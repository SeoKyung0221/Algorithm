#include<bits/stdc++.h>
using namespace std;
int n, x, y;

vector<pair<int,int>> v;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		v.push_back({y, x});
	}
	sort(v.begin(), v.end());
	for(pair<int,int> i : v){
		cout << i.second << " " << i.first <<"\n";
	}
}