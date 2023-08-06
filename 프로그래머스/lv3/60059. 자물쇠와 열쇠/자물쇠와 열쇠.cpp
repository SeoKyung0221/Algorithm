#include<bits/stdc++.h>
using namespace std;

void _rotate(vector<vector<int>> &key){
    int m = key.size();
    vector<vector<int>> temp(m, vector<int>(m, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            temp[i][j] = key[j][m-1-i];
        }
    }
    key = temp;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int n = lock.size();
    int m = key.size();
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(lock[i][j] == 0) cnt++;
        }
    }
    for(int k = 0; k < 4; k++){
        for(int i = -19; i <= 19; i++){
            for(int j = -19; j <= 19; j++){
                int flag = 0, count = 0;
                for(int y = 0; y < m; y++){
                    for(int x = 0; x < m; x++){
                        int ny = y + i;
                        int nx = x + j;
                        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                        if(lock[ny][nx] == 0 && key[y][x] == 1){
                            count++;
                        }
                        if(lock[ny][nx] == 1 && key[y][x] == 1){
                            flag = 1;
                            continue;
                        }
                    }
                }
                if(flag != 1 && count == cnt){
                    return true;
                }
            }
        }
        _rotate(key);
    }
    return false;
}