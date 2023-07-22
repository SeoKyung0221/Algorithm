#include<bits/stdc++.h>
using namespace std;
int n, k;

int main(){
    cin >> n >> k;
    int i = 1;
    int cnt = 0;
    int flag = 0;
    while(i <= n){
        if(n % i == 0){
            cnt++;
            if(cnt == k){
                flag = 1;
                break;
            }
        }
        i++;
    }
    if(flag) cout << i << "\n";
    else cout << "0\n";
}