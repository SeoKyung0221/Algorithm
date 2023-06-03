#include<bits/stdc++.h>
using namespace std;
string s, s1;
double n, cnt1, cnt2;

int main(){
	while(cin >> s >> n >> s1){
		if(s1 == "P") continue;
		else if(s1 == "A+") cnt2 += (n * 4.5);
		else if(s1 == "A0") cnt2 += (n * 4.0);
		else if(s1 == "B+") cnt2 += (n * 3.5);
		else if(s1 == "B0") cnt2 += (n * 3.0);
		else if(s1 == "C+") cnt2 += (n * 2.5);
		else if(s1 == "C0") cnt2 += (n * 2.0);
		else if(s1 == "D+") cnt2 += (n * 1.5);
		else if(s1 == "D0") cnt2 += (n * 1.0);
		cnt1 += n;
	}
	printf("%6lf\n", cnt2/cnt1);
}