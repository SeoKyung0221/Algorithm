#include<bits/stdc++.h>
using namespace std;
long long n, ret;

int main(){
    cin >> n;
    
    if(n == 1){
    	cout << 0 << "\n";
    	cout << 2 << "\n";
    	return 0;
	}
    for(int i = 1; i <= n-1; i++){
        for(int j = i + 1; j <= n; j++){
            ret++;
        }
    }
    cout << ret << "\n";
    cout << 2 << "\n";
}