#include<bits/stdc++.h>
using namespace std;
int m, n, ret;

bool check(int n){
    if(n <= 1) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int main(){
    cin >> m >> n;
    int mx = n;
    int flag = 0;
    for(int i = m; i <= n; i++){
        if(check(i)){
            mx = min(mx, i);
            ret += i;
            flag = 1;
        }
    }
    if(flag)
    cout << ret << "\n" << mx << "\n";
    else
        cout << "-1\n";
}