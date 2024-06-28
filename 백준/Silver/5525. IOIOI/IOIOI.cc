#include<bits/stdc++.h>
using namespace std;
int n, m, ret;
string s;

int main(){
	cin >> n >> m >> s;
	
	for(int i = 0; i < m; i++){
		int cnt = 0;
		
		if(s[i] == 'O') continue;
		else{
			while(s[i + 1] == 'O' && s[i + 2] == 'I'){
				cnt++;
				if(cnt == n){
					ret++;
					cnt--; // IOIOIOI 이렇게 있다고 생각(n = 1일 때) 맨 처음 IOI랑 만나면 IOI(cnt = 1)인 상태다.
					// 근데 다음 IOIOI를 만났을 때는 cnt = 2가 되므로 문제가 발생한다. ret이 증가하지 않는 것
					// 이를 방지하기 위해 앞의 cnt 하나를 없애서 뒤까지 모두 센다. 
				}
				i += 2;
			}
			cnt = 0;
		}	
	}
	cout << ret << "\n";
	
	return 0;
} 