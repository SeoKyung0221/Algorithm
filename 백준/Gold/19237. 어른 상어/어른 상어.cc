#include<bits/stdc++.h>
using namespace std;
struct MAP {
    int smell_count;
    int size;
};
struct Shark {
    int x, y;
    int dir;
    int prior_dir[5][5];
    bool alive;
};
// 위 아래 왼쪽 오른쪽
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,-1,1 };
// 변수들
int N, M, K;
Shark SHARK_INFO[401];
MAP MAP_INFO[21][21];
// 냄새가 있는 좌표 관리
bool check_range(int& next_x, int& next_y) {
    if (next_x >= 1 && next_y >= 1 && next_x <= N && next_y <= N)
        return true;
    else
        return false;
}
bool check_shark() {
    for (int i = 2; i <= M; i++) {
        if (SHARK_INFO[i].alive == true) {
            return false;
        }
    }
    return true;
}
void smell_Processing() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (MAP_INFO[i][j].smell_count != 0) {
                MAP_INFO[i][j].smell_count--;
                if (MAP_INFO[i][j].smell_count == 0) {
                    MAP_INFO[i][j].size = 0;
                }
            }
        }
    }
    for (int i = 1; i <= M; i++) {
        if (SHARK_INFO[i].alive == false)
            continue;
        int x = SHARK_INFO[i].x;
        int y = SHARK_INFO[i].y;
        MAP_INFO[x][y].size = i;
        MAP_INFO[x][y].smell_count = K;
    }
}
void kill_and_move() {
    for (int i = 1; i <= M; i++) {
        if (SHARK_INFO[i].alive == false) 
            continue;
        int x = SHARK_INFO[i].x;
        int y = SHARK_INFO[i].y;
        //cout << SHARK_INFO[i].x << SHARK_INFO[i].y << endl;
        if (MAP_INFO[x][y].size == 0 || MAP_INFO[x][y].size == i)
            MAP_INFO[x][y].size = i;
        else 
            SHARK_INFO[i].alive = false;
    }
}
void move() {
    for (int i = 1; i <= M; i++) {
        if (SHARK_INFO[i].alive == false)
            continue;
        // 처음에는 우선 순위로 빈칸 이동 확인하기
        int dir = SHARK_INFO[i].dir;
        bool flag = false;
        for (int j = 1; j <= 4; j++) {
            int next_x = SHARK_INFO[i].x + dx[SHARK_INFO[i].prior_dir[dir][j]];
            int next_y = SHARK_INFO[i].y + dy[SHARK_INFO[i].prior_dir[dir][j]];
            if (check_range(next_x, next_y) && MAP_INFO[next_x][next_y].size == 0) {
                SHARK_INFO[i].dir = SHARK_INFO[i].prior_dir[dir][j];
                SHARK_INFO[i].x = next_x;
                SHARK_INFO[i].y = next_y;
                flag = true;
                break;
            }
        }
        if (flag == true)
            continue;
        // 자기 냄새 칸으로 우선 순위 지켜서 이동
        for (int j = 1; j <= 4; j++) {
            int next_x = SHARK_INFO[i].x + dx[SHARK_INFO[i].prior_dir[dir][j]];
            int next_y = SHARK_INFO[i].y + dy[SHARK_INFO[i].prior_dir[dir][j]];
            if (check_range(next_x, next_y) && MAP_INFO[next_x][next_y].size == i) {
                SHARK_INFO[i].dir = SHARK_INFO[i].prior_dir[dir][j];
                SHARK_INFO[i].x = next_x;
                SHARK_INFO[i].y = next_y;
                break;
            }
        }
    }
}
void solve() {
    // 이동 할 칸 확인하기
    int day = 0;
    while (day < 1000){
        day++;
        move();
        kill_and_move();
        smell_Processing();
        if (check_shark() == true) {
            cout << day << endl;
            return;
        }
    }
    cout << -1 << endl;
}
void input() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> MAP_INFO[i][j].size;
            if (MAP_INFO[i][j].size != 0) {
                SHARK_INFO[MAP_INFO[i][j].size].x = i;
                SHARK_INFO[MAP_INFO[i][j].size].y = j;
                MAP_INFO[i][j].smell_count = K;
            }
        }
    }
    for (int i = 1; i <= M; i++) {
        cin >> SHARK_INFO[i].dir;
        SHARK_INFO[i].alive = true;
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= 4; k++) {
                cin >> SHARK_INFO[i].prior_dir[j][k];
            }
        }
    }
}
void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}
int main() {
    init();
    input();
    solve();
}