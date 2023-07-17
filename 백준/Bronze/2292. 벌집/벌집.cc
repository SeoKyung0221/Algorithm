#include<bits/stdc++.h>
using namespace std;
int n, ret;

int main(){
	cin >> n;
	int i = 0;
	while(n > 3*i*(i+1) + 1){
		i++;
		ret++;
	}
	ret++;
	cout << ret << "\n";
}