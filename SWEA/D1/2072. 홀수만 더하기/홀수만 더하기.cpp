#include<bits/stdc++.h>
using namespace std;
int te, tcnt, num, ret;

int main(){
    cin >> te;
    while(te--){
        ret = 0;
        tcnt++;
        for(int i = 0; i < 10; i++){
            cin >> num;
            if(num % 2 != 0) ret += num;
        }
        cout << "#" << tcnt << " " << ret << "\n";
    }
   	return 0;
}