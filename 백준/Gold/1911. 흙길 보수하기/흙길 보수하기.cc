#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ret;
int n, l, a, b;

vector<pair<int,int>> v;

int main(){
	cin >> n >> l;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		v.push_back({a,b});
	}
	sort(v.begin(), v.end());
	int s = v[0].first;
	int e = v[0].second;
	
	if((e-s) % l == 0) ret += (e-s) / l;
	else {
		ret += ((e-s) / l) + 1;
		e = s + (((e-s) / l) + 1) * l;
	}
	
	for(int i = 1; i < n; i++){
		if(v[i].second < e) continue;
		if(v[i].first < e){
			s = e;
			e = v[i].second;
		} else{
			s = v[i].first;
			e = v[i].second;
		}
		if((e-s) % l == 0) ret += (e-s) / l;
		else {
			ret += ((e-s) / l) + 1;
			e = s+ (((e-s) / l) + 1) * l;
		}		
	}
	cout << ret << "\n";
} 