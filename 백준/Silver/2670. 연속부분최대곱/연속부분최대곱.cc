#include<bits/stdc++.h>
using namespace std;
int n;
double a[10004], temp, ret;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	temp = 1;
	for(int i = 0; i < n; i++){
		temp *= a[i];
		ret = max(ret, temp);
		if(temp < 1){
			temp = 1;
		}
	}
	printf("%0.3lf", ret);
}