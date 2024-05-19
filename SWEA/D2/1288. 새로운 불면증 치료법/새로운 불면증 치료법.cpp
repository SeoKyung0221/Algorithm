#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll te, n, a[10];

bool check(){
	for(int i = 0; i < 10; i++){
    	if(a[i] == 0) return false;
    }
    return true;
}
int main(){
	cin >> te;
    for(ll t = 1; t <= te; t++){
        memset(a, 0, sizeof(a));
        int cnt = 1;
        
        cin >> n;
        int temp = n;
        while(true){
            cnt++;
        	string s = to_string(temp);
            for(int i = 0; i < s.size(); i++){
            	a[s[i] - '0'] = 1;
            }
            if(check()) break;
            temp = n * cnt;
        }
       	
    	cout << "#" << t << " " << temp << "\n";
    }
}