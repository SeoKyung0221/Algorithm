#include<bits/stdc++.h>
using namespace std;
int te, n, node[64], temp[6][20] = {
	{0, 2, 8, 6, 1, 5, 7, 3, 51, 31, 41, 21, 50, 30, 40, 20, 52, 32, 42, 22},
	{10, 12, 18, 16, 11, 15, 17, 13, 56, 26, 46, 36, 57, 27, 47, 37, 58, 28, 48, 38},
	{20, 22, 28, 26, 21, 25, 27, 23, 0, 40, 18, 58, 3, 43, 15, 55, 6, 46, 12, 52},
	{30, 32, 38, 36, 31, 35, 37, 33, 8, 50, 10, 48, 5, 53, 13, 45, 2, 56, 16, 42},
	{40, 42, 48, 46, 41, 45, 47, 43, 6, 30, 16, 28, 7, 33, 17, 25, 8, 36, 18, 22},
	{50, 52, 58, 56, 51, 55, 57, 53, 2, 20, 12, 38, 1, 23, 11, 35, 0, 26, 10, 32}
};
char dir[6] = {'U', 'D', 'L', 'R', 'F', 'B'};
char color[6] = {'w', 'y', 'g', 'b', 'r', 'o'};
char a, b;
map<int, int> mp;

// node[i]의 i는 각 큐브의 칸을 말하고, =이 뜻하는 그 값은 색깔을 의미.
// mp는 그냥 dir을 쉽게 맵핑하기 위해. 
int main(){
	cin >> te;
	for(int i = 0; i < 6; i++){
		mp[dir[i]] = i;
	}
	while(te--){
		for(int i = 0; i <= 60; i++){
			node[i] = i / 10;
		}
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a >> b;
			int c = mp[a];
			
			for(int j = 0; j < 20; j += 4){
				if(b == '+'){
					int k = node[temp[c][j]];
					node[temp[c][j]] = node[temp[c][j + 3]];
					node[temp[c][j + 3]] = node[temp[c][j + 2]];
					node[temp[c][j + 2]] = node[temp[c][j + 1]];
					node[temp[c][j + 1]] = k;
				}else{
					int k = node[temp[c][j]];
					node[temp[c][j]] = node[temp[c][j + 1]];
					node[temp[c][j + 1]] = node[temp[c][j + 2]];
					node[temp[c][j + 2]] = node[temp[c][j + 3]];
					node[temp[c][j + 3]] = k;
				}
			}
		}
		for(int i = 0; i < 9; i++){
			cout << color[node[i]];
			if(i == 2 || i == 5 || i == 8) cout << "\n";
		}
	}
}