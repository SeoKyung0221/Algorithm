#include<bits/stdc++.h>
using namespace std;
int n, ret;
char a[11][11];

int main(){
	for(int i = 1; i <= 10; i++){
		ret = 0;
		cin >> n;
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				scanf(" %c", &a[i][j]);
			}
		}
		for(int i = 0; i < 8; i++){
			for(int j = 0; j + n - 1 < 8; j++){
				string s1 = "", s2 = "";
				for(int k = 0; k < n; k++){
					s1 += a[i][j + k];
				}
				s2 = s1;
				reverse(s1.begin(), s1.end());
				if(s1 == s2) ret++;
			}
		}
		for(int j = 0; j < 8; j++){
			for(int i = 0; i + n - 1 < 8; i++){
				string s1 = "", s2 = "";
				for(int k = 0; k < n; k++){
					s1 += a[i+k][j];
				}
				s2 = s1;
				reverse(s1.begin(), s1.end());
				if(s1 == s2) ret++;
			}
		}
		cout << "#" << i << " " << ret << "\n";
	}
}