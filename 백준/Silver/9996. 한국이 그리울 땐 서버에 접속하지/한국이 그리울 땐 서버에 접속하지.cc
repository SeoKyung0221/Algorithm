#include<bits/stdc++.h>
using namespace std;
string a, b, front, back;
int N;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	cin >> a;
	int pos = a.find('*');
	front = a.substr(0, pos);
	back = a.substr(pos+1);
	
	for(int i = 1; i <= N; i++){
		cin >> b;
		if(a.size()-1 > b.size()){
			cout << "NE" << "\n";
		}else{
			if((front == b.substr(0, front.size())) && (back == b.substr(b.size()-back.size())))
				cout << "DA" << "\n";
			else
				cout << "NE" << "\n";
		}
	}
	return 0;
}