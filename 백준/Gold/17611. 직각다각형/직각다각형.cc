#include<bits/stdc++.h>
using namespace std;
#define y1 aaaa
int n, x, y, x1, y1, check_x[100004], check_y[100004], ret;
pair<int, int> a[100004];
map<int, int> mp_x, mp_y;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		x += 500000;
		y += 500000;
		check_x[i] = x;
		check_y[i] = y;
		a[i] = {x, y};
	}
	a[n] = a[0];
	
	for(int i = 0; i < n; i++){
		tie(x, y) = a[i];
		tie(x1, y1) = a[i + 1];
		
		if(x != x1){
			if(x > x1) swap(x, x1);
			for(int j = x; j < x1; j++){
				mp_x[j]++;
			}
		}
		if(y != y1){
			if(y > y1) swap(y, y1);
			for(int j = y; j < y1; j++){
				mp_y[j]++;
			}
		}
	}
	for(int i : check_x) ret = max(ret, mp_x[i]);
	for(int i : check_y) ret = max(ret, mp_y[i]);
	
	cout << ret << "\n";
}