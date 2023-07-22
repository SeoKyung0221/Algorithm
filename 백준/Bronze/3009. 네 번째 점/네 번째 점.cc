#include<bits/stdc++.h>
using namespace std;
int x, y, a[1004], b[1004];

int main(){
    for(int i = 0; i < 3; i++){
        cin >> x >> y;
        a[x]++; b[y]++;
    }
    for(int i = 0; i < 1004; i++){
        if(a[i] == 1) cout << i << " ";
    }
    for(int i = 0; i < 1004; i++){
        if(b[i] == 1) cout << i << "\n";
    }
}