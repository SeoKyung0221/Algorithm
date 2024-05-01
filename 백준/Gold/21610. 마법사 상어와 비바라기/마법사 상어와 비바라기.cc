#include<bits/stdc++.h>
using namespace std;
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int n, m, a[54][54], b[54][54], d, s, ret; // a는 물 바구니, b는 구름 

void bibaragi(){ // 비바라기 시전! 중에서 맨 처음 구름 만들기. 
	b[n - 1][0] = 1;
	b[n - 1][1] = 1;
	b[n - 2][0] = 1;
	b[n - 2][1] = 1;
}

void move(int d, int s){
	vector<pair<int, int>> v;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(b[i][j]){
				int ny = i + dy[d] * s;
				int nx = j + dx[d] * s;
				ny = (ny + n) % n;
				nx = (nx + n) % n;
				b[i][j] = 0;
				v.push_back({ny, nx});
			}
		}
	}
	
	for(auto i : v){
		b[i.first][i.second] = 1;
	}
}

void rain(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(b[i][j]) a[i][j]++;
		}
	}
}

void waterBug(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(b[i][j]){
				for(int k = 1; k < 8; k += 2){
					int ny = i + dy[k];
					int nx = j + dx[k];
					if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
					if(a[ny][nx] > 0) a[i][j]++;
				}
			}
		}
	}
}

void makeCloud(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(b[i][j] == 1) b[i][j] = 0;
			else if(b[i][j] == 0 && a[i][j] >= 2){
				b[i][j]++;
				a[i][j] -= 2;
			}
		}
	}
}

//void printCloud(){
//	cout << "---------cloud-------------\n";
//	for(int i = 0; i < n; i++){
//		for(int j = 0; j < n; j++){
//			cout << b[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	cout << "---------water-------------\n";
//	for(int i = 0; i < n; i++){
//		for(int j = 0; j < n; j++){
//			cout << a[i][j] << " ";
//		}
//		cout << "\n";
//	}
//}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	bibaragi();
	for(int i = 0; i < m; i++){
		cin >> d >> s;
		d--; s %= n;
		move(d, s);
		rain();
		//erase cloud
		waterBug();
		makeCloud();
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ret += a[i][j];
		}
	}
	cout << ret << "\n";
}