#include<bits/stdc++.h>
using namespace std;
int n, num, lis[1004], len;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        auto pos = lower_bound(lis, lis + len, num);
        if(*pos == 0) len++;
        *pos = num;
    }
    cout << len << "\n";
}