#include<bits/stdc++.h>
using namespace std;
string s;
char a[54][54];
int n, m;
long long ret = 987654321;

char b[8][8] = {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
                'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
                'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
                'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'};

char w[8][8] = {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
                'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
                'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
                'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
                'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
                'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'};

long long check(int y, int x){
    long long ans = 0;
    long long ans2 = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(a[y+i][x+j] != b[i][j]) ans++;
        }
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(a[y+i][x+j] != w[i][j]) ans2++;
        }
    }
    return min(ans, ans2);
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            a[i][j] = s[j];
        }
    }
    for(int i = 0; i <= n - 8; i++){
        for(int j = 0; j <= m - 8; j++){
            ret = min(ret, check(i, j));
        }
    }
    cout << ret << "\n";
}