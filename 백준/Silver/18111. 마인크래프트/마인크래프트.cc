#include<bits/stdc++.h>
using namespace std;
int n, m, b, a[504][504], ret = 1e9, ddang;

bool check(int mid){
	int _time = 0, _block = b;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] < mid){
				_block -= (mid - a[i][j]);
				_time += (mid - a[i][j]);
			}else if(a[i][j] > mid){
				_block += (a[i][j] - mid);
				_time += 2 * (a[i][j] - mid);
			}
		}
	}
	
	if(_block < 0) return false;
	if(_time <= ret){
		ret = min(ret, _time);
		return true;
	}else return false;
}
int main(){
	cin >> n >> m >> b;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	
	int l = 0;
	
	while(l <= 256){
		if(check(l)) ddang = l;
		l++;
	}
	cout << ret << " " << ddang << "\n";
}