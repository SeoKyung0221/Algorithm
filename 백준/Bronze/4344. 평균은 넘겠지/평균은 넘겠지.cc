#include<bits/stdc++.h>
using namespace std;
int c, n, num[1004];

int main(){
	cin >> c;
	while(c--){
		int cnt = 0;
		double avg = 0.0;
		double ret = 0.0;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> num[i];
			avg += num[i];
		}
		avg /= n;
		for(int i = 0; i < n; i++){
			if(avg < num[i]) cnt++;
		}
		ret = ((cnt * 100) / (double)n) + 0.0005;
		printf("%0.3lf%\n", ret);
	}
}