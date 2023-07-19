#include<bits/stdc++.h>
using namespace std;
int a, b, v, ret;

int main(){
	cin >> a >> b >> v;
    int c = (a-b);
    int h = (v-a);
    
    if(h % c == 0){
        ret = h / c + 1;
    }else ret = h / c + 2;
    cout << ret << "\n";
    return 0;
}