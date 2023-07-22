#include<bits/stdc++.h>
using namespace std;
int x, y, w, h, ret = 1000;

int main(){
    cin >> x >> y >> w >> h;
    ret = min(ret, x);
    ret = min(ret, w-x);
    ret = min(ret, y);
    ret = min(ret, h-y);
    
    cout << ret << "\n";
}