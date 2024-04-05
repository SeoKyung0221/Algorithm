#include<bits/stdc++.h>
using namespace std;
int n, k, num, ret;
vector<int> a, b;

void rotate_robot(){
	if(b[2 * n - 1] == 1 && a[0] >= 1){
		b[0] = b[2 * n] = 1;
		b[2 * n - 1] = b[4 * n - 1] = 0;
		
		a[0] -= 1;
		a[2 * n] -= 1;
	}
	for(int i = 2 * n - 2; i >= 0; i--){
		if(b[i] == 1){
			if(b[i + 1] == 0 && a[i + 1] >= 1){
				b[i + 1] = b[i + 1 + 2 * n] = 1;
				b[i] = b[i + 2 * n] = 0;
				
				a[i + 1] -= 1;
				a[i + 1 + 2 * n] -= 1;
			}	
		}
	}
	if(b[n - 1] == 1 && a[n] >= 1){
		b[n - 1] = b[3 * n - 1] = 0;
	}
}
void on_robot(){
	if(a[0] >= 1){
		b[0] = b[2 * n] = 1;
		
		a[0] -= 1;
		a[2 * n] -= 1;
	}
}
bool check(){
	int cnt = 0;
	for(int i = 0; i < 2 * n; i++){
		if(a[i] == 0) cnt++;
	}
	if(cnt >= k) return true;
	else return false;
}
int main(){
	cin >> n >> k;
	for(int i = 0; i < 2 * n; i++){
		cin >> num;
		a.push_back(num);
		b.push_back(0);
	}
	for(int i = 0; i < 2 * n; i++){
		a.push_back(a[i]);
		b.push_back(0);
	}
	
	while(true){
		ret++;
		rotate(a.rbegin(), a.rbegin() + 1, a.rend());
		rotate(b.rbegin(), b.rbegin() + 1, b.rend());
		if(b[n - 1] == 1){
			b[n - 1] = b[3 * n - 1] = 0;
		}
		rotate_robot();
		on_robot();
		if(check()) break;
	}
	cout << ret << "\n";
}