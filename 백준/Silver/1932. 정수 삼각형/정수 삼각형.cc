#include<bits/stdc++.h>
using namespace std;
int n, num, dp[504][10004], ret = -1;
vector<int> a[504];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin >> dp[i][j];
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0) dp[i][j] += dp[i-1][j];
            else if(j == i) dp[i][j] += dp[i-1][j-1];
            else dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
        }
    }
    for(int i = 0; i < n; i++){
        ret = max(ret, dp[n-1][i]);
    }
    cout << ret << "\n";
}