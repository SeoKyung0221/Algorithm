#include<bits/stdc++.h>
using namespace std;

void _rotate(vector<vector<int>> &key){
    int m = key.size();
    vector<vector<int>> temp(m, vector<int>(m, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            temp[i][j] = key[j][m - 1 - i];
        }
    }
    key = temp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int n = lock.size();
    int m = key.size();
    int cnt1 = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(lock[i][j] == 0) cnt1++;
        }
    }
    for(int i = 0; i < 4; i++){
        for(int dy = -19; dy <= 19; dy++){
            for(int dx = -19; dx <= 19; dx++){
                
                int flag = 0, cnt2 = 0;
                for(int y = 0; y < m; y++){
                    for(int x = 0; x < m; x++){
                        int ny = y + dy;
                        int nx = x + dx;
                        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if(lock[ny][nx] == 1 && key[y][x] == 1){
                            flag = 1;
                            continue;
                        }
                        if(lock[ny][nx] == 0 && key[y][x] == 1){
                            cnt2++;
                        }
                    } 
                } 
                if(cnt1 == cnt2 && !flag) return true;
            }
        }
        _rotate(key);
    }
    return false;
}