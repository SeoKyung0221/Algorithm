#include<bits/stdc++.h>
using namespace std;
int t, k, num, dir, ret;
string s;
vector<int> a[1004];

void goLeft(int num, int dir){
	int flag = (dir == 1) ? -1 : 1;
	
	if(num > 0){
		if(a[num][6] != a[num - 1][2]){
			goLeft(num - 1, flag);
		}
	}
	
	if(dir == 1){
		rotate(a[num].rbegin(), a[num].rbegin() + 1, a[num].rend());
	}else rotate(a[num].begin(), a[num].begin() + 1, a[num].end());
}

void goRight(int num, int dir){
	int flag = (dir == 1) ? -1 : 1;
	
	if(num < t - 1){
		if(a[num][2] != a[num + 1][6]){
			goRight(num + 1, flag);
		}
	}
	
	if(dir == 1){
		rotate(a[num].rbegin(), a[num].rbegin() + 1, a[num].rend());
	}else rotate(a[num].begin(), a[num].begin() + 1, a[num].end());
}
int main(){
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> s;
		for(int j = 0; j < s.size(); j++){
			a[i].push_back(s[j] - '0');
		}
	}
	cin >> k;
	for(int i = 0; i < k; i++){
		cin >> num >> dir;
		num--;
		
		int flag = (dir == 1) ? -1 : 1;
		if(num > 0){
			if(a[num][6] != a[num - 1][2]){
				goLeft(num - 1, flag);		
			}
		}
		
		if(num < t - 1){
			if(a[num][2] != a[num + 1][6]){
				goRight(num + 1, flag);
			}
		}
		
		if(dir == 1){
			rotate(a[num].rbegin(), a[num].rbegin() + 1, a[num].rend());
		}else rotate(a[num].begin(), a[num].begin() + 1, a[num].end());
	}
	for(int i = 0; i < t; i++){
		if(a[i][0] == 1) ret++;
	}
	cout << ret << "\n";
}