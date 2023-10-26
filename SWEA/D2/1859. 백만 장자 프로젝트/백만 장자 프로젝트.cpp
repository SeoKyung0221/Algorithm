#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll te, tcnt, n, a[1000004];

int main(){
    cin >> te;
    while(te--){
        tcnt++;
        ll ret = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        ll max = a[n-1];
        for(int i = n-2; i >= 0; i--){
        	if(a[i] < max){
        		ret += max - a[i];
			}else{
				max = a[i];
			}
		}
        cout << "#" << tcnt << " " << ret << "\n";
    }
   	return 0;
}