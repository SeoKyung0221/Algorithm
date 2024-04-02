#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int n = 4, y, x, num, dir, ret;
pair<int, int> a[4][4], c[4][4], fish_a[17], fish_c[17];

void move_fish(){
	for(int k = 1; k <= 16; k++){
		if(fish_c[k].first == 5) continue; // 이런 물고기는 없음. 
		
		tie(y, x) = fish_c[k]; // 현재 물고기 위치. 참고로 k가 현재 물고기 번호.
		for(int i = 0; i < 8; i++){
			int d = (c[y][x].second + i) % 8;
			int ny = y + dy[d];
			int nx = x + dx[d]; // 새 물고기의 위치 
			if(ny < 0 || ny >= n || nx < 0 || nx >= n || c[ny][nx].first == 17) continue;
			pair<int, int> temp = c[ny][nx]; // 원래 물고기의 번호 및 방향.
			
			c[ny][nx].first = c[y][x].first;
			c[ny][nx].second = d;
			fish_c[k] = make_pair(ny, nx); // 물고기 이동 
			
			c[y][x] = temp;
			if(temp.first == 0) fish_c[temp.first] = make_pair(5, 5);
			else fish_c[temp.first] = make_pair(y, x); // 물고기 위치 스왑

			// 참고로 빈칸인 경우에는 자연스럽게, k가 0이기 대문에 위치 스왑이 잘 이루어진다. 
			break; 
		}
	}
}
void solve(pair<int, int> a[4][4], pair<int, int> fish_a[17], int sy, int sx, int dir, int sum){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			c[i][j] = a[i][j];
		}
	}
	for(int i = 1; i <= 16; i++){
		fish_c[i] = fish_a[i];
	}
	
	move_fish(); // 복사받은 c를 이동. 
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i][j] = c[i][j];
		}
	}
	for(int i = 1; i <= 16; i++){
		fish_a[i] = fish_c[i];
	}
	// 이제 b함수는 그대로 두고, 다음 solve의 step으로 넘겨줘야함. 
	
	int flag = 0;
	for(int i = 1; i <= 3; i++){
		pair<int, int> b[4][4], fish_b[17];
		
		for(int p = 0; p < n; p++){
			for(int q = 0; q < n; q++){
				b[p][q] = a[p][q];
			}
		}
		for(int p = 1; p <= 16; p++){
			fish_b[p] = fish_a[p];
		}
		
		int ny = sy + dy[dir] * i;
		int nx = sx + dx[dir] * i;
		if(ny < 0 || ny >= n || nx < 0 || nx >= n || b[ny][nx].first == 0) continue;
		flag = 1;
		// 이제부터 상어 이동.
		// 1. 이동한 곳 물고기먹기
		// 2. 원래 있던 곳은 빈칸으로 이동한 곳은 17로
		// 3. 물고기 정보 삭제하기.
		
		b[sy][sx].first = 0; // 원래있던 곳은 빈칸
		fish_b[b[ny][nx].first] = make_pair(5, 5); // 갈 곳의 물고기정보 삭제.
		pair<int, int> temp = b[ny][nx]; // 먹을 물고기의 정보.
		b[ny][nx].first = 17;
	
		solve(b, fish_b, ny, nx, temp.second, sum + temp.first);
		
		b[ny][nx] = temp;
		fish_b[temp.first] = make_pair(ny, nx);
		b[sy][sx].first = 17; 
	}
	if(flag == 0){
		ret = max(ret, sum);
		return;
	}
}
int main(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> num >> dir;
			dir--;
			a[i][j] = make_pair(num, dir);
			fish_a[num] = make_pair(i, j);
		}
	}
	tie(num, dir) = a[0][0];
	a[0][0].first = 17;
	fish_a[num] = make_pair(5, 5);
	
	solve(a, fish_a, 0, 0, dir, num);
	
	cout << ret << "\n";
	return 0;
}