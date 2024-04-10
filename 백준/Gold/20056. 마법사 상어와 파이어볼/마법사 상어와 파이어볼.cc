#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m, k, r, c, fm, s, d, ret;
struct ball{
	int m, s, d, os;
};
vector<ball> a[54][54];

void goFire(){
	vector<ball> b[54][54];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j].size()){
				for(int h = 0; h < a[i][j].size(); h++){
					int ny = (i + dy[a[i][j][h].d] * a[i][j][h].s + n) % n;
					int nx = (j + dx[a[i][j][h].d] * a[i][j][h].s + n) % n;
					
					b[ny][nx].push_back({a[i][j][h].m, a[i][j][h].s, a[i][j][h].d, a[i][j][h].os});
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(b[i][j].size() >= 2){
				int tempM = 0, tempS = 0, even = 1, odd = 1;
				for(int h = 0; h < b[i][j].size(); h++){
					tempM += b[i][j][h].m;
					tempS += b[i][j][h].os;
					if(b[i][j][h].d % 2 == 0) odd = 0;
					else even = 0;
				}
				
				tempM /= 5;
				tempS /= b[i][j].size();
				
				b[i][j].clear();
				if(tempM == 0) continue;
				
				for(int h = 0; h < 4; h++){
					if(odd || even) b[i][j].push_back({tempM, tempS % n, h * 2, tempS});
					else b[i][j].push_back({tempM, tempS % n, h * 2 + 1, tempS});
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i][j] = b[i][j];
		}
	}
	return;
}
int main(){
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		cin >> r >> c >> fm >> s >> d;
		r--; c--;
		a[r][c].push_back({fm, s % n, d, s});
	}
	for(int i = 0; i < k; i++){
		goFire();
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j].size()){
				for(int h = 0; h < a[i][j].size(); h++){
					ret += a[i][j][h].m;
				}	
			} 
		}
	}
	cout << ret << "\n";
}