#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int te, tcnt, h, w, n, y, x;
char a[24][24];
string s;

void go(int y1, int x1, int dir){
	if(dir == 0) a[y1][x1] = '^';
	else if(dir == 1) a[y1][x1] = '>';
	else if(dir == 2) a[y1][x1] = 'v';
	else a[y1][x1] = '<';
	
	int ny = y1 + dy[dir];
	int nx = x1 + dx[dir];
	if(ny < 0 || ny >= h || nx < 0 || nx >= w) return;
	if(a[ny][nx] == '.'){
		a[ny][nx] = a[y1][x1];
		a[y1][x1] = '.';
		y = ny;
		x = nx;
	}
}

void shoot(char q){
	int dir = 0;
	if(q == '^') dir = 0;
	else if(q == 'v') dir = 2;
	else if(q == '<') dir = 3;
	else if(q == '>') dir = 1;
	int ky = y, kx = x;
	while(true){
		int ny = ky + dy[dir];
		int nx = kx + dx[dir];
		if(ny < 0 || ny >= h || nx < 0 || nx >= w || a[ny][nx] == '#') break;
		if(a[ny][nx] == '*'){
			a[ny][nx] = '.';
			break;
		}
		ky = ny;
		kx = nx;
	}
}
int main(){
	cin >> te;
	while(te--){
		tcnt++;
		
		cin >> h >> w;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				scanf(" %c", &a[i][j]);
				if(a[i][j] == '^' || a[i][j] == 'v' || a[i][j] == '<' || a[i][j] == '>'){
					y = i; x = j;
				} 
			}
		}
		cin >> n >> s;
		for(char b : s){
			if(b == 'S'){
				shoot(a[y][x]);
			}else{
				if(b == 'U') go(y, x, 0);
				else if(b == 'R') go(y, x, 1);
				else if(b == 'D') go(y, x, 2);
				else if(b == 'L') go(y, x, 3);
			}
		}
		cout << "#" << tcnt << " ";
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cout << a[i][j];
			}
			cout << "\n";
		}
	}
}