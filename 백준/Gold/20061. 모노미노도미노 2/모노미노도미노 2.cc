#include<bits/stdc++.h>
using namespace std;
int a[11][11], n, x, y, t, ret, ret2;

void move(vector<int> &v_x, vector<int> &v_y){ // x좌표따로, y좌표 따로해서 cnt로 최소 지점까지만 이동시키기.
	// 파랑블럭 x가 기준.
	int cnt = 1e9;
	for(int x : v_x){
		for(int i = 4; i < 10; i++){
			if(a[x][i] == 1){
				cnt = min(cnt, i);
				break;
			}
		}
	}
	if(cnt == 1e9) cnt = 10;
	for(int x : v_x){
		if(t == 2){
			a[x][cnt - 1] = 1;
			a[x][cnt - 2] = 1;
		}else{
			a[x][cnt - 1] = 1;
		}
	}
	
	cnt = 1e9;
	for(int y : v_y){
		for(int i = 4; i < 10; i++){
			if(a[i][y] == 1){
				cnt = min(cnt, i);
				break;
			}
		}
	}
	if(cnt == 1e9) cnt = 10;
	for(int y : v_y){
		if(t == 3){
			a[cnt - 1][y] = 1;
			a[cnt - 2][y] = 1;
		}else{
			a[cnt - 1][y] = 1;
		}
	}
	
	return;
}

void blueCopy(int cnt){
	for(int j = 8; j >= cnt; j--){
		for(int i = 0; i < 4; i++){
			a[i][j + 1] = a[i][j];
		}
	}
	for(int i = 0; i < 4; i++){
		a[i][cnt] = 0;
	}
	return;
}
void greenCopy(int cnt){
	for(int i = 8; i >= cnt; i--){
		for(int j = 0; j < 4; j++){
			a[i + 1][j] = a[i][j];
		}
	}
	for(int j = 0; j < 4; j++){
		a[cnt][j] = 0;
	}
	return;
}
void pointPush(){ // 점수 체크 및 연한 블록 위치 확인. 	
	for(int j = 6; j < 10; j++){
		if(a[0][j] && a[1][j] && a[2][j] && a[3][j]){
			ret++;
			for(int i = 0; i < 4; i++){
				a[i][j] = 0;
			}
			for(int k = j; k >= 6; k--){
				a[0][k] = a[0][k - 1];
				a[1][k] = a[1][k - 1];
				a[2][k] = a[2][k - 1];
				a[3][k] = a[3][k - 1];
			}
			for(int i = 0; i < 4; i++){
				a[i][5] = 0;
			}
		}
	}
	
	for(int i = 6; i < 10; i++){
		if(a[i][0] && a[i][1] && a[i][2] && a[i][3]){
			ret++;
			for(int j = 0; j < 4; j++){
				a[i][j] = 0;
			}
			for(int k = i; k >= 6; k--){
				a[k][0] = a[k - 1][0];
				a[k][1] = a[k - 1][1];
				a[k][2] = a[k - 1][2];
				a[k][3] = a[k - 1][3];
			}
			for(int j = 0; j < 4; j++){
				a[5][j] = 0;
			}
		}
	}
	
	// 파랑블럭
	for(int j = 4; j <= 5; j++){
		for(int i = 0; i < 4; i++){
			if(a[i][j]){
				blueCopy(j);
				break;
			}
		}
	}
	// 녹색
	for(int i = 4; i <= 5; i++){
		for(int j = 0; j < 4; j++){
			if(a[i][j]){
				greenCopy(i);
				break;
			}
		}
	}
	return;
}
int main(){	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t >> x >> y;
		
		vector<int> v_x, v_y;
		
		if(t == 1){
			v_x.push_back(x);
			v_y.push_back(y);
		}else if(t == 2){
			v_x.push_back(x);
			v_y.push_back(y);
			v_y.push_back(y + 1);
		}else{
			v_x.push_back(x);
			v_x.push_back(x + 1);
			v_y.push_back(y);
		}
		move(v_x, v_y);
//		cout << "-----------------move--------------\n";
//		for(int i = 0; i < 10; i++){
//			for(int j = 0; j < 10; j++){
//				cout << a[i][j] << " ";
//			}
//			cout << "\n";
//		}
		pointPush();
//		cout << "-----------------point--------------\n";
//		for(int i = 0; i < 10; i++){
//			for(int j = 0; j < 10; j++){
//				cout << a[i][j] << " ";
//			}
//			cout << "\n";
//		}
	}
	cout << ret << "\n";
	
	for(int i = 4; i < 10; i++){
		for(int j = 0; j < 4; j++){
			ret2 += a[i][j];
		}
	}
	for(int i = 0; i < 4; i++){
		for(int j = 4; j < 10; j++){
			ret2 += a[i][j];
		}
	}
	cout << ret2 << "\n";
} 