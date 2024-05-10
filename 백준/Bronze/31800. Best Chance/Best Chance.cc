#include<bits/stdc++.h>
using namespace std;
int n, a[300004], b[300004], mx;
vector<int> v;
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		v.push_back(a[i]);
		mx = max(mx, a[i]);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	
	for(int i = 0; i < n; i++){
		if(a[i] == mx){
			cout << a[i] - v[v.size() - 2] << " ";
		}else cout << a[i] - mx << " ";
	}
}