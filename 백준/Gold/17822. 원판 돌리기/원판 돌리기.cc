// 모든 원판은 각각의 원판임.
// 평균을 구하고 수를 더하고 빼는 과정은, 각 원판을 회전한 이후에 해야함. 

#include<bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};
int n, m, t, num, x, d, k, ret;
vector<int> a[54];

void st(){
	for(int i = 1; i <= n; i++){
		vector<int> temp;
		for(int k = 0; k < 2; k++){
			for(int j = 0; j < m; j++){
				temp.push_back(a[i][j]);
			}	
		}
		a[i] = temp;
	} // 정리 
	return;
}
void avg(){
	double count = 0, sum = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] != 0){
				sum += a[i][j];
				count++;
			}
		}
	}
	double avg = sum / count;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] != 0){
				if(a[i][j] > avg) a[i][j] -=1;
				else if(a[i][j] < avg) a[i][j] += 1;
			}
		}	
	}
	return;
}
void solve(int p, int flag, int cnt){
	for(int i = p; i <= n; i += p){
		if(flag == 0){
			rotate(a[i].rbegin(), a[i].rbegin() + cnt, a[i].rend());
		}else{
			rotate(a[i].begin(), a[i].begin() + cnt, a[i].end());
		}
	}// 회전
	
	st();
	
	vector<pair<int, int>> v; 
	int flag_r = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 0) continue;
			flag = 0;
			for(int k = 0; k < 4; k++){
				int ny = i + dy[k];
				int nx = j + dx[k];
				if(nx < 0) nx += m; 
				if(ny < 1 || ny > n) continue;
				if(a[ny][nx] == 0) continue;
				if(a[i][j] == a[ny][nx]){
					flag = 1;
					flag_r = 1;
					v.push_back({ny, nx});
				}
			}
			if(flag == 1) v.push_back({i, j});
		}
	}// 수 지우기
	
	for(auto i : v){
		a[i.first][i.second] = 0;
	}
	
	if(flag_r == 0) avg(); // 평균 
	
	st();
	
	return;
}
int main(){
	cin >> n >> m >> t;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < m; j++){
			cin >> num;
			a[i].push_back(num);
		}
		for(int j = 0; j < m; j++){
			a[i].push_back(a[i][j]);
		}
	}
	for(int i = 0; i < t; i++){
		cin >> x >> d >> k;
		solve(x, d, k);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < m; j++){
			ret += a[i][j];
		}
	}
	cout << ret << "\n";
	return 0;
}