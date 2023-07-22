#include<bits/stdc++.h>
using namespace std;
int a, b;

int gcb(int x, int y){
    if(x == 0) return y;
    return gcb(y % x, x);
}
int main(){
    while(true){
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        if(gcb(a, b) == 1) cout << "neither\n";
        else if(gcb(a, b) == a) cout << "factor\n";
        else cout << "multiple\n";
    }
}