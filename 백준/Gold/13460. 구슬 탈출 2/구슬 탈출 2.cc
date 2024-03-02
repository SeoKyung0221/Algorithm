#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};  
const int dx[] = {0, 1, 0, -1}; // 위, 오른, 아래, 왼 
int n, m, hy, hx, ry, rx, by, bx, ret = 1e9, flag;
struct Board{
	int ry = 0, rx = 0, by = 0, bx = 0;
	char a[11][11];
	
	bool move(int dir){
		int temp_ry = ry, temp_rx = rx, temp_by = by, temp_bx = bx;
		
		int rFlag = 0, bFlag = 0;
		while(true){
			int ny = temp_ry + dy[dir];
			int nx = temp_rx + dx[dir];
			if(ny <= 0 || ny >= n - 1 || nx <= 0 || nx >= m - 1 || a[ny][nx] == '#') break;
			if(a[ny][nx] == 'O'){
				temp_ry = ny;
				temp_rx = nx;
				rFlag = 1;
				break;
			}
			temp_ry = ny;
			temp_rx = nx;
		}
		while(true){
			int ny = temp_by + dy[dir];
			int nx = temp_bx + dx[dir];
			if(ny <= 0 || ny >= n - 1 || nx <= 0 || nx >= m - 1 || a[ny][nx] == '#') break;
			if(a[ny][nx] == 'O'){
				temp_by = ny;
				temp_bx = nx;
				bFlag = 1;
				break;
			}
			temp_by = ny;
			temp_bx = nx;
		}

		if(rFlag || bFlag){ // 구멍에 들어감	 
			if(rFlag && bFlag){
				flag = 1;
				return false;
			}
			if(bFlag){
				flag = 1;
				return false;
			}
			if(rFlag) return true;
		}else{ // 구멍에 안들어감 
			if(temp_ry == temp_by && temp_rx == temp_bx){
				if(dir == 0){
					if(ry > by){
						temp_ry++;
					}else if(ry < by){
						temp_by++;
					}
				}else if(dir == 1){
					if(rx > bx){
						temp_bx--;
					}else if(rx < bx){
						temp_rx--;
					}
				}else if(dir == 2){
					if(ry > by){
						temp_by--;
					}else if(ry < by){
						temp_ry--;
					}
				}else if(dir == 3){
					if(rx > bx){
						temp_rx++;
					}else if(rx < bx){
						temp_bx++;
					}
				}
				ry = temp_ry;
				rx = temp_rx;
				by = temp_by;
				bx = temp_bx;
				return false;
			}else{ 
				ry = temp_ry;
				rx = temp_rx;
				by = temp_by;
				bx = temp_bx;
				return false;
			}
		}
	}
};

void go(Board c, int cnt){
	if(cnt > 10) return;
	if(cnt > ret) return;
	for(int i = 0; i < 4; i++){
		Board d = c;
		if(d.move(i)){
			ret = min(ret, cnt);
			return;
		}else{
			if(flag){
				flag = 0;
				continue;
			}else{
				go(d, cnt + 1);
			}
		}
	}
	return; 
}
int main(){
	cin >> n >> m;
	Board c;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> c.a[i][j];
			if(c.a[i][j] == 'R'){
				c.ry = i;
				c.rx = j;
			}else if(c.a[i][j] == 'B'){
				c.by = i;
				c.bx = j;
			}
		}
	}
	go(c, 1);
	
	if(ret > 10) cout << "-1\n";
	else cout << ret << "\n";
	return 0;
} 