#include<bits/stdc++.h>
using namespace std;
int t, n, a[1004];
double ret, k;

int main(){
	cin >> t;
	while(t--){
		double cnt = 0;
		fill(&a[0], &a[0]+101, 0);
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i];	
		}
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum += a[i];
		}
		ret = sum / n;
		for(int i = 0; i < n; i++){
			if(a[i] > ret){
				cnt+=1;
			}
		}
		k = cnt/(double)n;
		k *= 100;
		printf("%.3lf%\n", k);
	}
}