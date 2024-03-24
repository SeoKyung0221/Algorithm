// 정렬의 우선순위는 1순위가 등장횟수(오름차순), 2순위는  수의 값(오름차순)
// 0은 무시한다.
// 최대 크기는 단, 100개까지만.
// 처음 시작할 때 r 연산 혹은 c연산을 수행함
// 행은 n, 열은 m 

#include<bits/stdc++.h>
using namespace std;
int r, c, k, a[104][104], n = 3, m = 3, ret;
map<int, int> mp;

bool cmp(int a, int b){
	if(mp[a] == mp[b]) return a < b;
	else return mp[a] < mp[b];
}

void r_cal(){
	for(int i = 1; i <= n; i++){
		vector<int> v;
		mp.clear();
		for(int j = 1; j <= m; j++){
			if(a[i][j] != 0) mp[a[i][j]]++;
		}
		for(int j = 1; j <= 100; j++){
			if(mp[j] != 0) v.push_back(j);
		}
		sort(v.begin(), v.end(), cmp);

		for(int j = 1; j <= v.size(); j++){
			for(int k = 1; k <= 2; k++){
				if(k == 1) a[i][2 * (j - 1) + k] = v[j - 1];
				else a[i][2 * (j - 1) + k] = mp[v[j - 1]];
			}
		}
		m = max(m, (int)(v.size() * 2));
		for(int j = 2 * v.size() + 1; j <= m; j++){
			a[i][j] = 0;
		}
	}
}

void c_cal(){
	for(int j = 1; j <= m; j++){
		vector<int> v;
		mp.clear();
		for(int i = 1; i <= n; i++){
			if(a[i][j] != 0) mp[a[i][j]]++;
		}
		for(int i = 1; i <= 100; i++){
			if(mp[i] != 0) v.push_back(i);
		}
		sort(v.begin(), v.end(), cmp);

		for(int i = 1; i <= v.size(); i++){
			for(int k = 1; k <= 2; k++){
				if(k == 1) a[2 * (i - 1) + k][j] = v[i - 1];
				else a[2 * (i - 1) + k][j] = mp[v[i - 1]];
			}
		}
		n = max(n, (int)(v.size() * 2));
		for(int i = 2 * v.size() + 1; i <= n; i++){
			a[i][j] = 0;
		}
	}
}

int main(){
	cin >> r >> c >> k;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	while(ret <= 100){
		if(a[r][c] == k) break;
		ret++;
		if(n >= m) r_cal();
		else c_cal();
	}
	if(ret > 100) cout << "-1\n";
	else cout << ret << "\n";
} 