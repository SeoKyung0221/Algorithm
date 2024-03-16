#include<bits/stdc++.h>
using namespace std;
int k, num, dir, ret;
vector<int> a[5];
string s;

int main(){	
	for(int i = 0; i < 4; i++){
		cin >> s;
		for(int j = 0; j < s.size(); j++){
			a[i].push_back({s[j] - '0'});
		}
	}
	cin >> k;
	for(int h = 0; h < k; h++){
		cin >> num >> dir;
		num--;
		
		int right, left;
		
		for(int i = num; i < 4; i++){
			if(i == 3) right = 3;
			else if(a[i][2] == a[i + 1][6]){
				right = i;
				break;
			}else right = i;
		}
		for(int i = num; i >= 0; i--){
			if(i == 0) left = 0;
			else if(a[i][6] == a[i - 1][2]){
				left = i;
				break;
			}else left = i;
		}
		
		int temp_dir = dir;
		for(int i = num; i <= right; i++){
			if(temp_dir == 1){
				rotate(a[i].rbegin(), a[i].rbegin() + 1, a[i].rend());
				temp_dir = -temp_dir;
			}else{
				rotate(a[i].begin(), a[i].begin() + 1, a[i].end());
				temp_dir = -temp_dir;
			}
		}
		
		temp_dir = -dir;
		for(int i = num - 1; i >= left; i--){
			if(temp_dir == 1){
				rotate(a[i].rbegin(), a[i].rbegin() + 1, a[i].rend());
				temp_dir = -temp_dir;
			}else{
				rotate(a[i].begin(), a[i].begin() + 1, a[i].end());
				temp_dir = -temp_dir;
			}
		}
	}
	for(int i = 0; i < 4; i++){
		if(i == 0 && a[i][0] == 1) ret += 1;
		if(i == 1 && a[i][0] == 1) ret += 2;
		if(i == 2 && a[i][0] == 1) ret += 4;
		if(i == 3 && a[i][0] == 1) ret += 8;
	}
	cout << ret << "\n";
}